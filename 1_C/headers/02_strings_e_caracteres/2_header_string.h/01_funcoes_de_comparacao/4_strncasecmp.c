#include <stdio.h>
#include <string.h>

/**
 * A função `strncasecmp()` compara até `n` caracteres das strings `str1` e `str2`
 * sem diferenciar maiúsculas de minúsculas (case-insensitive).
 *
 * @param str1     Ponteiro para a primeira string.
 * @param str2     Ponteiro para a segunda string.
 * @param n        Número máximo de caracteres a comparar.
 *
 * @return Um valor inteiro:
 *         - `< 0` se `str1` for menor que `str2`,
 *         - `0` se forem iguais nos primeiros `n` caracteres,
 *         - `> 0` se `str1` for maior que `str2`.
 *
 * @note Essa função não é parte do padrão ANSI C, mas é comum em sistemas POSIX.
 */

/**
 * @brief Compara as primeiras `n` letras de duas strings de forma insensível ao caso
 * usando `strncasecmp`.
 *
 * Comparando as primeiras `n` letras de `string1` e `string2` e imprime se são iguais ou qual
 * delas é maior ou menor, ignorando diferenças entre maiúsculas e minúsculas.
 *
 * @param string1 O primeiro ponteiro para char
 * @param string2 O segundo ponteiro para char
 */
void comparandoStringComStrcasecmp(const char *string1, const char *string2)
{
    printf("Comparando strings até um determinado caractere\n");

    /* Número de caracteres a serem comparados. */
    const size_t n = 5;

    /* Armazenando a função `strncasecmp`.*/
    int result = strncasecmp(string1, string2, n);

    /* Comparando os valores*/
    if (result == 0)
    {
        printf(" As primeiras %zu caracteres são iguais.\n", n);
    }
    else if (result < 0)
    {
        printf(" As primeiras %zu caracteres de str1 são menores que str2.\n", n);
    }
    else
    {
        printf(" As primeiras %zu caracteres de str1 são maiores que str2.\n", n);
    }

    printf("\n-----------------------------------------------\n");
    printf("Comparando todos os caracteres da string com strncasecmp\n");

    // Obter o comprimento das duas strings
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);

    // Comparar o comprimento máximo das duas strings
    size_t nMaximo = (len1 > len2) ? len1 : len2;

    int comparacao = strncasecmp(string1, string2, nMaximo);

    if (comparacao == 0)
    {
        printf("As strings são iguais, ignorando o case-sensitive.\n");
    }
    else if (comparacao < 0)
    {
        printf("string1 é menor que string2, ignorando o case-sensitive.\n");
    }
    else
    {
        printf("string1 é maior que string2, ignorando o case-sensitive.\n");
    }
}

int main(int argc, char **argv)
{
    /* Declarando dois vetores de caracteres. */
    const char str1[] = "HEllo, World!";
    const char str2[] = "Hello, C!";

    // Chamando a função para comparar os valores
    comparandoStringComStrcasecmp(str1, str2);
    return 0;
}
