#ifndef INPUT_H
#define INPUT_H

#include "libraries.h"
#include "structures.h"
#include "config.h"
#include "read.h"
#include "parse.h"

void set_filepath(int argc, char* argv[], Context_t* Context);

int read_and_parse_file(Context_t* Context);

int open_file(Context_t* Context);

int count_size(Context_t* Context);

#endif // INPUT_H
