#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

Stack *createStack(unsigned maxSize)
{
    if (maxSize == 0)
    {
        printf("Erro: Tamanho da pilha deve ser maior que zero\n");
        return NULL;
    }

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Erro ao alocar memória para a pilha\n");
        return NULL;
    }

    stack->maxSize = maxSize;
    stack->top = -1;
    stack->array = (int *)malloc(maxSize * sizeof(int));
    if (stack->array == NULL)
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
    return stack->top == (int)stack->maxSize - 1;
}

bool isEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        return true;
    }
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (stack == NULL || isFull(stack))
    {
        if (stack != NULL)
        {
            printf("Pilha cheia, não é possível inserir %d\n", item);
        }
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d empilhado\n", item);
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Pilha vazia\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Pilha vazia\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("A pilha está vazia\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = stack->top; i >= 0; --i)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void freeStack(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->array);
    free(stack);
}

void sortStack(Stack *stack)
{
    if (isEmpty(stack) || stack == NULL)
    {
        printf("Pilha vazia ou inválida, não é possível ordenar\n");
        return;
    }

    // Simple bubble sort on the array from index 0 to top
    for (int i = 0; i <= stack->top; i++)
    {
        for (int j = 0; j < stack->top - i; j++)
        {
            if (stack->array[j] > stack->array[j + 1])
            {
                // Swap elements
                int temp = stack->array[j];
                stack->array[j] = stack->array[j + 1];
                stack->array[j + 1] = temp;
            }
        }
    }
    printf("Pilha ordenada em ordem crescente\n");
}

bool searchStack(Stack *stack, int value)
{
    if (isEmpty(stack) || stack == NULL)
    {
        return false;
    }

    for (int i = stack->top; i >= 0; i--)
    {
        if (stack->array[i] == value)
        {
            return true;
        }
    }
    return false;
}
