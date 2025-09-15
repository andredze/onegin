#include "input.h"

int get_input(FileInfo_t* BookInfo)
{
    FILE* fp = fopen("onegin_part.txt", "r");

    if (fp == NULL)
    {
        printf("Error with opening the file\n");
        return EOF;
    }

    if (count_file(fp, BookInfo) == EOF)
    {
        return EOF;
    }

    printf("STRINGS_COUNT = %d\n", BookInfo->strings_count);
    printf("MAX_LINE_LEN = %zu\n\n", BookInfo->max_len);

    if (parse_text(fp, BookInfo) == EOF)
    {
        return EOF;
    }

    fclose(fp);
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
            if (feof(stream))
            {
                return 0;
            }
            printf("Reading from file error\n");
            return EOF;
        }
    }
    return 0;
}
