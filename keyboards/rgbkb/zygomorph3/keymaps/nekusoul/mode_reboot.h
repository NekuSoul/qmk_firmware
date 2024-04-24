#include "mode_reboot.c"

#define MODE_REBOOT {NULL,NULL,reboot_render,reboot_input}

void reboot_render(void);
void reboot_input(uint16_t keycode, keyrecord_t *record);
