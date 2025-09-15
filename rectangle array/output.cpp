#include "output.h"

void print_text(FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    FILE* output = fopen("output.txt", "w");

    assert(output != NULL);

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        assert(BookInfo->data[i] != NULL);

        fputs(BookInfo->data[i], output);
    }
}
