#include <stdio.h>
#include <string.h>

/**
 * A função `strcasecmp()` compara as strings `str1` e `str2` de forma case-insensitive,
 * ou seja, sem considerar diferenças entre letras maiúsculas e minúsculas.
 *
 * @param str1 Ponteiro para a primeira string.
 * @param str2 Ponteiro para a segunda string.
 *
 * @return Um valor inteiro:
 *         - `< 0` se `str1` for menor que `str2`,
 *         - `0` se forem iguais,
 *         - `> 0` se `str1` for maior que `str2`.
 *
 * @note Essa função não faz parte do padrão ANSI C, mas é amplamente suportada em sistemas POSIX.
 */

/**
 * @brief Compara duas strings de forma insensível ao caso usando `strcasecmp`.
 *
 * Compara duas strings ignorando diferenças entre maiúsculas e minúsculas e imprime se são
 * iguais, ou qual delas é maior ou menor.
 *
 * @param string1 O primeiro ponteiro para char
 * @param string2 O segundo ponteiro para char
 */
void comparandoStringComStrCaseCmp(const char *string1, const char *string2)
{
    /* Armazenando a função `strcasecmp`. */
    int result = strcasecmp(string1, string2);

    /* Comparando as strings */
    if (result == 0)
    {
        printf(" As strings são iguais\n");
    }
    else if (result < 0)
    {
        printf(" \"%s\" é menor que \"%s\".\n", string1, string2);
    }
    else
    {
        printf(" \"%s\" é maior que \"%s\".\n", string1, string2);
    }
}

int main(int argc, char **argv)
{
    /* Declarando vetores de caracteres para realizar a comparação.*/
    const char str1[] = "Linguagem c";
    const char str2[] = "LINGUAGEM C";

    // Comparando as strings
    comparandoStringComStrCaseCmp(str1, str2);

    printf("\n---------------------------------\n");

    /* Declarando vetores de caracteres para realizar a comparação.*/
    const char string1[] = "Hello!";
    const char string2[] = "Ola!";

    // Comparando as strings
    comparandoStringComStrCaseCmp(string1, string2);
    return 0;
}
