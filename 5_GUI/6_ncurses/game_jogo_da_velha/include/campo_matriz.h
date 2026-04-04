#ifndef CAMPO_MATRIZ_H
#define CAMPO_MATRIZ_H

#include <stdbool.h>

#define BOARD_SIZE 3

typedef char Board[BOARD_SIZE][BOARD_SIZE];

/**
 * @brief Inicializa o tabuleiro do jogo da velha, preenchendo-o com espaços em branco.
 *
 * @param board O tabuleiro a ser inicializado.
 */
void inicializarTabuleiro(Board board);

/**
 * @brief Imprime o tabuleiro do jogo da velha na saída padrão.
 *
 * @param board O tabuleiro a ser impresso.
 */
void imprimirTabuleiro(Board board);

/**
 * @brief Atualiza o campo do tabuleiro com o símbolo do jogador.
 *
 * @param board O tabuleiro a ser atualizado.
 * @param linha A linha do campo a ser atualizado.
 * @param coluna A coluna do campo a ser atualizado.
 * @param simbolo O símbolo a ser colocado no campo.
 */
void atualizarCampo(Board board, int linha, int coluna, char simbolo);

/**
 * @brief Verifica se o campo do tabuleiro está vazio.
 *
 * @param board O tabuleiro a ser verificado.
 * @param linha A linha do campo a ser verificado.
 * @param coluna A coluna do campo a ser verificado.
 * @return true se o campo estiver vazio, false caso contrário.
 */
bool campoVazio(Board board, int linha, int coluna);

/**
 * @brief Verifica se o campo do tabuleiro é válido para uma jogada.
 *
 * @param linha A linha do campo a ser verificado.
 * @param coluna A coluna do campo a ser verificado.
 * @return true se o campo for válido, false caso contrário.
 */
bool campoValido(int linha, int coluna);

#endif
