#include "../include/parser.h"
#include <string.h>

int parse_log_data(const void *raw_data, size_t data_size, void **parsed_output)
{
    if (raw_data == NULL || data_size == 0 || parsed_output == NULL)
    {
        return -1; // Parâmetros inválidos
    }

    // Exemplo simples de parsing: apenas copia os dados brutos para a saída parseada
    void *parsed_data = malloc(data_size);
    if (parsed_data == NULL)
    {
        return -2; // Falha na alocação de memória
    }

    memcpy(parsed_data, raw_data, data_size);
    *parsed_output = parsed_data;

    return 0; // Sucesso
}
