#include "process.h"

int process_all(Context_t* Context)
{
    assert(Context != NULL);

    if (process_text(Context, "by_start"))
    {
        return 1;
    }
    if (process_text(Context, "by_end"))
    {
        return 1;
    }
    if (process_text(Context, "original"))
    {
        return 1;
    }

    return 0;
}

int process_text(Context_t* Context, const char* method)
{
    assert(method != NULL);
    assert(Context != NULL);
    assert(Context->PtrDataParams.ptrdata != NULL);

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
        if (qsort_text(Context, compare))
        {
            fprintf(stderr, "<Error during sorting>\n");
            return 1;
        }
    }

    if (original == 1)
    {
        print_poem(Context);
    }
    else
    {
        if (print_text(Context))
        {
            fprintf(stderr, "<Error during printing>\n");
            return 1;
        }
    }

    return 0;
}
