/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

void usb_setup_interface();

static inline void setup_interface_respond_to_host();
static inline void setup_interface_request_to_pico();
static inline void setup_interface_unknown();