/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

void *get_pico_endpoint_handler(uint8_t EP_NUMBER);
void set_pico_endpoint_handler(uint8_t EP_NUMBER, void *callback_handler);
void usb_build_pico_endpoint(uint8_t EP_NUMBER, uint16_t TRANSFER_TYPE, uint16_t QUEUE_SIZE, void *completion_handler_address);

static inline uint32_t usb_buffer_offset(volatile uint8_t *buffer);
static inline uint32_t endpoint_control_base_config(uint8_t TRANSFER_TYPE, uint32_t address_base);

static inline void build_pico_default_endpoint(int16_t QUEUE_SIZE, void *completion_handler_address);
static inline void build_pico_function_endpoint(uint8_t EP_NUMBER, uint16_t TRANSFER_TYPE, int16_t QUEUE_SIZE, void *completion_handler_address);