#include <stdio.h>
#include "functions_pilha.h"

int main(int argc, char **argv)
{
    int items[STACK_SIZE]; // Array que representa os elementos da pilha
    int topo = -1;         // A pilha começa vazia (topo é -1)

    // Inserir alguns elementos na pilha
    topo = push(items, topo, 10); // Primeiro item na pilha
    topo = push(items, topo, 20); // Segundo item na pilha
    topo = push(items, topo, 30); // Terceiro item na pilha
    topo = push(items, topo, 40); // Quarto item na pilha
    topo = push(items, topo, 50); // Quinto item na pilha

    // Exibir a pilha
    printf("Pilha após inserções:\n");
    exibirPilha(items, topo);
    printf("Topo da pilha: %d\n", stackTop(items, topo));

    printf("\n------------------------------\n");

    // Remover um item da pilha, quem estiver no topo será removido
    printf("Pilha após remoção:\n");
    topo = pop(items, topo);
    exibirPilha(items, topo);

    // Obter o item no topo da pilha
    printf("Topo da pilha: %d\n", stackTop(items, topo));

    printf("\n------------------------------\n");

    return 0;
}
