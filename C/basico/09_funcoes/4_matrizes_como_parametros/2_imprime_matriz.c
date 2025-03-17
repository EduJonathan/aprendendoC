#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Imprime uma matriz 2D de inteiros.
 *
 * Esta função imprime os elementos de uma matriz 2D de inteiros.
 *
 * @param mat Ponteiro para a matriz.
 * @param linhas Número de linhas na matriz.
 * @param colunas Número de colunas na matriz.
 */
void imprimeMatriz(int *mat, int linhas, int colunas)
{
    // Percorrendo os elementos da matriz
    for (int i = 0; i < linhas; i++)
    {
        // Imprimindo os elementos da linha
        for (int j = 0; j < colunas; j++)
        {
            printf("[%d]x[%d]: %d", i, j, mat[i * colunas + j]);
        }
        printf("\n");
    }
}

/**
 * @brief Aloca, inicializa e libera uma matriz dinâmica de inteiros.
 *
 * Esta função aloca dinamicamente memória para uma matriz de inteiros com o tamanho
 * especificado por `linhas` e `colunas`, inicia a matriz com zeros e imprime-a.
 */
void alocaInicializaLiberaMatriz(void)
{
    // Definindo o tamanho da matriz
    int LINHAS = 2;
    int COLUNAS = 3;

    // Alocando espaço para a matriz
    int *mat = (int *)malloc(LINHAS * COLUNAS * sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (mat == NULL)
    {
        printf("Memória Insuficiente");
        exit(1);
    }

    // Inicializando a matriz
    for (int i = 0; i < LINHAS * COLUNAS; i++)
    {
        // Inicializando todos os elementos da matriz com zero
        mat[i] = i;
    }

    // Imprimindo a matriz
    printf("Matriz:\n");
    imprimeMatriz(mat, LINHAS, COLUNAS);

    printf("Indice: %d\n", mat[0]);
    printf("Indice: %d\n", mat[1]);

    // Liberando a memória alocada
    free(mat);
}

int main(int argc, char **argv)
{
    // Chamando a função para alocar, inicializar e liberar uma matriz
    alocaInicializaLiberaMatriz();
    return 0;
}
