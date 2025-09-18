#ifndef PTRDATA_H
#define PTRDATA_H

#include "common.h"

LinePointers_t* make_ptrdata(char* buffer, int* main_lines_count);

int count_lines(char* buffer, int* ptr_lines_count);

int allocate_ptrdata(LinePointers_t** ptrdata, int lines_count);

int fill_ptrdata(char* buffer, LinePointers_t* ptrdata, int lines_count);

#endif // PTRDATA_H
