/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "include/USB_descriptor_config.h"

const uint8_t pico_config_descriptor[] = {

  0x09, 0x02, 0x22, 0x00, 0x01, 0x01, 0x00, 0xA0, 0x32,           // Configuration Descriptor
  0x09, 0x04, 0x00, 0x00, 0x01, 0x03, 0x00, 0x04, 0x03,           // Interface Descriptor
  0x09, 0x21, 0x11, 0x01, 0x00, 0x01, 0x22, 0x59, 0x00,           // HID Descriptor
  0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x0A                        // Endpoint Descriptor: EP1 In to Host

};

const uint16_t config_total_length() {

  return pico_config_descriptor[3] << 8 | pico_config_descriptor[2];

}