#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Definição de uma estrutura chamada `matriz` com um campo inteiro.
 *
 * Esta estrutura é usada para armazenar um valor inteiro. Pode ser utilizada em diversas
 * situações onde é necessário encapsular um valor inteiro dentro de uma estrutura.
 */
struct matriz
{
    int valor;
};

/**
 * @brief Função para criar uma matriz usando a struct
 *
 * Esta função aloca dinamicamente uma matriz de struct matriz com o número especificado
 * de linhas e colunas. Os elementos da matriz são inicializados com o valor zero.
 *
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @return Um ponteiro para a matriz alocada dinamicamente.
 */
struct matriz **criaMatriz(size_t linhas, size_t colunas)
{
    // Alocando espaço para as linhas
    struct matriz **matriz = (struct matriz **)malloc(linhas * sizeof(struct matriz *));

    // Alocando espaço para as colunas em cada linha
    for (size_t i = 0; i < linhas; ++i)
    {
        // Alocando espaço para as colunas
        matriz[i] = (struct matriz *)malloc(colunas * sizeof(struct matriz));
    }

    // Inicializando os elementos da matriz
    for (size_t i = 0; i < linhas; ++i)
    {
        for (size_t j = 0; j < colunas; ++j)
        {
            matriz[i][j].valor = 0; //  Inicializando com zero Ou qualquer valor desejado
        }
    }
    return matriz; // Retornando o ponteiro para a matriz
}

/**
 * @brief Procedimento para imprimir a matriz de forma tradicional.
 *
 * Esta função imprime os valores da matriz utilizando índices de linha e coluna.
 *
 * @param matriz Matriz a ser impressa.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 */
void imprimirMatrizTradicional(struct matriz **matriz, size_t linhas, size_t colunas)
{
    for (size_t i = 0; i < linhas; ++i)
    {
        for (size_t j = 0; j < colunas; ++j)
        {
            printf("%d ", matriz[i][j].valor);
        }
        printf("\n");
    }
}

/**
 * @brief Procedimento para imprimir a matriz utilizando aritmética de ponteiro.
 *
 * Esta função imprime os valores da matriz utilizando aritmética de ponteiro para
 * acessar os elementos.
 *
 * @param matriz Matriz a ser impressa.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 */
void imprimirMatrizAritmetica(struct matriz **matriz, size_t linhas, size_t colunas)
{
    for (size_t i = 0; i < linhas; ++i)
    {
        for (size_t j = 0; j < colunas; ++j)
        {
            printf("%d ", (*((*(matriz + i)) + j)).valor);
        }
        printf("\n");
    }
}

/**
 * @brief Procedimento para liberar a memória alocada para a matriz
 *
 * @param matriz Matriz a ser impressa a ser libera
 * @param linhas Números de linhas da matriz.
 */
void liberarMatriz(struct matriz **matriz, size_t linhas)
{
    // Liberando a memória alocada para cada linha
    for (size_t i = 0; i < linhas; i++)
    {
        // Liberando a memória alocada para cada coluna
        free(matriz[i]);
    }
    free(matriz); // Liberando a memória alocada para as linhas
}

int main(int argc, char **argv)
{
    size_t linhas = 4ULL;
    size_t colunas = 4ULL;

    // Criando a matriz usando a struct
    struct matriz **minhaMatriz = criaMatriz(linhas, colunas);

    // Modificando alguns valores na matriz (apenas para exemplo)
    minhaMatriz[0][0].valor = 0;
    minhaMatriz[0][1].valor = 5;
    minhaMatriz[0][2].valor = 7;
    minhaMatriz[2][2].valor = 2;
    minhaMatriz[2][3].valor = 8;

    // Imprimindo a matriz de forma tradicional
    printf(">>Matriz impressa de forma tradicional<<\n");
    imprimirMatrizTradicional(minhaMatriz, linhas, colunas);

    printf("\n");

    // Imprimindo a matriz utilizando aritmética de ponteiro
    printf(">>Matriz impressa utilizando aritmética de ponteiro<<\n");
    imprimirMatrizAritmetica(minhaMatriz, linhas, colunas);

    // Liberando a memória alocada para a matriz
    liberarMatriz(minhaMatriz, linhas);
    return 0;
}
