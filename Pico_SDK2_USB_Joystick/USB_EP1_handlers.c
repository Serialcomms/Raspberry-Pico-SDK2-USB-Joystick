/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/structs/usb.h"           // USB hardware struct definitions
#include "include/USB_endpoint_struct.h"
#include "include/USB_queue_control.h"
#include "include/USB_buffer_control.h"
#include "include/USB_EP1_handlers.h"

void ep1_handler_to_host () {

    clear_buffer_status(USB_BUFF_STATUS_EP1_IN_BITS); 

    toggle_next_data_pid_to_host(1);

    set_queue_busy_to_host(1, false);

    printf("EP1 handler to Host, clearing buffer status, transfer bytes=%d\n\r",
    get_buffer_control_transfer_bytes_to_host(1));
 
}

static inline void clear_buffer_status (uint32_t buffer_mask) {

    usb_hardware_clear->buf_status = buffer_mask;
  
}