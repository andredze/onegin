#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include "config.h"

char* parse_text();

int open_file(const char* filename, FILE** stream);

int count_size(const char* filepath, size_t* size);

int allocate_buffer(char** buffer, size_t size);

int fill_buffer(char* buffer, size_t size, FILE* stream);

#endif // INPUT_H
