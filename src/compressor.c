#include "compressor.h"
#include <stdio.h>

int compress_file(const char *input_filename, const char *output_filename) {
    FILE *input = fopen(input_filename, "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    int current_char = fgetc(input);
    if (current_char == EOF) {  // empty file
        fclose(input);
        fclose(output);
        return 0;
    }

    int count = 1;
    int next_char;

    while ((next_char = fgetc(input)) != EOF) {
        if (next_char == current_char && count < 255) {
            count++;
        } else {
            // write count and char
            fputc(count, output);
            fputc(current_char, output);
            current_char = next_char;
            count = 1;
        }
    }

    // write last sequence
    fputc(count, output);
    fputc(current_char, output);

    fclose(input);
    fclose(output);
    return 0;
}

int decompress_file(const char *input_filename, const char *output_filename) {
    FILE *input = fopen(input_filename, "rb");
    if (!input) {
        perror("Error opening compressed file");
        return 1;
    }

    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    int count;
    int value;

    while ((count = fgetc(input)) != EOF) {
        value = fgetc(input);
        if (value == EOF) break; // corrupted file

        for (int i = 0; i < count; i++) {
            fputc(value, output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
