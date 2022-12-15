#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _NAVFN,
    _NUMSYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_fflx(
    MT(MOD_LALT, KC_EQL),   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,
    KC_MINS,                KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    MT(MOD_LSFT, KC_GRV),   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RBRC,
                             KC_BTN1, KC_LGUI,  KC_LCTL,    KC_SPC,   MO(_NAVFN), KC_LSFT,  MO(_NUMSYM), KC_BTN2

),

[_NUMSYM] = LAYOUT_fflx(
    MT(MOD_LALT, KC_PLUS),  KC_LCBR,  KC_1,     KC_2,     KC_3,     KC_RCBR,      KC_DEL,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DEL,  KC_LCBR,
    KC_UNDS,                KC_LPRN,  KC_4,     KC_5,     KC_6,     KC_RPRN,      KC_BSPC,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_PIPE,  KC_DQUO,
    MT(MOD_LSFT, KC_TILD),  KC_0,     KC_7,     KC_8,     KC_9,     KC_TAB,       XXXXXXX,    KC_AMPR,  KC_ASTR,  KC_ENT,   KC_BSLS, KC_RCBR,
                                _______, _______, _______, _______, _______, _______, _______, _______
),

[_NAVFN] = LAYOUT_fflx(
    RGB_VAI,   RGB_M_P, KC_F1,  KC_F2,  KC_F3,  KC_F10,            RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  XXXXXXX,  RGB_MOD,
    RGB_VAD,   RGB_M_B, KC_F4,  KC_F5,  KC_F6,  KC_F11,            KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  XXXXXXX,  RGB_TOG,
    XXXXXXX,   RGB_M_R, KC_F7,  KC_F8,  KC_F9,  KC_F12,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  XXXXXXX,  RGB_RMOD,
                                _______, _______, _______, _______, _______, _______, _______, _______
)
};

#if defined(COMBO_ENABLE)
enum combos {
      TAB_COMBO
    , ENT_COMBO
    , ESC_COMBO
    , ALT_COMBO
    , COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM TAB_combo[] = {KC_C,     KC_V,       COMBO_END};
const uint16_t PROGMEM ENT_combo[] = {KC_M,     KC_COMM,    COMBO_END};
const uint16_t PROGMEM ESC_combo[] = {KC_X,     KC_V,       COMBO_END};
const uint16_t PROGMEM ALT_combo[] = {KC_LGUI,  KC_LCTL,    COMBO_END};

combo_t key_combos[] = {
    [TAB_COMBO] = COMBO(TAB_combo, KC_TAB)
  , [ENT_COMBO] = COMBO(ENT_combo, KC_ENT)
  , [ESC_COMBO] = COMBO(ESC_combo, KC_ESC)
  , [ALT_COMBO] = COMBO(ALT_combo, KC_LALT)
};
#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        tap_code16(C(KC_RGHT));
      }
      else{
        tap_code16(C(KC_LEFT));
      }
    }
    else if (index == 2) {
      #ifdef ENCODERS_C_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        press_super_tab(true);
      } else {
        press_super_tab(false);
      }
    }

    return true;
}
#endif
