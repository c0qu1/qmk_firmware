// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _VIA1,
  _VIA2,
  _VIA3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O, KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
        KC_LCTL, MO(_VIA1),        KC_SPC,           KC_SPC,           MO(_VIA2), KC_RALT
      ),

     [_VIA1] = LAYOUT(
       QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, KC_BACKSPACE,
       _______, _______, _______, _______, _______, _______, _______, _______, KC_ENTER,
       KC_LSFT, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
       _______, _______,          _______,          KC_LEFT,          KC_DOWN, KC_RIGHT
     ),

     [_VIA2] = LAYOUT(
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
       _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, MO(_VIA3),          _______,          _______,          _______, _______
     ),

     [_VIA3] = LAYOUT(
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______,          _______,          _______,          _______, _______
     )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u\n",
            keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    return true;
}
