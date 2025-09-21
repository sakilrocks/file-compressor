
// handles the cli 
// checks the args


#include <stdio.h>
#include <string.h>
#include "compressor.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <compress|decompress> <input> <output>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        return compress_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        return decompress_file(argv[2], argv[3]);
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }
}
