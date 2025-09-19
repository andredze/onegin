#include "common.h"
#include "strcmp.h"
#include "input.h"
#include "parse.h"
#include "ptrdata.h"
#include "process.h"

int main(int argc, char* argv[])
{
    Context_t Context = {.InputFileInfo =  {.stream = NULL,
                                            .filepath = NULL,
                                            .size = 0},
                         .BufferData =     {.buffer = NULL,
                                            .lines_count = 0},
                         .PtrDataParams =  {.ptrdata = NULL,
                                            .lines_count = 0},
                         .OutputFileInfo = {.stream = NULL,
                                            .filepath = NULL}};
    get_filepath(argc, argv, &Context);

    if (open_file(&Context))
    {
        return 1;
    }
    if (parse_text(&Context))
    {
        fprintf(stderr, "<Error during parsing text>\n");
        return 1;
    }
    fclose(Context.InputFileInfo.stream);

    // puts(Context.BufferData.buffer);

    if (make_ptrdata(&Context))
    {
        fprintf(stderr, "<ptr_data is a NULL pointer>\n");
        return 1;
    }

    if (open_output(&Context))
    {
        return 1;
    }
    if (process_all(&Context))
    {
        fclose(Context.OutputFileInfo.stream);
        return 1;
    }

    fclose(Context.OutputFileInfo.stream);
    free(Context.PtrDataParams.ptrdata);

    fprintf(stderr, "<Programm ran>");

    return 0;
}
