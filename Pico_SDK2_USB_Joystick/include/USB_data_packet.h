/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

#define buffer_direction_to_host 0
#define buffer_direction_to_pico 1

#define USB_BUFFER_CONTROL_FULL 0x00008000

void start_async_send_data_packet(uint8_t EP_NUMBER, uint8_t transfer_bytes);
void start_async_receive_data_packet(uint8_t EP_NUMBER, uint8_t transfer_bytes);