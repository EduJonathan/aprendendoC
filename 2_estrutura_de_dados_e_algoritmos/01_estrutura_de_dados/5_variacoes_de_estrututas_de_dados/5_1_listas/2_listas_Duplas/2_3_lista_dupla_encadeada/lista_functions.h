#pragma once

#include "Elemento.h"

/**
 * @brief Estrutura que representa uma lista duplamente encadeada.
 *
 * Contém um ponteiro para o primeiro e o último elemento, além de controlar a quantidade de elementos.
 */
typedef struct list
{
    unsigned int size; /**< Quantidade de elementos na lista */
    Element *first;    /**< Ponteiro para o primeiro elemento da lista */
    Element *last;     /**< Ponteiro para o último elemento da lista */
} List;

/**
 * @brief Cria uma nova lista vazia.
 *
 * Aloca memória para a lista e inicializa seus atributos.
 *
 * @return Ponteiro para a lista recém-criada, ou NULL em caso de falha.
 */
List *list_create(void);

/**
 * @brief Adiciona um novo elemento ao final da lista.
 *
 * Cria um novo elemento com o valor especificado e o insere no final da lista.
 *
 * @param list Ponteiro para a lista onde o elemento será inserido.
 * @param data Valor do elemento a ser adicionado.
 */
void list_append(List *list, int data);

/**
 * @brief Imprime os elementos da lista do início ao fim.
 *
 * Percorre a lista do primeiro para o último elemento e imprime seus valores.
 *
 * @param list Ponteiro para a lista a ser impressa.
 */
void list_print_forward(const List *list);

/**
 * @brief Imprime os elementos da lista do fim ao início.
 *
 * Percorre a lista do último para o primeiro elemento e imprime seus valores.
 *
 * @param list Ponteiro para a lista a ser impressa.
 */
void list_print_reverse(const List *list);

/**
 * @brief Libera toda a memória alocada para a lista e seus elementos.
 *
 * Percorre a lista, libera cada elemento e, em seguida, libera a estrutura da lista.
 *
 * @param list Ponteiro para a lista a ser liberada.
 */
void list_free(List **list);
