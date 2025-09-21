
// declare the func compress_file and decompress_file
// interface between main.c (cli) and the compressor.c (compression logic)


#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <stddef.h>

// compress input file into output file

int compress_file(const char *input_filename, const char *output_filename);

// decompress input file into output file

int decompress_file(const char *input_filename, const char *output_filename);

#endif
