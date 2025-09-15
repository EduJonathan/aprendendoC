#pragma once

/**
 * @brief Estrutura que representa um elemento da lista duplamente encadeada.
 *
 * Cada elemento contém um valor (data) e ponteiros para o próximo e o anterior elemento.
 */
typedef struct Element
{
    int data;             /**< Valor armazenado no elemento */
    struct Element *next; /**< Ponteiro para o próximo elemento */
    struct Element *prev; /**< Ponteiro para o elemento anterior */
} Element;
