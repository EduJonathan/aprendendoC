#include <stdio.h>
#include <stdlib.h>

/*
 * ARRAYS MULTIDIMENSIONAIS: Em C, arrays multidimensionais podem ser tratados como um
 * "ponteiro para ponteiro" (ponteiro para um array de ponteiros), ou como um conceito conhecido
 * como "cadeias de ponteiros" (chains of pointers). Quando declaramos um array multidimensional,
 * o compilador aloca a memória de forma contígua. Isso significa que, embora a estrutura do array
 * seja conceitualmente bidimensional (ou de mais dimensões), os dados são armazenados de forma
 * linear na memória. Podemos acessar os elementos de um array multidimensional de duas maneiras:
 *
 * 1. Usando a notação tradicional de colchetes, por exemplo: `mat[linha][coluna]`.
 * 2. Usando ponteiros, que nos permitem acessar os elementos de forma semelhante,
 * mas com a notação de ponteiros: `*(*(mat + linha) + coluna)`.
 *
 * Para entender melhor o funcionamento da notação com ponteiros, podemos 
 * analisar a expressão: `*(*(mat + linha) + coluna)`:
 *
 * - `mat` é um ponteiro para o primeiro elemento do array, ou seja, um ponteiro 
 * para o primeiro "sub-array" (linha) do array.
 * - `mat + linha` desloca o ponteiro até a linha desejada.
 * - `*(mat + linha)` acessa a linha que foi deslocada e retorna um ponteiro para o
 * primeiro elemento dessa linha.
 * - `*(mat + linha) + coluna` desloca esse ponteiro até a posição da coluna desejada na linha.
 * - Finalmente, `*(*(mat + linha) + coluna)` acessa o valor da célula na posição
 * [linha][coluna] do array.
 *
 * Isso demonstra como é possível acessar os elementos de um array multidimensional
 * utilizando ponteiros de forma eficiente, aproveitando o fato de que os arrays em C
 * são armazenados de maneira contígua na memória.
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
    return 0;
}
