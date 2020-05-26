#include QMK_KEYBOARD_H
#include "raw_hid.h"

#define _LAYERDEF 0
#define _LAYERFNK 1
#define _LAYERKBC 2
#define _LAYERVNP 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYERDEF] = LAYOUT_65_ansi( /* Default */
        KC_GESC, KC_1,    KC_2,   KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,\
        KC_TAB,  KC_Q,    KC_W,   KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,\
        TT(1),   KC_A,    KC_S,   KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_HOME,\
        KC_LSFT, KC_Z,    KC_X,   KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_DEL,  KC_UP,   KC_END,\
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    KC_RALT, TT(2), TT(3),              KC_LEFT, KC_DOWN, KC_RGHT),
    [_LAYERFNK] = LAYOUT_65_ansi( /* Function keys */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, KC_PSCR,\
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,\
        _______, _______, _______,                   _______,                   XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______, _______),
    [_LAYERKBC] = LAYOUT_65_ansi( /* Keyboard control */
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
        XXXXXXX, RGB_VAI, RGB_HUI, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,\
        XXXXXXX, RGB_VAD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_TOG, RGB_SPI, XXXXXXX,\
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                   _______, XXXXXXX, XXXXXXX,          RGB_RMOD,RGB_SPD, RGB_MOD),
    [_LAYERVNP] = LAYOUT_65_ansi( /* Virtual Numpad */
        _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, _______, _______, _______,\
        _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,\
        XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,          _______, _______,\
        _______, KC_PDOT, KC_P0,   KC_PENT, KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______,\
        _______, _______, _______,                   XXXXXXX,                   XXXXXXX, XXXXXXX, _______,          _______, _______, _______)
};

const uint8_t functionkeys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14 };
const uint8_t controlkeys[] = { 0, 31, 32, 33, 45, 46, 47, 55, 56, 65, 66, 67 };
const uint8_t numkeys[] = { 1, 2, 3, 4, 16, 17, 18, 19, 31, 32, 33, 34, 45, 46, 47, 48};

uint8_t rgb_state_r[DRIVER_LED_TOTAL] = {0};
uint8_t rgb_state_g[DRIVER_LED_TOTAL] = {0};
uint8_t rgb_state_b[DRIVER_LED_TOTAL] = {0};

uint8_t r = 0;
uint8_t g = 0;
uint8_t b = 0;
uint8_t row = 0;
uint8_t col = 0;
uint8_t id = 0;
uint8_t id2 = 0;

void rgb_matrix_indicators_user(void)
{
    switch (biton32(layer_state)) {
        case _LAYERDEF: /* Default */
            id = 0;
            while(id < DRIVER_LED_TOTAL)
            {
                r = rgb_state_r[id];
                g = rgb_state_g[id];
                b = rgb_state_b[id];

                if(r != 0 || g != 0 || b != 0)
                {
                    rgb_matrix_set_color(id, r, g, b);
                }
                id++;
            }
            break;
        case _LAYERFNK: /* Function keys */
            rgb_matrix_set_color(30, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            for(uint8_t i = 0; i < 13; i++)
            {
                rgb_matrix_set_color(functionkeys[i], RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            }
            break;
        case _LAYERKBC: /* Keyboard control */
            rgb_matrix_set_color(62, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            for(uint8_t i = 0; i < 12; i++)
            {
                rgb_matrix_set_color(controlkeys[i], RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            }
            break;
        case _LAYERVNP: /* Virtual Numpad */
            rgb_matrix_set_color(64, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            for(uint8_t i = 0; i < 16; i++)
            {
                rgb_matrix_set_color(numkeys[i], RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x00, 0x00);
            }
            break;
    }
}

void raw_hid_receive(uint8_t *data, uint8_t length) 
{
    if(length < 4)
        return;

    if(data[0]>=MATRIX_ROWS)
        return;

    if(data[1]>=MATRIX_COLS)
        return;

    if(data[2]>RGB_MATRIX_MAXIMUM_BRIGHTNESS)
        return;

    if(data[3]>RGB_MATRIX_MAXIMUM_BRIGHTNESS)
        return;

    if(data[4]>RGB_MATRIX_MAXIMUM_BRIGHTNESS)
        return;

    id2 = g_led_config.matrix_co[data[0]][data[1]];

    if(id2 == NO_LED)
        return;
    
    rgb_state_r[id2] = data[2];
    rgb_state_g[id2] = data[3];
    rgb_state_b[id2] = data[4];
}
