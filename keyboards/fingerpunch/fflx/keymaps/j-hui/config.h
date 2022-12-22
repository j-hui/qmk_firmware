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

#define ENCODERS_A_REVERSE
#define ENCODERS_B_REVERSE

/* #ifdef RGBLIGHT_ENABLE */
/*     #undef RGBLED_NUM */
/*     #define RGBLIGHT_ANIMATIONS */
/*     #define RGBLED_NUM 27 */
/*     #define RGBLIGHT_LIMIT_VAL 120 */
/*     #define RGBLIGHT_HUE_STEP 10 */
/*     #define RGBLIGHT_SAT_STEP 17 */
/*     #define RGBLIGHT_VAL_STEP 17 */
/* #endif */
