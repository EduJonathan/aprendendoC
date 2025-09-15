#include "stack.h"

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

    /**
     * gcc -std=c11 main_pilha_estatica.c pilha.c -o pilha
     * .\pilha.exe
     */
    return 0;
}
