#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"
#include "sort.h"
#include "output.h"
#include "config.h"

int process_all(const char* output_path, LinePointers_t* ptrdata,
                char* buffer, int lines_count);

int process_text(FILE* output_stream, LinePointers_t* ptrdata, char* buffer,
                 int lines_count, const char* method);

#endif // PROCESS_H
