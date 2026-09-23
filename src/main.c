#include <popt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/ittt-info.h"
#include "include/main.h"

static int parseArg(const int argc, const char *argv[])
{
    bool returnZero = false;
    enum
    {
        //ERROR code
        ERROR_OPT = 1000,
        ERROR_COMMANDS = 1001,

        //options return values
        DONT_RETURN = 0, //DONT_RETURN means don't return, just update arg
        OPT_VERSION_VAL,
    };
    struct poptOption optionsTable[] =
    {
        {"version", 'v', 0, NULL, OPT_VERSION_VAL, "show version of i-TTT 2", NULL},
        POPT_AUTOHELP
        POPT_TABLEEND
    };

    poptContext optCon = poptGetContext("i-ttt_2", argc, argv, optionsTable, POPT_CONTEXT_NO_EXEC);
    poptSetOtherOptionHelp(optCon, "[OPTIONS]...");

    //start parse
    int rc;
    while((rc = poptGetNextOpt(optCon)) >= 0)
    {
        if(!rc) returnZero = true;
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
        poptPrintUsage(optCon, stderr, 0);
        poptFreeContext(optCon);
        return ERROR_OPT;
    }

    //parse Commands
    char *command = (char*)poptGetArg(optCon);
    while(command != NULL)
    {
        //No Command now
        fprintf(stderr, "No Commands now\n");
        return ERROR_COMMANDS;
        //command = (char*)poptGetArg(optCon);
    }

    poptFreeContext(optCon);
    if(returnZero) return 0;
    else return CONTINUE_RUN;
}

static inline bool checkReturnVal(int32_t returnVal)
{
    if(returnVal == CONTINUE_RUN) return false;
    else return true;
}

int32_t main(const int argc, const char *argv[])
{
    int32_t returnVal = parseArg(argc, argv);
    if(checkReturnVal(returnVal)) return returnVal;
    //returnVal = a function is needed at this line...

    return returnVal;
}
