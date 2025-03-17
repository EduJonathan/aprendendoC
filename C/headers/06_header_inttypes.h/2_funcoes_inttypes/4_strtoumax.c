#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

/**
 * @brief Converte uma string para um número do tipo uintmax_t.
 *
 * Esta função converte uma string para o tipo uintmax_t, utilizando a base fornecida.
 *
 * strtoumax(): Função que converte uma string para um número inteiro
 *
 * @param str A string a ser convertida.
 * @param base A base para a conversão (por exemplo, 10 para decimal, 16 para hexadecimal).
 * @return O número convertido do tipo uintmax_t.
 */
uintmax_t converte_strtoumax(const char *str, int base)
{
    char *endptr = NULL; // Ponteiro para o caractere onde a conversão parou

    // Função que converte uma string em um número inteiro
    return strtoumax(str, &endptr, base);
}

int main(int argc, char **argv)
{
    const char *str = "12345";                   // String para conversão
    uintmax_t num = converte_strtoumax(str, 10); // Base 10 (decimal)

    printf("Valor convertido (unsigned): %" PRIuMAX "\n", num);
    return 0;
}
