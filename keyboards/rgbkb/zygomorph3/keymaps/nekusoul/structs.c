#pragma once

//typedef void (*on_enter)(void);

typedef struct mode
{
    void (*on_enter)(void);
    void (*on_exit)(void);
    void (*on_render)(void);
    void (*on_input)(uint16_t, keyrecord_t*);
} mode;
