/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "include/USB_descriptor_device.h"

#define MASK              0xFF 
#define VENDOR_ID         0x2E8A  // (Raspberry Pi)
#define PRODUCT_ID        0xAAAA  // bogus PID for testing
#define PRODUCT_BCD       0x0200
   
const uint8_t pico_device_descriptor[] = {

  0x12, 0x01,           // DEVICE_DESCRIPTOR
  0x00, 0x02,           // USB_VERSION_BCD
  0x00, 0x00, 0x00,     // USE INTERFACE DESCRIPTOR
  0x40,                 // EP0_PACKET_SIZE
  VENDOR_ID & MASK,     VENDOR_ID >> 8 & MASK,       
  PRODUCT_ID & MASK,    PRODUCT_ID >> 8 & MASK, 
  PRODUCT_BCD & MASK,   PRODUCT_BCD >> 8 & MASK,     
  0x01,                 // STRING_MANUFACTURER 
  0x02,                 // STRING_PRODUCT 
  0x00,                 // STRING_SERIAL 
  0x01                  // CONFIGURATIONS

};

const uint16_t usb_vendor_id() {

  return pico_device_descriptor[9] << 8 | pico_device_descriptor[8];

}

const uint16_t usb_product_id() {

  return pico_device_descriptor[11] << 8 | pico_device_descriptor[10];

}

const float usb_device_version() {

  return bcd_convert(pico_device_descriptor[3] , pico_device_descriptor[2]);

}

const float usb_device_release() {

  return bcd_convert(pico_device_descriptor[13] , pico_device_descriptor[12]);

}

const uint8_t ep0_packet_size() {

    if (pico_device_descriptor[7]==16 | 
        pico_device_descriptor[7]==32 | 
        pico_device_descriptor[7]==64 ) 

    {
      return pico_device_descriptor[7];
    
    } else {

      return DEVICE_DESCRIPTOR_DEFAULT_SIZE;
    
    }
}

float bcd_convert(uint8_t major, uint8_t minor) {

  const float TEN = 10;
 
  uint8_t major_tens = MIN(major >> 4, 9);
  uint8_t minor_tens = MIN(minor >> 4, 9);
  
  uint8_t major_units = MIN(major & 0xF, 9);
  uint8_t minor_units = MIN(minor & 0xF, 9);

  float integer_part    = major_tens * TEN + major_units;
  float fractional_part = minor_tens * TEN + minor_units;

  return integer_part + fractional_part / (TEN * TEN);

}
