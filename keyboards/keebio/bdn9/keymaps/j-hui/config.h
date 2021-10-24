#pragma once

#define TAPPING_TERM 150
/* #define IGNORE_MOD_TAP_INTERRUPT */
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2

#define ONESHOT_TAP_TOGGLE 4
#define ONESHOT_TIMEOUT 200

#if defined(COMBO_ENABLE)
#define COMBO_COUNT 1
#define COMBO_TERM 150
#endif
