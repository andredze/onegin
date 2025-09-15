#include "common.h"
#include "strswp.h"

int count_file(FILE* stream, FileInfo_t* BookInfo);

int parse_text(FILE* stream, FileInfo_t* BookInfo);

int sort_text(FileInfo_t* BookInfo);

void print_text(FileInfo_t* BookInfo);

int main()
{
    // TODO отдельная функция input("file.txt") = fopen + count + parse
    // TODO output in file
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

    if (parse_text(fp, &OneginInfo) == EOF)
    {
        return EOF;
    }
    fclose(fp);

    // char_strswp test
    /*
    char str1[] = {'b', 'a', 'n', 'a', 'n', 'a', '\0'};
    char str2[] = {'a', 'p', 'p', 'l', 'e', '\0', '\0'};
    char_strswp(str1, str2);
    printf("1: %s\n", str1);
    printf("2: %s\n\n", str2);
    */

    // strcmp_by_end test
    /*
    int test = ('я' > 'а');
    printf("\'я\' > \'а\': %d\n", test);

    char str3[40] = "Вниманье дружбы возлюбя,\r\n";
    char str4[40] = "ааВысоких дум и простотыаааа;\r\n";
    printf("34: %d\n", strcmp_by_end(str3, str4));
    */

    print_text(&OneginInfo);

    sort_text(&OneginInfo);

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

int sort_text(FileInfo_t* BookInfo)
{
    assert(BookInfo != NULL);
    assert(BookInfo->data != NULL);

    int second = 0;

    for (int first = 0; first < STRINGS_COUNT; first++)
    {
        for (second = first + 1; second < STRINGS_COUNT; second++)
        {
            if (strcmp_by_end(BookInfo->data[first], BookInfo->data[second]) > 0)
            {
                char_strswp(BookInfo->data[first], BookInfo->data[second]);
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
