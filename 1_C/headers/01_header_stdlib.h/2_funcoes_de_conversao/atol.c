#include <stdio.h>
#include <stdlib.h>

/**
 * atoll(): Converte string para long long.
 *
 * SINTAXE: long atol(const char *_Str);
 * @param _Str Ponteiro para char
 * @return O valor da string convertido como um inteiro do tipo `long long`.
 */

/**
 * @brief Converte uma string em um inteiro longo longo.
 *
 * Esta função usa a função `atoll` para converter uma string dada
 * em um valor inteiro do tipo `long long`.
 *
 * @param str Ponteiro para a string terminada em nulo a ser convertida.
 * @return O valor convertido como um inteiro do tipo `long long`.
 */
long long stringParaLongLong(const char *str)
{
    long long strToLL = atoll(str);
    return strToLL;
}

/**
 * atol(): Converte string para Long.
 * SINTAXE: long atol(const char *_Str)
 * @param _Str Ponteiro para char
 */

/**
 * @brief Converte uma string em um valor inteiro `long`.
 *
 * Esta função usa a função `atol` para converter uma string dada
 * em um valor inteiro do tipo `long`.
 *
 * @param str Ponteiro para a string terminada em nulo a ser convertida.
 * @return O valor convertido como um inteiro do tipo `long`.
 */
long stringParaLong(const char *str)
{
    long strToL = atol(str);
    return strToL;
}

int main(int argc, char **argv)
{
    /* Declarando um vetor de string. */
    char str[] = "1234567890123456789";

    /* Declarando e inicializando para o valor de `str` convertido. */
    long int strConvertido = stringParaLong(str);

    printf(" String convertida para long int: %ld\n", strConvertido);
    printf(" Verificando tamanho da conversão em bytes: %zu\n", sizeof(strConvertido));

    printf("\n-----------------------------------------------\n");

    /* Declarando um vetor de string. */
    char *string = "123456789";

    /* Declarando e inicializando para o valor de `str` convertido. */
    long long stringConvertido = stringParaLongLong(string);

    printf(" String convertida para long int: %lld\n", stringConvertido);
    printf(" Verificando tamanho da conversão em bytes: %zu\n", sizeof(stringConvertido));
    return 0;
}
