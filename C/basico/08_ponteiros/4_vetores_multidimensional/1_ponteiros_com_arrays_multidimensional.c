#include <stdio.h>
#include <stdlib.h>

/*
 * ARRAY MULTIDIMENSIONAIS: Em C, pode ser tratado como um ponteiro para ponteiro (ponteiro
 * para array de ponteiros) ou o conceito de chains of pointer. Quando se declara um array
 * multidimensional, o compilador aloca a memória de forma contígua na memória e pode-se
 * usar ponteiros para acessar os elementos de um array multidimensional usando a notação
 * tradicional de colchetes(mat[linha][coluna]) ou a notação por ponteiros:
 * *(*(mat + linha) + coluna) Para entender melhor o que está acontecendo,
 * vamos trocar *(mat + linha) por um valor X. Desse modo, a expressão fica *(X + coluna)
 */

int main(int argc, char **argv)
{
    printf("\n\t>>EXEMPLO 1<<\n");

    // Declara e inicializa uma matriz 2x2
    int mat[2][2] = {{1, 2},
                     {3, 4}};

    // Declara um ponteiro para o primeiro elemento da matriz
    int *p = &mat[0][0];

    // Laço para percorrer os 4 elementos da matriz
    for (int i = 0; i < 4; i++)
    {
        // Acessa e imprime o i-ésimo elemento da matriz usando o ponteiro
        // p[i] é equivalente a *(p + i)
        printf("%d\n", p[i]);
    }

    printf("\n");

    // Outro laço para percorrer os 4 elementos da matriz
    for (int i = 0; i < 4; i++)
    {
        // Acessa e imprime o i-ésimo elemento da matriz usando aritmética de ponteiros
        // *(p + i) é equivalente a p[i]
        printf("%d\n", *(p + i));
    }

    printf("\n=============================================================================\n");
    printf("\n\t>>EXEMPLO 2<<\n");

    // Declaração e inicialização de uma matriz bidimensional
    int matriz[3][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}};

    int linhas = 3;
    int colunas = 4;

    // Ponteiro para ponteiro (ponteiro para array de ponteiros)
    int **ptrMatriz = NULL;

    // Alocação de memória para os ponteiros de linha
    ptrMatriz = (int **)malloc(linhas * sizeof(int *));

    // Alocação de memória para cada linha
    for (int i = 0; i < linhas; i++)
    {
        ptrMatriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Inicialização da matriz e impressão dos elementos usando ponteiros
    printf("Elementos da matriz:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            ptrMatriz[i][j] = matriz[i][j];
            printf("%d ", ptrMatriz[i][j]);
        }
        printf("\n");
    }

    // Inicialização da matriz e impressão dos elementos usando ponteiros
    printf("Elementos da matriz usando aritmética de ponteiros:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            *(*(ptrMatriz + i) + j) = *(*(matriz + i) + j);
            printf("%d ", *(*(ptrMatriz + i) + j));
        }
        printf("\n");
    }

    // Liberação de memória
    for (int i = 0; i < linhas; i++)
    {
        free(ptrMatriz[i]);
    }
    free(ptrMatriz);

    /*
     * ptrMatriz é declarado como um ponteiro para ponteiro (int **). Memória é
     * alocada para os ponteiros de linha. Para cada linha, memória é alocada para
     * armazenar os elementos daquela linha. A matriz está sendo inicializada com
     * valores da matriz estática e os elementos são impressos usando ponteiros.
     * A memória alocada dinamicamente é liberada no final do programa. Neste exemplo
     * demonstra como usar ponteiros para arrays de ponteiros para manipular uma matriz
     * bidimensional em C. Certifique-se de liberar a memória alocada dinamicamente para
     * evitar vazamentos de memória.
     */
    return 0;
}
