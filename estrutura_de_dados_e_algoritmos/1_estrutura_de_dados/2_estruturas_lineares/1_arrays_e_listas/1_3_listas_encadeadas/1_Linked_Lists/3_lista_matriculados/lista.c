#include <stdio.h>
#include "implementa_lista.h"

int main(int argc, char **argv)
{
    no *lista = NULL;        // Declara uma variável para armazenar a lista
    lista = iniciar_lista(); // Inicializa a lista como vazia

    // Insere alguns nós na lista
    lista = insere_lista(lista, 23, 9.5);
    lista = insere_lista(lista, 45, 8.4);
    lista = insere_lista(lista, 56, 7.3);
    lista = insere_lista(lista, 95, 6.2);

    // Imprime a lista após as inserções
    printf("Lista após inserções:\n");
    imprime_lista(lista);

    printf("\n------------------------------------\n");

    // Remove um nó específico da lista
    lista = remover(lista, 56);

    // Imprime a lista após a remoção
    printf("Lista após remoção do nó com matrícula 56:\n");
    imprime_lista(lista);

    printf("\n------------------------------------\n");

    // Libera toda a memória alocada para a lista
    lista = libera(lista);
    return 0;
}
