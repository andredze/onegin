#ifndef STRUCTURES_H
#define STRUCTURES_H

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

typedef struct FileInfo {
    FILE* stream;
    const char* filepath;
    size_t size;
} FileInfo_t;

typedef struct Context {
    FileInfo_t InputFileInfo;
    BufferData_t BufferData;
    PtrDataParams_t PtrDataParams;
    FileInfo_t OutputFileInfo;
    // enum
} Context_t;

#endif // STRUCTURES_H
