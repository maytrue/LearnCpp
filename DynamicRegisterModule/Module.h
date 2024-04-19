//
//  Module.h
//  DynamicRegisterModule
//
//  Created by guowei on 19/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#ifndef Module_h
#define Module_h

#include <stdio.h>

typedef struct ModuleInfo {
  char name[1024];
  void (*print)();
  struct ModuleInfo *next;
} ModuleInfo;

void my_module_register(ModuleInfo *info);

ModuleInfo *my_module_next(const ModuleInfo *info);

void my_module_register_all();

void register_module_c();

#endif /* Module_h */
