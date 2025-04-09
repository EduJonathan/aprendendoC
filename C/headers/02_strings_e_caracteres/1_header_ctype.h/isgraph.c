#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * isgraph(é grafíco): caractere considerado gráfico se for imprimível e não for um espaço em branco.
 *
 * SINTAXE: int isgraph(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for grafico.
 */

/**
 * @brief Verifica se um caractere é um caractere gráfico.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere gráfico
 * (ou seja, qualquer caractere imprimível, exceto espaços em branco).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for gráfico, e falso caso contrário.
 */
bool isGraph(int caractere)
{
    bool is_graph = isgraph((unsigned char)caractere);

    if (is_graph)
    {
        printf(" O caractere '%c' é grafico: %d - %s\n", caractere, is_graph, is_graph ? "true" : "false");
    }
    else
    {
        printf(" O caractere '%c' não é grafico: %d - %s\n", caractere, is_graph, is_graph ? "true" : "false");
    }
    return is_graph;
}

/**
 * @brief Verifica se todos os caracteres de uma string são caracteres gráficos.
 *
 * Esta função verifica se todos os caracteres na string fornecida são caracteres gráficos
 * (ou seja, caracteres imprimíveis, exceto espaços em branco). Retorna verdadeiro se todos os
 * caracteres forem gráficos e falso se algum caractere não for gráfico.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem gráficos.
 * @return false Se algum caractere da string não for gráfico.
 */
bool stringGraficas(const char *str)
{
    while (*str)
    {
        if (!isGraph(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    int var1 = 'd'; // Caractere gráfico
    int var2 = '%'; // Caractere gráfico
    int var3 = ' '; // Espaço em branco (não gráfico)

    isGraph(var1);
    isGraph(var2);
    isGraph(var3);

    printf("\n-----------------------------------------\n");

    const char *str1 = "Hello123!";  // String com apenas caracteres gráficos
    const char *str2 = "Hello 123!"; // String com espaço em branco (não gráfico)

    printf("A string \"%s\" %s apenas caracteres gráficos.\n", str1, stringGraficas(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas caracteres gráficos.\n", str2, stringGraficas(str2) ? "contém" : "não contém");
    return 0;
}
