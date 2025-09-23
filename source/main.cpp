#include "libraries.h"
#include "structures.h"
#include "input.h"
#include "process.h"
#include "output.h"

int main(int argc, char* argv[])
{
    Context_t Context = {};
    set_filepath(argc, argv, &Context);

    if (read_and_parse_file(&Context))
    {
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
