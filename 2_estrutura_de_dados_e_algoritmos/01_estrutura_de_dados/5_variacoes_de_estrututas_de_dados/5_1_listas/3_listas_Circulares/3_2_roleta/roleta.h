#pragma once

#include "node.h"

/**
 * @brief Estrutura que representa a roleta de armas.
 *
 * A roleta é uma lista circular onde cada nó contém o nome de uma arma.
 * O ponteiro atual indica a arma selecionada.
 */
typedef struct WeaponRoulette
{
    Node *current; /**< Ponteiro para o nó atual (arma selecionada) */
} WeaponRoulette;

/**
 * @brief Cria um novo nó contendo o nome de uma arma.
 *
 * Aloca memória dinamicamente para um nó e inicializa com o nome da arma.
 *
 * @param weapon Nome da arma a ser armazenado no nó.
 * @return Ponteiro para o nó recém-criado, ou NULL em caso de falha.
 */
Node *node_create(const char *weapon);

/**
 * @brief Inicializa a roleta de armas com uma lista circular.
 *
 * Cria uma lista circular com os nomes das armas fornecidas no array.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette a ser inicializada.
 * @param weapons Array de strings com os nomes das armas.
 * @param num_weapons Número de armas a serem adicionadas na roleta.
 */
void roulette_init(WeaponRoulette *roulette, const char *weapons[], int num_weapons);

/**
 * @brief Move a roleta para a esquerda (próximo nó).
 *
 * Atualiza o ponteiro atual para o próximo nó na lista circular.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_move_left(WeaponRoulette *roulette);

/**
 * @brief Move a roleta para a direita (nó anterior).
 *
 * Atualiza o ponteiro atual para o nó anterior na lista circular.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_move_right(WeaponRoulette *roulette);

/**
 * @brief Exibe o conteúdo da roleta de armas.
 *
 * Exibe todos os nomes das armas na roleta, destacando a arma atualmente selecionada.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_print(const WeaponRoulette *roulette);

/**
 * @brief Libera a memória alocada para a roleta de armas.
 *
 * Percorre todos os nós da lista circular e libera a memória de cada um.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette a ser liberada.
 */
void roulette_free(WeaponRoulette *roulette);
