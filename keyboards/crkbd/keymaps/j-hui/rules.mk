# RGBLIGHT_ENABLE = yes   # underglow lights
# BACKLIGHT_ENABLE = yes  # per-key lights
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

OLED_ENABLE = no

LEADER_ENABLE = no
COMBO_ENABLE = yes

BOOTLOADER = atmel-dfu

# Cut down on size: https://docs.qmk.fm/#/squeezing_avr?id=rgb-settings
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
# MAGIC_ENABLE = no
