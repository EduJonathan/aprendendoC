#include <stdio.h>

#define MAX_LINHAS 3
#define MAX_COLUNAS 3

/**
 * @brief Estrutura para representar uma matriz.
 *
 * Esta estrutura contém uma matriz bidimensional e suas dimensões.
 */
struct Matriz
{
    int dados[MAX_LINHAS][MAX_COLUNAS]; /**< Matriz de dados. */
    int linhas;                         /**< Número de linhas da matriz. */
    int colunas;                        /**< Número de colunas da matriz. */
};

/**
 * @brief Inicializa a matriz com zeros e define suas dimensões.
 *
 * @param mat Ponteiro para a estrutura Matriz a ser inicializada.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 */
void inicializarMatriz(struct Matriz *mat, int linhas, int colunas)
{
    // Define as dimensões da matriz
    mat->linhas = linhas;
    mat->colunas = colunas;

    // Inicializa todos os elementos da matriz com zero
    for (int i = 0; i < linhas; i++)
    {
        // Percorre todas as colunas
        for (int j = 0; j < colunas; j++)
        {
            // Inicializa com zero
            mat->dados[i][j] = 0;
        }
    }
}

/**
 * @brief Imprime a matriz na tela.
 *
 * @param mat Ponteiro para a estrutura Matriz a ser impressa.
 */
void imprimirMatriz(const struct Matriz *mat)
{
    // Percorre todas as linhas e colunas da matriz
    for (int i = 0; i < mat->linhas; i++)
    {
        // Percorre todas as colunas
        for (int j = 0; j < mat->colunas; j++)
        {
            // Imprime o valor da posição [i][j]
            printf("%d ", mat->dados[i][j]);
        }
        printf("\n"); // Nova linha após imprimir todos os elementos de uma linha
    }
}

/**
 * @brief Imprime a matriz utilizando aritmética de ponteiro.
 *
 * @param mat Ponteiro para a estrutura Matriz a ser impressa.
 */
void imprimirMatrizComPonteiros(const struct Matriz *mat)
{
    // Trata o endereço da matriz como um ponteiro para int
    int *p = (int *)mat->dados;

    // Calcula o número total de elementos na matriz
    size_t totalElementos = mat->linhas * mat->colunas;

    // Percorre todos os elementos da matriz usando aritmética de ponteiros
    for (size_t i = 0ull; i < totalElementos; i++)
    {
        printf("%d ", *(p + i)); // Imprime o valor apontado pelo ponteiro

        // Se chegarmos ao final de uma linha (i.e., múltiplo do número de colunas),
        // imprime uma nova linha
        if ((i + 1) % mat->colunas == 0)
        {
            printf("\n");
        }
    }
}

/**
 * @brief Define um valor em uma posição específica da matriz.
 *
 * @param mat Ponteiro para a estrutura Matriz onde o valor será definido.
 * @param linha Índice da linha onde o valor será definido.
 * @param coluna Índice da coluna onde o valor será definido.
 * @param valor Valor a ser definido na matriz.
 *
 * @note Se os índices estiverem fora dos limites da matriz, uma mensagem de erro será exibida.
 */
void definirValor(struct Matriz *mat, int linha, int coluna, int valor)
{
    // Verifica se os índices fornecidos estão dentro dos limites da matriz
    if (linha < mat->linhas && coluna < mat->colunas)
    {
        // Define o valor na posição [linha][coluna]
        mat->dados[linha][coluna] = valor;
    }
    else
    {
        // Mensagem de erro para índices inválidos
        printf("Índice fora dos limites da matriz.\n");
    }
}

int main(int argc, char **argv)
{
    // Criando uma instância para a struct `Matriz`
    struct Matriz matriz;

    // Inicializa a matriz com o tamanho 3x3
    inicializarMatriz(&matriz, MAX_LINHAS, MAX_COLUNAS);

    // Definindo alguns valores
    definirValor(&matriz, 0, 0, 1);
    definirValor(&matriz, 1, 1, 2);
    definirValor(&matriz, 2, 2, 3);

    // Imprime a matriz
    printf("Matriz:\n");
    imprimirMatriz(&matriz);

    // Imprime a matriz usando aritmética de ponteiro
    printf("Matriz:\n");
    imprimirMatrizComPonteiros(&matriz);
    return 0;
}
