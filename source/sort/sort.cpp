#include "sort.h"

int qsort_text(Context_t* Context,
               int (*compare) (const void *, const void *))
{
    assert(Context != NULL);
    assert(Context->PtrDataParams.ptrdata != NULL);
    assert(Context->PtrDataParams.lines_count >= 0);
    assert(compare != NULL);

    // fprintf(stderr, "<Sorting data>\n");

    qsort(Context->PtrDataParams.ptrdata,
          Context->PtrDataParams.lines_count,
          sizeof(LinePointers_t),
          compare);

    // fprintf(stderr, "<Sorting data went successfully>\n\n");

    return 0;
}

int bubble_sort_text(Context_t* Context,
                     int (*compare) (const void *, const void *))
{
    assert(Context != NULL);
    assert(Context->PtrDataParams.ptrdata != NULL);
    assert(compare != NULL);

    // fprintf(stderr, "<Sorting data>\n");

    LinePointers_t* ptrdata = Context->PtrDataParams.ptrdata;
    int lines_count = Context->PtrDataParams.lines_count;
    int first = 0;
    int second = 0;

    for (first = 0; first < lines_count - 1; first++)
    {
        for (second = first + 1; second < lines_count; second++)
        {
            if (compare(&(ptrdata[first]), &(ptrdata[second])) > 0)
            {
                swap_line_pointers(&(ptrdata[first]), &(ptrdata[second]));
            }
        }
    }

    // fprintf(stderr, "<Sorting data went successfully>\n\n");

    return 0;
}

void swap_line_pointers(LinePointers_t* line_ptrs_1,
                        LinePointers_t* line_ptrs_2)
{
    assert(line_ptrs_1 != NULL);
    assert(line_ptrs_2 != NULL);

    LinePointers_t switcher = *line_ptrs_1;
    *line_ptrs_1 = *line_ptrs_2;
    *line_ptrs_2 = switcher;
}
