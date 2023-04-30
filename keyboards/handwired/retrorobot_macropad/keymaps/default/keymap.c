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
  _0LAYER,
  _1LAYER,
  _2LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0LAYER] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        MO(1),         KC_X, KC_C, MO(2)
    ),
    [_1LAYER] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        KC_TRNS,         KC_X, KC_C, KC_TRNS
    ),
    [_2LAYER] = LAYOUT_only(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        KC_TRNS,         KC_X, KC_C, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _1LAYER) {
        set_big_LED_rgb(LED_ON, LED_OFF, LED_OFF);
    } else if (get_highest_layer(state) == _2LAYER) {
        set_big_LED_rgb(LED_OFF, LED_ON, LED_OFF);
    } else {
        set_big_LED_rgb(LED_OFF, LED_OFF, LED_ON);
    }
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state))
    {
        case _0LAYER:
            if (index == 0) { /* First encoder */
                //clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                clockwise ? tap_code(KC_U) : tap_code(KC_D);
            } else if (index == 1) { /* Second encoder */
                register_code(KC_LCTL);
                clockwise ? tap_code(KC_D) : tap_code(KC_U);
                unregister_code(KC_LCTL);
            }
            break;
        case _1LAYER:
            //nothing
            break;
        case _2LAYER:
            //nothing
            break;
//        case _VIA3:
//            if (index == 0) { /* First encoder */
//                change_RGB(clockwise);
//            } else if (index == 1) { /* Second encoder */
//                clockwise ? tap_code16(CK_UP) : tap_code16(CK_DOWN);
//            }
//            break;
    }
    return false;
}
