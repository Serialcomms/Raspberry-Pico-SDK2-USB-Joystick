/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

#define ZERO_LENGTH_PACKET 0

#define buffer_direction_to_host 0
#define buffer_direction_to_pico 1

void show_setup_packet();