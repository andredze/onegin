#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include "config.h"

char* parse_text(int argc, char* argv[]);

int open_file(int argc, char* argv[], char** filepath, FILE** stream);

int count_size(char* filepath, size_t* size);

int allocate_buffer(char** buffer, size_t size);

int fill_buffer(char* buffer, size_t size, FILE* stream);

#endif // INPUT_H
