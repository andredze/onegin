#ifndef BUFFER_H
#define BUFFER_H

#include "common.h"
#include "input.h"

int parse_text(Context_t* Context);

int allocate_buffer(Context_t* Context);

int fill_buffer(Context_t* Context);

#endif // BUFFER_H
