#include <stdio.h>
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

#define N 8

/**
 * @brief Função para imprimir a solução do tabuleiro.
 *
 * @param board Tabuleiro de xadrez com a posição das rainhas (1 para rainha, 0 para vazio).
 */
void printResolucao(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se é seguro colocar uma rainha na posição [linha][coluna].
 *
 * A função verifica se não há outra rainha na mesma linha, na mesma coluna ou nas diagonais.
 *
 * @param board Tabuleiro de xadrez com a posição das rainhas.
 * @param linha Linha onde a rainha será colocada.
 * @param coluna Coluna onde a rainha será colocada.
 * @return true Se é seguro colocar a rainha.
 * @return false Se não for seguro colocar a rainha.
 */
bool isSafe(int board[N][N], int linha, int coluna)
{
    int i = 0, j = 0;

    // Verifica a linha à esquerda
    for (i = 0; i < coluna; i++)
    {
        if (board[linha][i])
        {
            return false;
        }
    }

    // Verifica diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Verifica diagonal inferior esquerda
    for (i = linha, j = coluna; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Função recursiva para resolver o problema das N rainhas.
 *
 * A função tenta colocar uma rainha em todas as linhas de uma coluna e,
 * em caso de sucesso, tenta a próxima coluna. Se a posição não for válida, faz o backtracking
 * e tenta outras opções.
 *
 * @param board Tabuleiro de xadrez com as posições das rainhas.
 * @param coluna Coluna onde a rainha será colocada.
 * @return true Se foi possível resolver para todas as colunas.
 * @return false Se não for possível resolver a partir da coluna atual.
 */
bool resolucaoNQueen(int board[N][N], int coluna)
{
    // Caso base: todas as rainhas foram posicionadas
    if (coluna >= N)
    {
        return true;
    }

    // Tenta colocar a rainha em todas as linhas desta coluna
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, coluna))
        {
            // Coloca a rainha
            board[i][coluna] = 1;

            // Recursão para as próximas colunas
            if (resolucaoNQueen(board, coluna + 1))
            {
                return true;
            }

            // Backtracking: remove a rainha se não levar à solução
            board[i][coluna] = 0;
        }
    }

    // Se não encontrou posição válida nesta coluna
    return false;
}

/**
 * @brief Função principal que inicializa o tabuleiro e chama a função de resolução.
 *
 * @return true Se uma solução foi encontrada.
 * @return false Se não houver solução possível.
 */
bool resolucaoBacktracking()
{
    int board[N][N] = {{0}}; // Inicializa o tabuleiro com 0s

    if (!resolucaoNQueen(board, 0))
    {
        printf("Não há solução\n");
        return false;
    }

    printResolucao(board);
    return true;
}

int main(int argc, char **argv)
{
    resolucaoBacktracking();
    return 0;
}
