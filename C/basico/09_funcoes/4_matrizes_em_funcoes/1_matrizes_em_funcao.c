#include <stdio.h>

/**
 * @brief Imprime uma matriz
 *
 * Este procedimento percorre uma matriz de inteiros e imprime ele.
 *
 * @param matriz Parâmetro que recebe uma matriz
 * @param linhas Recebe a dimensão de linhas de uma matriz
 * @param colunas Recebe a dimensão de colunas de uma matriz
 */
void imprimeMatriz(int matriz[][3], size_t linhas, size_t colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf(" [%d]x[%d] = %d ", i, j, matriz[i][j]);
        }
        printf("\n");
    }
}

/*
 * Ao declarar uma função como um parâmetro que representa uma matriz em C, a quantidade
 * de colunas deve ser especificada na declaração da função para indicar ao compilador o
 * número fixo de colunas que cada linha da matriz terá. A razão para isso está na forma
 * como a linguagem C lida com matrizes multidimensionais.
 */

int main(int argc, char **argv)
{
    // Criando uma matriz de inteiro 2x3
    int minhaMatriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // Extraindo quantidade de linhas
    size_t linhas = sizeof(minhaMatriz) / sizeof(minhaMatriz[0]);

    // Extraindo quantidade de colunas
    size_t colunas = sizeof(minhaMatriz[0]) / sizeof(minhaMatriz[0][0]);

    // Chamando a função e passando a matriz e suas dimensões
    imprimeMatriz(minhaMatriz, linhas, colunas);
    return 0;
}
