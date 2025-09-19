#include "output.h"

int print_text(Context_t* Context)
{
    assert(Context != NULL);
    assert(Context->PtrDataParams.ptrdata != NULL);
    assert(Context->OutputFileInfo.stream != NULL);

    // fprintf(stderr, "<Printing text>\n");

    if (write_text(Context))
    {
        return 1;
    }

    // fprintf(stderr, "<Printing text to file went successfully>\n");

    return 0;
}

int open_output(Context_t* Context)
{
    assert(Context != NULL);
    assert(Context->OutputFileInfo.filepath != NULL);

    FILE* stream = fopen(Context->OutputFileInfo.filepath, "w");

    if (stream == NULL)
    {
        fprintf(stderr, "\n<Error with opening the file>\n");
        return 1;
    }
    Context->OutputFileInfo.stream = stream;

    return 0;
}

int write_text(Context_t* Context)
{
    assert(Context != NULL);
    assert(Context->OutputFileInfo.stream != NULL);

    FILE* stream = Context->OutputFileInfo.stream;
    LinePointers_t* ptrdata = Context->PtrDataParams.ptrdata;
    int lines_count = Context->PtrDataParams.lines_count;

    for (int i = 0; i < lines_count; i++)
    {
        if (fputs(ptrdata[i].start, stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the file>\n");
            return 1;
        }
        if (fputc('\n', stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the file>\n");
            return 1;
        }
    }
    fputc('\n', stream);

    return 0;
}

int print_poem(Context_t* Context)
{
    assert(Context != NULL);
    assert(Context->BufferData.lines_count >= 0);
    assert(Context->OutputFileInfo.stream != NULL);

    char* ptr = Context->BufferData.buffer;
    int lines_count = Context->BufferData.lines_count;
    FILE* stream = Context->OutputFileInfo.stream;

    for (int i = 0; i < lines_count; i++)
    {
        assert(ptr != NULL);

        if (fputs(ptr, stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the original file>\n");
            return 1;
        }
        if (fputc('\n', stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the original file>\n");
            return 1;
        }
        ptr = strchr(ptr, '\0') + 1;
        // for compatibility with windows files
        if (*ptr == '\0')
        {
            ptr++;
        }
    }
    return 0;
}
