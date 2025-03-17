#include <stdio.h>
#include <ctype.h>

/**
 * tolower(é minusculo): Converte um caractere maiúsculo para minúsculo.
 *
 * SINTAXE: int tolower(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser convertido.
 * @return Retorna o caractere convertido para minúsculo.
 */

/**
 * @brief Converte todos os caracteres de uma string para minúsculas e os imprime.
 *
 * Esta função percorre cada caractere da string fornecida e converte caracteres maiúsculos
 * para minúsculos usando a função `tolower`. Todos os caracteres são então impressos na tela.
 *
 * @param str Ponteiro para a string a ser convertida.
 */
void printLower(const char *str)
{
    // Loop que percorre toda a string
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Imprimindo os caracteres convertidos para minúsculos
        printf("%c", tolower((unsigned char)str[i]));
    }
}

int main(int argc, char **argv)
{
    int character = 'A';

    // Imprime o caractere convertido para minúsculo
    printf("%c", tolower(character));

    printf("\n----------------------------------\n");

    // Declarando um vetor de caracteres
    const char str[15] = "PROGRAmmING C";

    // Chama a função para converter e imprimir a string em minúsculas
    printLower(str);
    return 0;
}
