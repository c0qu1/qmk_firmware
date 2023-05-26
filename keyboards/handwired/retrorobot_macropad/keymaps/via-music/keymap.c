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

#ifdef AUDIO_ENABLE
float layer0_song[][2] = SONG(IMPERIAL_MARCH);
float layer1_song[][2] = SONG(ZELDA_TREASURE);
float layer2_song[][2] = SONG(ONE_UP_SOUND);
float layer3_song[][2] = SONG(MARIO_MUSHROOM);
#endif

enum custom_keycodes {
  BIG_LED_TOGG = QK_KB,
};

bool big_led_toggle_state = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_WWW_REFRESH,          KC_MUTE,
        KC_A,          KC_R, KC_S, KC_T,
        TO(1),         KC_X, KC_C, TO(2)
    ),
    [1] = LAYOUT(
        KC_Q,                      KC_P,
        KC_A,          KC_R, KC_S, KC_T,
        TO(0),         KC_X, KC_C, KC_TRNS
    ),
    [2] = LAYOUT(
        CK_TOGG,                 MU_TOGG,
        CK_RST,        KC_R, KC_S, KC_T,
        TO(3),         KC_X, KC_C, TO(0)
    ),
    [3] = LAYOUT(
        BIG_LED_TOGG,               QK_BOOT,
        KC_NO,          KC_NO, KC_NO, KC_NO,
        TO(0),          KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == 1 && big_led_toggle_state == true) {
        set_big_LED_rgb(LED_ON, LED_OFF, LED_OFF);
        PLAY_SONG(layer1_song);
    } else if (get_highest_layer(state) == 2 && big_led_toggle_state == true) {
        set_big_LED_rgb(LED_OFF, LED_ON, LED_OFF);
        PLAY_SONG(layer2_song);
    } else if (get_highest_layer(state) == 3 && big_led_toggle_state == true) {
        set_big_LED_rgb(LED_ON, LED_OFF, LED_ON);
        PLAY_SONG(layer3_song);
    } else if(get_highest_layer(state) == 0 && big_led_toggle_state == true) {
        set_big_LED_rgb(LED_OFF, LED_OFF, LED_ON);
        //PLAY_SONG(layer0_song);
    } else if(big_led_toggle_state == false) {
        set_big_LED_rgb(LED_OFF, LED_OFF, LED_OFF);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case BIG_LED_TOGG: //custom keycode
      if (record->event.pressed) {
        big_led_toggle_state = !big_led_toggle_state;
      }
    break;
  }
return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),   ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(CK_DOWN, CK_UP),               ENCODER_CCW_CW(MU_NEXT, MU_NEXT)  },
    [3] =   { ENCODER_CCW_CW(KC_NO, KC_NO),                 ENCODER_CCW_CW(KC_NO, KC_NO) }
    //                  Encoder 1                                     Encoder 2
};
#endif
