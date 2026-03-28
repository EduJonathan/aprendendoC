#pragma once

/**
 * @brief Estrutura que representa um elemento da lista duplamente encadeada.
 *
 * Cada elemento contém um valor (data) e ponteiros para o próximo e o anterior elemento.
 */
typedef struct element
{
    int data;             /**< Valor armazenado no elemento */
    struct element *next; /**< Ponteiro para o próximo elemento */
    struct element *prev; /**< Ponteiro para o elemento anterior */
} Element;
