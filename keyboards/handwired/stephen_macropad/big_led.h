/* Copyright 2021 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* Optional big LED pins */
#define BIG_LED_R_PIN GP7
#define BIG_LED_G_PIN GP8
#define BIG_LED_B_PIN GP9

#define LED_ON          2
#define LED_OFF         0

#define GPIO_STATE_LOW  0
#define GPIO_STATE_HIGH 1
//Inverted for common anode LED
//#define GPIO_STATE_LOW  1
//#define GPIO_STATE_HIGH 0

void
  set_big_LED_rgb(uint8_t r_mode, uint8_t g_mode, uint8_t b_mode),
  set_big_LED_r(uint8_t mode),
  set_big_LED_g(uint8_t mode),
  set_big_LED_b(uint8_t mode);
