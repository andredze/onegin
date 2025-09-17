#include "strcmp.h"

int strcmp_by_start(const void* line_ptrs_1, const void* line_ptrs_2)
{
    assert(line_ptrs_1 != line_ptrs_2);
    assert(line_ptrs_1 != NULL);
    assert(line_ptrs_2 != NULL);

    char* str1 = ((LinePointers_t*) line_ptrs_1) -> start;
    char* str2 = ((LinePointers_t*) line_ptrs_2) -> start;

    int i1 = 0, i2 = 0;

    for (; str1[i1] != '\0' && str2[i2] != '\0'; i1++, i2++)
    {
        while (!(isalpha(str1[i1])))
        {
            i1++;
        }
        while (!(isalpha(str2[i2])))
        {
            i2++;
        }
        if (tolower(str1[i1]) != tolower(str2[i2]))
        {
            break;
        }
    }
    return tolower(str1[i1]) - tolower(str2[i2]);
}

// int strcmp_by_end(const void* line_ptrs_1, const void* line_ptrs_2)
// {
//     assert(str1 != str2);
//     assert(str1 != NULL);
//     assert(str2 != NULL);
//
//     int len1 = (int) strlen(str1); // convert to int for easier code
//     int len2 = (int) strlen(str2);
//
//     int i1 = len1 - 1;
//     int i2 = len2 - 1;
//
//     assert(i1 >= 0);
//     assert(i2 >= 0);
//
//     for (; i1 > 0 && i2 > 0; i1--, i2--)
//     {
//         while (!(isalpha(str1[i1])))
//         {
//             i1--;
//         }
//         while (!(isalpha(str2[i2])))
//         {
//             i2--;
//         }
//
//         assert(i1 >= 0);
//         assert(i2 >= 0);
//
//         if (tolower(str1[i1]) != tolower(str2[i2]))
//         {
//             return tolower(str1[i1]) - tolower(str2[i2]);
//         }
//     }
//     return len1 - len2;
// }
