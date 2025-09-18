#include "common.h"
#include "strcmp.h"
#include "input.h"
#include "ptrdata.h"
#include "process.h"

int main(int argc, char* argv[])
{
    int lines_count = 0;

    char* buffer = parse_text(argc, argv);
    if (buffer == NULL)
    {
        fprintf(stderr, "<Error during parsing text>\n");
        return 1;
    }
    // puts(buffer);

    // LinePointers_t* ptrdata = NULL;
    LinePointers_t* ptrdata = make_ptrdata(buffer, &lines_count);
    if (ptrdata == NULL)
    {
        fprintf(stderr, "<ptr_data is a NULL pointer>\n");
        return 1;
    }

    const char* output_path = OUTPUT_PATH;

    if (process_all(output_path, ptrdata, buffer, lines_count))
    {
        return 1;
    }

    free(ptrdata);

    fprintf(stderr, "<Programm ran>");

    return 0;
}
