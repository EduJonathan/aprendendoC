#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isalpha(é um alfabeto): Retorna quando o valor for true, de um caractere alfabetico.
 *
 * SINTAXE: int isalpha(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for grafico.
 */

/**
 * @brief Verifica se um caractere é alfabético.
 *
 * Esta função verifica se o caractere passado como argumento é uma letra
 * (ou seja, um caractere alfabético).
 *
 * @param caractere Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for alfabético, e falso caso contrário.
 */
bool isAlpha(int caractere)
{
    bool is_alpha = isalpha((unsigned char)caractere);

    if (is_alpha)
    {
        printf(" O caractere '%c' é um caractere alfabético: %d - %s\n", caractere, is_alpha, is_alpha ? "true" : "false");
    }
    else
    {
        printf(" O caractere '%c' não é um caractere alfabético: %d - %s\n", caractere, is_alpha, is_alpha ? "true" : "false");
    }
    return is_alpha;
}

/**
 * @brief Verifica se todos os caracteres de uma string são alfabéticos.
 *
 * Esta função verifica se todos os caracteres na string fornecida são alfabéticos
 * (ou seja, letras). Retorna verdadeiro se todos os caracteres forem alfabéticos
 * e falso se algum caractere não for alfabético.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem alfabéticos.
 * @return false Se algum caractere da string não for alfabético.
 */
bool StringDeAlphas(const char *str)
{
    while (*str)
    {
        if (!isAlpha(*str))
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
    int var3 = '\t';
    int var4 = ' ';

    isAlpha(var1);
    isAlpha(var2);
    isAlpha(var3);
    isAlpha(var4);

    printf("\n-----------------------------------------\n");

    const char *test_str1 = "HelloWorld";
    const char *test_str2 = "Hello123"; // Contém números

    printf("A string \"%s\" %s alfabética.\n", test_str1, StringDeAlphas(test_str1) ? "é" : "não é");
    printf("A string \"%s\" %s alfabética.\n", test_str2, StringDeAlphas(test_str2) ? "é" : "não é");
    return 0;
}
