#pragma once

enum custom_layer {
  _BASIC,
  _EXTRA,
  _ADJUST
};

enum custom_keycode {
  MENU_B1 = SAFE_RANGE,
  MENU_U1,
  MENU_D1,
  MENU_L1,
  MENU_R1,
  MENU_B2,
  MENU_U2,
  MENU_D2,
  MENU_L2,
  MENU_R2
};

enum oled_mode {
    MODE_OFF,
    MODE_STATS,
    MODE_REBOOT,
    MODE_CONFIG,
    MODE_MAX
};

enum setting {
    SETTING_AUTOSHIFT,
    SETTING_NKRO,
    SETTING_MAX
};
