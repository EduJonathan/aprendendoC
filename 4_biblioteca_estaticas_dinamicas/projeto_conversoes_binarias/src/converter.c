#include <stdlib.h>
#include <string.h>
#include "../include/converter.h"

/**
 * @brief Função interna para mapear valores numéricos em caracteres (0–9, A–F)
 *
 * @param num Valor numérico a ser mapeado
 * @return Caractere correspondente
 */
static char map_value(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    return (char)(num - 10 + 'A');
}

ConversionResult *create_conversion(long decimal, BaseType target)
{
    // Validação da base
    if (target != BASE_BIN &&
        target != BASE_OCT &&
        target != BASE_DEC &&
        target != BASE_HEX)
    {
        return NULL;
    }

    ConversionResult *res = malloc(sizeof(ConversionResult));
    if (!res)
        return NULL;

    char buffer[65];
    int i = 0;

    // Tratamento de número negativo
    int is_negative = (decimal < 0);
    unsigned long temp_dec = is_negative ? (unsigned long)(-decimal)
                                         : (unsigned long)decimal;

    if (temp_dec == 0)
        buffer[i++] = '0';

    while (temp_dec > 0)
    {
        buffer[i++] = map_value(temp_dec % target);
        temp_dec /= target;
    }

    if (is_negative)
        buffer[i++] = '-';

    buffer[i] = '\0';

    res->size = i;
    res->base = target;

    res->output = malloc((size_t)i + 1);
    if (!res->output)
    {
        free(res);
        return NULL;
    }

    // Inversão da string
    for (int j = 0; j < i; j++)
    {
        res->output[j] = buffer[i - j - 1];
    }
    res->output[i] = '\0';

    return res;
}

void free_conversion(ConversionResult *res)
{
    if (!res)
        return;

    free(res->output);
    free(res);
}
