#ifndef READ_H
#define READ_H

#include "common.h"
#include "input.h"

int read_text(Context_t* Context);

int allocate_buffer(Context_t* Context);

int fill_buffer(Context_t* Context);

#endif // READ_H
