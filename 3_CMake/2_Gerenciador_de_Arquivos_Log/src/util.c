#include "../include/util.h"

int file_exists(const char *path)
{
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

int has_read_permission(const char *path)
{
    return (access(path, R_OK) == 0);
}

void safe_free(void **ptr)
{
    if (ptr != NULL && *ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
}
