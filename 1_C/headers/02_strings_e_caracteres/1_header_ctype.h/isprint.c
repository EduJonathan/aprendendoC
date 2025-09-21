#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

/**
 * isprint(é printavél): imprime qualquer caractere incluindo também o espaço,
 * porém não inclui o caractere de controle: caractere especiais.
 *
 * SINTAXE: int isprint(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for printável.
 */

/**
 * @brief Verifica se um caractere é imprimível.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere imprimível
 * (ou seja, um caractere que pode ser exibido na tela) usando a função isprint da biblioteca C.
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for imprimível, e falso caso contrário.
 */
bool isPrintavel(int caractere)
{
    bool is_print = isprint((unsigned char)caractere);

    // Imprime o resultado
    printf(" O caractere '%c' %s pontuação: %d - %s\n",
           caractere,
           is_print ? "é" : "não é",
           is_print,
           is_print ? "true" : "false");

    return is_print;
}

/**
 * @brief Verifica se todos os caracteres de uma string são imprimíveis.
 *
 * Esta função verifica se todos os caracteres na string fornecida são imprimíveis.
 * Retorna verdadeiro se todos os caracteres forem imprimíveis e falso se algum caractere
 * não for imprimível.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem imprimíveis.
 * @return false Se algum caractere da string não for imprimível.
 */
bool stringDeCaracteresPrintaveis(const char *str)
{
    while (*str)
    {
        if (!isPrintavel(*str))
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

    int var1 = 'k';  // Letra minúscula (imprimível)
    int var2 = '2';  // Dígito (imprimível)
    int var3 = '\t'; // Tabulação horizontal (não imprimível)
    int var4 = ' ';  // Espaço em branco (imprimível)

    isPrintavel(var1);
    isPrintavel(var2);
    isPrintavel(var3);
    isPrintavel(var4);

    printf("\n-----------------------------------------\n");

    const char *str1 = "Hello, 123!";  // String com apenas caracteres imprimíveis
    const char *str2 = "Hello\tWorld"; // String com caractere não imprimível (tabulação)

    printf("\nA string \"%s\" %s apenas caracteres imprimíveis.\n", str1, stringDeCaracteresPrintaveis(str1) ? "contém" : "não contém");
    printf("\nA string \"%s\" %s apenas caracteres imprimíveis.\n", str2, stringDeCaracteresPrintaveis(str2) ? "contém" : "não contém");
    return 0;
}
