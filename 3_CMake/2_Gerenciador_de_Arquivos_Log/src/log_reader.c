#include "../include/log_reader.h"

void *read_log_file(const char *file_path, size_t *out_size)
{
    if (file_path == NULL || out_size == NULL)
    {
        return NULL;
    }

    // Verifica se o arquivo existe
    if (access(file_path, F_OK) != 0)
    {
        return NULL;
    }
}