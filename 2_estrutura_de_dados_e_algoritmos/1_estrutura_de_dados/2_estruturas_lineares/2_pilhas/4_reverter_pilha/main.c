#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv)
{
    // Ponteiro para o topo da pilha
    struct pilha *pilha = NULL;

    // Gerar a pilha, permitindo que o usuário insira elementos
    gerarPilha(&pilha);
    printf("\n---------------------------------------------------\n");

    // Imprimir a pilha original
    printf("Pilha original: ");
    imprimirPilha(pilha);
    printf("\n---------------------------------------------------\n");

    // Reverter a pilha
    reverterPilha(&pilha);

    // Imprimir a pilha revertida
    printf("Pilha revertida: ");
    imprimirPilha(pilha);

    // Limpar a pilha
    limparPilha(&pilha);

    return 0;
}
