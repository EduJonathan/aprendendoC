#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10 /**< Tamanho máximo da pilha. */

_Static_assert(STACK_SIZE > 0, "O Tamanho Da Pilha deve ser positivo");

/**
 * @brief Adiciona um item no topo da pilha.
 *
 * A função `push` insere um item na pilha. Se a pilha estiver cheia, exibe uma mensagem
 * e retorna o topo sem alterações.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha. Inicialmente é -1.
 * @param item Item a ser inserido na pilha.
 * @return Novo índice do topo da pilha após a inserção.
 */
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

/**
 * @brief Verifica se a pilha está vazia.
 *
 * A função `is_empty` verifica se a pilha está vazia com base no índice do topo.
 *
 * @param top Índice do topo da pilha.
 * @return true se a pilha estiver vazia, false caso contrário.
 */
bool is_empty(int top)
{
    return top == -1;
}

/**
 * @brief Remove o item do topo da pilha.
 *
 * A função `pop` remove o item do topo da pilha. Se a pilha estiver vazia, exibe uma
 * mensagem e retorna o topo sem alterações.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha. Inicialmente é -1.
 * @return Novo índice do topo da pilha após a remoção.
 */
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

/**
 * @brief Obtém o item no topo da pilha sem removê-lo.
 *
 * A função `stack_top` retorna o item no topo da pilha sem removê-lo. Se a pilha estiver
 * vazia, exibe uma mensagem e retorna -1.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha.
 * @return Item no topo da pilha ou -1 se a pilha estiver vazia.
 */
int stack_top(int items[], int top)
{
    if (is_empty(top))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    return items[top];
}

/**
 * @brief Exibe todos os itens da pilha.
 *
 * A função exibe os itens da pilha do topo até a base. Se a pilha estiver vazia,
 * exibe uma mensagem correspondente.
 *
 * @param items Array que representa os elementos da pilha.
 * @param top Índice do topo da pilha.
 */
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

int main(int argc, char **argv)
{
    int items[STACK_SIZE];
    int top = -1;

    top = push(items, top, 10);
    top = push(items, top, 20);
    top = push(items, top, 30);
    top = push(items, top, 40);
    top = push(items, top, 50);

    printf("Pilha após inserções:\n");
    print_stack(items, top);
    printf("Topo da pilha: %d\n", stack_top(items, top));
    printf("\n------------------------------\n");

    printf("Pilha após remoção:\n");
    top = pop(items, top);
    print_stack(items, top);
    printf("Topo da pilha: %d\n", stack_top(items, top));
    printf("\n------------------------------\n");

    return 0;
}
