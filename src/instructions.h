#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "process.h"

void hlt(vm_state*);
void add(vm_state*);
void sub(vm_state*);
void inc(vm_state*);
void dec(vm_state*);
void bez(vm_state*);
void bnz(vm_state*);
void inp(vm_state*);
void out(vm_state*);

#endif