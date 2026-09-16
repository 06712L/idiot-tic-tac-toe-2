#include <popt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    bool ver_opt = false;
    struct poptOption options[] =
    {
        {"version", 'v', POPT_ARG_NONE, &ver_opt, 0, "show version of i-TTT 2", NULL},
        POPT_AUTOHELP
        POPT_TABLEEND
    };
}
