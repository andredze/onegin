#ifndef COMMON_H
#define COMMON_H

#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys\stat.h>

#define printdebug(a) fprintf(stderr, a)

typedef struct LinePointers {
    char* start;
    char* end;
} LinePointers_t;

#endif // COMMON_H
