#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @brief Estrutura que representa uma pilha dinâmica.
 *
 * A pilha é uma estrutura de dados LIFO (Last In, First Out) que armazena
 * elementos em um array dinâmico.
 */
typedef struct Stack
{
    int top;          /**< Índice do topo da pilha. */
    unsigned maxSize; /**< Tamanho máximo da pilha. */
    int *array;       /**< Array dinâmico que armazena os elementos da pilha. */
} Stack;

/**
 * @brief Cria uma pilha com o tamanho especificado.
 *
 * Aloca memória para a pilha e seu array interno. O topo é inicializado como -1.
 *
 * @param maxSize Tamanho máximo da pilha.
 * @return Ponteiro para a pilha criada ou NULL em caso de falha na alocação.
 */
Stack *createStack(unsigned maxSize);

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
 * @brief Insere um item no topo da pilha.
 *
 * Se a pilha estiver cheia ou for NULL, a função não insere o item.
 *
 * @param stack Ponteiro para a pilha.
 * @param item Item a ser inserido.
 */
void push(Stack *stack, int item);

/**
 * @brief Remove e retorna o item do topo da pilha.
 *
 * Se a pilha estiver vazia ou for NULL, retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha.
 * @return Item removido do topo ou INT_MIN se a pilha estiver vazia.
 */
int pop(Stack *stack);

/**
 * @brief Retorna o item do topo da pilha sem removê-lo.
 *
 * Se a pilha estiver vazia ou for NULL, retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha.
 * @return Item no topo da pilha ou INT_MIN se a pilha estiver vazia.
 */
int peek(Stack *stack);

/**
 * @brief Imprime os elementos da pilha.
 *
 * Exibe os elementos da pilha do topo até a base. Se a pilha estiver vazia,
 * exibe uma mensagem apropriada.
 *
 * @param stack Ponteiro para a pilha.
 */
void printStack(Stack *stack);

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Libera o array interno e a estrutura da pilha. Se a pilha for NULL, a função retorna.
 *
 * @param stack Ponteiro para a pilha.
 */
void freeStack(Stack *stack);

/**
 * @brief Ordena os elementos da pilha em ordem crescente.
 *
 * Reorganiza os elementos no array interno da pilha, mantendo o topo no maior valor.
 *
 * @param stack Ponteiro para a pilha.
 */
void sortStack(Stack *stack);

/**
 * @brief Busca um elemento na pilha.
 *
 * Verifica se o valor especificado existe na pilha.
 *
 * @param stack Ponteiro para a pilha.
 * @param value Valor a ser buscado.
 * @return true se o valor for encontrado, false caso contrário ou se a pilha for NULL/vazia.
 */
bool searchStack(Stack *stack, int value);

#endif
