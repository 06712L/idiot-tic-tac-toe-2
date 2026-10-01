#include <popt.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "ittt_info.h"
#include "main.h"

static inline int32_t show_ittt_version(void)
{
    printf("Version: %s\nVersion code: %d\n", VERSION_NAME, VERSION_CODE);
    return 0;
}

int32_t parse_main_arg(const int argc, const char *argv[])
{
    int32_t return_val = CONTINUE_RUN;
    enum
    {
        //ERROR code
        ERROR_OPT = 1000,
        ERROR_COMMANDS = 1001,

        //options return values
        DONT_RETURN = 0, //DONT_RETURN means don't return, just update arg
        OPT_VERSION_VAL,
    };
    struct poptOption options_table[] =
    {
        {"version", 'v', 0, NULL, OPT_VERSION_VAL, "show version of i-ttt 2", NULL},
        POPT_AUTOHELP
        POPT_TABLEEND
    };

    poptContext opt_con = poptGetContext("i-ttt_2", argc, argv, options_table, POPT_CONTEXT_NO_EXEC);
    poptSetOtherOptionHelp(opt_con, "[OPTIONS]...");

    //start parse
    int rc;
    while((rc = poptGetNextOpt(opt_con) >= 0))
    {
        switch(rc)
        {
            case OPT_VERSION_VAL:
                return_val = show_ittt_version();
                break;
        }
    }
    if(rc < -1)
    {
        poptPrintUsage(opt_con, stderr, 0);
        poptFreeContext(opt_con);
        return ERROR_OPT;
    }

    //parse Commands
    char *command = (char*)poptGetArg(opt_con);
    while(command != NULL)
    {
        //No Command now
        fprintf(stderr, "No Commands now\n");
        return ERROR_COMMANDS;
        //command = (char*)poptGetArg(optCon);
    }

    poptFreeContext(opt_con);
    return return_val;
}
