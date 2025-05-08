#include <stdio.h>
#include "implementa_lista.h"

int main(int argc, char **argv)
{
    no *lista = iniciar_lista();

    lista = insere_lista(lista, 23, 9.5);
    lista = insere_lista(lista, 45, 8.4);
    lista = insere_lista(lista, 56, 7.3);
    lista = insere_lista(lista, 95, 6.2);

    printf("Lista após inserções:\n");
    imprime_lista(lista);

    printf("\n------------------------------------\n");

    lista = remover(lista, 56);

    printf("Lista após remoção do nó com matrícula 56:\n");
    imprime_lista(lista);

    printf("\n------------------------------------\n");

    lista = libera(lista);
    return 0;
}
