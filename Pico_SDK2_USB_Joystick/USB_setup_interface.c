/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "include/USB_setup_packet.h"
#include "include/USB_setup_interface.h"
#include "include/USB_setup_hid.h"

void usb_setup_interface() {

  setup->direction ? setup_interface_respond_to_host() : setup_interface_request_to_pico();

}

static inline void setup_interface_respond_to_host() {

    printf("Setup Interface Standard, Request Type=%d, direction=%d\n\r", 
    setup->request_type, setup->direction);

    usb_setup_hid_joystick();   // send HID report descriptor

}

static inline void setup_interface_request_to_pico() {

    printf("Setup Interface Standard, Request Type=%d, direction=%d\n\r", 
    setup->request_type, setup->direction);

    setup_interface_unknown();
}

static inline void setup_interface_unknown() {

    printf("Setup Packet IRQ unknown interface request type=%d\n\r", setup->request_type);

}