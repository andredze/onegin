#ifndef OUTPUT_H
#define OUTPUT_H

#include "common.h"

int print_text(LinePointers_t* ptrdata, int lines_count);

int open_output(FILE** output);

int write_text(LinePointers_t* ptrdata, int lines_count, FILE* output);

#endif // OUTPUT_H
