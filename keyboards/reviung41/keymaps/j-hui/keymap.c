/* Copyright 2020 gtips
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

enum layer_names {
    _QWERTY = 0,
    _NAVFN,
    _NUMSYM
};

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
    TD_GUI_ALT,
    TD_NUM_NAV
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void gui_alt_finished(qk_tap_dance_state_t *state, void *user_data);
void gui_alt_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_reviung41(
    KC_EQL,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,
    KC_MINS,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_GRV,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RBRC,
                                            TD(TD_GUI_ALT),   KC_LCTL,    KC_SPC,   OSM(MOD_LSFT),    TD(TD_NUM_NAV)
  ),

  [_NUMSYM] = LAYOUT_reviung41(
    KC_PLUS,  KC_LCBR,  KC_1,     KC_2,     KC_3,     KC_RCBR,      KC_DEL,     KC_EXLM,  KC_AT,    KC_HASH,  KC_DEL,  KC_LCBR,
    KC_UNDS,  KC_LPRN,  KC_4,     KC_5,     KC_6,     KC_RPRN,      KC_BSPC,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_PIPE,  KC_DQUO,
    KC_TILD,  KC_0,     KC_7,     KC_8,     KC_9,     KC_TAB,       XXXXXXX,    KC_AMPR,  KC_ASTR,  KC_ENT,   KC_BSLS, KC_RCBR,
                                          _______, _______, _______, _______, _______
  ),

  [_NAVFN] = LAYOUT_reviung41(
    RGB_VAI,   RGB_M_P, KC_F1,  KC_F2,  KC_F3,  KC_F10,            RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  XXXXXXX,  RGB_MOD,
    RGB_VAD,   RGB_M_B, KC_F4,  KC_F5,  KC_F6,  KC_F11,            KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    RGB_TOG,   RGB_M_R, KC_F7,  KC_F8,  KC_F9,  KC_F12,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  XXXXXXX,  RGB_RMOD,
                                            _______,   _______,  _______,  _______,  _______
  ),
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

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t num_nav_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void num_nav_finished(qk_tap_dance_state_t *state, void *user_data) {
    num_nav_tap_state.state = cur_dance(state);
    switch (num_nav_tap_state.state) {
        case TD_SINGLE_TAP: layer_on(_NUMSYM); break;
        case TD_SINGLE_HOLD: layer_on(_NUMSYM); break;
        case TD_DOUBLE_TAP: layer_on(_NAVFN); break;
        case TD_DOUBLE_HOLD: layer_on(_NAVFN); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: layer_on(_NAVFN);
        case TD_UNKNOWN:
        case TD_NONE: break;
    }
}

void num_nav_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (num_nav_tap_state.state) {
        case TD_SINGLE_TAP: layer_off(_NUMSYM); break;
        case TD_SINGLE_HOLD: layer_off(_NUMSYM); break;
        case TD_DOUBLE_TAP: layer_off(_NAVFN); break;
        case TD_DOUBLE_HOLD: layer_off(_NAVFN); break;
        case TD_DOUBLE_SINGLE_TAP: layer_off(_NAVFN); break;
        case TD_UNKNOWN:
        case TD_NONE: layer_off(_NAVFN); layer_off(_NUMSYM); break;
    }
    num_nav_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_alt_finished, gui_alt_reset),
    [TD_NUM_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_nav_finished, num_nav_reset)
};
