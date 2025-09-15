#pragma once

/**
 * @brief Estrutura de um nó da lista duplamente encadeada.
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev) e um ponteiro
 * para o nó seguinte (next). Essa estrutura suporta operações bidirecionais,
 * mas consome mais memória devido aos dois ponteiros por nó.
 */
typedef struct Node
{
    int data;          /**< Valor armazenado no nó */
    struct Node *prev; /**< Ponteiro para o nó anterior */
    struct Node *next; /**< Ponteiro para o próximo nó */
} Node;
