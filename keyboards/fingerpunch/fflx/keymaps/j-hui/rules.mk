CONVERT_TO = stemcell

# RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = yes

# OLED_ENABLE = yes

LEADER_ENABLE = no
COMBO_ENABLE = yes

# BOOTLOADER = atmel-dfu

CIRQUE_ENABLE = yes
ENCODER_ENABLE = yes
MOUSEKEY_ENABLE = yes

FP_EVQ_UNDERPALMS = yes

### BEGIN Copied from fflx config.mk ###
ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := cirque_pinnacle_i2c
   OPT_DEFS += -DCIRQUE_ENABLE
endif

ifeq ($(strip $(FP_EC11_UNDER_PALMS)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DFP_EC11_UNDER_PALMS
endif

ifeq ($(strip $(FP_EVQ_UNDER_PALMS)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DFP_EVQ_UNDER_PALMS
endif
### END Copied from fflx config.mk ###

# Cut down on size: https://docs.qmk.fm/#/squeezing_avr?id=rgb-settings
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
# MOUSEKEY_ENABLE = no
# EXTRAKEY_ENABLE = no
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no
# MAGIC_ENABLE = no
