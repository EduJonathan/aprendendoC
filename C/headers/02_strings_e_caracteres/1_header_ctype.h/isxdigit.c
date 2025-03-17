#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isxdigit(é digito): Verifica se um caractere é um dígito hexadecimal.
 *
 * SINTAXE: int isxdigit(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for um dígito hexadecimal.
 */

/**
 * @brief Verifica se um caractere é um dígito hexadecimal.
 *
 * Esta função verifica se o caractere passado como argumento é um dígito hexadecimal
 * (0-9, a-f, A-F).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um dígito hexadecimal, e falso caso contrário.
 */
bool IsXDigit(char caractere) { return isxdigit((unsigned char)caractere); }

/**
 * @brief Verifica se um valor inteiro é representado como um dígito hexadecimal.
 *
 * Esta função verifica se o valor fornecido, tratado como um caractere, é um dígito hexadecimal.
 * Para isso, o valor é mascarado para garantir que apenas o byte menos significativo seja
 * considerado.
 *
 * @param valor Valor inteiro a ser verificado.
 * @return Retorna verdadeiro se o valor (como caractere) for um dígito hexadecimal,
 * e falso caso contrário.
 */
bool IsXDigitInt(int valor) { return isxdigit((unsigned char)(valor & 0xFF)); }

/**
 * @brief Verifica se todos os caracteres de uma string são dígitos hexadecimais.
 *
 * Esta função verifica se todos os caracteres na string fornecida são dígitos hexadecimais.
 * Retorna verdadeiro se todos os caracteres forem dígitos hexadecimais e falso se algum
 * caractere não for um dígito hexadecimal.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem dígitos hexadecimais.
 * @return false Se algum caractere da string não for um dígito hexadecimal.
 */
bool strDigits(const char *str)
{
    while (*str)
    {
        if (!IsXDigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    char var1[] = "Hexadecimal";
    char var2[] = "0xE";
    int hexa1 = 0x80000;
    int hexa2 = 0xFF;

    // Verifica se o primeiro caractere de var1 é um dígito hexadecimal
    bool isx_digit = IsXDigit(var1[0]);
    printf("A variavel '%s' é um caractere hexadecimal: %d - %s\n", var1, isx_digit, isx_digit ? "true" : "falso");

    // Verifica se o primeiro caractere de var2 é um dígito hexadecimal
    isx_digit = IsXDigit(var2[0]);
    printf("A variavel '%s' é um caractere hexadecimal: %d - %s\n", var2, isx_digit, isx_digit ? "true" : "falso");

    // Verifica se o valor hexa1 é um dígito hexadecimal
    isx_digit = IsXDigitInt(hexa1);
    printf("A variavel '%d' é um valor hexadecimal: %d - %s\n", hexa1, isx_digit, isx_digit ? "true" : "falso");

    // Verifica se o valor hexa2 é um dígito hexadecimal
    isx_digit = IsXDigitInt(hexa2);
    printf("A variavel '%d' é um valor hexadecimal: %d - %s\n", hexa2, isx_digit, isx_digit ? "true" : "falso");

    printf("\n-----------------------------------------\n");

    const char *str1 = "0A1B"; // String com apenas dígitos hexadecimais
    const char *str2 = "0A1G"; // String com caracteres não hexadecimais

    printf("A string \"%s\" %s apenas dígitos hexadecimais.\n", str1, strDigits(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas dígitos hexadecimais.\n", str2, strDigits(str2) ? "contém" : "não contém");
    return 0;
}
