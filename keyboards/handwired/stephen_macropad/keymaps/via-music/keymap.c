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
  CYCLE_LAYERS = QK_KB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_WWW_REFRESH,          KC_MUTE,
        KC_A, KC_R, KC_S,    CYCLE_LAYERS
    ),
    [1] = LAYOUT(
        KC_Q,                       KC_P,
        KC_A, KC_R, KC_S,    CYCLE_LAYERS
    ),
    [2] = LAYOUT(
        CK_TOGG,                 MU_TOGG,
        KC_A, KC_R, KC_S,    CYCLE_LAYERS
    ),
    [3] = LAYOUT(
        KC_A,                       KC_A,
        KC_A, KC_R, KC_S,    CYCLE_LAYERS
    )
};

// Light LED 1 in green when keyboard layer 0 is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
// Light LED 1 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
// Light LED 1 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
// Light LED 3 in red when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,    // Overrides other layers
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    if (get_highest_layer(state) == 1) {
        PLAY_SONG(layer1_song);
    } else if (get_highest_layer(state) == 2) {
        PLAY_SONG(layer2_song);
    } else if (get_highest_layer(state) == 3) {
        PLAY_SONG(layer3_song);
    } else {
        PLAY_SONG(layer0_song);
    }
    return state;
}

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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),   ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(CK_DOWN, CK_UP),               ENCODER_CCW_CW(MU_NEXT, MU_NEXT)  },
    [3] =   { ENCODER_CCW_CW(KC_NO, KC_NO),                 ENCODER_CCW_CW(KC_NO, KC_NO) }
    //                  Encoder 1                                     Encoder 2
};
#endif
