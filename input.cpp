#include "input.h"

char* parse_text(char* filepath)
{
    assert(filepath != NULL);

    printf("<Reading file>\n");

    FILE* stream = fopen(filepath, "rb");
    if (stream == NULL)
    {
        printf("\n<Error with opening the file>\n");
        return NULL;
    }
    struct stat fileinfo;

    if (stat(filepath, &fileinfo) == -1)
    {
        printf("\n<Error occured with stat()>\n");
        return NULL;
    }

    size_t size = fileinfo.st_size + 1;
    printf("size = %zu\n", size);
    char* buffer = (char*) calloc(size / sizeof(char), sizeof(char));
    if (buffer == NULL)
    {
        printf("<Memory allocation for buffer failed>");
        return NULL;
    }
    size_t fread_return = fread(buffer, size, 1, stream);
    if (fread_return != 1)
    {
        if (ferror(stream))
        {
            printf("\n<Error with reading the file>\n");
            printf("<fread_return = %zu>\n", fread_return);
            return NULL;
        }
        // if (feof(stream))
        // {
        //     printf("\n<EOF reached>\n")
        //     return NULL;
        // }
    }
    buffer[size - 1] = '\0'; // adding NULL-terminator

    printf("<Reading went successfully>\n\n");

    fclose(stream);

    return buffer;
}
