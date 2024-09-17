/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

extern datetime_t pico_datetime;

void init_main();

void init_pico_datetime();

void clear_uart_screen();

bool wait_for_joystick_set_idle();