#include "output.h"

int print_text(LinePointers_t* ptrdata, int lines_count, const char* output_path)
{
    assert(ptrdata != NULL);
    assert(output_path != NULL);

    // fprintf(stderr, "<Printing text>\n");

    FILE* output_stream = NULL;

    if (open_output(&output_stream, output_path))
    {
        return 1;
    }
    if (write_text(ptrdata, lines_count, output_stream))
    {
        return 1;
    }

    fclose(output_stream);

    // fprintf(stderr, "<Printing text to file went successfully>\n");

    return 0;
}

int open_output(FILE** output_stream, const char* output_path)
{
    *output_stream = fopen(output_path, "w");

    if (*output_stream == NULL)
    {
        fprintf(stderr, "\n<Error with opening the file>\n");
        return 1;
    }
    return 0;
}

int write_text(LinePointers_t* ptrdata, int lines_count, FILE* output_stream)
{
    for (int line_num = 0; line_num < lines_count; line_num++)
    {
        if (fputs(ptrdata[line_num].start, output_stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the file>\n");
            return 1;
        }
        fputc('\n', output_stream);
    }
    return 0;
}
