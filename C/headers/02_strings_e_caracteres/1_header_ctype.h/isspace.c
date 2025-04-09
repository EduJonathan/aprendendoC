#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isspace(é espaço): Imprime na tela espaços, formfeed, newline, return, tab, vertical tab.
 *
 * SINTAXE: int isspace(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for um espaço em branco.
 */

/**
 * @brief Verifica se um caractere é um caractere de espaço em branco.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere de espaço em branco
 * (incluindo espaços, tabulações e quebras de linha).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um caractere de espaço em branco,
 * e falso caso contrário.
 */
bool isSpace(int caractere)
{
    bool is_space = isspace((unsigned char)caractere);

    printf("O caractere '%c' %s um espaço: %d - %s\n", caractere, is_space ? "é" : "não é", is_space, is_space ? "true" : "false");
    return is_space;
}

/**
 * @brief Verifica se todos os caracteres de uma string são caracteres de espaço em branco.
 *
 * Esta função verifica se todos os caracteres na string fornecida são caracteres de espaço
 * em branco. Retorna verdadeiro se todos os caracteres forem espaços em branco e falso se
 * algum caractere não for um espaço em branco.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem caracteres de espaço em branco.
 * @return false Se algum caractere da string não for um caractere de espaço em branco.
 */
bool strDeEspaco(const char *str)
{
    while (*str)
    {
        if (!isSpace(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    int var1 = 'd';   // Letra minúscula (não é espaço)
    int var2 = '2';   // Dígito (não é espaço)
    int var3 = ' ';   // Espaço em branco
    char var4 = '\t'; // Tabulação horizontal (espaço em branco)
    char var5 = '\n'; // Quebra de linha (espaço em branco)

    isSpace(var1);
    isSpace(var2);
    isSpace(var3);
    isSpace(var4);
    isSpace(var5);

    printf("\n-----------------------------------------\n");

    const char *str1 = "   ";  // String com apenas espaços em branco
    const char *str2 = "abc "; // String com caracteres não espaços em branco

    printf("A string \"%s\" %s apenas caracteres de espaço em branco.\n", str1, strDeEspaco(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas caracteres de espaço em branco.\n", str2, strDeEspaco(str2) ? "contém" : "não contém");
    return 0;
}
