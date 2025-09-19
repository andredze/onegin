#ifndef STRCMP_H
#define STRCMP_H

#include "common.h"

int strcmp_by_start(const void* line_ptrs_1,
                    const void* line_ptrs_2);

int strcmp_by_end(const void* line_ptrs_1,
                  const void* line_ptrs_2);

#endif // STRCMP_H
