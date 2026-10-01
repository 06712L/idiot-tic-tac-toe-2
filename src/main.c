#include <popt.h>
#include <stdint.h>
#include <stdbool.h>
#include "include/main.h"
#include "include/menu.h"
#include "include/parse_arg.h"

static inline bool check_return_val(int32_t return_val)
{
    if(return_val == CONTINUE_RUN) return false;
    else return true;
}

int32_t main(const int argc, const char *argv[])
{
    int32_t return_val = parse_main_arg(argc, argv);
    if(check_return_val(return_val)) return return_val;

    return_val = into_menu();
    if(check_return_val(return_val)) return return_val;

    return return_val;
}
