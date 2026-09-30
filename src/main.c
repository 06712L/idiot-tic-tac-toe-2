#include <popt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/ittt_info.h"
#include "include/main.h"
#include "include/menu.h"

static int parse_arg(const int argc, const char *argv[])
{
    bool return_zero = false;
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
        {"version", 'v', 0, NULL, OPT_VERSION_VAL, "show version of i-TTT 2", NULL},
        POPT_AUTOHELP
        POPT_TABLEEND
    };

    poptContext opt_con = poptGetContext("i-ttt_2", argc, argv, options_table, POPT_CONTEXT_NO_EXEC);
    poptSetOtherOptionHelp(opt_con, "[OPTIONS]...");

    //start parse
    int rc;
    while((rc = poptGetNextOpt(opt_con)) >= 0)
    {
        if(!rc) return_zero = true;
        else
        {
            switch(rc)
            {
                case OPT_VERSION_VAL:
                    printf("Version: %s\nVersion code: %d\n", VERSION_NAME, VERSION_CODE);
                    break;
            }
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
    if(return_zero) return 0;
    else return CONTINUE_RUN;
}

static inline bool check_return_val(int32_t return_val)
{
    if(return_val == CONTINUE_RUN) return false;
    else return true;
}

int32_t main(const int argc, const char *argv[])
{
    int32_t return_val = parse_arg(argc, argv);
    if(check_return_val(return_val)) return return_val;

    return_val = into_menu();
    if(check_return_val(return_val)) return return_val;

    return return_val;
}
