#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isalnum(é um alfanúmerico): Verifica e retorna true se o valor for um alfanumerico.
 *
 * SINTAXE: int isalnum(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for alfanúmerico.
 */

/**
 * @brief Verifica se um caractere é alfanumérico.
 *
 * Esta função verifica se o caractere passado como argumento é alfanumérico
 * (ou seja, uma letra ou um dígito).
 *
 * @param caractere Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for alfanumérico, e falso caso contrário.
 */
bool isAlnum(int caractere)
{
    // Verifica se o caractere é alfanumérico
    bool is_alphanumeric = isalnum((unsigned char)caractere);

    // Imprime o resultado
    if (is_alphanumeric)
    {
        printf("O caractere '%c' é alfanumérico: %d - %s\n", caractere, is_alphanumeric, is_alphanumeric ? "true" : "false");
    }
    else
    {
        printf("O caractere '%c' não é alfanumérico: %d - %s\n", caractere, is_alphanumeric, is_alphanumeric ? "true" : "false");
    }
    return is_alphanumeric;
}

/**
 * @brief Verifica se todos os caracteres de uma string são alfanuméricos.
 *
 * Esta função verifica se todos os caracteres na string fornecida são alfanuméricos
 * (ou seja, letras ou dígitos). Retorna verdadeiro se todos os caracteres forem alfanuméricos
 * e falso se algum caractere não for alfanumérico.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem alfanuméricos.
 * @return false Se algum caractere da string não for alfanumérico.
 */
bool stringAlnum(const char *str)
{
    while (*str)
    {
        if (!isAlnum(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **agv)
{
    int var1 = 'd';  // Letra minúscula
    int var2 = '2';  // Dígito
    int var3 = '\t'; // Tabulação horizontal (não alfanumérico)
    int var4 = ' ';  // Espaço em branco (não alfanumérico)

    isAlnum(var1);
    isAlnum(var2);
    isAlnum(var3);
    isAlnum(var4);

    printf("\n-----------------------------------------\n");

    const char *test_str1 = "Hello123";
    const char *test_str2 = "Hello 123";

    printf("A string \"%s\" %s alfanumérica.\n", test_str1, stringAlnum(test_str1) ? "é" : "não é");
    printf("A string \"%s\" %s alfanumérica.\n", test_str2, stringAlnum(test_str2) ? "é" : "não é");
    return 0;
}
