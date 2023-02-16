#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _FN,
};

// Next space
#define SC_SNXT S(A(KC_RGHT))

// Previous space
#define SC_SPRV S(A(KC_LEFT))

// Mission control
#define SC_MCTL S(A(KC_UP))

// Show desktop
#define SC_DKTP S(A(KC_DOWN))

// Spotlight
#define SC_SRCH G(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  KC_ESC,  _______, MO(_FN), KC_LALT, KC_LGUI, KC_SPC,  MO(_FN), KC_LSFT, KC_MINS, KC_EQL,  KC_BSLS, KC_ENT
  ),

  [_FN] = LAYOUT_ortho_5x12(
  KC_BRIU, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  KC_BRID, KC_WH_L, SC_MCTL, KC_WH_R, XXXXXXX, QK_BOOT, KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, XXXXXXX, KC_MPRV,
  _______, SC_SPRV, SC_DKTP, SC_SNXT, SC_SRCH, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_MPLY,
  _______, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_MNXT,
  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

#if 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
    MT(MOD_LALT, KC_EQL),   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,
    KC_MINS,                KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    MT(MOD_LSFT, KC_GRV),   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RBRC,
                                            KC_LGUI,  KC_LCTL,    KC_SPC,   MO(_NAVFN), KC_LSFT,  MO(_NUMSYM)
  ),

  [_NUMSYM] = LAYOUT_split_3x6_3(
    MT(MOD_LALT, KC_PLUS),  KC_LCBR,  KC_1,     KC_2,     KC_3,     KC_RCBR,      KC_DEL,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DEL,  KC_LCBR,
    KC_UNDS,                KC_LPRN,  KC_4,     KC_5,     KC_6,     KC_RPRN,      KC_BSPC,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_PIPE,  KC_DQUO,
    MT(MOD_LSFT, KC_TILD),  KC_0,     KC_7,     KC_8,     KC_9,     KC_TAB,       XXXXXXX,    KC_AMPR,  KC_ASTR,  KC_ENT,   KC_BSLS, KC_RCBR,
                                          _______, _______, _______, _______, _______, _______
  ),

  [_NAVFN] = LAYOUT_split_3x6_3(
    RGB_VAI,   RGB_M_P, KC_F1,  KC_F2,  KC_F3,  KC_F10,            RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  XXXXXXX,  RGB_MOD,
    RGB_VAD,   RGB_M_B, KC_F4,  KC_F5,  KC_F6,  KC_F11,            KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  XXXXXXX,  RGB_TOG,
    XXXXXXX,   RGB_M_R, KC_F7,  KC_F8,  KC_F9,  KC_F12,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  XXXXXXX,  RGB_RMOD,
                                            _______,   _______,  _______,  _______,  _______, _______
  ),
};
#endif
