#include QMK_KEYBOARD_H

#include "enums.c"
#include "structs.c"

static bool reboot_to_flash = false;

static void reboot_render(void) {
    oled_clear();
    oled_write_P(reboot_to_flash ? PSTR(" ") : PSTR(">"), false);
    oled_write_ln_P(PSTR("REBOOT KEYBOARD"), false);
    oled_write_P(reboot_to_flash ? PSTR(">") : PSTR(" "), false);
    oled_write_ln_P(PSTR("FLASH FIRMWARE"), false);
}

static void reboot_reset(void)
{
    oled_clear();
    oled_write_ln_P(PSTR("REBOOT..."), false);
    soft_reset_keyboard();
}

static void reboot_flash(void)
{
    oled_clear();
    oled_write_ln_P(PSTR("FLASH..."), false);
    reset_keyboard();
}

static void reboot_input(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)
        return;

    if (keycode == MENU_B1)
    {
        if(reboot_to_flash)
            reboot_flash();
        else
            reboot_reset();
    }

    if (keycode == MENU_U1 || keycode == MENU_D1)
        reboot_to_flash = !reboot_to_flash;
}
