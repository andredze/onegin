#include "parse.h"

int parse_text(Context_t* Context)
{
    assert(Context != NULL);

    if (count_lines(Context))
    {
        return 1;
    }
    if (allocate_ptrdata(Context))
    {
        return 1;
    }
    if (fill_ptrdata(Context))
    {
        return 1;
    }

    return 0;
}

int count_lines(Context_t* Context)
{
    assert(Context != NULL);

    // fprintf(stderr, "<Counting lines>\n");

    char* ptr = Context->BufferData.buffer;
    char* endptr = strchr(ptr, '\0');
    int lines_count = 0;
    // fprintf(stderr, "endptr = %p; endch = %d\n", endptr, *endptr);

    while (ptr < endptr)
    {
        assert(ptr != NULL);

        ptr = strchr(ptr, '\n');

        assert(ptr != NULL);

        // fprintf(stderr, "lines_count = %d; ptr = %p; lett = %d; nextlett = %d\n",
        //         lines_count, ptr, *ptr, *(ptr + 1));

        ptr++; // skip '\n'
        lines_count += 1;
    }

    Context->BufferData.lines_count = lines_count;
    Context->PtrDataParams.lines_count = lines_count;

    // fprintf(stderr, "<Counted \\n>\n");
    return 0;
}

int allocate_ptrdata(Context_t* Context)
{
    assert(Context != NULL);

    // fprintf(stderr, "<Allocating memory>\n");

    LinePointers_t* ptrdata = (LinePointers_t*)
                              calloc(Context->BufferData.lines_count,
                                     sizeof(LinePointers_t));
    if (ptrdata == NULL)
    {
        fprintf(stderr, "\n<Memory allocation for ptrdata failed>\n");
        return 1;
    }
    Context->PtrDataParams.ptrdata = ptrdata;

    // fprintf(stderr, "<Allocating memory for ptrdata went successfully>\n");
    return 0;
}

int fill_ptrdata(Context_t* Context)
{
    assert(Context != NULL);

    // fprintf(stderr, "<Filling ptrdata>\n");

    // fill ptrdata and switch \r and \n to \0
    char* ptr = Context->BufferData.buffer;
    LinePointers_t* ptrdata = Context->PtrDataParams.ptrdata;
    int lines_count = Context->BufferData.lines_count;

    for (int line_num = 0; line_num < lines_count; line_num++)
    {
        ptrdata[line_num].start = ptr;

        // printf("line_num = %d; ptr = %p; lett = %d; nextlett = %d\n",
        //         line_num, ptr, *ptr, *(ptr + 1));
        assert(ptr != NULL);

        ptr = strchr(ptr, '\n') + 1;
        if (ptr == NULL)
        {
            fprintf(stderr, "\n<Can not find \\n in buffer>\n");
            return 1;
        }

        *(ptr - 1) = '\0'; // switch \n to \0
        if (*(ptr - 2) == '\r') // if windows file (\r\n at end)
        {
            *(ptr - 2) = '\0'; // switch \r to \0
            ptrdata[line_num].end = ptr - 3;
        }
        else // if no \r
        {
            ptrdata[line_num].end = ptr - 2;
        }
    }

    // fprintf(stderr, "<Filling ptrdata went successfully>\n\n");
    return 0;
}
