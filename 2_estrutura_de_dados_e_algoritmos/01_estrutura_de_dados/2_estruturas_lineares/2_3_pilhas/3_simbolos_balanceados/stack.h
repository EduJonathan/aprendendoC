#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @brief Estrutura de pilha para armazenar caracteres.
 *
 * Representa uma pilha dinâmica para verificar balanceamento de parênteses,
 * colchetes e chaves em uma expressão (LIFO).
 */
typedef struct stack
{
    unsigned int size;  /**< Tamanho máximo da pilha. */
    unsigned int top;   /**< Índice do topo da pilha. */
    unsigned char *arr; /**< Array dinâmico que armazena os elementos da pilha. */
} Stack;

/**
 * @brief Cria uma pilha com o tamanho especificado.
 *
 * Aloca memória para a pilha e seu array interno. O topo é inicializado como -1.
 *
 * @param size Tamanho máximo da pilha.
 * @return Ponteiro para a pilha criada ou NULL em caso de falha na alocação.
 */
Stack *createStack(unsigned int size);

/**
 * @brief Verifica se a pilha está cheia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver cheia, false caso contrário.
 */
bool isFull(Stack *stack);

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver vazia ou NULL, false caso contrário.
 */
bool isEmpty(Stack *stack);

/**
 * @brief Insere um caractere no topo da pilha.
 *
 * Se a pilha estiver cheia, exibe uma mensagem e não insere o caractere.
 *
 * @param item Caractere a ser inserido (ex.: '(', '{', '[').
 * @param stack Ponteiro para a pilha.
 */
void push(unsigned char item, Stack *stack);

/**
 * @brief Remove o caractere do topo da pilha se corresponder ao esperado.
 *
 * Verifica se o caractere de fechamento corresponde ao topo da pilha.
 * Se corresponder, remove o topo; caso contrário, não faz nada.
 *
 * @param closing Caractere de fechamento (ex.: ')', '}', ']').
 * @param stack Ponteiro para a pilha.
 * @return true se o caractere foi removido, false caso contrário.
 */
bool pop(unsigned char closing, Stack *stack);

/**
 * @brief Verifica o balanceamento de parênteses, colchetes e chaves.
 *
 * Analisa uma string para verificar se os parênteses, colchetes e chaves
 * estão balanceados (cada abertura tem um fechamento correspondente).
 *
 * @param expression String contendo a expressão a ser verificada.
 * @param stack Ponteiro para a pilha.
 * @return true se a expressão estiver balanceada, false caso contrário.
 */
bool parenthesesMatching(unsigned char *expression, Stack *stack);

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Libera o array interno e a estrutura da pilha. Se a pilha for NULL, a função retorna.
 *
 * @param stack Ponteiro para a pilha.
 */
void freeStack(Stack *stack);

#endif
