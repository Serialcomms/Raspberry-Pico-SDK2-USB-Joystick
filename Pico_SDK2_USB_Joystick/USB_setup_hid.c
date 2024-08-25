/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "include/USB_setup_control.h"
#include "include/USB_HID_descriptor.h"
#include "include/USB_setup_packet.h"
#include "include/USB_setup_hid.h"

bool HID_SET_IDLE_COMPLETE = false;

void usb_setup_hid_joystick() {

  switch (setup->request_type) {

    case USB_REQ_TYPE_STANDARD:     send_hid_report_to_host();        break;
    case USB_REQ_TYPE_TYPE_CLASS:   setup_hid_class_request();        break;
    default:                        setup_hid_request_type_unknown(); break;                     

  }

}

static inline void send_hid_report_to_host() {

  uint16_t hid_report_size = pico_hid_report_descriptor_size();

  start_control_transfer_to_host(pico_hid_report_descriptor, hid_report_size);

}

static inline void setup_hid_class_request() {

   if (setup->request == USB_HID_SET_IDLE) {

    printf("HID Setup Interface, Setting Idle, Request=%d\n\r", setup->request);

    HID_SET_IDLE_COMPLETE = true;

  } else {

    printf("HID Setup Interface \tUnknown Request=%d\n\r", setup->request);

    HID_SET_IDLE_COMPLETE = false;

  }

  send_zlp_to_host(0);

}

static inline void setup_hid_request_type_unknown() {

  printf("Setup HID, unknown request type=%d\n\r", setup->request_type);

}