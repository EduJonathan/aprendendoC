#pragma once
#include "node.h"

/**
 * @brief Libera toda a memória alocada para os nós da lista.
 *
 * Percorre a lista e libera cada nó, definindo o ponteiro da cabeça como NULL.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
void list_free(Node **head);

/**
 * @brief Insere um novo nó no início da lista.
 *
 * Cria um novo nó com o valor especificado e o insere no início da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 */
void list_insert_front(Node **head, int value);

/**
 * @brief Insere um novo nó no final da lista.
 *
 * Cria um novo nó com o valor especificado e o insere no final da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 */
void list_insert_back(Node **head, int value);

/**
 * @brief Insere um novo nó após uma posição específica na lista.
 *
 * Cria um novo nó com o valor especificado e o insere após a posição indicada.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 * @param pos Posição após a qual o novo nó será inserido (começando de 0).
 */
void list_insert_after(Node **head, int value, int pos);

/**
 * @brief Remove o nó do início da lista.
 *
 * Remove o primeiro nó da lista, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
void list_remove_front(Node **head);

/**
 * @brief Remove o nó do final da lista.
 *
 * Remove o último nó da lista, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
void list_remove_back(Node **head);

/**
 * @brief Remove um nó específico com base no valor.
 *
 * Remove o primeiro nó que contém o valor especificado, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor do nó a ser removido.
 */
void list_remove_value(Node **head, int value);

/**
 * @brief Exibe todos os elementos da lista.
 *
 * Percorre a lista e imprime os valores de cada nó em formato bidirecional.
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
void list_print(const Node *head);

/**
 * @brief Exibe o tamanho da lista
 *
 * Pecorre toda a lista para verificar o tamanho da lista
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
int list_size(const Node *head);
