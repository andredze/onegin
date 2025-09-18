#ifndef OUTPUT_H
#define OUTPUT_H

#include "common.h"

int print_text(LinePointers_t* ptrdata, int lines_count, const char* output_path);

int open_output(FILE** output_stream, const char* output_path);

int write_text(LinePointers_t* ptrdata, int lines_count, FILE* output_stream);

#endif // OUTPUT_H
