/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include "rev1.h"
#include "split_util.h"

#ifdef RGB_MATRIX_ENABLE
// clang-format off
led_config_t g_led_config = { {
    {   0,   1,   2,   3,   4,   5},
    {  15,  13,  11,  10,   8,   6},
    {  16,  18,  20,  21,  23,  25},
    {  35,  33,  31,  30,  28,  26},
    {  36,  38,  40,  41,  43,  45},

    {  46,  47,  48,  49,  50,  51},
    {  61,  59,  57,  56,  54,  52},
    {  62,  64,  66,  67,  69,  71},
    {  81,  79,  77,  76,  74,  72},
    {  82,  84,  86,  87,  89,  91},
}, { 
    // Left Half
    {   0,   0 }, {  19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,  0  },
    {  95,  19 }, {  86,  10 }, {  76,  19 }, {  67,  10 }, {  57,  19 }, {  38,  19 }, {  29,  10 }, {  19,  19 }, {  10,  10 }, {   0,  19 },
    {   0,  38 }, {  10,  29 }, {  19,  38 }, {  29,  29 }, {  38,  38 }, {  57,  38 }, {  67,  29 }, {  76,  38 }, {  86,  29 }, {  95,  38 },
    {  95,  57 }, {  86,  48 }, {  76,  57 }, {  67,  48 }, {  57,  57 }, {  38,  57 }, {  29,  48 }, {  19,  57 }, {  10,  48 }, {   0,  38 },
    {   0,  76 }, {  10,  67 }, {  19,  76 }, {  29,  67 }, {  38,  76 }, {  57,  76 }, {  67,  67 }, {  76,  76 }, {  86,  67 }, {  95,  76 },
    // Right Half
    { 114,   0 }, { 133,   0 }, { 152,   0 }, { 171,   0 }, { 190,   0 }, { 209,  0  },
    { 209,  19 }, { 200,  10 }, { 190,  19 }, { 181,  10 }, { 171,  19 }, { 152,  19 }, { 143,  10 }, { 133,  19 }, { 124,  10 }, { 114,  19 },
    { 114,  38 }, { 124,  29 }, { 133,  38 }, { 143,  29 }, { 152,  38 }, { 171,  38 }, { 181,  29 }, { 190,  38 }, { 200,  29 }, { 209,  38 },
    { 209,  57 }, { 200,  48 }, { 190,  57 }, { 181,  48 }, { 171,  57 }, { 152,  57 }, { 143,  48 }, { 133,  57 }, { 124,  48 }, { 114,  38 },
    { 114,  76 }, { 124,  67 }, { 133,  76 }, { 143,  67 }, { 152,  76 }, { 171,  76 }, { 181,  67 }, { 190,  76 }, { 200,  67 }, { 209,  76 }
    
}, {
    1, 4, 4, 4, 4, 4,
    4, 2, 4, 2, 4, 4, 2, 4, 2, 1,
    1, 2, 4, 2, 4, 4, 2, 4, 2, 4,
    4, 2, 4, 2, 4, 4, 2, 4, 2, 1,
    1, 2, 1, 2, 1, 1, 2, 1, 2, 1,

    4, 4, 4, 4, 4, 1,
    1, 2, 4, 2, 4, 4, 2, 4, 2, 4,
    4, 2, 4, 2, 4, 4, 2, 4, 2, 1,
    1, 2, 4, 2, 4, 4, 2, 4, 2, 4,
    1, 2, 1, 2, 1, 1, 2, 1, 2, 1

} };
// clang-format on

void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif


__attribute__((weak)) 
void render_layer_status(void) {
    // Keymap specific, expected to be overridden
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    oled_write_ln_P(PSTR("Undef"), false);
}

__attribute__((weak))
void render_leds_status(void)
{
    // Host Keyboard LED Status
    static const char PROGMEM led_icon[] = {
        0x0F,0x3A,0
    };
    oled_write_P(led_icon, false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(   led_state.num_lock ? PSTR("N") : PSTR(" "), false);
    oled_write_P(  led_state.caps_lock ? PSTR("C") : PSTR(" "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("S") : PSTR(" "), false);
}


oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    // Sol 3 uses OLED_ROTATION_270 for default rotation on both halves
    return oled_init_user(OLED_ROTATION_270);
}

bool oled_task_kb(void) {
    if (!oled_task_user())
        return false;
    
    if (is_keyboard_left()) {
        render_icon();
        oled_write_P(PSTR("     "), false);
        render_layer_status();
        oled_write_P(PSTR("     "), false);
        render_leds_status();
    }
    else {
        render_icon();
        oled_write_P(PSTR("     "), false);
        render_rgb_menu();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record))
        return false;

    switch(keycode) {
#ifdef RGB_MATRIX_ENABLE
        case RM_TOGG:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
#endif
    }
    return true;
};
