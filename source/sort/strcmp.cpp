#include "strcmp.h"

int strcmp_by_start(const void* line_ptrs_1,
                    const void* line_ptrs_2)
{
    assert(line_ptrs_1 != line_ptrs_2);
    assert(line_ptrs_1 != NULL);
    assert(line_ptrs_2 != NULL);

    char* str1 = ((const LinePointers_t*) line_ptrs_1) -> start;
    char* str2 = ((const LinePointers_t*) line_ptrs_2) -> start;

    int i1 = 0, i2 = 0;

    for (; str1[i1] != '\0' && str2[i2] != '\0'; i1++, i2++)
    {
        // skip non letters
        while (!(isalpha(str1[i1])))
        {
            i1++;
            if (str1[i1] == '\0')
            {
                break;
            }
        }
        while (!(isalpha(str2[i2])))
        {
            i2++;
            if (str2[i2] == '\0')
            {
                break;
            }
        }

        if (tolower(str1[i1]) != tolower(str2[i2]))
        {
            break;
        }
    }

    return tolower(str1[i1]) - tolower(str2[i2]);
}

int strcmp_by_end(const void* line_ptrs_1,
                  const void* line_ptrs_2)
{
    assert(line_ptrs_1 != line_ptrs_2);
    assert(line_ptrs_1 != NULL);
    assert(line_ptrs_2 != NULL);

    char* str1 = ((const LinePointers_t*) line_ptrs_1) -> end;
    char* str2 = ((const LinePointers_t*) line_ptrs_2) -> end;

    char* start1 = ((const LinePointers_t*) line_ptrs_1) -> start;
    char* start2 = ((const LinePointers_t*) line_ptrs_2) -> start;

    int letter1 = '\0';
    int letter2 = '\0';

    for (; start1 <= str1 && start2 <= str2; str1--, str2--)
    {
        // skip non letters
        while (!(isalpha(*str1)))
        {
            str1--;
            if (*str1 == '\0')
            {
                break;
            }
        }
        while (!(isalpha(*str2)))
        {
            str2--;
            if (*str2 == '\0')
            {
                break;
            }
        }

        letter1 = tolower(*str1);
        letter2 = tolower(*str2);

        if (letter1 != letter2)
        {
            return letter1 - letter2;
        }
    }

    return letter1 - letter2;
}
