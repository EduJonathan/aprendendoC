#include "stack.h"

int main(int argc, char **argv)
{
    Stack *top = NULL;

    generateStack(&top);
    printf("\nPilha gerada:\n");
    printStack(top);

    printf("\nTamanho da pilha: %zu\n", stackSize(top));

    printf("\nRevertendo a pilha...\n");
    reverseStack(&top);
    printStack(top);

    freeStack(&top);

    /**
     * gcc -std=c11 main_reverte_pilha.c functions.c -o pilha_reversa
     * .\pilha_reversa.exe
     */
    return 0;
}
