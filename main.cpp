#include "common.h"
#include "strcmp.h"
#include "input.h"
#include "ptrdata.h"
#include "process.h"

int main()
{
    int lines_count = 0;

    char* buffer = parse_text();
    if (buffer == NULL)
    {
        fprintf(stderr, "<Error during parsing text>\n");
        return 1;
    }
    // puts(buffer);

    LinePointers_t* ptrdata = make_ptrdata(buffer, &lines_count);
    if (ptrdata == NULL)
    {
        fprintf(stderr, "<ptr_data is a NULL pointer>\n");
        return 1;
    }

    if (process_text(ptrdata, lines_count, "by_start"))
    {
        return 1;
    }
    if (process_text(ptrdata, lines_count, "by_end"))
    {
        return 1;
    }

    free(ptrdata);
    // fprintf(stderr, "<Memory freed>\n");

    return 0;
}
