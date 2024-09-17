
/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "include/USB_queue_control.h"
#include "include/USB_queue_receive.h"

int16_t start_queue_transfer_to_pico(uint8_t EP_NUMBER, void *pico_buffer, uint16_t pico_buffer_bytes) {

  int16_t queue_bytes = PICO_ERROR_NO_DATA;
 
  set_queue_busy_to_pico(EP_NUMBER, true);

  bool queue_empty = queue_is_empty_to_pico(EP_NUMBER);

  if (queue_empty) {

    bool new_data = wait_for_new_data_from_host(EP_NUMBER, 333);

    if (new_data) {

      queue_bytes = send_queue_bytes_to_pico_buffer(EP_NUMBER, pico_buffer, pico_buffer_bytes);

    } 

  } else {

    queue_bytes = send_queue_bytes_to_pico_buffer(EP_NUMBER, pico_buffer, pico_buffer_bytes);

  }

  set_queue_busy_to_pico(EP_NUMBER, false);

  return queue_bytes;

}

int16_t send_queue_bytes_to_pico_buffer(uint8_t EP_NUMBER, void *pico_buffer, uint16_t pico_buffer_bytes) {

  uint8_t QUEUE_BYTE;
  uint16_t buffer_offset = 0;
  int16_t bytes_sent = PICO_ERROR_NO_DATA;
  uint8_t *stdin_buffer_bytes = pico_buffer;
  
  while (buffer_offset < pico_buffer_bytes) {

   bool byte_removed = queue_try_remove_to_pico(EP_NUMBER, &QUEUE_BYTE);

    if (byte_removed) {

      stdin_buffer_bytes[buffer_offset] = QUEUE_BYTE;

      ++buffer_offset;

    }
   
  }

  if (buffer_offset) bytes_sent = buffer_offset;

  printf("EP%d, Send Queue Transfer to Pico, buffer address=%08X, bytes sent=%d, max_bytes=%d \n\r", 
  EP_NUMBER, pico_buffer, bytes_sent, pico_buffer_bytes); 

  return bytes_sent;

}

static inline bool wait_for_new_data_from_host(uint8_t EP_NUMBER, uint16_t wait_milliseconds) {

  absolute_time_t wait_time = make_timeout_time_ms(wait_milliseconds);

  bool wait_timeout;

  do {

    wait_timeout = time_reached(wait_time);

  } while (!wait_timeout & get_queue_busy_to_pico(EP_NUMBER));

  return (!queue_is_empty_to_pico(EP_NUMBER));

}