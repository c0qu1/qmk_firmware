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
#include "nibble.h"

// Use Bit-C LED or Big LED to show CAPS LOCK status
void led_update_ports(led_t led_state) {
    // set_big_LED_r(led_state.caps_lock ? LED_ON : LED_OFF);
    //set_big_LED_g(led_state.caps_lock ? LED_ON : LED_OFF);
    // set_big_LED_b(led_state.caps_lock ? LED_ON : LED_OFF);
    set_bitc_LED(led_state.caps_lock ? LED_DIM : LED_OFF);
}
