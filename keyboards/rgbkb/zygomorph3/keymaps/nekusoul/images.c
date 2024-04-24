#include QMK_KEYBOARD_H

static void render_checked() {
    static const char PROGMEM raw_logo[] = {
        127, 99, 85, 73, 85, 99,127,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_unchecked() {
    static const char PROGMEM raw_logo[] = {
        127, 65, 65, 65, 65, 65,127,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
