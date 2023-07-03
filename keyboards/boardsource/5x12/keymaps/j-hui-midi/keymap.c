#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x12(
  MI_AOFF, MI_OCN2, MI_OCN1, MI_OC0,  MI_OC1,  MI_OC2,  MI_OC3,  MI_OC4,  MI_OC5,  MI_OC6,  MI_OC7,  MI_VL10,
  MI_TRSU, MI_As1,  MI_C2,   MI_Cs2,  MI_Ds2,  MI_F2,   MI_Fs2,  MI_Gs2,  MI_As2,  MI_C3,   MI_Cs3,  MI_VL8,
  MI_TR0,  MI_A1,   MI_B1,   MI_C2,   MI_D2,   MI_E2,   MI_F2,   MI_G2,   MI_A2,   MI_B2,   MI_C3,   MI_VL6,
  MI_TRSD, MI_Ab1,  MI_Bb1,  MI_B1,   MI_Db2,  MI_Eb2,  MI_E2,   MI_Gb2,  MI_Ab2,  MI_Bb2,  MI_B2,   MI_VL4,
  KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TAB,  KC_SPC,  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
};
