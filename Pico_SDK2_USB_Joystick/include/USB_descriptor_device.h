/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

#define DEVICE_DESCRIPTOR_DEFAULT_SIZE 8

extern const uint8_t pico_device_descriptor[];

const uint8_t ep0_packet_size();
const uint16_t usb_vendor_id();
const uint16_t usb_product_id();

const uint16_t config_total_length();

const float usb_device_version();
const float usb_device_release();

float bcd_convert(uint8_t major, uint8_t minor);