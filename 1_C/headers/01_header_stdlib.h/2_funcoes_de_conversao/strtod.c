#include <stdio.h>
#include <stdlib.h>

/**
 * strtod(): converte uma string em um número de ponto flutuante (double).
 *
 * SINTAXE: strtof(const char *__restrict__ nptr, char **__restrict__ endptr);
 *
 * @param nptr Ponteiro para a string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @return O número convertido do tipo `float`.
 */

/**
 * @brief Converte uma string para um número de ponto flutuante do tipo `double`.
 *
 * Esta função utiliza a função `strtod` para converter uma string em um número de ponto
 * flutuante do tipo `double`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @return O número convertido do tipo `double`.
 */
double convertendoComStrtod(const char *str, char **endptr)
{
    // Função que converte uma string em um número de ponto flutuante
    double num = strtod(str, endptr);

    // Verifica se houve erro durante a conversão
    if (*endptr != NULL && **endptr != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **endptr);
    }
    return num; // Retorna o número convertido
}

/**
 * @brief Converte uma string para um número de ponto flutuante do tipo `float`.
 *
 * Esta função utiliza a função `strtof` para converter uma string em um número de ponto
 * flutuante do tipo `float`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param fim Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @return O número convertido do tipo `float`.
 */
float convertendoComStrtof(const char *str, char **fim)
{
    // Função que converte uma string em um número de ponto flutuante
    float num = strtof(str, fim);

    // Verifica se houve erro durante a conversão
    if (*fim != NULL && **fim != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **fim);
    }
    return num; // Retorna o número convertido
}

/**
 * @brief Converte uma string para um número de ponto flutuante do tipo `long double`.
 *
 * Esta função utiliza a função `strtold` para converter uma string em um número de ponto
 * flutuante do tipo `long double`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param fim Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @return O número convertido do tipo `long double`.
 */
long double convertendoComStrtod(const char *str, char **fim)
{
    // Função que converte uma string em um número de ponto flutuante
    long double num = strtold(str, fim);

    // Verifica se houve erro durante a conversão
    if (*fim != NULL && **fim != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **fim);
    }
    return num; // Retorna o número convertido
}

int main(int argc, char **argv)
{
    printf("STRTOD\n");

    char str[] = "123.456";
    char *endptr = NULL;
    double num = convertendoComStrtod(str, &endptr);

    printf("String convertida para ponto flutuante: %f\n", num);
    printf("Verificando tamanho da conversão em bytes: %zu\n", sizeof(num));

    printf("\n--------------------------------------\n");
    printf("STRTOF\n");

    const char string[] = "9e5";
    char *fim = NULL;
    float stringConvertida = convertendoComStrtof(string, &fim);

    printf("String convertida para ponto flutuante: %f\n", stringConvertida);
    printf("Verificando tamanho da conversão em bytes: %zu\n", sizeof(stringConvertida));

    printf("\n--------------------------------------\n");
    printf("STRTOLD\n");

    const char *String = "900.4785";
    char *fimDoPonteiro = NULL;
    long double numConvertido = convertendoComStrtod(String, &fimDoPonteiro);

    printf("String convertida para ponto flutuante: %Lf\n", numConvertido);
    printf("Verificando tamanho da conversão em bytes: %zu\n", sizeof(numConvertido));
    return 0;
}
