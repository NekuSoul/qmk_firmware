#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_LAYER0] = LAYOUT_65_ansi( /* Base */
            KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,   KC_5,   KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,    KC_DEL,\
            KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLASH,  KC_PGUP,\
            TT(1),    KC_A,     KC_S,     KC_D,     KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,     KC_PGDN,\
            KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,   KC_UP,      KC_END,\
            KC_LCTL,  KC_LGUI,  KC_LALT,                    KC_SPC,                 TT(2),    TT(3),    TT(4),              KC_LEFT,   KC_DOWN,    KC_RIGHT),
        [_LAYER1] = LAYOUT_65_ansi( /* Function keys */
            KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,      KC_NO,\
            KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,              KC_NO,     KC_NO,      KC_NO,\
            KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_NO,                  KC_NO,    KC_NO,    KC_NO,              KC_NO,     KC_NO,      KC_NO),
        [_LAYER2] = LAYOUT_65_ansi( /* Keyboard control */
            RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    RGB_VAI,  RGB_HUI,  RGB_SAI,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,      KC_NO,\
            KC_NO,    RGB_VAD,  RGB_HUD,  RGB_SAD,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,              RGB_TOG,   RGB_SPI,    KC_NO,\
            KC_NO,    KC_NO,    KC_NO,                      KC_NO,                  KC_TRNS,  KC_NO,    KC_NO,              RGB_RMOD,  RGB_SPD,    RGB_MOD),
        [_LAYER3] = LAYOUT_65_ansi( /* Virtual Numpad */
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_P7,  KC_P8,    KC_P9,    KC_PSLS,  KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_P4,  KC_P5,    KC_P6,    KC_PAST,  KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_P1,  KC_P2,    KC_P3,    KC_PMNS,  KC_NO,               KC_NO,      KC_NO,\
            KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_P0,  KC_PDOT,  KC_PENT,  KC_PPLS,            KC_NO,     KC_NO,      KC_NO,\
            KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_NO,                  KC_NO,    KC_TRNS,  KC_NO,              KC_NO,     KC_NO,      KC_NO),
        [_LAYER4] = LAYOUT_65_ansi( /* Lockdown */
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,              KC_NO,     KC_NO,      KC_NO,\
            KC_NO,    KC_NO,    KC_NO,                      KC_NO,                  KC_NO,    KC_NO,    KC_TRNS,            KC_NO,     KC_NO,      KC_NO),
};

const uint16_t functionkeys[] = { 16, 15, 14, 13, 12, 11, 10, 9, 18, 19, 20, 21 };
const uint16_t controlkeys[] = { 17, 48, 47, 46, 40, 39, 38, 58, 59, 67, 34, 33 };
const uint16_t numkeys[] = { 61, 62, 63, 57, 51, 52, 53, 54, 0, 26, 27, 28, 10, 9, 18, 19 };

void rgb_matrix_indicators_user(void)
{
    switch (biton32(layer_state)) {
        case _LAYER1:
            for(uint8_t i = 0; i < 12; i++)
            {
                rgb_matrix_set_color(functionkeys[i], 0xFF, 0x00, 0x00);
            }
            break;
        case _LAYER2:
            for(uint8_t i = 0; i < 12; i++)
            {
                rgb_matrix_set_color(controlkeys[i], 0xFF, 0x00, 0x00);
            }
            break;
        case _LAYER3:
            for(uint8_t i = 0; i < 16; i++)
            {
                rgb_matrix_set_color(numkeys[i], 0xFF, 0x00, 0x00);
            }
            break;
        case _LAYER4:
            rgb_matrix_set_color(66, 0xFF, 0x00, 0x00);
            break;
    }
}
