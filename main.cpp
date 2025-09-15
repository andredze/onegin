#include "common.h"
#include "strswp.h"
#include "text.h"
#include "text_ptr.h"
#include "input.h"

int main()
{
    // TODO отдельная функция input("file.txt") = fopen + count + parse
    // input, output, sort,
    // TODO для массива с указателями; поменять константы на переменные (и мб каллок)
    // через каллок размер стрингс_коунт найти
    // указатель на ф-ии
    // naming, codestyle
    // return 1 при ошибках
    // тесты

    FileInfo_t OneginInfo = {.data = {{}},
                             .strings_count = 0,
                             .max_len = 0};

    get_input(&OneginInfo);
    sort_text(&OneginInfo);

    FILE* output = fopen("output.txt", "w");
    print_text(&OneginInfo, output);

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

//     char* ptr_data[STRINGS_COUNT] = {};
//     if (parse_text_ptr(fp, ptr_data) == EOF)
//     {
//         return EOF;
//     }
//
//     fclose(fp);
//
//     sort_text_ptr(ptr_data);
//     print_text_ptr(ptr_data, output);
//
//     free_ptr_data(ptr_data);

    printf("Programm ran successfully :)");
    return 0;
}
