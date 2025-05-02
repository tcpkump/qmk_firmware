#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _LOWER = 1,
  _UPPER = 2,
  _ADJUST = 3
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

#define LT_BSPC LT(_LOWER, KC_BSPC)
#define LT_ENT  LT(_UPPER, KC_ENT)

#define HOME_Z LGUI_T(KC_Z)
#define HOME_X LALT_T(KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_EQL,           KC_1,       KC_2,       KC_3,             KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,             KC_9,      KC_0,    KC_MINS,
  KC_TAB,           KC_Q,       KC_W,       KC_F,             KC_P,    KC_B,                                             KC_J,    KC_L,    KC_U,             KC_Y,      KC_QUOT, KC_GRV,
  KC_BSLS,          KC_A,       KC_R,       KC_S,             KC_T,    KC_G,                                             KC_M,    KC_N,    KC_E,             KC_I,      KC_O,    KC_SCLN,
  KC_LSFT,          HOME_Z,     HOME_X,     KC_C,             KC_D,    KC_V,    KC_MUTE,                 KC_MPLY,        KC_K,    KC_H,    KC_COMM,          KC_DOT,    KC_SLSH, KC_RSFT,
                                KC_LEFT,    KC_RGHT,LGUI_T(KC_TAB),    LT_BSPC,LCTL_T(KC_ESC),           LT_ENT, KC_SPC,  KC_LALT, KC_DOWN,          KC_UP
),
[_LOWER] = LAYOUT(
  _______,          _______,    _______,    _______,        _______,   _______,                                          KC_F6,   KC_F7,   KC_F8,            KC_F9,     KC_F10,  KC_DEL,
  QK_BOOT,          _______,    _______,    _______,        _______,   _______,                                          KC_PLUS, KC_7,    KC_8,             KC_9,      KC_DOT,  KC_MINS,
  _______,          _______,    _______,    _______,        _______,   _______,                                          KC_EQL,  KC_4,    KC_5,             KC_6,      KC_0,    KC_RBRC,
  _______,          _______,    _______,    _______,        _______,   _______, _______,                 _______,        KC_MINS, KC_1,    KC_2,             KC_3,      _______, _______,
                                _______,    _______,        _______,   _______, _______,                 MO(_ADJUST),    _______, _______, KC_PGDN,          KC_PGUP
),
[_UPPER] = LAYOUT(
  _______,          KC_F1,      KC_F2,      KC_F3,            KC_F4,   KC_F5,                                            _______, _______, _______,          _______,   _______, _______,
  QK_BOOT,          KC_EXLM,    KC_AT,      KC_LBRC,          KC_RBRC, KC_PIPE,                                          _______, _______, _______,          _______,   _______, _______,
  _______,          KC_HASH,    KC_DLR,     KC_LPRN,          KC_RPRN, KC_GRV,                                           _______, _______, _______,          _______,   _______, _______,
  _______,          KC_PERC,    KC_CIRC,    KC_LCBR,          KC_RCBR, KC_TILD,     _______,                 _______,    _______, _______, _______,          _______,   _______, _______,
                                KC_HOME,    KC_END,           _______, MO(_ADJUST), _______,                 _______,    _______, _______, _______,          _______
),
[_ADJUST] = LAYOUT(
  _______,          KC_F11,     KC_F12,     _______,          _______, _______,                                          _______, _______, _______,          _______,   _______, _______,
  QK_BOOT,          KC_AMPR,    KC_UNDS,    KC_BSLS,          KC_SCLN, _______,                                          _______, _______, _______,          _______,   _______, _______,
  _______,          KC_LEFT,    KC_DOWN,    KC_UP,            KC_RGHT, _______,                                          _______, _______, _______,          _______,   _______, _______,
  _______,          KC_HOME,    KC_PGDN,    KC_PGUP,          KC_END,  _______,     _______,                 _______,    _______, _______, _______,          _______,   _______, _______,
                                KC_HOME,    KC_END,           _______, MO(_ADJUST), _______,                 _______,    _______, _______, _______,          _______
)
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
