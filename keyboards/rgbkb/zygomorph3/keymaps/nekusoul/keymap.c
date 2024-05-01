#include QMK_KEYBOARD_H

#include "enums.c"
#include "structs.c"
#include "mode_off.h"
#include "mode_stats.h"
#include "mode_reboot.h"

// Keymaps

#define EXTRA    MO(_EXTRA)
#define MENU_ON  DF(_ADJUST)
#define MENU_OFF DF(_BASIC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASIC] = LAYOUT(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_SLSH ,
    KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
    KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_UP   , KC_ENT  ,
    KC_LCTL , KC_LGUI , KC_RALT , KC_DEL  , EXTRA   , KC_SPC  , KC_BSPC , KC_MINS , KC_EQL  , KC_LEFT , KC_DOWN , KC_RGHT ,

    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______
  ),
  [_EXTRA] = LAYOUT(
    MENU_ON , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_LT   , KC_GT   , KC_P7   , KC_P8   , KC_P9   , KC_NUM  , KC_SCRL ,
    KC_ESC  , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_LCBR , KC_RCBR , KC_P4   , KC_P5   , KC_P6   , KC_PSLS , KC_PAST ,
    KC_TAB  , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_LPRN , KC_RPRN , KC_P1   , KC_P2   , KC_P3   , KC_PMNS , KC_PPLS ,
    KC_RSFT , KC_SCRL , KC_PAUS , KC_INS  , KC_PSCR , KC_LBRC , KC_RBRC , KC_PEQL , KC_P0   , KC_PDOT , KC_PGUP , KC_PENT ,
    KC_RCTL , KC_LGUI , KC_LALT , KC_DEL  , KC_TRNS , KC_SPC  , KC_BSPC , KC_CAPS , KC_APP  , KC_HOME , KC_PGDN , KC_END  ,

    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______
  ),
  [_ADJUST] =  LAYOUT(
    QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , RGB_TOG , RGB_RMOD, RGB_MOD , RGB_TOG , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT ,
    XXXXXXX , XXXXXXX , MENU_U1 , XXXXXXX , AS_OFF  , RGB_HUD , RGB_HUI , AS_ON   , XXXXXXX , MENU_U2 , XXXXXXX , XXXXXXX ,
    XXXXXXX , MENU_L1 , MENU_B1 , MENU_R1 , AS_DOWN , RGB_SAD , RGB_SAI , AS_UP   , MENU_L2 , MENU_B2 , MENU_R2 , XXXXXXX ,
    XXXXXXX , XXXXXXX , MENU_D1 , XXXXXXX , XXXXXXX , RGB_VAD , RGB_VAI , XXXXXXX , XXXXXXX , MENU_D2 , XXXXXXX , XXXXXXX ,
    QK_RBT  , XXXXXXX , XXXXXXX , XXXXXXX , MENU_OFF, RGB_SPD , RGB_SPI , MENU_OFF, XXXXXXX , XXXXXXX , XXXXXXX , QK_RBT  ,

    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______
  )
};

// QMK events

const mode PROGMEM modes[] = {
    MODE_OFF,
    MODE_STATS,
    MODE_REBOOT
};

uint16_t current_mode = 0;

bool should_process_keypress(void) {
    return true;
}

static void mode_prev(void)
{
    if(current_mode == 0)
        current_mode = 2;
    else
        current_mode--;
}

static void mode_next(void)
{
    if(current_mode == 2)
        current_mode = 0;
    else
        current_mode++;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(keycode < SAFE_RANGE)
        return true;

    if (is_keyboard_left() && keycode <= MENU_R1)
    {
        switch (keycode)
        {
            case MENU_L1:
                if (!record->event.pressed)
                    mode_prev();
                return false;
            case MENU_R1:
                if (!record->event.pressed)
                    mode_next();
                return false;
            default:
                if(modes[current_mode].on_input != NULL)
                    modes[current_mode].on_input(keycode, record);
                return false;
        }
    }
    else if (!is_keyboard_left() && keycode <= MENU_R2)
    {
        switch (keycode)
        {
            case MENU_L2:
                if (!record->event.pressed)
                    mode_prev();
                return false;
            case MENU_R2:
                if (!record->event.pressed)
                    mode_next();
                return false;
            default:
                if(modes[current_mode].on_input != NULL)
                    modes[current_mode].on_input(keycode-5, record);
                return false;
        }
    }

    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_0;
    }
    else {
        return OLED_ROTATION_180;
    }
}

bool oled_task_user(void) {
    if(modes[current_mode].on_render != NULL)
        modes[current_mode].on_render();
    else
        oled_clear();

    return false;
}
