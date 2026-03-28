#include "../include/parser.h"
#include <string.h>
#include <ctype.h>

int parse_log_data(const void *raw_data, size_t data_size, void **parsed_output)
{
    if (!raw_data || data_size == 0 || !parsed_output)
        return -1;

    LogSummary *summary = malloc(sizeof(LogSummary));
    if (!summary)
        return -2;

    summary->total_lines = 0;
    summary->error_lines = 0;

    const char *ptr = raw_data;
    const char *end = ptr + data_size;

    while (ptr < end)
    {
        // pula até a próxima linha
        const char *newline = memchr(ptr, '\n', end - ptr);
        size_t len = newline ? (newline - ptr) : (end - ptr);

        if (len > 0)
        {
            summary->total_lines++;

            // procura "error" case-insensitive
            for (size_t i = 0; i < len - 5; i++)
            {
                if (tolower(ptr[i]) == 'e' && tolower(ptr[i + 1]) == 'r' &&
                    tolower(ptr[i + 2]) == 'r' && tolower(ptr[i + 3]) == 'o' && tolower(ptr[i + 4]) == 'r')
                {
                    summary->error_lines++;
                    break;
                }
            }
        }

        ptr += len + (newline ? 1 : 0);
        if (ptr >= end)
            break;
    }

    *parsed_output = summary;
    return 0;
}
