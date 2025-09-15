#include "common.h"
#include "strswp.h"
#include "rectangle array/input.h"
#include "rectangle array/sort.h"
#include "rectangle array/output.h"
#include "text_ptr.h"

int run_rect();

int run_ptr();

int main()
{
    // if (run_rect())
    // {
    //     return 1;
    // }
    if (run_ptr())
    {
        return 1;
    }

    return 0;
}

int run_rect()
{
    FileInfo_t OneginInfo = {.data = {{}},
                             .strings_count = 0,
                             .max_len = 0};

    get_input(&OneginInfo);
    sort_text(&OneginInfo);
    print_text(&OneginInfo);

    return 0;
}

int run_ptr()
{
    FILE* fp = fopen("onegin.txt", "r");

    if (fp == NULL)
    {
        printf("Error with opening the file\n");
        return EOF;
    }
    char* ptr_data[STRINGS_COUNT] = {};
    if (parse_text_ptr(fp, ptr_data) == EOF)
    {
        return EOF;
    }

    fclose(fp);

    sort_text_ptr(ptr_data);
    FILE* output = fopen("output.txt", "w");
    print_text_ptr(ptr_data, output);

    free_ptr_data(ptr_data);
    return 0;
}
