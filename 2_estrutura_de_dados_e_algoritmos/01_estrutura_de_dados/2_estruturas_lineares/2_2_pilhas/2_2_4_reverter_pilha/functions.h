#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

void generateStack(Stack **stack)
{
    size_t size = 0ull;
    printf("Digite o tamanho da pilha: ");
    if (scanf("%zu", &size) != 1 || size == 0)
    {
        printf("O tamanho da pilha deve ser maior que 0.\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        Stack *node = malloc(sizeof(Stack));
        if (node == NULL)
        {
            printf("Erro ao alocar memória para o nó da pilha.\n");
            freeStack(stack); // Libera a pilha parcial em caso de erro
            return;
        }

        printf("Digite o valor para o elemento %zu: ", i);
        if (scanf("%d", &node->value) != 1)
        {
            printf("Erro ao ler o valor.\n");
            free(node);
            freeStack(stack);
            return;
        }
        printf("Valor %d ocupa a posição %zu\n", node->value, i);

        node->next = *stack;
        *stack = node;
    }
}

void printStack(Stack *stack)
{
    if (stack == NULL)
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Topo -> ");
    for (Stack *current = stack; current != NULL; current = current->next)
    {
        printf("%d -> ", current->value);
    }
    printf("NULL\n");
}

void reverseStack(Stack **stack)
{
    Stack *prev = NULL;
    Stack *current = *stack;
    Stack *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *stack = prev;
}

void freeStack(Stack **stack)
{
    Stack *current = *stack;
    while (current != NULL)
    {
        Stack *temp = current;
        current = current->next;
        free(temp);
    }
    *stack = NULL;
}

size_t stackSize(Stack *stack)
{
    size_t count = 0ull;
    for (Stack *current = stack; current != NULL; current = current->next)
    {
        count++;
    }
    return count;
}
