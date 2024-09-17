/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

#define USB_REQ_TYPE_STANDARD       0x00
#define USB_REQ_TYPE_TYPE_MASK      0x60
#define USB_REQ_TYPE_TYPE_CLASS     0x20
#define USB_REQ_TYPE_TYPE_VENDOR    0x40

#define USB_HID_GET_REPORT  0x01
#define USB_HID_GET_IDLE    0x02
#define USB_HID_SET_IDLE    0x0A

extern bool HID_SET_IDLE_COMPLETE;

void usb_setup_hid_joystick();

static inline void send_hid_report_to_host();
static inline void setup_hid_class_request();
static inline void setup_hid_request_type_unknown();