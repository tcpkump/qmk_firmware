#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _LOWER = 1,
  _GAME = 2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_EQL,           KC_1,       KC_2,       KC_3,             KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,             KC_9,      KC_0,    KC_MINS,
  KC_TAB,           KC_Q,       KC_W,       KC_F,             KC_P,    KC_B,                                       KC_J,    KC_L,    KC_U,             KC_Y,      KC_QUOT, KC_GRV,
  KC_BSLS,          KC_A,       KC_R,       KC_S,             KC_T,    KC_G,                                       KC_M,    KC_N,    KC_E,             KC_I,      KC_O,    KC_SCLN,
  KC_LSFT,          KC_Z,       KC_X,       KC_C,             KC_D,    KC_V,    KC_MUTE,           KC_MPLY,        KC_K,    KC_H,    KC_COMM,          KC_DOT,    KC_SLSH, KC_RSFT,
                                KC_LEFT,    KC_RGHT, KC_LCMD, LT(_LOWER,KC_BSPC), LCTL_T(KC_ESC),    LCTL_T(KC_ENT), KC_SPC,  KC_LALT, KC_DOWN,        KC_UP
),
[_LOWER] = LAYOUT(
  _______,          KC_F1,      KC_F2,      KC_F3,            KC_F4,   KC_F5,                                      KC_F6,   KC_F7,   KC_F8,            KC_F9,     KC_F10,  KC_DEL,
  KC_EQL,           KC_F11,     KC_F12,     _______,          _______, KC_LALT,                                    _______, KC_7,    KC_8,             KC_9,      _______, KC_MINS,
  KC_LBRC,          KC_LEFT,    KC_DOWN,    KC_UP,            KC_RGHT, KC_LGUI,                                    _______, KC_4,    KC_5,             KC_6,      KC_DOT,  KC_RBRC,
  _______,          KC_HOME,    KC_PGDN,    KC_PGUP,          KC_END,  _______, _______,           _______,        KC_0,    KC_1,    KC_2,             KC_3,      KC_SLSH, _______,
                                _______,    _______,          _______, _______, TG(_GAME),         _______,        _______, _______, _______,          _______
),
[_GAME] = LAYOUT(
  KC_ESC,           KC_1,       KC_2,       KC_3,             KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,             KC_9,      KC_0,    KC_BSPC,
  KC_TAB,           KC_Q,       KC_W,       KC_E,             KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,             KC_O,      KC_P,    KC_BSLS,
  KC_LCTL,          KC_A,       KC_S,       KC_D,             KC_F,    KC_G,                                       KC_H,    KC_J,    KC_K,             KC_L,      KC_SCLN, KC_ENT,
  KC_LSFT,          KC_Z,       KC_X,       KC_C,             KC_V,    KC_B,    KC_MUTE,           KC_MPLY,        KC_N,    KC_M,    KC_COMM,          KC_DOT,    KC_SLSH, KC_RSFT,
                                KC_X,       KC_LALT,          KC_SPC,  KC_M,    TG(_GAME),         _______,        KC_SPC,  _______, _______,          _______
),
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    return true;
}

#endif
