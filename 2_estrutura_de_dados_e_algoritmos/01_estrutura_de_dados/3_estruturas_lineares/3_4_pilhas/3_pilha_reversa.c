#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

/**
 * @brief Enum para representar os tipos de dados suportados.
 */
typedef enum
{
    TYPE_INT,    /**< Inteiro */
    TYPE_CHAR,   /**< Caractere */
    TYPE_STRING, /**< Cadeia de caracteres (string) */
    TYPE_DOUBLE  /**< Número de ponto flutuante (double) */
} DataType;

/**
 * @brief Estrutura que representa um nó da pilha encadeada.
 *
 * Contém um ponteiro genérico para o valor, um identificador do tipo
 * e um ponteiro para o próximo nó.
 */
typedef struct Stack
{
    void        *value; /**< Ponteiro para o valor armazenado. */
    DataType     type;  /**< Tipo do valor armazenado. */
    struct Stack *next; /**< Ponteiro para o próximo nó da pilha. */
} Stack;

/**
 * @brief Inverte a ordem dos elementos da pilha.
 *
 * Modifica a pilha “in-place”, invertendo a ordem dos nós.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void reverseStack(Stack **stack)
{
    Stack *prev = NULL, *curr = *stack;

    while (curr)
    {
        Stack *next = curr->next;
        curr->next  = prev;
        prev        = curr;
        curr        = next;
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

/**
 * @brief Gera uma pilha encadeada com valores fornecidos pelo usuário.
 *
 * Lê o tamanho da pilha, o tipo de dado e os valores a serem inseridos,
 * alocando dinamicamente cada nó.
 * Exibe a posição de cada valor inserido (0 é o topo).
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
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
        node->next  = *stack;
        *stack      = node;
    }
}

/**
 * @brief Imprime os elementos da pilha.
 *
 * Mostra os valores da pilha do topo até a base.
 * Se a pilha estiver vazia, exibe uma mensagem.
 *
 * @param stack Ponteiro para o topo da pilha.
 */
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

/**
 * @brief Calcula o tamanho atual da pilha.
 *
 * @param stack Ponteiro para o topo da pilha.
 * @return Número de elementos na pilha.
 */
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

/**
 * @brief Ordena os elementos da pilha em ordem crescente.
 *
 * Reorganiza os nós da pilha, mantendo o maior valor no topo.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
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
            while (cur->next && compareValues(node->value, cur->next->value, type) < 0)
                cur = cur->next;

            node->next = cur->next;
            cur->next = node;
        }
    }
    *stack = sorted;
}

/**
 * @brief Busca um elemento na pilha.
 *
 * Verifica se o valor especificado existe na pilha, respeitando o tipo de dado.
 *
 * @param stack Ponteiro para o topo da pilha.
 * @param value Valor a ser buscado (deve corresponder ao tipo da pilha).
 * @param type Tipo do valor a ser buscado.
 * @return 1 se o valor for encontrado, 0 caso contrário ou se a pilha for vazia/NULL.
 */
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

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Desaloca todos os nós da pilha e define o topo como NULL.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
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

int main(int argc, char **argv)
{
    Stack *stack = NULL;
    int option   = 0;

    printf("Escolha o tipo de dado da pilha:\n");
    printf("0 - int\n");
    printf("1 - char\n");
    printf("2 - string\n");
    printf("3 - double\n");
    printf("> ");

    if (scanf("%d", &option) != 1 || option < 0 || option > 3)
    {
        printf("Tipo inválido.\n");
        return 1;
    }
    getchar(); /* limpa o '\n' */

    DataType type = (DataType)option;

    /* Gera a pilha */
    generateStack(&stack, type);

    printf("\nPilha gerada:\n");
    printStack(stack, type);

    printf("\nTamanho da pilha: %zu\n", stackSize(stack));

    /* Reverte a pilha */
    printf("\nRevertendo a pilha...\n");
    reverseStack(&stack);
    printStack(stack, type);

    /* Ordena a pilha */
    printf("\nOrdenando a pilha (maior no topo)...\n");
    sortStack(&stack, type);
    printStack(stack, type);

    /* Libera memória */
    freeStack(&stack);

    return 0;
}
