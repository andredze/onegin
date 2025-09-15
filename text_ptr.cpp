#include "text_ptr.h"

/* wrong version */
// int parse_text_ptr(FILE* stream, char* ptr_data[])
// {
//     assert(stream != NULL);
//     assert(ptr_data != NULL);
//
//     char line[MAX_LINE_LEN] = "";
//
//     for (int i = 0; i < STRINGS_COUNT; i++)
//     {
//         if (fgets(line, MAX_LINE_LEN, stream) == NULL)
//         {
//             return EOF;
//         }
//         ptr_data[i] = line;
//     }
//     return 0;
// }

int sort_text_ptr(char* ptr_data[])
{
    assert(ptr_data != NULL);

    int second = 0;
    char* switcher = NULL;

    for (int first = 0; first < STRINGS_COUNT - 1; first++)
    {
        for (second = first + 1; second < STRINGS_COUNT; second++)
        {
            assert(ptr_data[first] != NULL);
            assert(ptr_data[second] != NULL);

            if (strcmp_by_end(ptr_data[first], ptr_data[second]) > 0)
            {
                switcher = ptr_data[first];
                ptr_data[first] = ptr_data[second];
                ptr_data[second] = switcher;
            }
        }
    }
    return 0;
}

void free_ptr_data(char* ptr_data[])
{
    assert(ptr_data != NULL);

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        free(ptr_data[i]);
    }
}

int parse_text_ptr(FILE* stream, char* ptr_data[])
{
    assert(stream != NULL);
    assert(ptr_data != NULL);

    char line[MAX_LINE_LEN] = "";

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        if (fgets(line, MAX_LINE_LEN, stream) == NULL)
        {
            return EOF;
        }
        // ? - выделяется MAX_LINE_LEN памяти или strlen(line) памяти
        // ответ - до \0  в моей реализации, в библиотечной?
        // мы передаем только ptr => до стрлена
        ptr_data[i] = strdup(line);
    }
    return 0;
}

int print_text_ptr(char* ptr_data[])
{
    assert(ptr_data != NULL);

    for (int i = 0; i < STRINGS_COUNT; i++)
    {
        assert(ptr_data[i] != NULL);

        printf("%s", ptr_data[i]);
    }
    printf("\n");
    return 0;
}
