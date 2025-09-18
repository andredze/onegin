#include "output.h"

int print_text(LinePointers_t* ptrdata, int lines_count, FILE* output_stream)
{
    assert(ptrdata != NULL);
    assert(output_stream != NULL);

    // fprintf(stderr, "<Printing text>\n");

    if (write_text(ptrdata, lines_count, output_stream))
    {
        return 1;
    }

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
        if (fputc('\n', output_stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the file>\n");
            return 1;
        }
    }
    fputc('\n', output_stream);
    return 0;
}

int print_poem(char* buffer, int lines_count, FILE* output_stream)
{
    assert(buffer != NULL);
    assert(lines_count >= 0);
    assert(output_stream != NULL);

    char* ptr = buffer;

    for (int line_num = 0; line_num < lines_count; line_num++)
    {
        assert(ptr != NULL);

        if (fputs(ptr, output_stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the original file>\n");
            return 1;
        }
        if (fputc('\n', output_stream) == EOF)
        {
            fprintf(stderr, "\n<Error with printing the original file>\n");
            return 1;
        }
        ptr = strchr(ptr, '\0') + 1;
    }
    return 0;
}
