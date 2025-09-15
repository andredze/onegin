#include "common.h"
#include "strswp.h"

int count_file(FILE* stream, FileInfo_t* BookInfo);

int read_text(FILE* stream, FileInfo_t* BookInfo);

int sort_text_by_start(FileInfo_t* BookInfo);

void print_text(FileInfo_t* BookInfo);

int main()
{
    // TODO отдельная функция input("file.txt") = fopen + count + read
    FILE* fp = fopen("onegin_part.txt", "r");

    if (fp == NULL)
    {
        printf("Error with opening the file\n");
        return EOF;
    }

    FileInfo_t OneginInfo = {.data = {{}},
                             .strings_count = 0,
                             .max_len = 0};

    if (count_file(fp, &OneginInfo) == EOF)
    {
        return EOF;
    }

    printf("STRINGS_COUNT = %d\n", OneginInfo.strings_count);
    // strings_count = 17
    printf("MAX_LINE_LEN = %zu\n\n", OneginInfo.max_len);
    // MAX_LINE_LEN = 36

    if (read_text(fp, &OneginInfo) == EOF)
    {
        return EOF;
    }
    fclose(fp);

    // char_strswp test
    char str1[] = {'b', 'a', 'n', 'a', 'n', 'a', '\0'};
    char str2[] = {'a', 'p', 'p', 'l', 'e', '\0', '\0'};
    char_strswp(str1, str2);
    printf("%s\n", str1);
    printf("%s\n", str2);

    print_text(&OneginInfo);

    sort_text_by_start(&OneginInfo);

    print_text(&OneginInfo);

    return 0;
}

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

int sort_text_by_start(FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    int second = 0;

    for (int first = 0; first < STRINGS_COUNT; first++)
    {
        for (second = 0; second < STRINGS_COUNT; second++)
        {
            if (strcmp(BookInfo->data[second], BookInfo->data[first]) > 0)
            {
                char_strswp(BookInfo->data[second], BookInfo->data[first]);
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

int read_text(FILE* stream, FileInfo_t* BookInfo)
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
