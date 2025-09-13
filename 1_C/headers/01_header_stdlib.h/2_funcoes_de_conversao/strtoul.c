#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Converte uma string para um número inteiro do tipo `unsigned long`.
 *
 * Esta função utiliza a função `strtoul` para converter uma string em um número inteiro do
 * tipo `unsigned long`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @param base A base para a conversão (por exemplo, 10 para decimal).
 * @return O número convertido do tipo `unsigned long`.
 */
unsigned long converteStringParaUl(const char *str, char **endptr, int base)
{
    // Função que converte uma string em um número inteiro
    unsigned long num = strtoul(str, endptr, base);

    // Verifica se houve erro durante a conversão
    if (*endptr != NULL && **endptr != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **endptr);
    }
    return num; // Retorna o número convertido
}

/**
 * @brief Converte uma string para um número inteiro do tipo `long long`.
 *
 * Esta função utiliza a função `strtoll` para converter uma string em um número inteiro do
 * tipo `long long`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @param base A base para a conversão (por exemplo, 10 para decimal).
 * @return O número convertido do tipo `long long`.
 */
long long converteStringParaLLD(const char *str, char **endptr, int base)
{
    // Função que converte uma string em um número inteiro
    long long num = strtoll(str, endptr, base);

    // Verifica se houve erro durante a conversão
    if (*endptr != NULL && **endptr != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **endptr);
    }
    return num; // Retorna o número convertido
}

/**
 * @brief Converte uma string para um número inteiro do tipo `unsigned long long`.
 *
 * Esta função utiliza a função `strtoull` para converter uma string em um número inteiro
 * do tipo `unsigned long long`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @param base A base para a conversão (por exemplo, 10 para decimal).
 * @return O número convertido do tipo `unsigned long long`.
 */
unsigned long long converteStrinParaULL(const char *str, char **endptr, int base)
{
    // Função que converte uma string em um número inteiro
    unsigned long long num = strtoull(str, endptr, base);

    // Verifica se houve erro durante a conversão
    if (*endptr != NULL && **endptr != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **endptr);
    }
    return num; // Retorna o número convertido
}

/**
 * @brief Converte uma string para um número inteiro do tipo `long`.
 *
 * Esta função utiliza a função `strtol` para converter uma string em um número inteiro
 * do tipo `long`. A função também verifica se houve erro durante a conversão.
 *
 * @param str A string a ser convertida.
 * @param endptr Ponteiro para o caractere onde a conversão parou. Pode ser NULL.
 * @param base A base para a conversão (por exemplo, 10 para decimal).
 * @return O número convertido do tipo `long`.
 */
long converteStringParaL(const char *str, char **endptr, int base)
{
    // Função que converte uma string em um número inteiro
    long num = strtol(str, endptr, base);

    // Verifica se houve erro durante a conversão
    if (*endptr != NULL && **endptr != '\0')
    {
        printf("Erro na conversão. Caractere inválido encontrado: %c\n", **endptr);
    }

    // Retorna o número convertido
    return num;
}

int main(int argc, char **argv)
{
    printf("STRTOUL\n");

    const char *str_ulong = "123456789";
    char *endptr_ulong = NULL;
    unsigned long num_ulong = converteStringParaUl(str_ulong, &endptr_ulong, 10);

    printf("String convertida para unsigned long: %lu\n", num_ulong);
    printf("String convertida para unsigned long: %lu\n", num_ulong);

    printf("\n--------------------------------------\n");
    printf("STRTOLL\n");

    const char *str_longlong = "-9876543210123456";
    char *endptr_longlong = NULL;
    long long num_longlong = converteStringParaLLD(str_longlong, &endptr_longlong, 10);

    printf("String convertida para long long: %lld\n", num_longlong);
    printf("String convertida para long long: %lld\n", sizeof(num_longlong));

    printf("\n--------------------------------------\n");
    printf("STROULL\n");

    const char *str_ulonglong = "18446744073709551615";
    char *endptr_ulonglong = NULL;
    unsigned long long num_ulonglong = converteStrinParaULL(str_ulonglong, &endptr_ulonglong, 10);

    printf("String convertida para unsigned long long: %llu\n", num_ulonglong);
    printf("String convertida para unsigned long long: %llu\n", sizeof(num_ulonglong));

    printf("\n--------------------------------------\n");
    printf("STRTOL\n");

    const char *str_long = "-123456";
    char *endptr_long = NULL;
    long num_long = converteStringParaL(str_long, &endptr_long, 10);

    printf("String convertida para long: %ld\n", num_long);
    printf("String convertida para long: %ld\n", sizeof(num_long));
    return 0;
}
