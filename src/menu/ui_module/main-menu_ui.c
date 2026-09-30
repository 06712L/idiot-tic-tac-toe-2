#include "ui/notcurses_values.h"
#include <notcurses/notcurses.h>
#include <stdint.h>
#include <unistd.h>

int32_t mainMenu(struct notcurses_values nc_values)
{
    //Some code is needed in the function...
}

int32_t intoMenu(void)
{
    struct notcurses_values nc_values;
    nc_values.options =
    {
        .flags = NCOPTION_SUPPRESS_BANNERS,
        .termtype = NULL,
        .loglevel = 0,
    };

    nc_values.nc = notcurses_init(&(nc_values.options), stdout);
    if(!nc_values.nc) return 1;
    nc_values.stdplane = notcurses_stdplane(nc_values.nc);
    return mainMenu(nc_values);
}
