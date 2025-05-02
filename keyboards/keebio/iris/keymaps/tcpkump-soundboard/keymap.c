#include QMK_KEYBOARD_H

#define _BASE 0

// enum custom_keycodes {
//   BASE = SAFE_RANGE,
//   LOWER,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_LCMD,          KC_LALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______,KC_ESC,LCTL_T(KC_BSPC),            KC_SPC,LGUI_T(KC_ENT),_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case BASE:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_BASE);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER);
//       }
//       return false;
//       break;
//   }
//   return true;
// }
