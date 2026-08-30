#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "i-ttt-tui.h"

char* set_input_buf(size_t size)
{
    if(size == 0) size = 16;
    return calloc(size, 1);
}

bool get_a_key(char *buf, size_t buf_size, const char *key)
{
    if(buf_size == 0) return false;
    if(strlen(buf) != strlen(key)) return false;
    for(size_t i = 0; i < buf_size && buf[i] != '\0'; i++)
    {
        if(buf[i] != key[i]) return false;
    }

    for(size_t i = 0; i < buf_size && buf[i] != '\0'; i++)
    {
        buf[i] = '\0';
    }

    return true;
}

uint8_t set_cursor_location_from_al(mouse_lan *mouse, const ui_btn arr[], const uint16_t arr_location)
{
    if(arr[arr_location].arr_location != arr_location) return 1;
    mouse->x = arr[arr_location].x;
    mouse->y = arr[arr_location].y;
    return 0;
}

int32_t move(const ui_btn arr[], mouse_lan *mouse, const uint8_t dir)
{
    size_t next_location = 0;
    if(dir == right || dir == down) next_location = SIZE_MAX;
    uint16_t next_btn_al = 0;
    bool have_btn = false;

    size_t *mouse_apl = NULL;
    size_t *mouse_va = NULL;
    if(dir == up || dir == down)
    {
        mouse_apl = &mouse->y;
        mouse_va = &mouse->x;
    }
    else
    {
        mouse_apl = &mouse->x;
        mouse_va = &mouse->y;
    }

    for(int i = 0; arr[i].x != 0; i++)
    {
        size_t *va = NULL;
        size_t *apl = NULL;
        if(dir == up || dir == down)
        {
            va = &arr[i].x;
            apl = &arr[i].y;
        }
        else
        {
            va = &arr[i].y;
            apl = &arr[i].x;
        }

        if(*va == *mouse_va)
        {
            if(dir == down || dir == right)
            {
                if(*apl < *mouse_apl) continue;
                else if(*apl > next_location) continue;
            }
            else
            {
                if(*apl > *mouse_apl) continue;
                else if(*apl < next_location) continue;
            }
            next_location = *apl;
            next_btn_al = arr[i].arr_location;
            have_btn = true;
        }
    }

    if(have_btn)
    {
        *mouse_apl = next_location;
        mouse->arr_location = next_btn_al;
        return 0;
    }
    else return 1;
}
