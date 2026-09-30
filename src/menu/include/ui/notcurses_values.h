#ifndef NOTCURSES_VALUES_H
#define NOTCURSES_VALUES_H

#include <notcurses/notcurses.h>

typedef struct notcurses_values
{
    struct notcurses_options options;
    struct notcurses *nc;
    struct ncplane *stdplane;
}notcurses_values;

#endif
