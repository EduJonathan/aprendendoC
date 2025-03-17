#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

/**
 * @brief Converte uma string para um número do tipo intmax_t.
 *
 * Esta função converte uma string para o tipo intmax_t, utilizando a base fornecida.
 *
 * strtoimax(): Função que converte uma string para um número inteiro
 *
 * @param str A string a ser convertida.
 * @param base A base para a conversão (por exemplo, 10 para decimal, 16 para hexadecimal).
 * @return O número convertido do tipo intmax_t.
 */
intmax_t converte_strtoimax(const char *str, int base)
{
    char *endptr;
    return strtoimax(str, &endptr, base);
}

int main(int argc, char **argv)
{
    const char *str = "12345";
    intmax_t num = converte_strtoimax(str, 10); // Base 10 (decimal)

    printf("Valor convertido: %" PRIdMAX "\n", num);
    return 0;
}
