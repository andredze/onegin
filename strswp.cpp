#include "strswp.h"

char my_tolower(char ch)
{
    if (ch <= 'ß' && ch >= 'À')
    {
        return ch - 'À' + 'à';
    }
    return ch;
}

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
        if (my_tolower(str1[i1]) != my_tolower(str2[i2]))
        {
            break;
        }
    }
    return my_tolower(str1[i1]) - my_tolower(str2[i2]);
}

int strcmp_by_end(char* str1, char* str2)
{
    assert(str1 != str2);
    assert(str1 != NULL);
    assert(str2 != NULL);

    int len1 = (int) strlen(str1); // convert to int for easier code
    int len2 = (int) strlen(str2);

    int i1 = len1 - 1;
    int i2 = len2 - 1;

    assert(i1 >= 0);
    assert(i2 >= 0);

    for (; i1 > 0 && i2 > 0; i1--, i2--)
    {
        while (not_symbol(str1[i1]))
        {
            i1--;
        }
        while (not_symbol(str2[i2]))
        {
            i2--;
        }

        assert(i1 >= 0);
        assert(i2 >= 0);

        if (my_tolower(str1[i1]) != my_tolower(str2[i2]))
        {
            return my_tolower(str1[i1]) - my_tolower(str2[i2]);
        }
    }

    return len1 - len2;
}

int string_strswp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    assert(str1 != str2);

    char switcher[MAX_LINE_LEN] = "";

    strcpy(switcher, str2);
    strcpy(str2, str1);
    strcpy(str1, switcher);
    return 0;
}

int llu_strswp(char* char_str1, char* char_str2)
{
    assert(char_str1 != NULL);
    assert(char_str2 != NULL);
    assert(char_str1 != char_str2);

    size_t* llu_str1 = (size_t*) char_str1;
    size_t* llu_str2 = (size_t*) char_str2;

    size_t len1 = strlen(char_str1);
    size_t len2 = strlen(char_str2);

    size_t end = max(len1 / (sizeof(size_t) / sizeof(char)),
                     len2 / (sizeof(size_t) / sizeof(char)));

    size_t llu_switcher = 0;
    char char_switcher = '\0';
    size_t i = 0;

    for (; i < end; i++)
    {
        llu_switcher = llu_str1[i];
        llu_str1[i] = llu_str2[i];
        llu_str2[i] = llu_switcher;
    }

    i = i * sizeof(size_t) / sizeof(char);

    while (!(char_str1[i] == '\0' && char_str2[i] == '\0'))
    {
        char_switcher = char_str1[i];
        char_str1[i] = char_str2[i];
        char_str2[i] = char_switcher;
        i++;
    }
    return 0;
}

// note: str1 and str2 should have enough memory
int char_strswp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    assert(str1 != str2);

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
