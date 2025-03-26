// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    LOWER,
    UPPER,
    ADJUST,
    FUNC
};

enum combos {
  FP_CLN,
  WF_SCN
};

const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[] = {
  [FP_CLN] = COMBO(fp_combo, KC_COLN),
  [WF_SCN] = COMBO(wf_combo, KC_SCLN),
};

#define LT_BSPC LT(LOWER, KC_BSPC)
#define LT_ENT  LT(UPPER, KC_ENT)
#define LT_PGDN LT(FUNC,  KC_PGDN)

// Left-hand home row mods
#define HOME_Z LGUI_T(KC_Z)
#define HOME_X LALT_T(KC_X)
#define HOME_C LSFT_T(KC_C)
#define HOME_D LCTL_T(KC_D)

// Right-hand home row mods
#define HOME_H    RCTL_T(KC_H)
#define HOME_COMM RSFT_T(KC_COMM)
#define HOME_DOT  LALT_T(KC_DOT)
#define HOME_SLSH RGUI_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,   KC_F,    KC_P,    KC_B,                                         KC_J, KC_L,    KC_U,    KC_Y,   KC_QUOT, KC_GRV,
        KC_CAPS, KC_A,    KC_R,   KC_S,    KC_T,    KC_G,                                         KC_M, KC_N,    KC_E,    KC_I,   KC_O,    KC_SCLN,
        KC_LSFT, HOME_Z,  HOME_X, KC_C,    KC_D,    KC_V,                                         KC_K, KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,                                                     KC_DEL, KC_BSLS, KC_LBRC,  KC_RBRC,
                                                          KC_END,  KC_ESC,     LT_BSPC, KC_HOME,
                                         CTL_T(KC_TAB), KC_LGUI, KC_LALT,     KC_RCTL, KC_PGUP, KC_SPC,
                                                                   LT_ENT,     LT_PGDN
    ),
    [LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______,                                      KC_PLUS, KC_7,    KC_8,    KC_9,    KC_DOT,  _______,
        _______, _______, _______, _______, _______, _______,                                      KC_EQL,  KC_4,    KC_5,    KC_6,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,                                      KC_MINS, KC_1,    KC_2,    KC_3,    KC_ASTR, _______,
                 _______, _______, _______, _______,                                                        _______, _______, _______, _______,
                                                          _______, KC_ESC,      LT_BSPC, _______,
                                                 _______, _______, _______,     _______, _______,  MO(ADJUST),
                                                                   LT_ENT,      _______
    ),
    [UPPER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
        QK_BOOT, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PIPE,                                      _______, _______, _______, _______, _______, _______,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                       _______, _______, _______, _______, _______, _______,
        _______, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_TILD,                                      _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                                                         _______, _______, _______, _______,
                                                          _______, KC_ESC,      MO(ADJUST), _______,
                                                 KC_DEL,  _______, _______,     _______, _______,  KC_SPC,
                                                                   LT_ENT,      _______
    ),
    [ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
        QK_BOOT, KC_AMPR, KC_UNDS, KC_BSLS, KC_SCLN, _______,                                       _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,                                       _______, _______, _______, _______, _______, _______,
        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,                                       _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                                                         _______, _______, _______, _______,
                                                          _______, KC_ESC,      LT_BSPC, _______,
                                                 _______, _______, _______,     _______, _______,  KC_SPC,
                                                                   LT_ENT,      _______
    ),
    [FUNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_F11,  KC_F12,  _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                                                         _______, _______, _______, _______,
                                                          _______, KC_ESC,      LT_BSPC, _______,
                                                 _______, _______, _______,     _______, _______,  KC_SPC,
                                                                   LT_ENT,      _______
    )
};
