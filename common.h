#ifndef COMMON_H
#define COMMON_H

#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys\stat.h>

// const char* output_filepath = "output.txt";

typedef struct LinePointers {
    char* start;
    char* end;
} LinePointers_t;

#endif // COMMON_H
