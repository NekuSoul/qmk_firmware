#include QMK_KEYBOARD_H

#include "structs.c"

static void stats_render(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(is_keyboard_left() ? PSTR("L") : PSTR("R"), false);
    oled_write_P(is_keyboard_master() ? PSTR("M ") : PSTR("S "), false);
    oled_write_ln_P(get_autoshift_state() ? PSTR("AS ") : PSTR("   "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
