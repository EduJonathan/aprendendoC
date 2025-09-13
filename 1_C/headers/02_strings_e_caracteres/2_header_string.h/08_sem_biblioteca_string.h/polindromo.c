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
int isPolindrome(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        // Verificando se os caracteres sao iguais, caso contrario nao eh um polindromo
        if (str[left] != str[right])
        {
            // não é um polindromo
            return 0;
        }

        left++;  // avançando para o próximo caractere
        right--; // avançando para o caractere anterior
    }

    // é um polindromo
    return 1;
}

int main(int argc, char **argv)
{
    // Declarando uma string e pedindo para o usuário digitar uma string
    char str[100] = {0};
    printf("Digite uma string: ");
    scanf("%99[^\n]", str);

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
