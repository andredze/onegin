#include "input.h"

void get_filepath(int argc, char* argv[], Context_t* Context)
{
    assert(argv != NULL);
    assert(argc >= 1);
    assert(Context != NULL);

    if (argc > 1)
    {
        Context->InputFileInfo.filepath = argv[1];
    }
    else
    {
        Context->InputFileInfo.filepath = INPUT_FILEPATH;
    }
    if (argc > 2)
    {
        Context->OutputFileInfo.filepath = argv[2];
    }
    else
    {
        Context->OutputFileInfo.filepath = OUTPUT_FILEPATH;
    }
}

int open_file(Context_t* Context)
{
    assert(Context != NULL);
    assert(Context->InputFileInfo.filepath != NULL);

    const char* filepath = Context->InputFileInfo.filepath;

    FILE* stream = fopen(filepath, "rb");
    if (stream == NULL)
    {
        fprintf(stderr, "\n<Can not open the file %s>\n", filepath);
        return 1;
    }
    Context->InputFileInfo.stream = stream;

    return 0;
}

int count_size(Context_t* Context)
{
    struct stat fileinfo = {};

    if (stat(Context->InputFileInfo.filepath, &fileinfo) == -1)
    {
        fprintf(stderr, "\n<Error occured with stat()>\n");
        return 1;
    }

    size_t size = fileinfo.st_size + 1;
    // fprintf(stderr, "size = %zu\n", size);
    Context->InputFileInfo.size = size;

    return 0;
}
