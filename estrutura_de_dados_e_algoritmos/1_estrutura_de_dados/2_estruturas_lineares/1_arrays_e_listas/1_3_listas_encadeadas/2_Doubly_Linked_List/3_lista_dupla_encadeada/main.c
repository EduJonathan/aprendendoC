#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv)
{
    // Cria uma nova lista
    Lista *lista = criarLista();

    // Adiciona 15 elementos à lista
    for (size_t i = 0; i < 15; i++)
    {
        // A cada iteração adiciona um novo elemento na lista, adicionando 10
        add(lista, (i + 1) * 10);
    }

    // Imprime a lista na ordem normal
    print(lista);

    // Imprime a lista na ordem reversa
    printReverse(lista);

    // Libera a memória da lista
    liberarLista(lista);
    return 0;
}
