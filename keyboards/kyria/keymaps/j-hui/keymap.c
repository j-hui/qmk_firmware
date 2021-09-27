/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TD_GUI_ALT
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void gui_alt_finished(qk_tap_dance_state_t *state, void *user_data);
void gui_alt_reset(qk_tap_dance_state_t *state, void *user_data);

enum layers {
    _QWERTY = 0,
    _NAVFN,
    _NUMSYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  = +   |  Q   |  W   |  E   |  R   |  T   |                              |  Y   |  U   |  I   |  O   |  P   |  [ {   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  - _   |  A   |  S   |  D   |  F   |  G   |                              |  H   |  J   |  K   |  L   | ; :  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  ` ~   |  Z   |  X   |  C   |  V   |  B   | Left | Right|  | Down |  Up  |  N   |  M   | , <  | . >  | / ?  |  ] }   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mse1 |      | Space|      |      |  |      |      | Bspc |      |      |
 *                        |      | Super|      | Ctrl | Alt  |  | Nav  |LShift|      | Sym  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_EQL,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                           KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,     KC_LBRC,
      KC_MINS,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                           KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
      KC_GRV,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LEFT,  KC_RIGHT,   KC_DOWN,  KC_UP,  KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_RBRC,
      KC_BTN1, TD(TD_GUI_ALT), KC_LCTL, KC_SPC, KC_LALT,           OSL(_NUMSYM), OSL(_NAVFN), OSM(MOD_LSFT), OSL(_NUMSYM), TO(_QWERTY)
    ),
/*
 * SYMNUM
 *
 * _NUM                                                                                                                _SYM
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  {   |  1   |  2   |  3   |  }   |                              |      |  !   |  @   |  #   | Del  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  (   |  4   |  5   |  6   |  )   |                              |      |  $   |  %   |  ^   |  |   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  0   |  7   |  8   |  9   | Tab  |      |      |  |      |      |      |  &   |  *   | Ent  |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |  0   |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMSYM] = LAYOUT(
      KC_PLUS,  KC_LCBR,  KC_1,     KC_2,       KC_3,       KC_RCBR,                                          KC_DEL, KC_EXLM,  KC_AT,    KC_HASH,  KC_DEL,  KC_LCBR,
      KC_UNDS,  KC_LPRN,  KC_4,     KC_5,       KC_6,       KC_RPRN,                                          KC_BSPC, KC_DLR,   KC_PERC,  KC_CIRC,  KC_PIPE,  KC_DQUO,
      KC_TILD,  KC_0,     KC_7,     KC_8,       KC_9,       KC_TAB,  KC_HOME,  KC_END,  KC_PGDN,  KC_PGUP,   _______, KC_AMPR,  KC_ASTR,  KC_ENT,   KC_BSLS, KC_RCBR,
                       _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______
    ),
/*
 * Nav function layer: arrow and function keys
 */
    [_NAVFN] = LAYOUT(
      _______,  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F10,                                           _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  KC_F4,  KC_F5,  KC_F6,  KC_F11,                                           KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,
      _______,  _______,  KC_F7,  KC_F8,  KC_F9,  KC_F12,   _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  _______,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#if defined(COMBO_ENABLE)
enum combos {
      TAB_COMBO
    , ENT_COMBO
    , ESC_COMBO
    /* , EQL_COMBO */
    /* , MIN_COMBO */
    /* , ACC_COMBO */
    /* , LBR_COMBO */
    /* , QUT_COMBO */
    /* , RBR_COMBO */
};

const uint16_t PROGMEM TAB_combo[] = {KC_C,     KC_V,       COMBO_END};
const uint16_t PROGMEM ENT_combo[] = {KC_M,     KC_COMM,    COMBO_END};
const uint16_t PROGMEM ESC_combo[] = {KC_X,     KC_V,       COMBO_END};
/* const uint16_t PROGMEM EQL_combo[] = {KC_Q,     KC_W,       COMBO_END}; */
/* const uint16_t PROGMEM MIN_combo[] = {KC_A,     KC_S,       COMBO_END}; */
/* const uint16_t PROGMEM ACC_combo[] = {KC_Z,     KC_X,       COMBO_END}; */
/* const uint16_t PROGMEM LBR_combo[] = {KC_O,     KC_P,       COMBO_END}; */
/* const uint16_t PROGMEM QUT_combo[] = {KC_L,     KC_SCLN,    COMBO_END}; */
/* const uint16_t PROGMEM RBR_combo[] = {KC_DOT,   KC_SLSH,    COMBO_END}; */

combo_t key_combos[COMBO_COUNT] = {
    [TAB_COMBO] = COMBO(TAB_combo, KC_TAB)
  , [ENT_COMBO] = COMBO(ENT_combo, KC_ENT)
  , [ESC_COMBO] = COMBO(ESC_combo, KC_ESC)
  /* , [EQL_COMBO] = COMBO(EQL_combo, KC_EQL) */
  /* , [MIN_COMBO] = COMBO(MIN_combo, KC_MINS) */
  /* , [ACC_COMBO] = COMBO(ACC_combo, KC_GRV) */
  /* , [LBR_COMBO] = COMBO(LBR_combo, KC_LBRC) */
  /* , [QUT_COMBO] = COMBO(QUT_combo, KC_QUOT) */
  /* , [RBR_COMBO] = COMBO(RBR_combo, KC_RBRC) */
};
#endif

#if defined(LEADER_ENABLE)
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

    SEQ_ONE_KEY(KC_K) {
      tap_code(KC_ESC);
    } else
    SEQ_ONE_KEY(KC_N) {
      layer_move(_NUMSYM);
    } else
    SEQ_ONE_KEY(KC_M) {
      layer_move(_NAVFN);
    } else
    SEQ_ONE_KEY(KC_LEAD) {
      layer_clear();
    } else
    SEQ_ONE_KEY(KC_B) {
      reset_keyboard();
    }
    leader_end();
  }
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0 xD\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("default\n"), false);
            break;
        case _NUMSYM:
            oled_write_P(PSTR("num/sym\n"), false);
            break;
        case _NAVFN:
            oled_write_P(PSTR("nav/function\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (layer_state_is(_NUMSYM)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
    else if (index == 1) {
        if (layer_state_is(_NUMSYM)) {
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}
#endif

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t gui_alt_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void gui_alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    gui_alt_tap_state.state = cur_dance(state);
    switch (gui_alt_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_LALT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LGUI); register_code(KC_LALT);
        case TD_UNKNOWN:
        case TD_NONE: break;
    }
}

void gui_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (gui_alt_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: unregister_code(KC_LALT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LALT); break;
        case TD_UNKNOWN:
        case TD_NONE: unregister_code(KC_LALT); unregister_code(KC_LGUI); break;
    }
    gui_alt_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_alt_finished, gui_alt_reset)
};

