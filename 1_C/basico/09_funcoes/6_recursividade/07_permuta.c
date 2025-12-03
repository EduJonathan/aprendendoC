#include <stdio.h>

/**
 * @brief Troca o conteúdo de dois caracteres.
 *
 * Esta função realiza a troca dos valores apontados por `a` e `b`.
 *
 * @param a Ponteiro para o primeiro caractere.
 * @param b Ponteiro para o segundo caractere.
 */
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Gera todas as permutações possíveis de uma string usando recursão.
 *
 * Uma permutação é uma reorganização dos elementos de um conjunto onde
 * **a ordem importa**. Esta função utiliza a técnica de "backtracking":
 * troca o caractere atual com cada posição possível e chama recursivamente
 * para permutar o restante da string. Após a chamada recursiva,
 * desfaz a troca (backtrack) para restaurar o estado original.
 *
 * @param s A string cuja permutação será gerada.
 * @param i Índice atual sendo fixado.
 * @param n Índice final (última posição da string).
 */
void permuta(char *s, int i, int n)
{
    // Caso base: índice atual ultrapassou o final → string completa
    if (i == n)
    {
        printf("%s\n", s);
        return;
    }

    // Permuta o caractere da posição i com todas as posições restantes
    for (int j = i; j <= n; j++)
    {
        swap(&s[i], &s[j]);   // Coloca o caractere de s[j] na posição i
        permuta(s, i + 1, n); // Permuta o restante da string
        swap(&s[i], &s[j]);   // Desfaz (backtrack) para restaurar a string
    }
}

int main(int argc, char **argv)
{
    char str1[] = "123";
    permuta(str1, 0, 2);
    printf("\n--------------------------\n");

    char str2[] = "abc";
    permuta(str2, 0, 2);
    printf("\n--------------------------\n");

    char str3[] = "1234";
    permuta(str3, 0, 3);

    return 0;
}
