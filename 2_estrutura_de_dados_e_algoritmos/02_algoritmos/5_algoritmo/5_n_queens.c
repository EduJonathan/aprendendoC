#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 *
 * @brief Resolução do problema das N-Rainhas utilizando Backtracking.
 *
 * O problema das N-Rainhas (ou N-Queens) consiste em dispor N rainhas em um tabuleiro
 * quadrado de dimensões NxN de modo que nenhuma rainha esteja ameaçada por outra. As rainhas
 * podem se mover nas direções horizontal, vertical e diagonal, portanto, o objetivo é garantir
 * que não haja duas rainhas na mesma linha, coluna ou diagonal.
 *
 * No caso de N=8, o tabuleiro é 8x8, e a solução consiste em colocar 8 rainhas
 * de forma que nenhuma delas se ataque.
 *
 * Este algoritmo utiliza **Backtracking** (retorno atrás) para testar todas as possíveis
 * colocações das rainhas no tabuleiro. Caso uma posição não seja segura, a função volta para
 * a etapa anterior e tenta uma nova solução. Este processo continua até que todas as rainhas
 * sejam colocadas de forma segura ou até que todas as possibilidades sejam esgotadas.
 *
 * A ideia do Backtracking é explorar todas as possibilidades e descartar cedo as que
 * não podem dar certo. Aplicações comuns: Problema das N-rainhas, Sudoku,
 * Geração de permutações/combi­nações, Maze solver (labirinto).
 */

/**
 * @brief Função para embaralhar um array de inteiros (Fisher-Yates shuffle).
 *
 * @param array Array a ser embaralhado
 * @param size Tamanho do array
 */
void shuffle(int *array, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j    = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * @brief Função para imprimir a solução do tabuleiro.
 *
 * @param board Tabuleiro de xadrez (matriz dinâmica)
 * @param n Tamanho do tabuleiro
 */
void printResolucao(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é seguro colocar uma rainha na posição [linha][coluna].
 *
 * @param board Tabuleiro de xadrez
 * @param n Tamanho do tabuleiro
 * @param linha Linha onde a rainha será colocada
 * @param coluna Coluna onde a rainha será colocada
 * @return true Se é seguro colocar a rainha
 * @return false Se não for seguro
 */
bool isSafe(int **board, int n, int linha, int coluna)
{
    for (int i = 0; i < coluna; i++)
    {
        if (board[linha][i])
        {
            return false;
        }
    }

    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = linha, j = coluna; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Função recursiva para resolver o problema das N rainhas com escolha aleatória.
 *
 * @param board Tabuleiro de xadrez
 * @param n Tamanho do tabuleiro
 * @param col Coluna atual
 * @return true Se uma solução foi encontrada
 * @return false Se não for possível resolver
 */
bool solveNQueens(int **board, int n, int col)
{
    if (col >= n)
        return true; // Todas as rainhas foram colocadas

    // Cria lista de linhas e embaralha para tentar ordem aleatória
    int *rows = malloc(n * sizeof(int));
    if (!rows)
        return false;

    for (int i = 0; i < n; i++)
        rows[i] = i;

    shuffle(rows, n);

    for (int i = 0; i < n; i++)
    {
        int row = rows[i];

        if (isSafe(board, n, row, col))
        {
            board[row][col] = 1; // Coloca a rainha

            if (solveNQueens(board, n, col + 1))
            {
                free(rows);
                return true;
            }

            board[row][col] = 0; // Backtracking (remove a rainha)
        }
    }

    free(rows);
    return false;
}

/**
 * @brief Cria e inicializa o tabuleiro dinamicamente.
 *
 * @param n Tamanho do tabuleiro
 * @return Ponteiro para o tabuleiro alocado, ou NULL em caso de falha
 */
int **createBoard(int n)
{
    if (n <= 0)
        return NULL;

    int **board = malloc(n * sizeof(int *));
    if (!board)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        board[i] = malloc(n * sizeof(int));
        if (!board[i])
        {
            // Libera memória parcial em caso de falha
            for (int j = 0; j < i; j++)
                free(board[j]);
            free(board);
            return NULL;
        }
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    return board;
}

/**
 * @brief Libera a memória do tabuleiro.
 *
 * @param board Tabuleiro de xadrez
 * @param n Tamanho do tabuleiro
 */
void freeBoard(int **board, int n)
{
    if (!board)
        return;

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
}

/**
 * @brief Função principal para resolver o problema das N rainhas.
 *
 * @param n Tamanho do tabuleiro
 * @return true Se uma solução foi encontrada
 * @return false Se não houver solução
 */
bool solveNQueensProblem(int n)
{
    if (n < 1 || n > 20)
    { 
        // Limite prático (acima de 15 fica muito lento)
        printf("Erro: N deve estar entre 1 e 20.\n");
        return false;
    }

    int **board = createBoard(n);
    if (!board)
    {
        printf("Erro: Falha ao alocar memória para o tabuleiro.\n");
        return false;
    }

    printf("Tentando resolver o problema das %d-Rainhas...\n", n);

    if (solveNQueens(board, n, 0))
    {
        printBoard(board, n);
        freeBoard(board, n);
        return true;
    }
    else
    {
        printf("Não existe solução para N = %d\n", n);
        freeBoard(board, n);
        return false;
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));        // Inicializa gerador de números aleatórios

    int n = 8;
    solveNQueensProblem(n);

    // Exemplos adicionais (descomente se quiser testar):
    // solveNQueensProblem(4);
    // solveNQueensProblem(5);
    // solveNQueensProblem(6);
    return 0;
}
