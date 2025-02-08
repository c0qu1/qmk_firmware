/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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
#include QMK_KEYBOARD_H

enum custom_keycodes {
  CYCLE_LAYERS = QK_KB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MAIL, KC_MPLY, KC_MUTE,
        KC_MPRV, KC_MNXT, CYCLE_LAYERS
    ),
    [1] = LAYOUT(
        KC_WBAK, KC_WFWD, KC_WSTP,
        S(C(KC_TAB)), C(KC_TAB), CYCLE_LAYERS
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)             },
    [1] =   { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) }
};
#endif

uint8_t selected_layer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case CYCLE_LAYERS: //custom keycode
      if (record->event.pressed) {
        selected_layer++;
        if(selected_layer > 3) { selected_layer = 0;}
        layer_clear();
        layer_on(selected_layer);
      }
    break;
  }
return true;
}
