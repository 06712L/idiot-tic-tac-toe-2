#ifndef TUI_H
#define TUI_H

#if defined(__linux__) || defined(__MACH__)
#include <ncurses.h>
#elif defined(_WIN32)
#include <pdcurses.h>
#else
#error "tui.h: UNKNOWN OS DEFINE"
#endif

#endif
