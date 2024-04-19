#include <stdio.h>

#include "Module.h"

static void my_module_c_print() { printf("my_module_c_print\n"); }

ModuleInfo my_module_c_info = {
    .name = "module_c",
    .print = my_module_c_print,
};
