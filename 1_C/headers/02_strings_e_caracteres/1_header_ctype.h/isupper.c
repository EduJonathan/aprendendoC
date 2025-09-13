#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isupper(é maiusculo): classifica quando a letra é maiúscula.
 *
 * SINTAXE: int isupper(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for maiúsculo.
 */

/**
 * @brief Verifica se um caractere é uma letra maiúscula.
 *
 * Esta função verifica se o caractere passado como argumento é uma letra maiúscula.
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for uma letra maiúscula, e falso caso contrário.
 */
bool isUpper(int caractere)
{
    bool is_upper = isupper((unsigned char)caractere);

    if (is_upper)
    {
        printf("O caractere '%c' é maiusculo: %d - %s\n", caractere, is_upper, is_upper ? "true" : "false");
    }
    else
    {
        printf("O caractere '%c' não é maiusculo: %d - %s\n", caractere, is_upper, is_upper ? "true" : "false");
    }
    return is_upper;
}

/**
 * @brief Verifica se todos os caracteres de uma string são letras maiúsculas.
 *
 * Esta função verifica se todos os caracteres na string fornecida são letras maiúsculas.
 * Retorna verdadeiro se todos os caracteres forem letras maiúsculas e falso se algum caractere
 * não for uma letra maiúscula.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem letras maiúsculas.
 *
 * false Se algum caractere da string não for uma letra maiúscula.
 */
bool StringUpper(const char *str)
{
    while (*str)
    {
        if (!isUpper(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    int var1 = 'M'; // Letra maiúscula
    int var2 = 'm'; // Letra minúscula (não é maiúscula)
    int var3 = '3'; // Dígito (não é maiúscula)

    isUpper(var1);
    isUpper(var2);
    isUpper(var3);

    printf("\n-----------------------------------------\n");

    const char *str1 = "HELLO"; // String com apenas letras maiúsculas
    const char *str2 = "Hello"; // String com letras maiúsculas e minúsculas

    printf("A string \"%s\" %s apenas letras maiúsculas.\n", str1, StringUpper(str1) ? "contém" : "não contém");
    printf("\nA string \"%s\" %s apenas letras maiúsculas.\n", str2, StringUpper(str2) ? "contém" : "não contém");
    return 0;
}
