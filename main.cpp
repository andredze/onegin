#include "common.h"
#include "strswp.h"
#include "text.h"

int main()
{
    // TODO отдельная функция input("file.txt") = fopen + count + parse
    // TODO output in file
    // TODO массив с указателями

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
    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);
    */

    // llu_strswp test
    /*
    char str2[] = {'b', 'a', 'n', 'a', 'n', 'a', 'n', 'a', 'n', 'a', '\0'};
    char str1[] = {'z', 'p', 'p', 'l', 'e', 'z', 'p', 'l', 'e', '\0', '\0'};
    llu_strswp(str1, str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);
    */

    // strcmp_by_end test
    /*
    int test = ('я' > 'а');
    printf("\'я\' > \'а\': %d\n", test);

    char str3[40] = "Вниманье дружбы возлюбя,\r\n";
    char str4[40] = "ааВысоких дум и простотыаааа;\r\n";
    printf("strcmp34: %d\n", strcmp_by_end(str3, str4));
    */

    print_text(&OneginInfo);

    sort_text(&OneginInfo);

    print_text(&OneginInfo);

    return 0;
}
