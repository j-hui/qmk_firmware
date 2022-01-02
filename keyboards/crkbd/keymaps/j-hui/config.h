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

#pragma once

#define MASTER_LEFT

#define TAPPING_TERM 120
/* #define IGNORE_MOD_TAP_INTERRUPT */
/* #define TAPPING_FORCE_HOLD */
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2

#define ONESHOT_TAP_TOGGLE 4
#define ONESHOT_TIMEOUT 200

#if defined(LEADER_ENABLE)
#define LEADER_TIMEOUT 500
#endif

#if defined(COMBO_ENABLE)
#define COMBO_TERM 150
/* #define COMBO_COUNT 4 */
#endif

#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
