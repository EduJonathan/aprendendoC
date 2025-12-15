#pragma once

#include <stdbool.h>
#include "node.h"

/**
 * @brief Verifica se a lista circular está vazia.
 *
 * @param head Ponteiro para a cabeça da lista.
 * @return bool Verdadeiro se a lista está vazia, falso caso contrário.
 */
bool list_is_empty(const Node *head);

/**
 * @brief Insere um elemento no início da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 */
void list_insert_front(Node **head, int value);

/**
 * @brief Insere um elemento no final da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 */
void list_insert_back(Node **head, int value);

/**
 * @brief Insere um elemento em uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 * @param position Posição onde o valor deve ser inserido (começando de 0).
 */
void list_insert_at(Node **head, int value, int position);

/**
 * @brief Remove o primeiro nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_remove_front(Node **head);

/**
 * @brief Remove o último nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_remove_back(Node **head);

/**
 * @brief Remove um nó em uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param position Posição do nó a ser removido (começando de 0).
 */
void list_remove_at(Node **head, int position);

/**
 * @brief Busca um elemento na lista circular.
 *
 * @param head Ponteiro para a cabeça da lista.
 * @param value Valor a ser buscado.
 * @return bool Verdadeiro se o valor for encontrado, falso caso contrário.
 */
bool list_search(const Node *head, int value);

/**
 * @brief Exibe todos os elementos da lista circular.
 *
 * @param head Ponteiro para a cabeça da lista.
 */
void list_print(const Node *head);

/**
 * @brief Libera a memória de todos os nós da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_free(Node **head);
