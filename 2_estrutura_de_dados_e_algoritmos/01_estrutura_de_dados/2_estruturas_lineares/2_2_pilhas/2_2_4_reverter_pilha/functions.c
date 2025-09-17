#include "stack.h"

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

/**
 * @brief Função auxiliar para comparar dois valores de acordo com o tipo.
 *
 * @param value1 Primeiro valor a ser comparado.
 * @param value2 Segundo valor a ser comparado.
 * @param type Tipo de dado dos valores.
 * @return -1 se value1 < value2, 0 se value1 == value2, 1 se value1 > value2.
 */
static int compareValues(void *value1, void *value2, DataType type)
{
    switch (type)
    {
    case TYPE_INT:
        if (*(int *)value1 < *(int *)value2)
            return -1;

        if (*(int *)value1 > *(int *)value2)
            return 1;
        return 0;

    case TYPE_CHAR:
        if (*(char *)value1 < *(char *)value2)
            return -1;

        if (*(char *)value1 > *(char *)value2)
            return 1;
        return 0;

    case TYPE_STRING:
        return strcmp((char *)value1, (char *)value2);

    case TYPE_DOUBLE:
        if (*(double *)value1 < *(double *)value2)
            return -1;

        if (*(double *)value1 > *(double *)value2)
            return 1;
        return 0;

    default:
        return 0; // Tipo inválido, considera igual
    }
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
static int readValue(DataType type, void **value)
{
    switch (type)
    {
    case TYPE_INT:
    {
        int *val = malloc(sizeof(int));
        if (val == NULL)
            return 0;

        printf("Digite um valor inteiro: ");
        if (scanf("%d", val) != 1)
        {
            free(val);
            return 0;
        }
        *value = val;
        return 1;
    }
    case TYPE_CHAR:
    {
        char *val = malloc(sizeof(char));
        if (val == NULL)
            return 0;

        printf("Digite um caractere: ");
        scanf(" %c", val); // Espaço para consumir espaços em branco
        *value = val;
        return 1;
    }
    case TYPE_STRING:
    {
        char buffer[256];
        printf("Digite uma string: ");
        scanf(" %255[^\n]", buffer); // Lê string, limite de 255 chars

        char *val = malloc(strlen(buffer) + 1);
        if (val == NULL)
            return 0;

        strcpy(val, buffer);
        *value = val;
        return 1;
    }
    case TYPE_DOUBLE:
    {
        double *val = malloc(sizeof(double));
        if (val == NULL)
            return 0;

        printf("Digite um valor double: ");
        if (scanf("%lf", val) != 1)
        {
            free(val);
            return 0;
        }
        *value = val;
        return 1;
    }

    default:
        return 0;
    }
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

    case TYPE_STRING:
        printf("%s", (char *)value);
        break;

    case TYPE_DOUBLE:
        printf("%.2f", *(double *)value);
        break;
    }
}

void generateStack(Stack **stack)
{
    size_t size = 0;
    printf("Digite o tamanho da pilha: ");
    if (scanf("%zu", &size) != 1 || size == 0)
    {
        printf("O tamanho da pilha deve ser maior que 0.\n");
        return;
    }

    int type_choice = 0;
    printf("Escolha o tipo de dado (0: int, 1: char, 2: string, 3: double): ");
    if (scanf("%d", &type_choice) != 1 || type_choice < 0 || type_choice > 3)
    {
        printf("Tipo de dado inválido.\n");
        return;
    }
    DataType type = (DataType)type_choice;

    for (size_t i = 0; i < size; i++)
    {
        Stack *node = malloc(sizeof(Stack));
        if (node == NULL)
        {
            printf("Erro ao alocar memória para o nó da pilha.\n");
            freeStack(stack); // Libera a pilha parcial em caso de erro
            return;
        }

        void *value;
        printf("Digite o valor para o elemento %zu: ", i);
        if (!readValue(type, &value))
        {
            printf("Erro ao ler valor.\n");
            free(node);
            freeStack(stack);
            return;
        }

        node->value = value;
        node->type = type;
        node->next = *stack;
        *stack = node;

        printf("Valor ");
        printValue(node->value, node->type);
        printf(" ocupa a posição %zu\n", i);
    }
}

void printStack(Stack *stack)
{
    if (stack == NULL)
    {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Topo -> ");
    for (Stack *current = stack; current != NULL; current = current->next)
    {
        printValue(current->value, current->type);
        printf(" -> ");
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
        free(temp->value); // Libera o valor
        free(temp);        // Libera o nó
    }
    *stack = NULL;
}

size_t stackSize(Stack *stack)
{
    size_t count = 0;
    for (Stack *current = stack; current != NULL; current = current->next)
    {
        count++;
    }
    return count;
}

void sortStack(Stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("Pilha vazia ou com apenas um elemento, não é necessário ordenar.\n");
        return;
    }
    DataType type = (*stack)->type;

    Stack *sorted = NULL;
    Stack *current = *stack;

    while (current != NULL)
    {
        Stack *next = current->next;
        if (sorted == NULL || compareValues(current->value, sorted->value, type) >= 0)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Stack *temp = sorted;
            while (temp->next != NULL && compareValues(current->value, temp->next->value, type) < 0)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    *stack = sorted;
    printf("Pilha ordenada em ordem crescente.\n");
}

int searchStack(Stack *stack, void *value, DataType type)
{
    if (stack == NULL)
    {
        return 0;
    }

    if (stack->type != type)
    {
        printf("Tipo de dado da busca não corresponde ao tipo da pilha.\n");
        return 0;
    }

    for (Stack *current = stack; current != NULL; current = current->next)
    {
        if (compareValues(current->value, value, type) == 0)
        {
            return 1;
        }
    }
    return 0;
}
