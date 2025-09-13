#include <stdio.h>
#include <string.h>

/**
 * strcasecmp (string case compare): Função que compara duas strings iguais, que por mais que
 * sejam diferente (uma escrita em maiúscula) e outra escrita (em minuscula), ele vai comparar
 * sem diferenciar o case-sensitive da string.
 *
 * SINTAXE: int strcasecmp(const char *_Str1, const char *_Str2);
 *
 * @param _Str1 O primeiro ponteiro para char
 * @param _Str2 O segundo ponteiro para char
 * @return retorna um inteiro com as comparações sendo realizadas com os valores de seu parâmetros.
 *
 * @note A função compara o case sensitive das strings.
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
