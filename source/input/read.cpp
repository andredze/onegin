#include "read.h"

int read_text(Context_t* Context)
{
    assert(Context != NULL);

    // fprintf(stderr, "<Reading file>\n");

    if (count_size(Context))
    {
        return 1;
    }
    if (allocate_buffer(Context))
    {
        return 1;
    }
    if (fill_buffer(Context))
    {
        return 1;
    }
    // fprintf(stderr, "<Reading went successfully>\n\n");

    return 0;
}

int allocate_buffer(Context_t* Context)
{
    size_t size = Context->InputFileInfo.size;
    char* buffer = (char*) calloc(size / sizeof(char), sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "<Memory allocation for buffer failed>");
        return 1;
    }
    Context->BufferData.buffer = buffer;

    return 0;
}

int fill_buffer(Context_t* Context)
{
    char* buffer = Context->BufferData.buffer;
    size_t size = Context->InputFileInfo.size;
    FILE* stream = Context->InputFileInfo.stream;

    size_t fread_return = fread(buffer, size - 1, 1, stream);
    if (fread_return != 1)
    {
        if (ferror(stream))
        {
            fprintf(stderr, "\n<Error with reading the file>\n");
            fprintf(stderr, "<fread_return = %zu>\n", fread_return);
            return 1;
        }
        if (feof(stream))
        {
            fprintf(stderr, "\n<EOF reached>\n");
            return 1;
        }
    }
    buffer[size - 1] = '\0'; // adding NULL-terminator

    return 0;
}
