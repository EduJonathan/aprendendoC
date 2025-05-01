#include <stdio.h>
#include <stdlib.h> // Para rand() e srand() que geram números aleatórios
#include <time.h>   // Para time() que inicializa a semente de números aleatórios

#define LINHAS 5
#define COLUNAS 5

/**
 * @brief Soma os elementos de cada linha da matriz e armazena em um vetor.
 *
 * @param matriz A matriz cujas linhas serão somadas.
 * @param somaLinhas O vetor onde as somas das linhas serão armazenadas.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void somandoLinhasMatriz(int (*matriz)[COLUNAS], int *somaLinhas, size_t linhas, size_t colunas)
{
    for (size_t i = 0; i < linhas; i++)
    {
        somaLinhas[i] = 0; // Inicializa a soma da linha como zero
        for (size_t j = 0; j < colunas; j++)
        {
            // Ambas as formas funcionam:
            // somaLinhas[i] += matriz[i][j]; // Tradicional
            somaLinhas[i] += *(*(matriz + i) + j); // Aritmética de ponteiro
        }
    }

    // Listar somas das linhas
    for (size_t i = 0; i < linhas; i++)
    {
        printf("A soma da linha %zu é: %d\n", i, somaLinhas[i]);
    }
}

/**
 * @brief Imprime a matriz na tela.
 *
 * @param matriz A matriz a ser impressa.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void imprimirMatriz(int (*matriz)[COLUNAS], size_t linhas, size_t colunas)
{
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            // Ambas as formas funcionam:
            // printf("%2d ", matriz[i][j]); // Tradicional
            printf("%2d ", *(*(matriz + i) + j)); // Aritmética de ponteiro
        }
        printf("\n");
    }
}

/**
 * @brief Soma os elementos de cada coluna da matriz e armazena em um vetor.
 *
 * @param matriz A matriz cujas colunas serão somadas.
 * @param somaColunas O vetor onde as somas das colunas serão armazenadas.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void somarColunasMatriz(int (*matriz)[COLUNAS], int *somaColunas, size_t linhas, size_t colunas)
{
    for (size_t i = 0; i < colunas; i++) // i = índice da coluna
    {
        somaColunas[i] = 0;                 // Inicializa a soma da coluna i como zero
        for (size_t j = 0; j < linhas; j++) // j = índice da linha
        {
            // Soma o elemento na linha j, coluna i
            // somaColunas[i] += matriz[j][i]; // Forma tradicional
            somaColunas[i] += *(*(matriz + j) + i); // Aritmética de ponteiros
        }
    }

    // Imprime as somas das colunas
    for (size_t i = 0; i < colunas; i++)
    {
        printf("A soma da coluna %zu é: %d\n", i, somaColunas[i]);
    }
}

int main(int argc, char **argv)
{
    int matriz[LINHAS][COLUNAS];
    int somaLinhas[LINHAS] = {0}; // Vetor para armazenar as somas

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    // Preenche a matriz com números aleatórios de 0 a 9
    for (size_t linha = 0; linha < LINHAS; linha++)
    {
        for (size_t coluna = 0; coluna < COLUNAS; coluna++)
        {
            matriz[linha][coluna] = rand() % 10;
        }
    }

    printf("Matriz:\n");
    imprimirMatriz(matriz, LINHAS, COLUNAS);

    printf("\nSomas das linhas:\n");
    somandoLinhasMatriz(matriz, somaLinhas, LINHAS, COLUNAS);

    printf("\nSomas das colunas:\n");
    somarColunasMatriz(matriz, somaLinhas, LINHAS, COLUNAS);
    return 0;
}
