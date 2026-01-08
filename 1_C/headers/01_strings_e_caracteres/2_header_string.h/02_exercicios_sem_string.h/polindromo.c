#include <stdio.h>
#include <string.h>

/**
 * @brief Este programa verifica se uma string eh polindromo
 *
 * isPolindrome(): Função que verifica se uma string é polindromo.
 *
 * @param str String a ser verificada.
 * @return 1 se a string for polindromo, 0 caso contrario.
 */
int isPalindrome(char str[])
{
    int left = 0;
    int right = 0;

    // Encontrar o tamanho da string manualmente (substituindo strlen)
    while (str[right] != '\0')
    {
        right++;
    }

    // Ajustar para o último caractere válido
    right--;

    // Importante: Se o fgets capturou o '\n', ignore-o
    if (right >= 0 && str[right] == '\n')
    {
        right--;
    }

    // Lógica de comparação das extremidades
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0; // Não é palíndromo
        }
        left++;
        right--;
    }

    return 1; // É palíndromo
}

int main(int argc, char **argv)
{
    // Declarando uma string e pedindo para o usuário digitar uma string
    char str[100] = {0};
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    if (isPolindrome(str))
    {
        printf("polindromo");
    }
    else
    {
        printf("Nao é polindromo");
    }
    return 0;
}
