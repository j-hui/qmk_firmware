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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
                            KC_MUTE         ,   KC_MPLY         ,
        KC_TAB          ,   KC_1            ,   KC_2            ,   KC_3            ,
        KC_SPC          ,   KC_4            ,   KC_5            ,   KC_6            ,
        KC_0            ,   KC_7            ,   KC_8            ,   KC_9            ,
        LT(1, KC_ESC)   ,   KC_UP           ,   LT(2, KC_ENT)   ,   KC_BSPC         ,
        KC_LEFT         ,   KC_DOWN         ,   KC_RGHT         ,   KC_LSFT
    ),
    [1] = LAYOUT_all(
                 KC_MUTE,  KC_MPLY      ,
       _______          ,  _______      ,  _______          ,    _______,
       _______          ,  _______      ,  _______          ,    _______,
       _______          ,  _______      ,  _______          ,    _______,
       _______          ,  LSA(KC_UP)   ,  _______          ,    _______,
       LSA(KC_LEFT)     ,  LSA(KC_DOWN) ,  LSA(KC_RGHT)     ,    _______
    ),
    [2] = LAYOUT_all(
                 KC_MUTE,  KC_MPLY      ,
       _______          ,  _______      ,  _______          ,    _______,
       _______          ,  _______      ,  _______          ,    _______,
       _______          ,  _______      ,  _______          ,    _______,
       KC_LSFT          ,  LGUI(KC_A)   ,  _______          ,    _______,
       LGUI(KC_X)       ,  LGUI(KC_C)   ,  LGUI(KC_V)       ,    _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
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
