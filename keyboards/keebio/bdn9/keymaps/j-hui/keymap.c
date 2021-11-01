/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        RESET           , RGB_MOD       , _______           ,
        LT(1, KC_TAB)   , KC_UP         , KC_LCTL           ,
        KC_LEFT         , KC_DOWN       , KC_RGHT
    ),
    [1] = LAYOUT(
        _______         , _______       , _______           ,
        _______         , KC_PGUP       , LSFT_T(KC_ESC)    ,
        KC_HOME         , KC_PGDN       , KC_END
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            for (int i = 0; i < 16; i++) {
                tap_code(KC_DOWN);
            }
        } else {
            for (int i = 0; i < 16; i++) {
                tap_code(KC_UP);
            }
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_WH_L);
        } else {
            tap_code(KC_WH_R);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return true;
}

#if defined(COMBO_ENABLE)
enum combos {
    ENT_COMBO
};

const uint16_t PROGMEM ENT_combo[] = {KC_UP,     KC_DOWN,    COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ENT_COMBO] = COMBO(ENT_combo, KC_ENT)
};
#endif
