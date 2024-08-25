/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

extern const uint8_t pico_hid_report_descriptor[];

const uint16_t pico_hid_report_descriptor_size();