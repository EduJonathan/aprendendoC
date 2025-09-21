#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

/**
 * islower(é minusculo): Verifica se o caracter é uma letra minúscula.
 *
 * SINTAXE: int islower(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for minúsculo.
 */

/**
 * @brief Verifica se um caractere é uma letra minúscula.
 *
 * Esta função verifica se o caractere passado como argumento é uma letra minúscula.
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for uma letra minúscula, e falso caso contrário.
 */
bool isLower(int caractere)
{
    bool is_lwr = islower((unsigned char)caractere);

    // Imprime o resultado
    printf(" O caractere '%c' %s pontuação: %d - %s\n",
           caractere,
           is_lwr ? "é" : "não é",
           is_lwr,
           is_lwr ? "true" : "false");

    return is_lwr;
}

/**
 * @brief Verifica se todos os caracteres de uma string são minúsculos.
 *
 * Esta função verifica se todos os caracteres na string fornecida são letras minúsculas.
 * Retorna verdadeiro se todos os caracteres forem minúsculos e falso se algum caractere
 * não for minúsculo.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem minúsculos.
 * @return false Se algum caractere da string não for minúsculo.
 */
bool stringMinusculas(const char *str)
{
    while (*str)
    {
        if (!isLower(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int var1 = 'D'; // Letra maiúscula
    int var2 = 'd'; // Letra minúscula
    int var3 = '2'; // Dígito

    isLower(var1);
    isLower(var2);
    isLower(var3);

    printf("\n-----------------------------------------\n");

    const char *str1 = "hello"; // String com apenas letras minúsculas
    const char *str2 = "Hello"; // String com letras maiúsculas

    printf("A string \"%s\" %s apenas letras minúsculas.\n", str1, stringMinusculas(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas letras minúsculas.\n", str2, stringMinusculas(str2) ? "contém" : "não contém");
    return 0;
}
