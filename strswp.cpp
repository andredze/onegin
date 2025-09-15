#include "strswp.h"

int not_symbol(char ch)
{
    return strchr(",.?! \t:;(){}[]\'\"-", ch) != NULL;
}

int strcmp_by_start(char* str1, char* str2)
{
    assert(str1 != str2);
    assert(str1 != NULL);
    assert(str2 != NULL);
    int i1 = 0, i2 = 0;

    for (; str1[i1] != '\0' && str2[i2] != '\0'; i1++, i2++)
    {
        while (not_symbol(str1[i1]))
        {
            i1++;
        }
        while (not_symbol(str2[i2]))
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

int string_strswp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    char switcher[MAX_LINE_LEN] = "";

    strcpy(switcher, str2);
    strcpy(str2, str1);
    strcpy(str1, switcher);
    return 0;
}

// note: str1 and str2 should have enough memory
int char_strswp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    char switcher = '\0';
    int str1_ended = 0;
    int str2_ended = 0;
    for (size_t i = 0; i < MAX_LINE_LEN && !(str1_ended && str2_ended); i++)
    {
        // printf("before: str1[%zu] = %c str2[%zu] = %c\n", i, str1[i], i, str2[i]);
        if (str1[i] == '\0')
        {
            str1_ended = 1;
        }
        if (str2[i] == '\0')
        {
            str2_ended = 1;
        }
        switcher = str1[i];
        str1[i] = str2[i];
        str2[i] = switcher;
        // printf("after: str1[%zu] = %c str2[%zu] = %c\n\n", i, str1[i], i, str2[i]);
    }
    return 0;
}
