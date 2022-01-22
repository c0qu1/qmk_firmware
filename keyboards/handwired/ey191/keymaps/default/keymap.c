// Copyright 2022 Juan Rivera (@c0qu1)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                                                          KC_F16,                    KC_F17,  KC_F18,
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,           KC_BSPC, KC_HOME,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             MO(_VIA1), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
      ),

     [_VIA1] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       _______,                   _______,  _______,
       RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           _______,  KC_END,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,   _______,
       _______, _______,          _______,                   _______,                            _______, _______, _______, KC_MPRV, KC_MPLY,   KC_MNXT
     ),

     [_VIA2] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       _______,                   _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
       _______, _______,          _______,                   _______,                            _______, _______, _______, _______, _______, _______
     ),

     [_VIA3] = LAYOUT_ansi65x(
       _______, _______, _______, _______, _______,                                                       _______,                   _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
       _______, _______,          _______,                   _______,                            _______, _______, _______, _______, _______, _______
     )
};

// RGB config, for changing RGB settings on non-VIA firmwares
void change_RGB(bool clockwise) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    bool alt = get_mods() & MOD_MASK_ALT;
    bool ctrl = get_mods() & MOD_MASK_CTRL;

    if (clockwise) {
        if (alt) {
            rgblight_increase_hue();
        } else if (ctrl) {
            rgblight_increase_val();
        } else if (shift) {
            rgblight_increase_sat();
        } else {
            rgblight_step();
        }

  } else {
      if (alt) {
            rgblight_decrease_hue();
        } else if (ctrl) {
            rgblight_decrease_val();
        } else if (shift) {
            rgblight_decrease_sat();
        } else {
            rgblight_step_reverse();
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        //change RGB settings
        change_RGB(clockwise);
    }
    return false;
}
