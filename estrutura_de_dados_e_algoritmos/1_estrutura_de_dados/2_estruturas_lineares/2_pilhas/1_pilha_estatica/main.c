#include "functions_pilha.h"

/**
 * Pilha: Estrutura de dados que armazena elementos de forma LIFO (Last In First Out).
 * A pilha é uma estrutura linear onde o último elemento inserido é o primeiro a ser removido.
 * Muito utilizada em algoritmos de backtracking, expressões matemáticas e controle de fluxo.
 * 
 * As operações principais são:
 * - push: Adiciona um elemento ao topo da pilha.
 * - pop: Remove o elemento do topo da pilha.
 * - stackTop: Retorna o elemento do topo da pilha sem removê-lo.
 * - exibirPilha: Exibe os elementos da pilha do topo para a base.
 * - vazia: Verifica se a pilha está vazia.
 * - cheia: Verifica se a pilha está cheia.
 */

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
