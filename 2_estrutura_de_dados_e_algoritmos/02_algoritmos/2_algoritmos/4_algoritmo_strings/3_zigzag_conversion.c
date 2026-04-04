#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ZigZag é um tipo de algoritmo backtacking que pode ser usado para resolver problemas de permutação e combinação,
 * onde a ordem dos elementos é importante. O exemplo a seguir implementa a conversão de uma string em um formato zigzag,
 * onde os caracteres são escritos em um padrão diagonal e depois lidos linha por linha para formar a string resultante.
 */

/**
 * @brief Converte string para formato zigzag
 *
 * NÃO é backtracking. É um algoritmo de simulação/iteração que distribui caracteres em linhas seguindo um padrão de "serpente".
 *
 * @param s String de entrada
 * @param numRows Número de linhas do padrão
 * @return String no formato zigzag
 */
char *convert(char *s, int numRows)
{
    // Caso base: se for 1 linha ou a string for menor que as linhas, retorna a original
    int len = strlen(s);
    if (numRows <= 1 || numRows >= len)
    {
        char *res = (char *)malloc((len + 1) * sizeof(char));
        strcpy(res, s);
        return res;
    }

    // Criamos um array de strings (buffers). Para simplificar e evitar múltiplas realocações, cada linha pode ter até 'len' caracteres
    char **rows   = (char **)malloc(numRows * sizeof(char *));
    int *rowSizes = (int *)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++)
    {
        rows[i] = (char *)malloc((len + 1) * sizeof(char));
    }

    int i = 0;
    while (i < len)
    {
        // Movimento vertical para baixo
        for (int j = 0; j < numRows && i < len; j++)
        {
            rows[j][rowSizes[j]++] = s[i++];
        }

        // Movimento diagonal para cima
        for (int j = numRows - 2; j > 0 && i < len; j--)
        {
            rows[j][rowSizes[j]++] = s[i++];
        }
    }

    // Concatenar tudo na primeira linha (ou em um novo buffer)
    char *result = (char *)malloc((len + 1) * sizeof(char));
    int pos = 0;
    for (int k = 0; k < numRows; k++)
    {
        for (int l = 0; l < rowSizes[k]; l++)
        {
            result[pos++] = rows[k][l];
        }
        free(rows[k]); // Liberando memória das linhas individuais
    }
    result[pos] = '\0'; // Finalizador de string

    free(rows);
    free(rowSizes);

    return result;
}

int main(int argc, char **argv)
{
    char *s      = "Parafraseando";
    int  numRows = 3;
    char *result = convert(s, numRows);

    printf("%s\n", result);
    free(result);
    return 0;
}
