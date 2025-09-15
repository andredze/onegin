#include "text.h"

void print_text(FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        printf("%s", BookInfo->data[i]);
    }
    printf("\n");
}

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

int count_file(FILE* stream, FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);

    char line[MAXLEN] = "";

    int count = 0;
    size_t max_len = 0;
    size_t len = 0;

    for (;; count++)
    {
        if (fgets(line, MAXLEN, stream) == NULL)
        {
            if (feof(stream))
            {
                BookInfo->strings_count = count;
                BookInfo->max_len = max_len + 1; // +1 for '\0' symbol

                rewind(stream);
                return 0;
            }

            printf("Error with reading file\n");
            return EOF;
        }
        len = strlen(line) / sizeof(char);
        if (len > max_len)
        {
            max_len = len;
        }
    }
    return EOF;
}

int parse_text(FILE* stream, FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        if (fgets(BookInfo->data[i], MAX_LINE_LEN, stream) == NULL)
        {
            // printf("%s", BookInfo->data[i]);
            if (feof(stream))
            {
                return 0;
            }
            printf("Reading from file error\n");
            return EOF;
        }
        // printf("%s", BookInfo->data[i]);
    }
    return 0;
}
