#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isblank(está em branco): considera os caracteres em branco como o caractere de tabulação
 * e o caractere de espaço.
 *
 * SINTAXE: int isblank(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um espaço ou tabulação.
 */

/**
 * @brief Verifica se um caractere é um caractere em branco.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere em branco
 * (como espaço ou tabulação).
 *
 * @param caractere Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um caractere em branco, e falso caso contrário.
 */
bool isBlank(int caractere)
{
    bool is_Blank = isblank((unsigned char)caractere);

    if (is_Blank)
    {
        printf(" O caractere '%c' é um caractere alfabético: %d - %s\n", caractere, is_Blank, is_Blank ? "true" : "false");
    }
    else
    {
        printf(" O caractere '%c' não é um caractere alfabético: %d - %s\n", caractere, is_Blank, is_Blank ? "true" : "false");
    }
    return is_Blank;
}

/**
 * @brief Verifica se todos os caracteres de uma string são caracteres em branco.
 *
 * Esta função verifica se todos os caracteres na string fornecida são caracteres em branco
 * (como espaço ou tabulação). Retorna verdadeiro se todos os caracteres forem em branco
 * e falso se algum caractere não for um caractere em branco.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem caracteres em branco.
 * @return false Se algum caractere da string não for um caractere em branco.
 */
bool stringBlanks(const char *str)
{
    while (*str)
    {
        if (!isBlank(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    char var1 = ' ';  // Espaço em branco
    char var2 = '\t'; // Tabulação horizontal
    char var3 = 'A';  // Letra maiúscula

    isBlank(var1);
    isBlank(var2);
    isBlank(var3);

    printf("\n-----------------------------------------\n");

    const char *test_str1 = "   ";        // Apenas espaços
    const char *test_str2 = " \t \v \t "; // Espaços e tabulações
    const char *test_str3 = "Hello";      // Contém letras

    printf("A string \"%s\" %s um conjunto de caracteres em branco.\n", test_str1, stringBlanks(test_str1) ? "é" : "não é");
    printf("A string \"%s\" %s um conjunto de caracteres em branco.\n", test_str2, stringBlanks(test_str2) ? "é" : "não é");
    printf("A string \"%s\" %s um conjunto de caracteres em branco.\n", test_str3, stringBlanks(test_str3) ? "é" : "não é");
    return 0;
}
