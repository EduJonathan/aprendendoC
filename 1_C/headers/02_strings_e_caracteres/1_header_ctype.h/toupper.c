#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * toupper(é maiusculo): Converte um caractere minúsculo para maiúsculo.
 *
 * SINTAXE: int toupper(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser convertido.
 * @return Retorna o caractere convertido para maiúsculo.
 */

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas e os imprime.
 *
 * Esta função percorre cada caractere da string fornecida e converte caracteres minúsculos
 * para maiúsculos usando a função `toupper`. Todos os caracteres são então impressos na tela.
 *
 * @param str Ponteiro para a string a ser convertida.
 */
void printUppr(const char *str)
{
    // Inicio do começo da string
    unsigned int sizeStr = 0;

    // Pecorre a string até o '\0' e aqueles que estiverem em maiúsculo
    while (sizeStr < strlen(str))
    {
        // Imprime convertendo em maiúsculos
        printf("%c", toupper((unsigned char)str[sizeStr]));

        // Incrementa o conteúdo
        sizeStr++;
    }
}

int main(int argc, char **argv)
{
    int character = 0X62; // Letra minúscula 'b', Hexadecimal: 0x62, Decimal: 98

    // Imprime o caractere convertido para maiúsculo
    printf("%c\n", toupper(character));

    printf("\n----------------------------------\n");

    // Declarando um vetor de caracteres
    const char str[14] = "ProGRaMmING c";

    // Chama a função para converter e imprimir a string em maiúsculas
    printUppr(str);
    return 0;
}
