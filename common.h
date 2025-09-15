#ifndef COMMON_H
#define COMMON_H

#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MAXLEN = 500;

const int STRINGS_COUNT = 5134;

const size_t MAX_LINE_LEN = 47;

typedef struct FileInfo {
    char data[STRINGS_COUNT][MAX_LINE_LEN];
    int strings_count = STRINGS_COUNT;
    size_t max_len = MAX_LINE_LEN;
} FileInfo_t;

#endif // COMMON_H
