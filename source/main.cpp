#include "common.h"
#include "strcmp.h"
#include "input.h"
#include "buffer.h"
#include "ptrdata.h"
#include "process.h"

int main(int argc, char* argv[])
{
    Context_t Context = {};
    set_filepath(argc, argv, &Context);

    if (open_file(&Context))
    {
        return EXIT_FAILURE;
    }
    if (read_text(&Context)) // enum oneginstatus success - failure
    {
        fprintf(stderr, "<Error during parsing text>\n");
        return EXIT_FAILURE;
    }
    fclose(Context.InputFileInfo.stream);

    // puts(Context.BufferData.buffer);

    if (parse_text(&Context))
    {
        fprintf(stderr, "<ptr_data is a NULL pointer>\n");
        return EXIT_FAILURE;
    }

    if (open_output(&Context))
    {
        return EXIT_FAILURE;
    }
    if (process_all(&Context))
    {
        fclose(Context.OutputFileInfo.stream);
        return EXIT_FAILURE;
    }

    fclose(Context.OutputFileInfo.stream);
    free(Context.PtrDataParams.ptrdata);

    fprintf(stderr, "<Programm ran>");

    return EXIT_SUCCESS;
}
