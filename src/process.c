#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "instructions.h"

void execute(char *program) {
    vm_state *state = init_state(program);
    opcode *instr = init_instr();

    while (state->running) {
        if (state->program_ptr >= strlen(state->program)) {
            state->running = 0;
            break;
        }

        instr[(uint8_t) state->program[state->program_ptr]](state);
        state->program_ptr++;
    }

    free(instr);
    free(state);
}

vm_state *init_state(char *prog) {
    vm_state *out = malloc(sizeof(vm_state));
    *out = (vm_state){{0}, 0, {0}, 0, prog, 0, 1};

    return out;
}

opcode *init_instr() {
    opcode *instr = malloc(sizeof(opcode) * 256);

    for (int i = 0; i < 256; i++) {
        switch((char) i) {
            case '+':
                instr[i] = add;
                break;
            case '-':
                instr[i] = sub;
                break;
            case '>':
                instr[i] = inc;
                break;
            case '<':
                instr[i] = dec;
                break;
            case '[':
                instr[i] = bez;
                break;
            case ']':
                instr[i] = bnz;
                break;
            case ',':
                instr[i] = inp;
                break;
            case '.':
                instr[i] = out;
                break;
            default:
                instr[i] = hlt;
        }
    }

    return instr;
}