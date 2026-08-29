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


int right(ui_btn arr[], mouse_lan *mouse)
{
    size_t min_location = SIZE_MAX;
    uint16_t next_btn_al = 0;
    bool have_btn = false;
    for(int i = 0; arr[i].x != 0; i++)
    {
        if(arr[i].y == mouse->y && arr[i].x > mouse->x && arr[i].x < min_location)
        {
            min_location = arr[i].x;
            next_btn_al = arr[i].arr_location;
            have_btn = true;
        }
    }

    if(have_btn)
    {
        mouse->x = min_location;
        mouse->arr_location = next_btn_al;
        return 0;
    }
    else return 1;
}

int left(ui_btn arr[], mouse_lan *mouse)
{
    size_t max_location = 0;
    uint16_t next_btn_al = 0;
    bool have_btn = false;
    for(int i = 0; arr[i].x != 0; i++)
    {
        if(arr[i].y == mouse->y && arr[i].x < mouse->x && arr[i].x > max_location)
        {
            max_location = arr[i].x;
            next_btn_al = arr[i].arr_location;
            have_btn = true;
        }
    }

    if(have_btn)
    {
        mouse->x = max_location;
        mouse->arr_location = next_btn_al;
        return 0;
    }
    else return 1;
}

int up(ui_btn arr[], mouse_lan *mouse)
{
    size_t max_location = 0;
    uint16_t next_btn_al = 0;
    bool have_btn = false;
    for(int i = 0; arr[i].x != 0; i++)
    {
        if(arr[i].x == mouse->x && arr[i].y < mouse->y && arr[i].y > max_location)
        {
            max_location = arr[i].y;
            next_btn_al = arr[i].arr_location;
            have_btn = true;
        }
    }

    if(have_btn)
    {
        mouse->y = max_location;
        mouse->arr_location = next_btn_al;
        return 0;
    }
    else return 1;
}

int down(ui_btn arr[], mouse_lan *mouse)
{
    size_t min_location = SIZE_MAX;
    uint16_t next_btn_al = 0;
    bool have_btn = false;
    for(int i = 0; arr[i].x != 0; i++)
    {
        if(arr[i].x == mouse->x && arr[i].y > mouse->y && arr[i].y < min_location)
        {
            min_location = arr[i].y;
            next_btn_al = arr[i].arr_location;
            have_btn = true;
        }
    }

    if(have_btn)
    {
        mouse->y = min_location;
        mouse->arr_location = next_btn_al;
        return 0;
    }
    else return 1;
}
