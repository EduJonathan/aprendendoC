#pragma once

#define MAX_WEAPON_NAME 20

/**
 * @brief Estrutura que representa um nó da lista circular.
 *
 * Cada nó contém o nome de uma arma e um ponteiro para o próximo nó.
 */
typedef struct Node
{
    char weapon[MAX_WEAPON_NAME]; /**< Nome da arma */
    struct Node *next;            /**< Ponteiro para o próximo nó */
} Node;