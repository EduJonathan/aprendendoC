#include "stack.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Stack *stack = NULL;
    int option = 0;

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

    /**
     * gcc -std=c11 main_reverte_pilha.c functions.c -o pilha_reversa
     * .\pilha_reversa.exe
     */
    return 0;
}
