#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de pilha para armazenar caracteres.
 *
 * Representa uma pilha dinâmica para verificar balanceamento de parênteses,
 * colchetes e chaves em uma expressão (LIFO).
 */
typedef struct stack
{
    unsigned int  size;  /**< Tamanho máximo da pilha. */
    unsigned int  top;   /**< Índice do topo da pilha. */
    unsigned char *arr; /**< Array dinâmico que armazena os elementos da pilha. */
} Stack;

_Static_assert(sizeof(unsigned char) == 1, "unsigned int deve ter pelo menos 32 bits");

/**
 * @brief Cria uma pilha com o tamanho especificado.
 *
 * Aloca memória para a pilha e seu array interno. O topo é inicializado como -1.
 *
 * @param size Tamanho máximo da pilha.
 * @return Ponteiro para a pilha criada ou NULL em caso de falha na alocação.
 */
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
    stack->top  = -1;
    stack->arr  = malloc(size * sizeof(unsigned char));
    if (stack->arr == NULL)
    {
        printf("Erro ao alocar memória para o array da pilha\n");
        free(stack);
        return NULL;
    }

    return stack;
}

/**
 * @brief Verifica se a pilha está cheia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver cheia, false caso contrário.
 */
bool isFull(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }
    return stack->top == stack->size - 1;
}

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver vazia ou NULL, false caso contrário.
 */
bool isEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        return true;
    }
    return stack->top == -1;
}

/**
 * @brief Insere um caractere no topo da pilha.
 *
 * Se a pilha estiver cheia, exibe uma mensagem e não insere o caractere.
 *
 * @param item Caractere a ser inserido (ex.: '(', '{', '[').
 * @param stack Ponteiro para a pilha.
 */
void push(unsigned char item, Stack *stack)
{
    if (stack == NULL || isFull(stack))
    {
        printf("Pilha cheia, não é possível inserir '%c'\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}

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

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Libera o array interno e a estrutura da pilha. Se a pilha for NULL, a função retorna.
 *
 * @param stack Ponteiro para a pilha.
 */
void freeStack(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->arr);
    free(stack);
}

int main(int argc, char **argv)
{
    Stack *stack = createStack(100);
    if (stack == NULL)
    {
        return 1;
    }

    unsigned char expression[100] = {0};
    printf("Entre com uma expressão (ex.: \"(([]{}))\"): ");
    // scanf("%99[^\n]", expression);
    fgets(expression, sizeof(expression), stdin);

    if (parenthesesMatching(expression, stack))
    {
        printf("Parênteses estão balanceados\n");
    }
    else
    {
        printf("Parênteses não estão balanceados\n");
    }

    freeStack(stack);

    return 0;
}
