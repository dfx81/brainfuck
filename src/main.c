#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "process.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("USAGE: bf [filename.bf]");
        return 0;
    }

    FILE *file = fopen(argv[1], "rb");

    fseek(file, 0, SEEK_END); 
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size > 64 * 1024) {
        size = 64 * 1024 - 1;
    }

    char *buffer = malloc(sizeof(uint8_t) * 64 * 1024);
    uint16_t read = fread(buffer, sizeof(uint8_t), size, file);

    buffer[read] = '\0';

    execute(buffer);
    free(buffer);
}