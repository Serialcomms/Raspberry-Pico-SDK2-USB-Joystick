/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

uint16_t get_queue_free_to_host(uint8_t EP_NUMBER);
uint16_t get_queue_free_to_pico(uint8_t EP_NUMBER);

uint16_t get_queue_level_to_host(uint8_t EP_NUMBER);
uint16_t get_queue_level_to_pico(uint8_t EP_NUMBER);

bool queue_is_empty_to_host(uint8_t EP_NUMBER);
bool queue_is_empty_to_pico(uint8_t EP_NUMBER);

bool get_queue_busy_to_host(uint8_t EP_NUMBER);
bool get_queue_busy_to_pico(uint8_t EP_NUMBER);

void set_queue_busy_to_host(uint8_t EP_NUMBER, bool busy_state);
void set_queue_busy_to_pico(uint8_t EP_NUMBER, bool busy_state);

bool queue_try_add_to_host(uint8_t EP_NUMBER, const uint8_t *source_data_byte);
bool queue_try_add_to_pico(uint8_t EP_NUMBER, const uint8_t *source_data_byte);

bool queue_try_remove_to_host(uint8_t EP_NUMBER, void *source_data_byte);
bool queue_try_remove_to_pico(uint8_t EP_NUMBER, void *source_data_byte);