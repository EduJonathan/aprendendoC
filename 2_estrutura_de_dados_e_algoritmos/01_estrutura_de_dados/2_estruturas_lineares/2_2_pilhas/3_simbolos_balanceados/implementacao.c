#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

_Static_assert(sizeof(unsigned char) == 1, "unsigned int deve ter pelo menos 32 bits");

Stack *createStack(unsigned int size)
{
    if (size == 0)
    {
        printf("Erro: Tamanho da pilha deve ser maior que zero\n");
        return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Erro ao alocar memória para a pilha\n");
        return NULL;
    }

    stack->size = size;
    stack->top = -1;
    stack->arr = malloc(size * sizeof(unsigned char));
    if (stack->arr == NULL)
    {
        printf("Erro ao alocar memória para o array da pilha\n");
        free(stack);
        return NULL;
    }

    return stack;
}

bool isFull(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }
    return stack->top == stack->size - 1;
}

bool isEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        return true;
    }
    return stack->top == -1;
}

void push(unsigned char item, Stack *stack)
{
    if (stack == NULL || isFull(stack))
    {
        printf("Pilha cheia, não é possível inserir '%c'\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}

bool pop(unsigned char closing, Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Pilha vazia, não é possível remover '%c'\n", closing);
        return false;
    }

    unsigned char top = stack->arr[stack->top];
    if ((closing == ')' && top == '(') ||
        (closing == '}' && top == '{') ||
        (closing == ']' && top == '['))
    {
        stack->top--;
        return true;
    }
    return false;
}

bool parenthesesMatching(unsigned char *expression, Stack *stack)
{
    if (stack == NULL || expression == NULL)
    {
        printf("Erro: Pilha ou expressão inválida\n");
        return false;
    }

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(expression[i], stack);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (!pop(expression[i], stack))
            {
                printf("Parênteses não balanceados: '%c' sem correspondência\n", expression[i]);
                return false;
            }
        }
    }

    if (!isEmpty(stack))
    {
        printf("Parênteses não balanceados: Há parênteses de abertura sem correspondência\n");
        return false;
    }

    return true;
}

void freeStack(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->arr);
    free(stack);
}
