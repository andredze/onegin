#include "process.h"

int process_text(LinePointers_t* ptrdata, int lines_count, const char* method)
{
    assert(ptrdata != NULL);
    assert(method != NULL);

    int (* compare) (const void*, const void*) = NULL;
    const char* output_path = NULL;

    if (strcmp(method, "by_start"))
    {
        compare = strcmp_by_start;
        output_path = SORTED_BYSTART_FILEPATH;
    }
    else if (strcmp(method, "by_end"))
    {
        compare = strcmp_by_end;
        output_path = SORTED_BYEND_FILEPATH;
    }
    else
    {
        fprintf(stderr, "<Unnexpected method of sorting>\n");
        return 1;
    }

    if (qsort_text(ptrdata, lines_count, compare))
    {
        fprintf(stderr, "<Error during sorting>\n");
        return 1;
    }

    if (print_text(ptrdata, lines_count, output_path))
    {
        fprintf(stderr, "<Error during printing>\n");
        return 1;
    }

    return 0;
}
