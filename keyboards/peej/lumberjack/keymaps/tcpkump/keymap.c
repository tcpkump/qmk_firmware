/* Copyright 2020 Paul James
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

enum layers {
  _BASE = 0,
  _LOWER = 1,
  _RAISE = 2,
  _GAME = 3,
};

#define FN MO(_FUNCTION)
#define LT_Z LT(_LOWER, KC_Z)
#define LT_SLSH LT(_RAISE, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_5x12(
        KC_EQL,  KC_1,      KC_2,    KC_3,    KC_4,       KC_5,                       KC_6,       KC_7,       KC_8,    KC_9,       KC_0,       KC_MINS,
        KC_TAB,  KC_Q,      KC_W,    KC_F,    KC_P,       KC_B,                       KC_J,       KC_L,       KC_U,    KC_Y,       KC_QUOT,    KC_GRV,
        KC_BSLS, KC_A,      KC_R,    KC_S,    KC_T,       KC_G,                       KC_M,       KC_N,       KC_E,    KC_I,       KC_O,       KC_SCLN,
        KC_LSFT, LT_Z,      KC_X,    KC_C,    KC_D,       KC_V,                       KC_K,       KC_H,       KC_COMM, KC_DOT,     LT_SLSH,    KC_RSFT,
        XXXXXXX, TG(_GAME), _______, MO(_RAISE), LGUI_T(KC_ESC), LCTL_T(KC_BSPC),     KC_SPC, LCTL_T(KC_ENT), KC_LALT, MO(_LOWER), MO(_RAISE), XXXXXXX
    ),

    [_LOWER] = LAYOUT_ortho_5x12(
        KC_F12,  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______,   _______, _______, _______, _______,        _______, KC_AMPR, KC_ASTR, KC_TILD, KC_GRV,  _______,
        _______, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, _______,        _______, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, _______,
        _______, KC_HOME, KC_PGDN,   KC_PGUP, KC_END,  _______,        _______, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, _______,
        _______, _______,   _______, _______, _______, _______,        _______, _______, _______, XXXXXXX, _______, QK_BOOT
    ),

    [_RAISE] = LAYOUT_ortho_5x12(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,        _______, KC_4,    KC_5,    KC_6,    KC_DOT,  _______,
        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,        _______, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
        _______, _______, _______, XXXXXXX, _______, _______,        _______, KC_0, _______, _______,    XXXXXXX, QK_BOOT
    ),

    [_GAME] = LAYOUT_ortho_5x12(
        KC_ESC,   KC_1,      KC_2,    KC_3,    KC_4,    KC_5,           KC_6,   KC_7,       KC_8,    KC_9,       KC_0,       KC_BSPC,
        KC_TAB,   KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,   KC_U,       KC_I,    KC_O,       KC_P,       KC_DEL,
        KC_LCTL,  KC_A,      KC_S,    KC_D,    KC_F,    KC_G,           KC_H,   KC_J,       KC_K,    KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,  KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,           KC_N,   KC_M,       KC_COMM, KC_DOT,     KC_SLSH,    KC_LSFT,
        TG(_GAME),_______,   KC_M,    KC_LALT, KC_SPC,  KC_GRV,         KC_SPC, MO(_LOWER), KC_LCMD, MO(_LOWER), MO(_RAISE), _______
    )

};
