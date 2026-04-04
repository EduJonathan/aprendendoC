#include "../include/game.h"
#include "../include/campo_matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Funções para gerenciar o estado do jogo, escolher modo, símbolo, realizar jogadas e verificar vitória/empate.
 *
 * @param b Tabuleiro do jogo.
 * @param s Símbolo do jogador.
 */
static bool checarLinhas(const Board b, char s)
{
    for (int i = 0; i < 3; i++)
    {
        if (b[i][0] == s && b[i][1] == s && b[i][2] == s)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Função para verificar se o jogador venceu checando as colunas do tabuleiro.
 *
 * @param b Tabuleiro do jogo.
 * @param s Símbolo do jogador.
 * @return true se o jogador venceu, false caso contrário.
 */
static bool checarColunas(const Board b, char s)
{
    for (int j = 0; j < 3; j++)
    {
        if (b[0][j] == s && b[1][j] == s && b[2][j] == s)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Função para verificar se o jogador venceu checando as diagonais do tabuleiro.
 *
 * @param b Tabuleiro do jogo.
 * @param s Símbolo do jogador.
 * @return true se o jogador venceu, false caso contrário.
 */
static bool checarDiagonais(const Board b, char s)
{
    return (b[0][0] == s && b[1][1] == s && b[2][2] == s) || (b[0][2] == s && b[1][1] == s && b[2][0] == s);
}

bool checarVitoria(const Game *game)
{
    char s = game->simboloAtual;
    return checarLinhas(game->board, s) || checarColunas(game->board, s) || checarDiagonais(game->board, s);
}

bool checarEmpate(const Game *game)
{
    return game->jogadas == 9;
}

void newGame(Game *game)
{
    inicializarTabuleiro(game->board);
    game->simboloJogador1 = game->simboloJogador2 = game->simboloAtual = ' ';
    game->jogadas         = 0;
    game->vsAI            = false;
    game->simboloIA       = ' ';
}

void escolherModo(Game *game)
{
    int op = 0;
    do
    {
        printf("\n=== JOGO DA VELHA ===\n");
        printf("1 - Jogador vs Jogador\n");
        printf("2 - Jogador vs IA (imbatível)\n");
        printf("Escolha: ");
        scanf("%d", &op);
    } while (op < 1 || op > 2);
    game->vsAI = (op == 2);
}

void escolherSimbolo(Game *game)
{
    char c = '\0';
    do
    {
        printf("Jogador, escolha seu símbolo (X ou O): ");
        scanf(" %c", &c);
        c = toupper(c);
    } while (c != 'X' && c != 'O');

    game->simboloJogador1 = c;
    game->simboloJogador2 = (c == 'X') ? 'O' : 'X';
    game->simboloAtual    = game->simboloJogador1;

    if (game->vsAI)
    {
        game->simboloIA = game->simboloJogador2; // IA joga com o outro símbolo
    }
}

/**
 * @brief Função de avaliação para o algoritmo Minimax, atribuindo pontuações para vitórias, derrotas e empates.
 *
 * @param board Tabuleiro do jogo.
 * @param ai Símbolo da IA.
 * @param human Símbolo do jogador humano.
 * @return 10 para vitória da IA, -10 para vitória do humano, 0 para empate ou jogo em andamento.
 */
static int avaliar(const Board board, char ai, char human)
{
    if (checarLinhas(board, ai) || checarColunas(board, ai) || checarDiagonais(board, ai))
        return 10;

    if (checarLinhas(board, human) || checarColunas(board, human) || checarDiagonais(board, human))
        return -10;
    return 0;
}

/**
 * @brief Função recursiva do algoritmo Minimax para determinar a melhor jogada para a IA, considerando todas as possibilidades futuras.
 *
 * @param board Tabuleiro do jogo.
 * @param isMaximizing Indica se a função está maximizando (IA) ou minimizando (humano).
 * @param ai Símbolo da IA.
 * @param human Símbolo do jogador humano.
 * @return A pontuação da melhor jogada encontrada.
 */
static int minimax(Board board, bool isMaximizing, char ai, char human)
{
    int score = avaliar(board, ai, human);
    if (score == 10 || score == -10)
        return score;

    bool full = true;
    for (int i = 0; i < 3 && full; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                full = false;
                break;
            }
        }
    }

    if (full)
        return 0;

    if (isMaximizing)
    {
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = ai;
                    int val = minimax(board, false, ai, human);
                    board[i][j] = ' ';
                    if (val > best)
                    {
                        best = val;
                    }
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = human;
                    int val = minimax(board, true, ai, human);
                    board[i][j] = ' ';
                    if (val < best)
                    {
                        best = val;
                    }
                }
            }
        }
        return best;
    }
}

void fazerJogadaIA(Game *game)
{
    char ai    = game->simboloIA;
    char human = (ai == game->simboloJogador1) ? game->simboloJogador2 : game->simboloJogador1;

    int bestScore = -1000;
    int bestRow   = -1,
        bestCol   = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game->board[i][j] == ' ')
            {
                game->board[i][j] = ai;
                int score = minimax(game->board, false, ai, human);
                game->board[i][j] = ' ';

                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    if (bestRow != -1)
    {
        atualizarCampo(game->board, bestRow, bestCol, ai);
        game->jogadas++;
    }
}

void jogar(Game *game)
{
    int linha  = 0,
        coluna = 0;
        
    const char *nome = (game->simboloAtual == game->simboloJogador1) ? "Jogador" : "Jogador 2";

    do
    {
        printf("%s (%c), linha e coluna (1-3): ", nome, game->simboloAtual);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;
    } while (!campoValido(linha, coluna) || !campoVazio(game->board, linha, coluna));

    atualizarCampo(game->board, linha, coluna, game->simboloAtual);
    game->jogadas++;
}
