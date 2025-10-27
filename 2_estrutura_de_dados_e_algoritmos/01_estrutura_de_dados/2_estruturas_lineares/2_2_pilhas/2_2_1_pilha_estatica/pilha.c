#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

_Static_assert(STACK_SIZE > 0, "O Tamanho Da Pilha deve ser positivo");

int push(int items[], int top, int item)
{
    if (top == STACK_SIZE - 1)
    {
        printf("Pilha cheia\n");
        return top;
    }
    items[++top] = item;
    return top;
}

bool is_empty(int top)
{
    return top == -1;
}

int pop(int items[], int top)
{
    if (is_empty(top))
    {
        printf("Pilha vazia\n");
        return top;
    }
    top--;
    return top;
}

int stack_top(int items[], int top)
{
    if (is_empty(top))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    return items[top];
}

void print_stack(int items[], int top)
{
    if (is_empty(top))
    {
        printf("Pilha vazia\n");
        return;
    }
    
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", items[i]);
    }
}
