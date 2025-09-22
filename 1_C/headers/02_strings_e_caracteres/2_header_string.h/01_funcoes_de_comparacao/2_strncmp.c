#include <stdio.h>
#include <string.h>

/**
 * A função `strncmp()` compara, no máximo, `n` caracteres das strings `str1` e `str2`.
 * A comparação é feita com distinção entre maiúsculas e minúsculas (case sensitive).
 *
 * @param str1 Ponteiro para a primeira string.
 * @param str2 Ponteiro para a segunda string.
 * @param n    Número máximo de caracteres a comparar.
 *
 * @return Um valor inteiro:
 *         - `< 0` se `str1` for menor que `str2`,
 *         - `0` se forem iguais até os `n` caracteres,
 *         - `> 0` se `str1` for maior que `str2`.
 *
 * @note A comparação para quando um caractere nulo (`'\0'`) é encontrado ou após `n` caracteres.
 */

/**
 * @brief Compara as primeiras `n` caracteres de duas strings usando `strncmp`.
 *
 * Compara as primeiras `n` caracteres de `string1` e `string2` e imprime se são iguais
 * ou qual delas é maior ou menor.
 *
 * @param string1 O primeiro ponteiro para char
 * @param string2 O segundo ponteiro para char
 */
void comparandoStringComStrncmp(const char *string1, const char *string2)
{
    /* Número de caracteres a serem comparados. */
    size_t n = 5;

    /* Armazenando a função `strncmp`.*/
    int result = strncmp(string1, string2, n);

    /* Comparando os valores*/
    if (result == 0)
    {
        printf("As primeiras %zu caracteres são iguais.\n", n);
    }
    else if (result < 0)
    {
        printf("As primeiras %zu caracteres de str2 são menores que str1.\n", n);
    }
    else
    {
        printf("As primeiras %zu caracteres de str1 são maiores que str2.\n", n);
    }
}

int main(int argc, char **argv)
{
    /* Declarando vetor de caracteres. */
    char str1[] = "Hello, World!";
    char str2[] = "hello, C!";

    // Comparando os valores
    comparandoStringComStrncmp(str1, str2);

    printf("\n--------------------------\n");

    /* Declarando vetor de caracteres. */
    const char string1[] = "hello, World!";
    const char string2[] = "hello, C!";

    // Comparando os valores para verficar o case sensitive
    comparandoStringComStrncmp(string1, string2);
    return 0;
}
