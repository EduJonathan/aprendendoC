#pragma once

/**
 * @brief Estrutura para representar um nó de uma lista circular.
 *
 * Cada nó contém um valor e um ponteiro para o próximo nó, formando um ciclo contínuo
 * onde o último nó aponta para o primeiro.
 */
typedef struct Node
{
    int value;         /**< Valor armazenado no nó */
    struct Node *next; /**< Ponteiro para o próximo nó */
} Node;
