/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_uart.h"
#include "pico/util/datetime.h"
#include "hardware/rtc.h"
#include "include/USB_initialise.h"
#include "include/USB_setup_hid.h"
#include "include/USB_joystick.h"
#include "include/USB_main.h"

datetime_t pico_datetime;

int main() {

    init_main();

    if (wait_for_joystick_set_idle) {

        busy_wait_ms(1000);
        
        init_joystick_timer();

    } else {

        printf("Joystick enumeration failed\n\r");

    }

    while (1) {

        tight_loop_contents();

    }

}

void init_main() {

    init_pico_datetime();

    stdio_deinit_all();
    
    stdio_uart_init();

    clear_uart_screen();

    usb_device_init();

    usb_insert_device();

    busy_wait_ms(100);

    gpio_init(PICO_DEFAULT_LED_PIN);
      
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    gpio_put(PICO_DEFAULT_LED_PIN, 1);

}

void init_pico_datetime() {

    pico_datetime.year = 2024;
    pico_datetime.month = 1;
    pico_datetime.day = 1;
    pico_datetime.dotw = 0;
    pico_datetime.hour = 0;
    pico_datetime.min = 0;
    pico_datetime.sec = 0;
  
    rtc_init();

    bool datetime_is_set = rtc_set_datetime(&pico_datetime);

    if (!datetime_is_set) {

        printf("Error setting Pico DateTime - check settings above\n\r");

        busy_wait_ms(5000);

    }

}

void clear_uart_screen() {

    printf("\033[H");        // cursor home
    printf("\033[2J");       // clear screen
    printf("\033[3J");       // clear scrollback
    printf("\033[40m");      // black background
    printf("\033[?25l");     // hide cursor (reduce flicker)

}

bool wait_for_joystick_set_idle() {

    bool wait_timeout;
    absolute_time_t wait_time = make_timeout_time_ms(5000);

    do {

        wait_timeout = time_reached(wait_time);

    } while (!wait_timeout && !HID_SET_IDLE_COMPLETE);

    return HID_SET_IDLE_COMPLETE;

}