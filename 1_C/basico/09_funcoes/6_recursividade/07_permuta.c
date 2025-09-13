#include <stdio.h>

/**
 * @brief Função para trocar dois caracteres
 *
 * Função de troca de dois caracteres
 *
 * @param a Ponteiro para um caractere
 * @param b Ponteiro para um caractere
 */
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Função para permutar uma string
 *
 * Função recursiva para permutar uma string, permute(ou permuta/permutando) é uma
 * reorganização de todos os elementos de um conjunto em uma ordem diferente.
 * Em outras palavras, é uma disposição ou arranjo dos elementos de um conjunto,
 * onde a ordem importa.
 *
 * @param s A string a ser permutada
 * @param i O índice inicial da string
 * @param n O tamanho da string
 */
void permuta(char *s, int i, int n)
{
    // Caso base: se o índice atingir o tamanho da string, imprimir a string
    if (i == n)
    {
        printf("%s\n", s);
    }
    else
    {
        // Se não, permuta o caractere atual com todos os caracteres restantes
        for (int j = i; j <= n; j++)
        {
            swap(&s[i], &s[j]);   // Faz o swap
            permuta(s, i + 1, n); // Chama a função recursivamente
            swap(&s[i], &s[j]);   // Desfaz o swap
        }
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
