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
        return 1;
    }
    puts(buffer);

    LinePointers_t* ptr_data = make_ptrdata(buffer, &lines_count);
    if (ptr_data == NULL)
    {
        printf("<ptr_data is a NULL pointer>\n");
        return 1;
    }

    bubble_sort_text(ptr_data, lines_count);
    print_text(ptr_data, lines_count);

    free(ptr_data);
    printf("<Memory freed>\n");

    return 0;
}
