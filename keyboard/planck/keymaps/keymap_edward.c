// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0 /* Qwerty -- for software Dvorak */
#define _DV 1 /* Dvorak */
#define _SM 2 /* symbols */
#define _TK 3 /* tenkey */
#define _TS 4 /* tenkey symbols */
#define _FN 5 /* functions */
#define _PV 6 /* Plover */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Soft Dvorak */
  {KC_TAB,                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC},
  {MT(MOD_LCTL, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {MT(MOD_LSFT, KC_BSPC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_LSFT, KC_ENT)},
  {M(0),                  KC_LCTL, KC_LALT, KC_LGUI, MO(_TK), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_DOWN, KC_UP,   TG(_PV)}
},
[_DV] = { /* Hard Dvorak */
  {KC_TAB,                KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_RBRC},
  {MT(MOD_LCTL, KC_ESC),  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_SLSH},
  {MT(MOD_LSFT, KC_BPSC), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  MT(MOD_LSFT, KC_ENT)},
  {M(0),                  KC_LCTL, KC_LALT, KC_LGUI, MO(_TK), KC_SPC,  KC_SPC,  MO(_RS), KC_RGUI, KC_DOWN, KC_UP, TG(_PV)}
},
[_SM] = { /* symbols */
  {KC_TILD, KC_GRV,  KC_AT,   KC_PERC, KC_TRNS, KC_TRNS, KC_CIRC, KC_EQL,  KC_X,    KC_DLR,  KC_ASTR, KC_SLSH},
  {KC_TRNS, KC_AMPR, KC_LCBR, KC_LBRC, KC_LPRN, KC_EXLM, KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR, KC_PLUS, KC_PIPE},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_LTCL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[_TK] = { /* tenkey */
  {KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8, KC_9,   KC_ASTR, KC_SLSH},
  {MT(MOD_LCTL, KC_ESC),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5, KC_6,   KC_PLUS, KC_MINS},
  {MT(MOD_LSFT, KC_BSPC), DF(_QW), DF(_DV), MO(_FN), MO(_TS), KC_TRNS, KC_TRNS, KC_1,    KC_2, KC_3,   KC_ENT,  KC_ENT},
  {KC_TRNS,               KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,  KC_SPC,  KC_TRNS, KC_0, KC_DOT, KC_ENT,  KC_TRNS}
},
[_TS] = { /* tenkey symbols */
  {KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,  KC_X,  KC_DLR,  KC_LPRN, KC_RPRN},
  {MT(MOD_LCTL, KC_ESC),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D,    KC_E,  KC_F,    KC_PLUS, KC_MINS},
  {MT(MOD_LSFT, KC_BSPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_A,    KC_B,  KC_C,    KC_ENT,  KC_ENT},
  {KC_TRNS,               KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,  KC_SPC,  KC_TRNS, M(00), KC_COMM, KC_ENT,  KC_TRNS}
},
[_FN] = { /* function */
  {KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP,   KC_PGUP, KC_ASTR, KC_SLSH},
  {MT(MOD_LCTL, KC_ESC),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_P5,   KC_RGHT, KC_PLUS, KC_MINS},
  {MT(MOD_LSFT, KC_BSPC), DF(_QW), DF(_DV), MO(_FN), MO(_TS), KC_TRNS, KC_TRNS, KC_END,  KC_DOWN, KC_PGDN, KC_ENT,  KC_ENT},
  {KC_TRNS,               KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,  KC_SPC,  KC_TRNS, KC_0,    KC_DOT,  KC_ENT,  KC_TRNS}
},
[_PV] = { /* Plover */
  {KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_T,   KC_U, KC_I, KC_O, KC_P,    KC_RBRC},
  {KC_ESC,  KC_Q, KC_S, KC_D, KC_F, KC_T,   KC_T,   KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
  {KC_BSPC, KC_Z, KC_Z, KC_1, KC_1, KC_Z,   KC_Z,   KC_1, KC_1, KC_Z, KC_Z,    KC_ENT},
  {M(0),    KC_Z, KC_Z, KC_c, KC_V, KC_SPC, KC_SPC, KC_N, KC_M, KC_Z, KC_Z,    KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
