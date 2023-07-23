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


/*
  NOTE: flash with

        qmk flash -kb keebio/bdn9/rev2 -km j-hui
*/
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE         , KC_SPC        , KC_MPLY           ,
        LT(1, KC_ESC)   , KC_UP         , LT(2, KC_ENT)     ,
        KC_LEFT         , KC_DOWN       , KC_RGHT
    ),
    [1] = LAYOUT(
        _______         , _______       , _______           ,
        XXXXXXX         , LSA(KC_UP)    , LCAG(KC_SPC)      ,
        LSA(KC_LEFT)    , LSA(KC_DOWN)  , LSA(KC_RGHT)
    ),
    [2] = LAYOUT(
        _______         , _______       , _______           ,
        KC_LSFT         , LGUI(KC_A)    , XXXXXXX           ,
        LGUI(KC_X)      , LGUI(KC_C)    , LGUI(KC_V)
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }

    } else {
        return true;
    }
    return false;
}
