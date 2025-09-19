#ifndef COMMON_H
#define COMMON_H

// #include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys\stat.h>

typedef struct LinePointers {
    char* start;
    char* end;
} LinePointers_t;

typedef struct BufferData {
    char* buffer;
    int lines_count;
} BufferData_t;

typedef struct PtrDataParams {
    LinePointers_t* ptrdata;
    int lines_count;
} PtrDataParams_t;

typedef struct InputFileInfo {
    FILE* stream;
    const char* filepath;
    size_t size;
} InputFileInfo_t;

typedef struct OutputFileInfo {
    FILE* stream;
    const char* filepath;
} OutputFileInfo_t;

typedef struct Context {
    InputFileInfo_t InputFileInfo;
    BufferData_t BufferData;
    PtrDataParams_t PtrDataParams;
    OutputFileInfo_t OutputFileInfo;
    // enum
} Context_t;

#endif // COMMON_H
