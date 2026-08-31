#ifndef I_TTT_TUI_H
#define I_TTT_TUI_H

#include <stddef.h>

typedef struct UI_BUTTON
{
    const unsigned short arr_location;
    const size_t x;
    const size_t y;
    const char *name;
}ui_btn;

typedef struct MOUSE_LOCATION
{
    unsigned short arr_location;
    size_t x;
    size_t y;
}mouse_lan;

enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

#endif
