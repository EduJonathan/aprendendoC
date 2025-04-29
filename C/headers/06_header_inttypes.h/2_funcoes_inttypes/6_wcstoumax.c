#include <stdio.h>
#include <inttypes.h>
#include <wchar.h>
#include <stdlib.h>

/**
 * @brief Converte uma string wide character para um número do tipo uintmax_t.
 *
 * Esta função converte uma string de caracteres largos (wchar_t) para o tipo uintmax_t,
 * utilizando a base fornecida.
 *
 * wcstoumax(): Função que converte uma string de caracteres largos (wchar_t) para um número inteiro
 *
 * @param str A string wide character a ser convertida.
 * @param base A base para a conversão (por exemplo, 10 para decimal, 16 para hexadecimal).
 * @return O número convertido do tipo uintmax_t.
 */
uintmax_t converte_wcstoumax(const wchar_t *str, int base)
{
    // Ponteiro para o caractere onde a conversão parou
    wchar_t *endptr = NULL;

    // Função que converte uma string de caracteres largos (wchar_t) para o tipo uintmax_t
    return wcstoumax(str, &endptr, base);
}

int main(int argc, char **argv)
{
    // String para conversão
    const wchar_t *str = L"12345";
    uintmax_t num = converte_wcstoumax(str, 10); // Base 10 (decimal)

    printf("Valor convertido (wchar_t para uintmax_t): %" PRIuMAX "\n", num);
    return 0;
}
