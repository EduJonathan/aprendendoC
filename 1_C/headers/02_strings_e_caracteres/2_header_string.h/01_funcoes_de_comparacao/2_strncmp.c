#include <stdio.h>
#include <string.h>

/**
 * strncmp(): Função compara a cadeia de caracteres de acordo com a quantidade de `n`.
 *
 * SINTAXE: int strncmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
 *
 * @param _Str1 O primeiro ponteiro para char
 * @param _Str2 O segundo ponteiro para char
 * @param _MaxCount Número de caracteres a serem comparados
 * @return retorna um inteiro com as comparações sendo realizadas com os valores de seu parâmetros
 *
 * @note A função compara o case sensitive também das strings
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
