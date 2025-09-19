#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"
#include "sort.h"
#include "output.h"
#include "config.h"

int process_all(Context_t* Context);

int process_text(Context_t* Context, const char* method);

#endif // PROCESS_H
