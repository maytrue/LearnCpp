//
//  main.c
//  DynamicRegisterModule
//
//  Created by guowei on 19/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#include <stdio.h>
#include "Module.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    my_module_register_all();
    ModuleInfo *info = NULL;
    do {
        info = my_module_next(info);
        if (info) {
            info->print();
        }
    } while(info);
    
    return 0;
}
