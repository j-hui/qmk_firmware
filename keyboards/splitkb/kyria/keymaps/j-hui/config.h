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

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#if defined(LEADER_ENABLE)
#define LEADER_TIMEOUT 500
#endif

#if defined(COMBO_ENABLE)
#define COMBO_TERM 150
// #define COMBO_COUNT 3
#endif

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_DEFAULT_HUE 127
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
  // #define RGBLIGHT_ANIMATIONS
  // #define RGBLIGHT_HUE_STEP 8
  // #define RGBLIGHT_SAT_STEP 8
  // #define RGBLIGHT_VAL_STEP 8
  // #define RGBLIGHT_LIMIT_VAL 150
#endif
