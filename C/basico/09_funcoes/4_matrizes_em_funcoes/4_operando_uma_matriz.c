#include <stdio.h>

/**
 * @brief Realiza a soma de duas matrizes e imprime o resultado.
 *
 * Esta função solicita ao usuário as dimensões de duas matrizes e seus
 * elementos, realiza a soma das matrizes e imprime a matriz resultante.
 * As matrizes de entrada são recebidas como parâmetros e os elementos são
 * acessados utilizando aritmética de ponteiros.
 *
 * @param matrizA Ponteiro para a primeira matriz.
 * @param matrizB Ponteiro para a segunda matriz.
 * @param linhas Número de linhas das matrizes.
 * @param colunas Número de colunas das matrizes.
 */
void somandoDuasMatrizes(int (*matrizA)[2], int (*matrizB)[2], size_t linhas, size_t colunas)
{
    // Preenchendo a primeira matriz
    printf("Digite os elementos da primeira matriz:\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("Digite o valor de [%zu]x[%zu] para a primeira matriz: ", i, j);
            // Solicitando ao usuário o valor para cada posição específica
            // scanf("%d", &matrizB[i][j]);

            // Utilizando aritmética de ponteiro para acessar e preencher os elementos
            scanf("%d", (*(matrizA + i) + j));
        }
    }

    printf("----------------------------------------\n");

    // Preenchendo a segunda matriz
    printf("Digite os elementos da segunda matriz:\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("Digite o valor de [%zu]x[%zu] para a segunda matriz: ", i, j);
            // Solicitando ao usuário o valor para cada posição específica
            // scanf("%d", &matrizB[i][j]);

            // Utilizando aritmética de ponteiro para acessar e preencher os elementos
            scanf("%d", (*(matrizB + i) + j));
        }
    }

    printf("----------------------------------------\n");

    // Realizando a soma das matrizes
    int adicao[2][2]; // Matriz de soma

    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            // adicao[i][j] = matrizA[i][j] + matrizB[i][j];
            // Aritmética de ponteiros para realizar a soma
            *(*(adicao + i) + j) = *(*(matrizA + i) + j) + *(*(matrizB + i) + j);
        }
    }

    // Imprimindo a matriz resultado
    printf("A soma resultante das matrizes A e B:\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            // printf("%d ", adicao[i][j]);
            // Aritmética de ponteiros para imprimir a matriz
            printf("%d ", *(*(adicao + i) + j));
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    // Definição das matrizes
    int matriz1[2][2], matriz2[2][2];

    // Definição das dimensões com size_t
    size_t linhas = 2,
           colunas = 2;

    somandoDuasMatrizes(matriz1, matriz2, linhas, colunas);
    return 0;
}
