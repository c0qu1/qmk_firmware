// Copyright 2022 Juan Rivera (@c0qu1)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
float layer0_song[][2] = SONG(IMPERIAL_MARCH);
float layer1_song[][2] = SONG(ZELDA_TREASURE);
float layer2_song[][2] = SONG(ZELDA_PUZZLE);
float layer3_song[][2] = SONG(ONE_UP_SOUND);
float layer4_song[][2] = SONG(COIN_SOUND);
float layer5_song[][2] = SONG(MARIO_MUSHROOM);
float layer6_song[][2] = SONG(MARIO_THEME);
#endif

enum custom_keycodes {
  IMP_MARCH = QK_KB,
  ZELDA_TRSR,
  ZELDA_PZZLE,
  ONE_UP,
  COIN,
  MUSHROOM,
  MARIO
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _VIA1,
  _VIA2,
  _VIA3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_ansi65x(
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                                                          KC_MUTE,                   KC_F17,  KC_F18,
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,           KC_BSPC, KC_INS,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT,           KC_HOME,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             TT(_VIA1), TT(_VIA3), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
      ),

     [_VIA1] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       _______,                   _______, _______,
       RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_PGUP,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,   KC_PGDN,
       _______, _______,          _______,                   _______,                            TG(_VIA1), TG(_VIA2), _______, KC_MPRV, KC_MPLY,   KC_MNXT
     ),

     [_VIA2] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       _______,                   _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
       _______, _______,          _______,                   _______,                            _______, TG(_VIA2), _______, _______, _______, _______
     ),

     [_VIA3] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       RGB_TOG,                   CK_TOGG, MU_TOGG,
       _______, IMP_MARCH, ZELDA_TRSR, ZELDA_PZZLE, ONE_UP, COIN, MUSHROOM, MARIO, _______, _______, _______, _______, _______,          CK_RST,  MU_NEXT,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AU_TOGG,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
       _______, _______,          _______,                   _______,                            _______, TG(_VIA3), _______, _______, _______, _______
     )
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}       // Light first LED
);
// Light LED 2 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_PINK} // Light 4 LEDs, starting with LED 6
);
// Light LED 2 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GOLD}
);
// Light LED 3 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_GREEN}
);
// Light LED 3 in green when keyboard layer 3 is active

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides other layers
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer    // Overrides other layers
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
//    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _VIA1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _VIA2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _VIA3));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case IMP_MARCH: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer0_song);
      }
      break;
    case ZELDA_TRSR: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer1_song);
      }
      break;
    case ZELDA_PZZLE: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer2_song);
      }
      break;
    case ONE_UP: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer3_song);
      }
      break;
    case COIN: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer4_song);
      }
      break;
    case MUSHROOM: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer5_song);
      }
      break;
    case MARIO: //custom keycode
      if (record->event.pressed) {
        PLAY_SONG(layer6_song);
      }
      break;
  }
  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_VIA1] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),   ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_VIA2] =   { ENCODER_CCW_CW(CK_DOWN, CK_UP),               ENCODER_CCW_CW(MU_NEXT, MU_NEXT)  },
    [_VIA3] =   { ENCODER_CCW_CW(KC_NO, KC_NO),                 ENCODER_CCW_CW(KC_NO, KC_NO) }
    //                  Encoder 1                                     Encoder 2
};
#endif
