#ifndef GAME_H
#define GAME_H

#include "campo_matriz.h"

typedef struct
{
    Board board;
    char simboloJogador1;
    char simboloJogador2;
    char simboloAtual;
    int jogadas;
    bool vsAI;
    char simboloIA;
} Game;

/**
 * @brief Funções para gerenciar o estado do jogo, escolher modo, símbolo, realizar jogadas e verificar vitória/empate.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 */
void newGame(Game *game);

/**
 * @brief Permite ao jogador escolher o modo de jogo (PvP ou PvIA).
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 */
void escolherModo(Game *game);

/**
 * @brief Permite ao jogador escolher seu símbolo (X ou O) e define os símbolos para ambos os jogadores e IA.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 */
void escolherSimbolo(Game *game);

/**
 * @brief Realiza a jogada do jogador, solicitando linha e coluna, e atualiza o tabuleiro.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 */
void jogar(Game *game);

/**
 * @brief Realiza a jogada da IA usando o algoritmo Minimax para escolher a melhor jogada possível.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 */
void fazerJogadaIA(Game *game);

/**
 * @brief Verifica se o jogador atual venceu o jogo, checando linhas, colunas e diagonais.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 * @return true se o jogador atual venceu, false caso contrário.
 */
bool checarVitoria(const Game *game);

/**
 * @brief Verifica se o jogo terminou em empate, ou seja, se todas as jogadas foram feitas sem um vencedor.
 *
 * @param game Ponteiro para a estrutura Game que contém o estado do jogo.
 * @return true se o jogo terminou em empate, false caso contrário.
 */
bool checarEmpate(const Game *game);

#endif
