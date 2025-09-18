#ifndef SORT_H
#define SORT_H

#include "common.h"
#include "strcmp.h"

int qsort_text(LinePointers_t* ptrdata, int lines_count,
               int (*compare) (const void *, const void *));

int bubble_sort_text(LinePointers_t* ptrdata, int lines_count,
                     int (*compare) (const void *, const void *));

void swap_line_pointers(LinePointers_t* line_ptrs_1, LinePointers_t* line_ptrs_2);

#endif // SORT_H
