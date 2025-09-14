#include "strswp.h"

int string_strswp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    char switcher[MAX_LINE_LEN] = "";

    if (strcmp(str1, str2) > 0)
    {
        strcpy(switcher, str2);
        strcpy(str2, str1);
        strcpy(str1, switcher);
    }

    return 0;
}

// int char_strswp(char* str1, char* str2)
// {
//     assert(str1 != NULL);
//     assert(str2 != NULL);
//
//     char switcher = '\0';
//
//     for (int i = 0; i < MAX_LINE_LEN && str1[i] != '\0' && str2[i] != '\0')
// }
