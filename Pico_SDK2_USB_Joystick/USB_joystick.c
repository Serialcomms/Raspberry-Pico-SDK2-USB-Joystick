/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <math.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/util/datetime.h" 
#include "hardware/rtc.h"
#include "include/USB_queue_transmit.h"
#include "include/USB_joystick.h"

uint8_t joystick_buffer[6];
uint8_t *joystick_report = joystick_buffer;
repeating_timer_t joystick_loop_timer;

int8_t pointer_x;
int8_t pointer_y;

uint8_t rudder;
uint8_t throttle;
uint8_t buttons; 
uint8_t hat_switch;
uint16_t angle; 
uint16_t i = 200; 

bool send_joystick_movement(repeating_timer_t *stdio_test_loop_timer) {

   calculate_joystick_movement();

   joystick_report[0] = rudder;
   joystick_report[1] = throttle;
   joystick_report[2] = pointer_x;
   joystick_report[3] = pointer_y;
   joystick_report[4] = hat_switch;
   joystick_report[5] = buttons;

   start_queue_transfer_to_host(1, joystick_report, count_of(joystick_buffer));

   gpio_xor_mask(1 << PICO_DEFAULT_LED_PIN);
   
   show_joystick_data();


   return true;

}

void calculate_joystick_movement() {

   const uint16_t radius = 120;
   const float radians = M_PI / (float) 180.0; 

   i %= 16535;         
   angle %= 360;

   rudder = (i % 0xFF * 8) & 0xFF;               // values -127 to +128;
   throttle = 255 - (i % 0xFF * 8) & 0xFF;       // values -127 to +128;
   buttons = (int8_t) (1 << (i%8)) & 0xff;       // one bit per button 
   hat_switch = (i) & 0x07;                      // hat switch value 
   pointer_x = cosf(angle * radians) * radius ;  // values -127 to +128
   pointer_y = sinf(angle * radians) * radius ;  // values -127 to +128

   i += 1;
   angle += 6; 

}

void init_joystick_timer() {

   add_repeating_timer_ms(1000, send_joystick_movement, NULL, &joystick_loop_timer);

}

void show_joystick_data() {

   extern datetime_t pico_datetime;

   rtc_get_datetime(&pico_datetime);
        
   printf("Time=%02d:%02d:%02d, Joystick HID = %02X, %02X, %02X, %02X, %02X, %02X\n\r", 
   pico_datetime.hour, 
   pico_datetime.min, 
   pico_datetime.sec,
   joystick_report[0], 
   joystick_report[1], 
   joystick_report[2], 
   joystick_report[3],
   joystick_report[4], 
   joystick_report[5] 
  
   ); 

   printf("Time=%02d:%02d:%02d, Joystick Data: Angle=%d, Rudder=%d, Throttle=%d, Pointer x/y=%d/%d \n\r", 
   pico_datetime.hour, 
   pico_datetime.min, 
   pico_datetime.sec,
   angle, 
   rudder, 
   throttle,
   pointer_x, 
   pointer_y
   ); 

}