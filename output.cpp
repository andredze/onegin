#include "output.h"

int print_text(LinePointers_t* ptrdata, int lines_count)
{
    assert(ptrdata != NULL);

    printf("<Printing text>\n");

    FILE* output = NULL;

    if (open_output(&output))
    {
        return 1;
    }
    if (write_text(ptrdata, lines_count, output))
    {
        return 1;
    }

    fclose(output);

    printf("<Printing text to file went successfully>\n");

    return 0;
}

int open_output(FILE** output)
{
    const char* filename = "output.txt";
    *output = fopen(filename, "w");

    if (*output == NULL)
    {
        printf("\n<Error with opening the file>\n");
        return 1;
    }
    return 0;
}

int write_text(LinePointers_t* ptrdata, int lines_count, FILE* output)
{
    for (int line_num = 0; line_num < lines_count; line_num++)
    {
        if (fputs(ptrdata[line_num].start, output) == EOF)
        {
            printf("\n<Error with printing the file>\n");
            return 1;
        }
    }
    return 0;
}
