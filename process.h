#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"
#include "sort.h"
#include "output.h"
#include "config.h"

int process_text(LinePointers_t* ptrdata, int lines_count, const char* method);

#endif // PROCESS_H
