/*
Copyright 2023 c0qu1

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "big_led.h"

enum layer_names {
  _0,
  _1,
  _2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        MO(1),         KC_X, KC_C, MO(2)
    ),
    [_1] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        KC_TRNS,         KC_X, KC_C, KC_TRNS
    ),
    [_2] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        KC_TRNS,         KC_X, KC_C, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _1) {
        set_big_LED_rgb(LED_ON, LED_OFF, LED_OFF);
    } else if (get_highest_layer(state) == _2) {
        set_big_LED_rgb(LED_OFF, LED_ON, LED_OFF);
    } else {
        set_big_LED_rgb(LED_OFF, LED_OFF, LED_ON);
    }
    return state;
}
