/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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

#define _DVORAK 0
#define _LOWER  1
#define _RAISE  2
#define _FUNC   3

#define ____ KC_TRNS
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( /* Base */
    KC_ESC, NO_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_UNDS, NO_LCBR, NO_RCBR, NO_BSLS, \
        KC_TAB, KC_TAB, NO_AA, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, NO_SLSH, NO_APOS, KC_BSPC, \
        MO(_RAISE), KC_LSFT, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S,NO_MINS, KC_ENT, \
        KC_LALT, KC_LCTL, KC_LCTL, NO_OSLH, NO_AE, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LGUI, \
                            MO(_LOWER),                KC_SPC
  ),
  [_LOWER] = LAYOUT(
    NO_TILD, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, NO_MINS, ____, ____, ____, ____, ____, ____, ____, ____, \
      ____, ____, ____, ____, NO_PLUS, NO_EQL, ____, ____, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
                            ____,                ____
  ),
  [_RAISE] = LAYOUT(
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
                            ____,                ____
  ),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
