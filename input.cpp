#include "input.h"

char* parse_text(int argc, char* argv[])
{
    assert(argc >= 1);
    assert(argv != NULL);

    // fprintf(stderr, "<Reading file>\n");

    FILE* stream = NULL;
    char* filepath = NULL;

    if (open_file(argc, argv, &filepath, &stream))
    {
        return NULL;
    }

    size_t size = 0;
    if (count_size(filepath, &size))
    {
        return NULL;
    }

    char* buffer = NULL;
    if (allocate_buffer(&buffer, size))
    {
        return NULL;
    }

    if (fill_buffer(buffer, size, stream))
    {
        return NULL;
    }

    // fprintf(stderr, "<Reading went successfully>\n\n");

    fclose(stream);

    return buffer;
}

int open_file(int argc, char* argv[], char** filepath, FILE** stream)
{
    assert(stream != NULL);
    assert(argv != NULL);
    assert(argc >= 1);
    assert(filepath != NULL);

    if (argc > 1)
    {
        *filepath = argv[1];
    }
    else
    {
        *filepath = "onegin.txt";
    }

    *stream = fopen(*filepath, "rb");
    if (*stream == NULL)
    {
        fprintf(stderr, "\n<Can not open the file>\n");
        return 1;
    }
    return 0;
}

int count_size(char* filepath, size_t* size)
{
    struct stat fileinfo;

    if (stat(filepath, &fileinfo) == -1)
    {
        fprintf(stderr, "\n<Error occured with stat()>\n");
        return 1;
    }

    *size = fileinfo.st_size + 1;
    // fprintf(stderr, "size = %zu\n", *size);
    return 0;
}

int allocate_buffer(char** buffer, size_t size)
{
    *buffer = (char*) calloc(size / sizeof(char), sizeof(char));
    if (*buffer == NULL)
    {
        fprintf(stderr, "<Memory allocation for buffer failed>");
        return 1;
    }
    return 0;
}

int fill_buffer(char* buffer, size_t size, FILE* stream)
{
    size_t fread_return = fread(buffer, size - 1, 1, stream);
    if (fread_return != 1)
    {
        if (ferror(stream))
        {
            fprintf(stderr, "\n<Error with reading the file>\n");
            fprintf(stderr, "<fread_return = %zu>\n", fread_return);
            return 1;
        }
        if (feof(stream))
        {
            fprintf(stderr, "\n<EOF reached>\n");
            return 1;
        }
    }
    buffer[size - 1] = '\0'; // adding NULL-terminator
    return 0;
}
