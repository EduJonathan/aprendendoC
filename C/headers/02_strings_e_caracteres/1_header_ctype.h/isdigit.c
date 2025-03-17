#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isdigit(é um digíto): retorna o valor quando for um digíto decimal.
 *
 * SINTAXE: int isdigit(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for númerico.
 */

/**
 * @brief Verifica se um caractere é um dígito.
 *
 * Esta função verifica se o caractere passado como argumento é um dígito
 * (ou seja, um caractere numérico).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um dígito, e falso caso contrário.
 */
bool isDigit(int caractere)
{
    bool is_digit = isdigit(caractere);

    if (is_digit)
    {
        printf(" O caractere '%c' é um digito: %d - %s\n", caractere, is_digit, is_digit ? "true" : "false");
    }
    else
    {
        printf(" O caractere '%c' não é um digito: %d - %s\n", caractere, is_digit, is_digit ? "true" : "false");
    }

    return is_digit;
}

/**
 * @brief Verifica se todos os caracteres de uma string são dígitos.
 *
 * Esta função verifica se todos os caracteres na string fornecida são dígitos
 * (ou seja, caracteres numéricos). Retorna verdadeiro se todos os caracteres forem
 * dígitos e falso se algum caractere não for um dígito.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem dígitos.
 * @return false Se algum caractere da string não for um dígito.
 */
bool stringDeDigitos(const char *str)
{
    while (*str)
    {
        if (!isDigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    int var1 = 'd';
    int var2 = '2';

    isDigit(var1);
    isDigit(var2);

    printf("\n-----------------------------------------\n");

    const char *str1 = "12345"; // String com apenas dígitos
    const char *str2 = "123a5"; // String com caracteres não dígitos

    printf("A string \"%s\" %s apenas dígitos.\n", str1, stringDeDigitos(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas dígitos.\n", str2, stringDeDigitos(str2) ? "contém" : "não contém");
    return 0;
}
