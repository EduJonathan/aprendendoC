#include <stdio.h>
#include <inttypes.h>
#include <wchar.h>
#include <stdlib.h>

/**
 * @brief Converte uma string wide character para um número do tipo intmax_t.
 *
 * Esta função converte uma string de caracteres largos (wchar_t) para o tipo intmax_t,
 * utilizando a base fornecida.
 * 
 * wcstoimax(): Função que converte uma string de caracteres largos (wchar_t) para um número inteiro
 *
 * @param str A string wide character a ser convertida.
 * @param base A base para a conversão (por exemplo, 10 para decimal, 16 para hexadecimal).
 * @return O número convertido do tipo intmax_t.
 */
intmax_t converte_wcstoimax(const wchar_t *str, int base)
{
    // Ponteiro para o caractere onde a conversão parou
    wchar_t *endptr;

    // Função que converte uma string de caracteres largos (wchar_t) para o tipo intmax_t
    return wcstoimax(str, &endptr, base);
}

int main(int argc, char **argv)
{
    const wchar_t *str = L"12345";              // String para conversão
    intmax_t num = converte_wcstoimax(str, 10); // Base 10 (decimal)

    printf("Valor convertido (wchar_t para intmax_t): %" PRIdMAX "\n", num);
    return 0;
}
