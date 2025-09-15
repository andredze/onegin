#ifndef TEXT_PTR_H
#define TEXT_PTR_H

#include "common.h"
#include "strswp.h"

int parse_text_ptr(FILE* stream, char* ptr_data[]);

int print_text_ptr(char* ptr_data[]);

int sort_text_ptr(char* ptr_data[]);

void free_ptr_data(char* ptr_data[]);

#endif // TEXT_PTR_H
