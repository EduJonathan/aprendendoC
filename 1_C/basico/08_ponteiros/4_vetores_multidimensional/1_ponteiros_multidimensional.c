#include <stdio.h>
#include <stdlib.h>

/*
 * ARRAYS MULTIDIMENSIONAIS:
 *
 * Em C, arrays multidimensionais são armazenados em memória de forma CONTÍGUA,
 * mesmo que sejam representados conceitualmente como tabelas (2D) ou cubos (3D).
 * Diferente de “ponteiro para ponteiro”, arrays multidimensionais **não** são
 * compostos por cadeias de ponteiros — a menos que você explicitamente os crie assim.
 *
 * Quando você declara, por exemplo:
 *
 *     int mat[3][4];
 *
 * o compilador aloca 3 * 4 inteiros de maneira sequencial na memória.
 * Nesse caso, `mat` é do tipo “ponteiro para array de 4 inteiros”:
 *
 *     int (*)[4]
 *
 * e **não** `int **`.
 *
 * ACESSO AOS ELEMENTOS:
 *
 * Podemos acessar os elementos de duas formas equivalentes:
 *
 * 1. Via notação tradicional: mat[linha][coluna]
 * 2. Via aritmética de ponteiros: *(*(mat + linha) + coluna)
 *
 * ENTENDENDO A EXPRESSÃO DE PONTEIROS:
 *
 * - `mat` é um ponteiro para o primeiro subarray (primeira linha).
 * - `mat + linha` desloca o ponteiro para a linha desejada.
 * - `*(mat + linha)` acessa essa linha e retorna um ponteiro para seu primeiro elemento.
 * - `*(mat + linha) + coluna` desloca esse ponteiro até a coluna desejada.
 *
 * - Finalmente: *(*(mat + linha) + coluna)
 *   acessa o valor na posição [linha][coluna].
 *
 * Esse mecanismo funciona porque arrays em C são contíguos. Assim, a notação com
 * colchetes e a notação com ponteiros são totalmente equivalentes em arrays
 * multidimensionais declarados de forma estática (ex.: int mat[3][4]).
 *
 * OBSERVAÇÃO:
 * Um array multidimensional **não é** a mesma coisa que um “ponteiro para ponteiro”. Memorize:
 *
 * int mat[3][4]   -->  contíguo na memória, tipo int (*)[4]
 * int **ptr       -->  ponteiro para ponteiro, normalmente usado para
 * matrizes alocadas dinâmica e irregularmente.
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
