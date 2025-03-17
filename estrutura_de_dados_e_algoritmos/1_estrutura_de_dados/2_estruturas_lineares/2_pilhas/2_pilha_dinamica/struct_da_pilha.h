#ifndef STRUCT_DA_PILHA_H
#define STRUCT_DA_PILHA_H

#ifndef STACK_H
#define STACK_H

/**
 * @brief Estrutura da pilha
 *
 * Definição da estrutura da pilha
 */
struct Stack
{
    int top;          /**< Indica o topo da pilha */
    unsigned maxSize; /**< Indica o tamanho da pilha */
    int *array;       /**< Indica o array da pilha */
};

#endif

struct Stack *createStack(unsigned maxSize);
int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, int item);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
void printStack(struct Stack *stack);

#endif
