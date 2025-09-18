#ifndef COMMON_H
#define COMMON_H

#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys\stat.h>

typedef struct Context {
    CmdArguments_t CmdArguments;
    InputFileInfo_t InputFileInfo;
    BufferData_t BufferData;
    PtrDataInfo_t PtrDataInfo;
    OutputFileInfo_t OutputFileInfo;
} Context_t;

typedef struct CmdArguments {
    int argc;
    char* argv[];
} CmdArguments_t;

typedef struct BufferData {
    char* buffer;
    size_t size;
    int lines_count;
} BufferData_t;

typedef struct PtrDataInfo {
    LinePointers_t* ptrdata;
    int lines_count;
} PtrDataInfo_t;

typedef struct InputFileInfo {
    FILE* stream;
    char* filepath;
} InputFileInfo_t;

typedef struct OutputFileInfo {
    FILE* stream;
    char* filepath;
} OutputFileInfo_t;

typedef struct LinePointers {
    char* start;
    char* end;
} LinePointers_t;

#endif // COMMON_H
