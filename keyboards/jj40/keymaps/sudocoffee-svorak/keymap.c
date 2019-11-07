#include QMK_KEYBOARD_H

#include "keymap_swedish.h"

#define _DVORAK 0
#define _LOWER  1
#define _RAISE  2
#define _FUNC   3

#define NAV_TAP LT(_NAV, KC_SPC)

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  CC_ARRW,
  CC_PRN,
  CC_BRC,
  CC_CBR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   `  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |Lower |Shift |Raise |    Space    | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,    NO_AA,   KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,   NO_APOS, \
  KC_LSFT,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,   KC_SLSH, \
  KC_ESC,    NO_OSLH, NO_AE,   KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,   KC_Z, \
  MO(_FUNC), KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,  MO(_LOWER),  MO(_RAISE),  KC_BSPC,   KC_ENT, KC_HOME, KC_END,   KC_LALT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ins  |      |      |  ()  |  []  |  {}  | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |RESET | Back | Fwd  |      |      |      |      |      | Mute | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Lock |      |             | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  NO_TILD, KC_EXLM, NO_AT,   KC_HASH, NO_DLR,  KC_PERC, NO_CIRC, NO_AMPR, NO_ASTR, NO_LPRN, NO_RPRN,  KC_UNDS, \
  _______, _______,   _______,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT, \
  KC_LSFT, _______,   _______,  _______, _______, _______, _______, KC_UNDS, KC_PLUS, NO_LCBR, NO_RCBR,  NO_BSLS, \
  _______, _______, _______, _______, _______, _______, _______,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Caps |   &  |   *  |   _  |   (  |   )  |   7  |   8  |   9  |   =  | Bksp | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   $  |   %  |   ^  |   [  |   ]  |   4  |   5  |   6  |   -  |   +  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  ->  |   !  |   @  |   #  |   {  |   }  |   1  |   2  |   3  |   .  |   \  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |      |Shift |      |      0      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  NO_PIPE,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NO_ACUT, \
  _______,S(KC_GRV),KC_GRV,  NO_LCBR,  NO_RCBR,  NO_GRTR,   NO_LESS,   KC_MINS, NO_EQL,  NO_LBRC, NO_RBRC, KC_ENT, \
  _______, _______, NO_ACUT, NO_QUOT, NO_AM, KC_GRV, _______,  CC_ARRW, _______, _______, _______, NO_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_FUNC] = LAYOUT_ortho_4x12( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F10,  KC_7,    KC_8,    KC_9,   KC_F11,  KC_F12,  \
    _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_4,    KC_5,    KC_6,   CC_PRN,  KC_VOLU, \
    _______, KC_CALC, RGB_HUD, RGB_SAD, RGB_VAD, KC_WBAK, _______, KC_1,    KC_2,    KC_3,   KC_PSCR, KC_VOLD, \
    _______, _______, RGB_MOD, _______, _______, _______, _______, _______, KC_0, _______, _______, _______ \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case CC_ARRW:
        SEND_STRING("->");
        return false;
      case CC_PRN:
        SEND_STRING("()"SS_TAP(X_LEFT));
        return false;
      case CC_BRC:
        SEND_STRING("[]"SS_TAP(X_LEFT));
        return false;
      case CC_CBR:
        SEND_STRING("{}"SS_TAP(X_LEFT));
        return false;
    }
  }
  return true;
}


// Loop
void matrix_scan_user(void) {
  // Empty
};
