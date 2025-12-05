#include "../include/println.h"

// Implementação de println em C que formata e adiciona '\n'
int println(const char *format, ...)
{
    va_list args;
    char buffer[1024]; // Buffer para a string formatada
    int length;

    // 1. Formata a string (igual ao printf)
    va_start(args, format);
    length = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (length < 0)
    {
        return -1; // Erro na formatação
    }

    // 2. Adiciona a quebra de linha
    if (length < sizeof(buffer) - 1)
    {
        buffer[length] = '\n';
        buffer[length + 1] = '\0';
        length++;
    }

    // 3. Chama a função em assembly para imprimir
    return _println_internal(buffer);
}
