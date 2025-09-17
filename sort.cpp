#include "sort.h"

int bubble_sort_text(LinePointers_t* ptrdata, int lines_count)
{
    assert(ptrdata != NULL);

    printf("<Sorting data>\n");

    int first = 0;
    int second = 0;

    for (first = 0; first < lines_count - 1; first++)
    {
        for (second = first + 1; second < lines_count; second++)
        {
            if (strcmp_by_start(&(ptrdata[first]), &(ptrdata[second])) > 0)
            {
                swap_line_pointers(&(ptrdata[first]), &(ptrdata[second]));
            }
        }
    }

    printf("<Sorting data went successfully>\n\n");

    return 0;
}

void swap_line_pointers(LinePointers_t* line_ptrs_1, LinePointers_t* line_ptrs_2)
{
    assert(line_ptrs_1 != NULL);
    assert(line_ptrs_2 != NULL);

    char* switcher = NULL;

    switcher = line_ptrs_1->start;
    line_ptrs_1->start = line_ptrs_2->start;
    line_ptrs_2->start = switcher;

    switcher = line_ptrs_1->end;
    line_ptrs_1->end = line_ptrs_2->end;
    line_ptrs_2->end = switcher;
}
