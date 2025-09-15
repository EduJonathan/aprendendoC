#pragma once

#include "node.h"

/**
 * @brief Insere um nó no início da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido no novo nó.
 */
void list_insert_front(Node **head, int value);

/**
 * @brief Insere um nó no final da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido no novo nó.
 */
void list_insert_back(Node **head, int value);

/**
 * @brief Remove o nó do início da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_remove_front(Node **head);

/**
 * @brief Remove o nó do final da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_remove_back(Node **head);

/**
 * @brief Remove um nó específico com base no valor.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor do nó a ser removido.
 */
void list_remove_value(Node **head, int value);

/**
 * @brief Imprime os elementos da lista.
 *
 * @param head Ponteiro para a cabeça da lista.
 */
void list_print(const Node *head);

/**
 * @brief Libera toda a memória alocada pela lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_free(Node **head);
