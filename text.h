#ifndef TEXT_H
#define TEXT_H

#include "common.h"
#include "strswp.h"

int count_file(FILE* stream, FileInfo_t* BookInfo);

int parse_text(FILE* stream, FileInfo_t* BookInfo);

int sort_text(FileInfo_t* BookInfo);

void print_text(FileInfo_t* BookInfo, FILE* output);

#endif // TEXT_H
