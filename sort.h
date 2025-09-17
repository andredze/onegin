#ifndef SORT_H
#define SORT_H

#include "common.h"
#include "strcmp.h"

int bubble_sort_text(LinePointers_t* ptrdata, int lines_count);

void swap_line_pointers(LinePointers_t* line_ptrs_1, LinePointers_t* line_ptrs_2);

#endif // SORT_H
