#ifndef FUNCOES_DA_PILHA_H
#define FUNCOES_DA_PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "struct_da_pilha.h"

/**
 * @brief Função que cria uma pilha
 *
 * A função createStack() cria uma pilha com o tamanho especificado e
 * inicia o topo da pilha como -1. Retorna um ponteiro para a pilha criada.
 *
 * @param maxSize Tamanho da pilha
 * @return Ponteiro para a pilha
 */
struct Stack *createStack(unsigned maxSize)
{
    // Aloca memória para a pilha
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    // Verifica se a alocação de memória para a pilha não foi bem-sucedida
    if (stack == NULL)
    {
        printf("Erro ao alocar memória para a pilha\n");
        exit(1); // Termina o programa em caso de erro de alocação
    }

    stack->maxSize = maxSize;                                   // Define o tamanho da pilha
    stack->top = -1;                                            // Inicia o topo da pilha como -1
    stack->array = (int *)malloc(stack->maxSize * sizeof(int)); // Aloca memória para o array da pilha

    // Verifica se a alocação de memória para o array da pilha foi não foi bem-sucedida
    if (stack->array == NULL)
    {
        printf("Erro ao alocar memória para o array da pilha\n");
        free(stack);
        exit(1);
    }

    // Retorna um ponteiro para a pilha
    return stack;
}

/**
 * @brief Função que verifica se a pilha esta cheia
 *
 * A função isFull() verifica se a pilha esta cheia.
 * Retorna 1 se a pilha estiver cheia e 0 caso contrario.
 *
 * @param stack Ponteiro para a pilha
 * @return 1 se a pilha estiver cheia e 0 caso contrario
 */
int isFull(struct Stack *stack)
{
    // Verifica se o topo da pilha  -1
    return stack->top == stack->maxSize - 1;
}

/**
 * @brief Função que verifica se a pilha esta vazia
 *
 * A função isEmpty() verifica se a pilha esta vazia.
 * Retorna 1 se a pilha estiver vazia e 0 caso contrario.
 *
 * @param stack Ponteiro para a pilha
 * @return 1 se a pilha estiver vazia e 0 caso contrario
 */
int isEmpty(struct Stack *stack)
{
    // Verifica se o topo da pilha -1
    if (stack == NULL)
    {
        return true;
    }

    // Verifica se o topo da pilha -1
    return stack->top == -1;
}

/**
 * @brief Função que insere um item na pilha
 *
 * A função push() insere um item na pilha. Se a pilha estiver cheia,
 * a funcão retorna sem inserir o item na pilha.
 *
 * @param stack Ponteiro para a pilha
 * @param item Item a ser inserido na pilha
 * @return void
 */
void push(struct Stack *stack, int item)
{
    if (stack == NULL)
    {
        return; // Verifica se a pilha é válida
    }
    if (isFull(stack))
    {
        return; // Verifica se a pilha está cheia
    }

    // Insere o item na pilha
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

/**
 * @brief Função que remove um item da pilha
 *
 * A função pop() remove um item da pilha. Se a pilha estiver vazia,
 * a funcão retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha
 * @return Retorna o item removido da pilha
 */
int pop(struct Stack *stack)
{
    // Verifica se a pilha estiver vazia
    if (isEmpty(stack))
    {
        // Se estiver vazia, retorna INT_MIN(Valor: -2147483648)
        return INT_MIN;
    }

    // Retorna o item removido da pilha
    return stack->array[stack->top--];
}

/**
 * @brief Função que retorna o item do topo da pilha
 *
 * A função peek() retorna o item do topo da pilha. Se a pilha estiver vazia,
 * a funcão retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha
 * @return Retorna o item do topo da pilha
 */
int peek(struct Stack *stack)
{
    if (stack == NULL)
    {
        return INT_MIN;
    }
    if (isEmpty(stack))
    {
        return INT_MIN;
    }

    // Retorna o item do topo da pilha
    return stack->array[stack->top];
}

/**
 * @brief Função que imprime os elementos da pilha
 *
 * A função printStack() imprime os elementos da pilha. Se a pilha estiver vazia,
 * a funcão imprime "Stack is empty".
 *
 * @param stack Ponteiro para a pilha
 * @return void
 */
void printStack(struct Stack *stack)
{
    // Verifica se a pilha estiver vazia
    if (isEmpty(stack))
    {
        printf("A pilha está vazia\n");
        return;
    }

    // Imprime os elementos da pilha
    printf("Os elementos da pilha são: ");

    // Percorre os elementos da pilha
    for (int i = stack->top; i >= 0; --i)
    {
        printf("%d ", stack->array[i]);
    }

    printf("\n");
}

/**
 * @brief Função que libera a memória alocada para a pilha
 *
 * A função freeStack() libera a memória alocada para a pilha. Se a pilha for
 * nula, a função simplesmente retorna.
 *
 * @param stack Ponteiro para a pilha
 * @return void
 */
void freeStack(struct Stack *stack)
{
    // Verifica se a pilha está vazia
    if (stack == NULL)
    {
        return;
    }

    // Libera memória alocada para a pilha
    free(stack->array);
    free(stack);
}

#endif
