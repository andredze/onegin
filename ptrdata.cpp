#include "ptrdata.h"

LinePointers_t* make_ptrdata(char* buffer, int* main_lines_count)
{
    assert(buffer != NULL);
    assert(main_lines_count != NULL);

    int lines_count = 0;
    if (count_lines(buffer, &lines_count))
    {
        return NULL;
    }
    *main_lines_count = lines_count;

    LinePointers_t* ptrdata = NULL;
    if (allocate_ptrdata(&ptrdata, lines_count))
    {
        return NULL;
    }

    if (fill_ptrdata(buffer, ptrdata, lines_count))
    {
        return NULL;
    }

    return ptrdata;
}

int count_lines(char* buffer, int* ptr_lines_count)
{
    assert(buffer != NULL);
    assert(ptr_lines_count != NULL);

    // printdebug("<Counting lines>\n");

    char* ptr = buffer;
    int lines_count = 0;

    char* endptr = strchr(ptr, '\0');
    // printdebug("endptr = %p; endch = %d\n", endptr, *endptr);

    while (ptr < endptr)
    {
        assert(ptr != NULL);

        ptr = strchr(ptr, '\n');

        assert(ptr != NULL);

        // printdebug("lines_count = %d; ptr = %p; lett = %d; nextlett = %d\n",
        //         lines_count, ptr, *ptr, *(ptr + 1));
        ptr++; // skip '\n'
        lines_count += 1;
    }

    *ptr_lines_count = lines_count;

    // printdebug("<Counted \\n>\n");
    return 0;
}

int allocate_ptrdata(LinePointers_t** ptrdata, int lines_count)
{
    assert(ptrdata != NULL);

    // printdebug("<Allocating memory>\n");

    *ptrdata = (LinePointers_t*) calloc(lines_count, sizeof(LinePointers_t));
    if (ptrdata == NULL)
    {
        printdebug("\n<Memory allocation for ptrdata failed>\n");
        return 1;
    }

    // printdebug("<Allocating memory for ptrdata went successfully>\n");
    return 0;
}

int fill_ptrdata(char* buffer, LinePointers_t* ptrdata, int lines_count)
{
    assert(buffer != NULL);
    assert(ptrdata != NULL);

    // printdebug("<Filling ptrdata>\n");

    // fill ptrdata and switch \n to \0
    char* ptr = buffer;
    for (int line_num = 0; line_num < lines_count; line_num++)
    {
        ptrdata[line_num].start = ptr;

        // printf("line_num = %d; ptr = %p; lett = %d; nextlett = %d\n",
        //         line_num, ptr, *ptr, *(ptr + 1));
        assert(ptr != NULL);

        ptr = strchr(ptr, '\n') + 1;
        if (ptr == NULL)
        {
            printdebug("\n<Can not find \\n in buffer>\n");
            return 1;
        }
        *(ptr - 1) = '\0'; // switch \n to \0

        ptrdata[line_num].end = ptr - 2;
    }

    // printdebug("<Filling ptrdata went successfully>\n\n");
    return 0;
}
