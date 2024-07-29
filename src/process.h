#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

typedef struct {
    uint8_t mem[64 * 1024];
    uint16_t ptr;
    uint16_t stack[64 * 1024];
    uint16_t stack_ptr;
    char *program;
    uint64_t program_ptr;
    uint8_t running;
} vm_state;

typedef void (*opcode)(vm_state*);

vm_state *init_state(char *prog);
opcode *init_instr();
void execute(char*);

#endif