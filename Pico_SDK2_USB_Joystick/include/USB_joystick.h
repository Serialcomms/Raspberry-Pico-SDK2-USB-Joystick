/*
 * Copyright (c) 2024 Serialcomms (GitHub).
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LIB_TINYUSB_HOST
#undef LIB_TINYUSB_DEVICE

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void init_joystick_timer();

void show_joystick_data();

void calculate_joystick_movement();

bool send_joystick_movement(repeating_timer_t *stdio_test_loop_timer);