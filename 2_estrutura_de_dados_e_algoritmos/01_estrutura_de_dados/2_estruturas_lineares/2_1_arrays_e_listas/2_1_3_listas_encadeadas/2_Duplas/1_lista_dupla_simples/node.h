#pragma once

/**
 * @brief Estrutura de um nó da lista duplamente encadeada
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev) e um ponteiro
 * para o nó seguinte (next). Essa estrutura é útil para operações bidirecionais, como
 * percorrimento reverso, mas consome mais memória devido aos dois ponteiros por nó.
 */
typedef struct Node
{
    int data;          /**< O valor armazenado no nó */
    struct Node *next; /**< Ponteiro para o nó seguinte na lista */
    struct Node *prev; /**< Ponteiro para o nó anterior na lista */
} Node;
