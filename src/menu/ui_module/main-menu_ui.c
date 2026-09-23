#include <notcurses/notcurses.h>
#include <stdint.h>
#include <unistd.h>

int32_t mainMenu(struct notcurses *nc, struct ncplane *stdplane)
{
    //Some code is needed in the function...
}

int32_t intoMenu(void)
{
    struct notcurses_options options =
    {
        .flags = NCOPTION_SUPPRESS_BANNERS,
        .termtype = NULL,
        .loglevel = 0,
    };

    struct notcurses *nc = notcurses_init(&options, stdout);
    if(!nc) return 1;
    struct ncplane *stdplane = notcurses_stdplane(nc);
    return mainMenu(nc, stdplane);
}
