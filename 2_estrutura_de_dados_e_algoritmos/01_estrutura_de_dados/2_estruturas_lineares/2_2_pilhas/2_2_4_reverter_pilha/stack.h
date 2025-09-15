#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó da pilha encadeada.
 *
 * Contém um valor inteiro e um ponteiro para o próximo nó da pilha.
 */
typedef struct Stack
{
    int value;          /**< Valor armazenado no nó. */
    struct Stack *next; /**< Ponteiro para o próximo nó da pilha. */
} Stack;

/**
 * @brief Gera uma pilha encadeada com valores fornecidos pelo usuário.
 *
 * Lê o tamanho da pilha e os valores a serem inseridos, alocando dinamicamente cada nó.
 * Exibe a posição de cada valor inserido (0 é o topo).
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void generateStack(Stack **stack);

/**
 * @brief Imprime os elementos da pilha.
 *
 * Exibe os valores da pilha do topo até a base. Se a pilha estiver vazia, exibe uma mensagem.
 *
 * @param stack Ponteiro para o topo da pilha.
 */
void printStack(Stack *stack);

/**
 * @brief Reverte a ordem dos elementos da pilha.
 *
 * Modifica a pilha in-place, invertendo a ordem dos nós.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void reverseStack(Stack **stack);

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Desaloca todos os nós da pilha e define o topo como NULL.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void freeStack(Stack **stack);

/**
 * @brief Calcula o tamanho atual da pilha.
 *
 * @param stack Ponteiro para o topo da pilha.
 * @return Número de elementos na pilha.
 */
size_t stackSize(Stack *stack);

#endif
