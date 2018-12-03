
#include "iris.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _EMPTY 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET

#define KC_AA NO_AA
#define KC_AE NO_AE
#define KC_OE NO_OSLH
#define KC_LESS NO_LESS
#define KC_QQQ NO_QUES
#define KC_DOLLA NO_DLR

// Helpful defines
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DOLLA,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB , SLSH,COMM,DOT,  P,   Y  ,                F  , G  , C , R  , L  , QQQ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      LSFT, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S,  BSLS,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      LSFT,QQQ, Q  , J  , K  ,X, LGUI ,       RASE, B  , M  , W,   V,   Z,  SLSH,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        RCTL,LOWR,SPC ,         BSPC ,RASE,LALT
    //                  `----+----+----'        `----+----+----'
  ),
  [_LOWER] = LAYOUT(
      //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
        NO_TILD,KC_EXLM,NO_AT ,KC_HASH,NO_DLR ,KC_PERC,                     NO_CIRC,NO_AMPR,NO_ASTR,NO_SLSH,NO_LPRN,NO_RPRN,
      //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
        RALT(KC_TAB),NO_OSLH,NO_AE, NO_AA, KC_GRV,LSFT(KC_GRV),                  NO_LCBR,KC_TRNS,KC_UP,NO_PIPE,NO_LCBR,NO_ACUT,
      //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
        KC_LSFT,LCTL(KC_A),LCTL(KC_S),KC_TRNS,LCTL(KC_F),NO_BSLS,            KC_TRNS, KC_LEFT,KC_DOWN,KC_RGHT,NO_LBRC,NO_RBRC,
      //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------%%¢#”^^&*&^%$
        KC_LSFT,LCTL(KC_Z),LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_LGUI,  NO_ASTR,NO_ASTR,LSFT(NO_LBRC),LSFT(NO_RBRC),KC_TRNS,NO_LESS,NO_GRTR,
      //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                      KC_TRNS,KC_TRNS,KC_TRNS,         KC_ENT,LSFT(NO_LBRC),LSFT(NO_RBRC)
      //                              `-------+-------+-------'        `-------+-------+-------'
    ),
    [_RAISE] = LAYOUT(
      //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
        KC_F12 ,RALT(LSFT(NO_ASTR))  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                     KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
      //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
        NO_GRV ,KC_7   ,KC_8   ,KC_9   ,NO_MINS,NO_ASTR,                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,NO_PIPE,
      //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
        KC_TRNS,KC_4   ,KC_5   ,KC_6   ,NO_PLUS,NO_SLSH,                     KC_HOME,RALT(NO_ASTR),KC_PGUP,KC_END ,KC_TRNS,NO_BSLS,
      //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
        KC_TRNS,KC_1   ,KC_2   ,KC_3   ,KC_0   ,NO_EQL ,KC_TRNS,     KC_TRNS,NO_ASTR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                      KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS
      //                              `-------+-------+-------'        `-------+-------+-------'
    )
};
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
  }
  return true;
}
