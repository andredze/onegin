#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include "config.h"

void get_filepath(int argc, char* argv[], Context_t* Context);

int open_file(Context_t* Context);

int count_size(Context_t* Context);

#endif // INPUT_H
