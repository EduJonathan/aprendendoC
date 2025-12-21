#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

void reverseStack(Stack **stack)
{
    Stack *prev = NULL, *curr = *stack;

    while (curr)
    {
        Stack *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *stack = prev;
}

static char *stringDuplicate(const char *src)
{
    size_t len = strlen(src) + 1;
    char *dest = (char *)malloc(len);
    if (!dest)
        return NULL;
    memcpy(dest, src, len);
    return dest;
}

/**
 * @brief Função auxiliar para comparar dois valores de acordo com o tipo.
 *
 * @param value1 Primeiro valor a ser comparado.
 * @param value2 Segundo valor a ser comparado.
 * @param type Tipo de dado dos valores.
 * @return -1 se value1 < value2, 0 se value1 == value2, 1 se value1 > value2.
 */
static int compareValues(const void *a, const void *b, DataType type)
{
    switch (type)
    {
    case TYPE_INT:
        return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);

    case TYPE_CHAR:
        return (*(char *)a > *(char *)b) - (*(char *)a < *(char *)b);

    case TYPE_DOUBLE:
        return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);

    case TYPE_STRING:
        return strcmp((char *)a, (char *)b);
    }
    return 0;
}

static int readLine(char *buffer, size_t size)
{
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

/**
 * @brief Função auxiliar para ler um valor de acordo com o tipo de dado.
 *
 * Aloca memória para o valor e o lê do usuário.
 *
 * @param type Tipo de dado do valor.
 * @param value Ponteiro para armazenar o valor alocado.
 * @return 1 em caso de sucesso, 0 em caso de falha.
 */
static void *readValue(DataType type)
{
    char buffer[BUFFER_SIZE];

    if (!readLine(buffer, sizeof(buffer)))
        return NULL;

    switch (type)
    {
    case TYPE_INT:
    {
        int *v = (int *)malloc(sizeof(int));
        if (!v || sscanf(buffer, "%d", v) != 1)
        {
            free(v);
            return NULL;
        }
        return v;
    }

    case TYPE_CHAR:
    {
        char *v = (char *)malloc(sizeof(char));
        if (!v || buffer[0] == '\0')
        {
            free(v);
            return NULL;
        }
        *v = buffer[0];
        return v;
    }

    case TYPE_DOUBLE:
    {
        double *v = (double *)malloc(sizeof(double));
        if (!v || sscanf(buffer, "%lf", v) != 1)
        {
            free(v);
            return NULL;
        }
        return v;
    }

    case TYPE_STRING:
        return stringDuplicate(buffer);
    }

    return NULL;
}

/**
 * @brief Função auxiliar para imprimir um valor de acordo com seu tipo.
 *
 * @param value Ponteiro para o valor.
 * @param type Tipo de dado do valor.
 */
static void printValue(void *value, DataType type)
{
    switch (type)
    {
    case TYPE_INT:
        printf("%d", *(int *)value);
        break;

    case TYPE_CHAR:
        printf("%c", *(char *)value);
        break;

    case TYPE_DOUBLE:
        printf("%.2f", *(double *)value);
        break;

    case TYPE_STRING:
        printf("%s", (char *)value);
        break;
    }
}

/* ================= IMPLEMENTAÇÃO DA PILHA ================= */

void generateStack(Stack **stack, DataType type)
{
    size_t size = 0ull;
    printf("Tamanho da pilha: ");
    scanf("%zu", &size);
    getchar(); /* limpa '\n' */

    for (size_t i = 0; i < size; i++)
    {
        printf("Valor %zu: ", i);

        void *value = readValue(type);
        if (!value)
        {
            printf("Entrada inválida.\n");
            freeStack(stack);
            return;
        }

        Stack *node = (Stack *)malloc(sizeof(Stack));

        if (!node)
        {
            free(value);
            freeStack(stack);
            return;
        }

        node->value = value;
        node->next = *stack;
        *stack = node;
    }
}

void printStack(const Stack *stack, DataType type)
{
    if (!stack)
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Topo -> ");
    while (stack)
    {
        printValue(stack->value, type);
        printf(" -> ");
        stack = stack->next;
    }
    printf("NULL\n");
}

size_t stackSize(const Stack *stack)
{
    size_t count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

void sortStack(Stack **stack, DataType type)
{
    Stack *sorted = NULL;

    while (*stack)
    {
        Stack *node = *stack;
        *stack = node->next;

        if (!sorted || compareValues(node->value, sorted->value, type) >= 0)
        {
            node->next = sorted;
            sorted = node;
        }
        else
        {
            Stack *cur = sorted;
            while (cur->next &&
                   compareValues(node->value, cur->next->value, type) < 0)
                cur = cur->next;

            node->next = cur->next;
            cur->next = node;
        }
    }
    *stack = sorted;
}

int searchStack(const Stack *stack, const void *value, DataType type)
{
    while (stack)
    {
        if (compareValues(stack->value, value, type) == 0)
            return 1;
        stack = stack->next;
    }
    return 0;
}

void freeStack(Stack **stack)
{
    while (*stack)
    {
        Stack *tmp = *stack;
        *stack = tmp->next;
        free(tmp->value);
        free(tmp);
    }
}
