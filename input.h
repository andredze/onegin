#ifndef INPUT_H
#define INPUT_H

#include "common.h"

int get_input(FileInfo_t* BookInfo);

int count_file(FILE* stream, FileInfo_t* BookInfo);

int parse_text(FILE* stream, FileInfo_t* BookInfo);

#endif // INPUT_H
