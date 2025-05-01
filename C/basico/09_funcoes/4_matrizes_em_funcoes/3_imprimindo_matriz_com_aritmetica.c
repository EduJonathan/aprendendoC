#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Aloca memória para uma matriz de inteiros com o número especificado de linhas e colunas.
 *
 * Esta função aloca dinamicamente memória para uma matriz de inteiros com o tamanho
 * especificado por `linhas` e `colunas`. Retorna um ponteiro para um array de ponteiros,
 * onde cada ponteiro aponta para um array de inteiros representando uma linha da matriz.
 *
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 * @return Um ponteiro para a matriz alocada.
 *
 * @note A memória alocada deve ser liberada com a função `liberarMatriz` após o uso.
 */
int **alocarMatriz(size_t linhas, size_t colunas)
{
    // Aloca memória para o array de ponteiros para linhas
    int **mat = (int **)malloc(linhas * sizeof(int *));

    // Verifica se a alocação foi bem-sucedida
    if (mat == NULL)
    {
        printf("Memoria Insuficiente");
        exit(1);
    }

    // Aloca memória para cada linha
    for (int i = 0; i < linhas; i++)
    {
        // Aloca memória para a linha
        mat[i] = (int *)malloc(colunas * sizeof(int));

        // Verifica se a alocação foi bem-sucedida para cada linha
        if (mat[i] == NULL)
        {
            printf("Memoria Insuficiente");
            exit(1);
        }
    }
    return mat;
}

/**
 * @brief Imprime uma matriz de inteiros de tamanho especificado.
 *
 * Esta função imprime os elementos de uma matriz de inteiros. Cada linha da matriz
 * é impressa em uma linha separada, com os elementos separados por espaços.
 *
 * @param mat Ponteiro para a matriz de inteiros.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void imprimirMatriz(int **mat, size_t linhas, size_t colunas)
{
    // Converte o array de ponteiros para um único ponteiro
    int *ptr = (int *)mat;

    // Pecorrendo os valores
    for (int i = 0; i < linhas; i++)
    {
        // Imprimindo os valores
        for (int j = 0; j < colunas; j++)
        {
            printf("[%d][%d]: %d ", i, j, *(ptr + i * colunas + j));
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para uma matriz de inteiros.
 *
 * Esta função libera a memória alocada para a matriz e suas linhas. Primeiro
 * libera a memória de cada linha e, em seguida, libera o array de ponteiros para as linhas.
 *
 * @param mat Ponteiro para a matriz de inteiros.
 * @param linhas O número de linhas na matriz.
 */
void liberarMatriz(int **mat, size_t linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        // Libera a memória de cada linha
        free(mat[i]);
    }
    free(mat); // Libera a memória do array de ponteiros para linhas
}

int main(int argc, char **argv)
{
    int **mat = NULL;
    size_t linhas = 2;
    size_t colunas = 2;

    // Aloca memória para a matriz
    mat = alocarMatriz(linhas, colunas);

    // Imprime a matriz utilizando aritmética de ponteiros
    imprimirMatriz(mat, linhas, colunas);

    // Libera a memória alocada para a matriz
    liberarMatriz(mat, linhas);
    return 0;
}
