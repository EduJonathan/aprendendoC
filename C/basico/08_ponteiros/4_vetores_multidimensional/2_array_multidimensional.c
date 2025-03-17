#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("\n\t>>EXEMPLO 01\n");

    // Criando uma matriz 3x4
    int matriz[3][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}};

    // Usando size_t para armazenar o número de linhas e colunas
    size_t linhas = 3ULL;
    size_t colunas = 4ULL;

    // Usando ponteiro para armazenar a matriz
    int *ptrMatriz = &matriz[0][0];

    // Imprimindo os elementos da matriz tradicionalmente
    printf("NÃO UTILIZANDO A ARITMÉTICA DE PONTEIROS\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    putchar('\n');

    // Imprimindo os elementos da matriz usando a aritmética de ponteiros
    printf("ELEMENTOS DA MATRIZ UTILIZANDO A ARITMÉTICA DE PONTEIROS\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("%d ", *(ptrMatriz + i * colunas + j));
        }
        printf("\n");
    }

    /*
    printf("Elementos da matriz utilizando a aritmetica de ponteiros:\n");
    for (int i = 0; i < linhas * colunas; ++i)
    {
        printf("%d ", *(ptrMatriz + i));
        if ((i + 1) % colunas == 0)
        {
            printf("\n");
        }
    }*/

    /*
     * ptrMatriz é um ponteiro para o primeiro elemento da matriz. Para acessar
     * um elemento específico, você utiliza a aritmética de ponteiros.
     * A expressão *(ptrMatriz + i * colunas + j) acessa o elemento na linha i e coluna
     * j da matriz.
     */

    printf("\n=============================================================================\n");
    printf("\n\t>>EXEMPLO 02<<\n");

    /*
     * Se você estiver lidando com uma matriz bidimensional dinamicamente alocada,
     * você pode usar um ponteiro para ponteiro (int **) para representar a matriz
     */

    // Variáveis para armazenar o número de linhas e colunas
    int rows = 3;
    int columns = 4;

    // Alocação dinâmica para a matriz e Aloca um array de ponteiros para int.
    // Cada ponteiro irá apontar para uma linha da matriz.
    int **matrizDinamica = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        matrizDinamica[i] = (int *)malloc(columns * sizeof(int));
    }

    // Inicialização da matriz
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrizDinamica[i][j] = i * columns + j + 1;
        }
    }

    // Impressão da matriz
    printf("ELEMENTOS DA MATRIZ DINÂMICA\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrizDinamica[i][j]);
        }
        printf("\n");
    }

    putchar('\n');

    // Impressão da matriz usando ponteiro
    printf("ELEMENTOS DA MATRIZ DINÂMICA USANDO ARITMETICA DE PONTEIROS\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", *(*(matrizDinamica + i) + j));
        }
        printf("\n");
    }

    // Liberação de memória
    for (int i = 0; i < rows; i++)
    {
        free(matrizDinamica[i]);
    }
    free(matrizDinamica);
    return 0;
}
