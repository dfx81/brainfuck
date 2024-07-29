#include <stdio.h>
#include <string.h>
#include "process.h"

void hlt(vm_state *state) {
    state->running = state->running;
    return;
}

void add(vm_state *state) {
    (state->mem[state->ptr])++;
}

void sub(vm_state *state) {
    (state->mem[state->ptr])--;
}

void inc(vm_state *state) {
    (state->ptr)++;
}

void dec(vm_state *state) {
    (state->ptr)--;
}

void bez(vm_state *state) {
    int skip = 0;
    int end = 0;

    if (state->mem[state->ptr] != 0) {
        state->stack[state->stack_ptr] = state->program_ptr;
        state->stack_ptr++;
        return;
    }

    while (end != 1) {
        (state->program_ptr)++;

        if (state->program_ptr >= strlen(state->program) -1) {
            state->running = 0;
            return;
        }

        switch (state->program[state->program_ptr]) {
            case '[':
                skip++;
                break;
            case ']':
                if (skip > 0) skip--;
                else end = 1;
        }
    }
}

void bnz(vm_state *state) {
    if (state->mem[state->ptr] == 0) {
        state->stack_ptr--;
    } else {
        if (state->stack_ptr > 0) {
            state->program_ptr = state->stack[state->stack_ptr - 1];
        }
    }
}

void inp(vm_state *state) {
    state->mem[state->ptr] = (uint8_t) getchar();
}

void out(vm_state *state) {
    printf("%c", state->mem[state->ptr]);
}