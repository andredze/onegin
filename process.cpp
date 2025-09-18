#include "process.h"

int process_all(const char* output_path, LinePointers_t* ptrdata,
                char* buffer, int lines_count)
{
    FILE* output_stream = NULL;

    if (open_output(&output_stream, output_path))
    {
        return 1;
    }

    if (process_text(output_stream, ptrdata, buffer, lines_count, "by_start"))
    {
        fclose(output_stream);
        return 1;
    }
    if (process_text(output_stream, ptrdata, buffer, lines_count, "by_end"))
    {
        fclose(output_stream);
        return 1;
    }
    if (process_text(output_stream, ptrdata, buffer, lines_count, "original"))
    {
        fclose(output_stream);
        return 1;
    }

    fclose(output_stream);
    return 0;
}

int process_text(FILE* output_stream, LinePointers_t* ptrdata, char* buffer,
                 int lines_count, const char* method)
{
    assert(ptrdata != NULL);
    assert(method != NULL);

    int (* compare) (const void*, const void*) = NULL;

    int original = 0;

    if (strcmp(method, "by_start") == 0)
    {
        compare = strcmp_by_start;
    }
    else if (strcmp(method, "by_end") == 0)
    {
        compare = strcmp_by_end;
    }
    else if (strcmp(method, "original") == 0)
    {
        original = 1;
    }
    else
    {
        fprintf(stderr, "<Unnexpected method of sorting>\n");
        return 1;
    }

    if (original == 0)
    {
        if (qsort_text(ptrdata, lines_count, compare))
        {
            fprintf(stderr, "<Error during sorting>\n");
            return 1;
        }
    }

    if (original == 1)
    {
        print_poem(buffer, lines_count, output_stream);
    }
    else
    {
        if (print_text(ptrdata, lines_count, output_stream))
        {
            fprintf(stderr, "<Error during printing>\n");
            return 1;
        }
    }
    return 0;
}
