/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "include/USB_setup_control.h"
#include "include/USB_setup_packet.h"
#include "include/USB_build_endpoints.h"
#include "include/USB_buffer_control.h"

uint8_t hid_config_number = 0;

bool HID_CONFIGURATION_SET = false;

void usb_set_configuration(uint8_t configuration_number) {

  printf("USB Set Configuration, Number=%d\n\r", configuration_number);

  hid_config_number = configuration_number;

  if (hid_config_number == 1) {

    usb_build_function_endpoints();

    set_buffer_control_available_to_host(1, true);
   
    printf("USB Set HID Configuration ");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\r");

    HID_CONFIGURATION_SET = true;

  } else {

    printf("USB Set Configuration, Number Requested is Zero or Invalid\n\r");

  }

  send_zlp_to_host(0);

}