//
//  Module.c
//  DynamicRegisterModule
//
//  Created by guowei on 19/10/2016.
//  Copyright © 2016 guowei. All rights reserved.
//

#include "Module.h"

ModuleInfo *first_module = NULL;
ModuleInfo **last_module = &first_module;

void my_module_register(ModuleInfo *info) {
  ModuleInfo **p = last_module;
  info->next = NULL;

  while (*p) {
    p = &((*p)->next);
  }

  *p = info;
  last_module = &(info->next);
}

ModuleInfo *my_module_next(const ModuleInfo *info) {
  if (info)
    return info->next;
  else
    return first_module;
}

#define REGISTER_MODULE(x)                     \
  {                                            \
    extern ModuleInfo my_module_##x##_info;    \
    my_module_register(&my_module_##x##_info); \
  }

void my_module_register_all() {
  REGISTER_MODULE(a);
  REGISTER_MODULE(b);
}

void register_module_c() { REGISTER_MODULE(c); }
