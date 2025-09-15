#include "sort.h"

int sort_text(FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    int second = 0;

    for (int first = 0; first < STRINGS_COUNT - 1; first++)
    {
        for (second = first + 1; second < STRINGS_COUNT; second++)
        {
            if (strcmp_by_end(BookInfo->data[first], BookInfo->data[second]) > 0)
            {
                llu_strswp(BookInfo->data[first], BookInfo->data[second]);
            }
        }
    }
    return 0;
}
