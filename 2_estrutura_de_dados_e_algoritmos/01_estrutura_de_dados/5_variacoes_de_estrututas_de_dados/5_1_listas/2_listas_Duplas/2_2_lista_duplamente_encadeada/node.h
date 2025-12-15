#pragma once

/**
 * @brief Estrutura de um nó da lista duplamente encadeada.
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev) e um ponteiro
 * para o nó seguinte (next). Essa estrutura suporta operações bidirecionais,
 * mas consome mais memória devido aos dois ponteiros por nó.
 */
typedef struct node
{
    int data;          /**< Valor armazenado no nó */
    struct node *prev; /**< Ponteiro para o nó anterior */
    struct node *next; /**< Ponteiro para o próximo nó */
} Node;
