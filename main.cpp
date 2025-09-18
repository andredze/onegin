#include "common.h"
#include "strcmp.h"
#include "input.h"
#include "ptrdata.h"
#include "sort.h"
#include "output.h"

int main()
{
    int lines_count = 0;

    char filename[] = "onegin_part.txt";
    char* buffer = parse_text(filename);
    if (buffer == NULL)
    {
        fprintf(stderr, "<Error during parsing text>\n");
        return 1;
    }
    puts(buffer);

    LinePointers_t* ptr_data = make_ptrdata(buffer, &lines_count);
    if (ptr_data == NULL)
    {
        fprintf(stderr, "<ptr_data is a NULL pointer>\n");
        return 1;
    }

    int (* compare) (const void*, const void*) = NULL;
    compare = strcmp_by_end;

    if (qsort_text(ptr_data, lines_count, compare))
    {
        fprintf(stderr, "<Error during sorting>\n");
        return 1;
    }
    if (print_text(ptr_data, lines_count))
    {
        fprintf(stderr, "<Error during printing>\n");
        return 1;
    }

    free(ptr_data);
    // fprintf(stderr, "<Memory freed>\n");

    return 0;
}
