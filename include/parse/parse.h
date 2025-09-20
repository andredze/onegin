#ifndef PARSE_H
#define PARSE_H

#include "common.h"

int parse_text(Context_t* Context);

int count_lines(Context_t* Context);

int allocate_ptrdata(Context_t* Context);

int fill_ptrdata(Context_t* Context);

#endif // PARSE_H
