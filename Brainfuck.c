// Brainfuck.c
// ---
// Author  : dfx
// Version : 1
// ---
// Brainfuck interpreter written in C.
// Use by passing .bf file as arg.
// Pass -d flag as third arg to enable debug mode.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void error(int err);
void load();
void run();
void add();
void sub();
void inc();
void dec();
void get();
void out();
void bez(int *i);
void bnz(int *i);

// Implementation based on Wikipedia.
// Memory size is 30000 * 1 byte.
const int MEM_LENGTH = 30000;

// Memory is implemented as unsigned 8 bit integer.
// No signed values + overflow/underflow.
// All cells assigned with inital value of 0.
// A *char was declared to store instructions from file.
// The memory pointer was also implemented as *ptr.
// len will be used to store the length of instructions.
FILE *fp;
uint8_t mem[MEM_LENGTH] = {0};
uint8_t *ptr = mem;
char *cur = NULL;
long len;
bool debug = false;

// Error Codes.
enum ErrorCode {
    ERR_NO_INPUT_FILE = -1,
    ERR_FILE_NOT_FOUND = -2,
    ERR_PTR_OUT_OF_RANGE = -3
};

// Check whether the user provided the filename or not.
// Also check whether the user want to enable debug mode.
// Then, call load() to start reading instruction from file.
// Finally, execute the instructions.l by calling run().
int main(int argc, char *argv[]) {
    if (argc < 2) {
        error(ERR_NO_INPUT_FILE);
    } else {
        fp = fopen(argv[1], "rb");

        if (fp == NULL) {
            error(ERR_FILE_NOT_FOUND);
        }

        if (argc == 3 && strcmp(argv[2], "-d") == 0) {
            debug = true;
        }

        load();
    }

    run();

    return 0;
}

// Use this whenever error occurs
void error(int err) {
    printf("Exited with error code %d\n", err);
    exit(err);
}

// Used to read instructions from file.
// Instructions will be stored as a char array pointed by *char.
// First check the length of file and store it as a long.
// Then malloc the required size to store the instructions and
// point to it by *char earlier.
// Return the file pointer back to start and begin storing the
// instructions into the char array.
void load() {
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    cur = malloc(len * sizeof(char));

    for (int i = 0; i != len; i++) {
        cur[i] = fgetc(fp);
    }

    fclose(fp);
}

// Execute instructions one-by-one until it reached the end
// of instruction.
// Get a single byte of instruction and call the appropriate
// function.
// Finally, if debug is on, print the final val of the memory.
void run() {
    for (int i = 0; i != len; i++) {
        switch (cur[i]) {
            case '+': add(); break;
            case '-': sub(); break;
            case '>': inc(); break;
            case '<': dec(); break;
            case ',': get(); break;
            case '.': out(); break;
            case '[': bez(&i); break;
            case ']': bnz(&i); break;
            default : break;
        }
    }

    if (debug) {
        printf("\n---\n");

        for (int i = 0; i != MEM_LENGTH; i++) {
            if (i % 256 == 0 && i != 0) {
                printf("\n");
            }
            printf("%-2X ", mem[i]);
        }

        printf("\n");
    }

    free(cur); // IMPORTANT: FREE THE MEMORY
}

// add responds to '+'.
// Add 1 to current cell pointed by mem ptr (can overflow).
void add() {
    ++*ptr;
}

// sub responds to '-'.
// Deduct 1 from current cell pointed by mem ptr (can underflow).
void sub() {
    --*ptr;
}

// inc responds to '>'.
// Move the mem ptr to the right (can overflow).
void inc() {
    if (ptr + 1 > &mem[MEM_LENGTH - 1]) {
        ptr = mem;
    } else {
        ptr++;
    }
}

// dec responds to '<'.
// Move the mem ptr to the left (can underflow).
void dec() {
    if (ptr - 1 < mem) {
        ptr = &mem[MEM_LENGTH - 1];
    } else {
        ptr--;
    }
}

// get responds to ','.
// Accept 1 byte of input from user.
// Value stored in current cell pointed by mem ptr.
void get() {
    *ptr = getchar();
}

// out responds to '.'.
// Output 1 byte of data from current cell pointed by mem ptr
// as ASCII.
void out() {
    putchar(*ptr);
}

// bez (Branch if Equal Zero) responds to '['.
// If current cell value is 0, proceed to the matching ']'.
void bez(int *i) {
    if (*ptr == 0) {
        int open = 1;
        int loc = *i;

        while (open) {
            if (++loc >= len) {
                error(ERR_PTR_OUT_OF_RANGE);
            }

            if (cur[loc] == '[') {
                open++;
            } else if (cur[loc] == ']') {
                open--;
            }
        }

        *i = loc;
    }
}

// bnz (Branch if Not Zero) responds to ']'.
// When current cell value is not zero, returns to the matching
// '['.
void bnz(int *i) {
    if (*ptr != 0) {
        int open = 1;
        int loc = *i;

        while (open) {
            if (--loc < 0) {
                error(ERR_PTR_OUT_OF_RANGE);
            }

            if (cur[loc] == '[') {
                open--;
            } else if (cur[loc] == ']') {
                open++;
            }
        }

        *i = loc;
    }
}
