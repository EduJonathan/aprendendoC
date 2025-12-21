#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 10 /**< Tamanho máximo da pilha. */

/**
 * @brief Adiciona um item no topo da pilha.
 *
 * A função `push` insere um item na pilha. Se a pilha estiver cheia, exibe uma mensagem
 * e retorna o topo sem alterações.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha. Inicialmente é -1.
 * @param item Item a ser inserido na pilha.
 * @return Novo índice do topo da pilha após a inserção.
 */
int push(int items[], int top, int item);

/**
 * @brief Verifica se a pilha está vazia.
 *
 * A função `is_empty` verifica se a pilha está vazia com base no índice do topo.
 *
 * @param top Índice do topo da pilha.
 * @return true se a pilha estiver vazia, false caso contrário.
 */
bool is_empty(int top);

/**
 * @brief Remove o item do topo da pilha.
 *
 * A função `pop` remove o item do topo da pilha. Se a pilha estiver vazia, exibe uma
 * mensagem e retorna o topo sem alterações.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha. Inicialmente é -1.
 * @return Novo índice do topo da pilha após a remoção.
 */
int pop(int items[], int top);

/**
 * @brief Obtém o item no topo da pilha sem removê-lo.
 *
 * A função `stack_top` retorna o item no topo da pilha sem removê-lo. Se a pilha estiver
 * vazia, exibe uma mensagem e retorna -1.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha.
 * @return Item no topo da pilha ou -1 se a pilha estiver vazia.
 */
int stack_top(int items[], int top);

/**
 * @brief Exibe todos os itens da pilha.
 *
 * A função exibe os itens da pilha do topo até a base. Se a pilha estiver vazia,
 * exibe uma mensagem correspondente.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha.
 */
void print_stack(int items[], int top);

#endif
