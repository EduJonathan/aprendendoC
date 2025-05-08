#include "operacoes.h"

int main(int argc, char **argv)
{
    struct no *lista = NULL;

    // Inserindo elementos na lista
    insereNoPrimeiroElemento(&lista, 1, 10);
    insereNoPrimeiroElemento(&lista, 2, 20);
    insereNoPrimeiroElemento(&lista, 3, 30);

    // Imprimindo a lista
    printf("Lista após inserção inicial:\n");
    imprimeLista(lista);

    // Inserindo mais elementos
    insereNoPrimeiroElemento(&lista, 4, 40);
    insereNoPrimeiroElemento(&lista, 5, 50);

    // Imprimindo a lista após mais inserções
    printf("Lista após novas inserções:\n");
    imprimeLista(lista);

    // Buscando um elemento
    int chaveProcurada = 3;
    struct no *elemento = encontrarElemento(lista, chaveProcurada);
    if (elemento != NULL)
    {
        printf("Elemento com chave %d encontrado: (%d, %d)\n", chaveProcurada, elemento->chave, elemento->dado);
    }
    else
    {
        printf("Elemento com chave %d não encontrado.\n", chaveProcurada);
    }

    // Inserindo elementos de forma ordenada
    insereOrdenado(&lista, 2, 20);
    insereOrdenado(&lista, 1, 10);
    insereOrdenado(&lista, 3, 30);
    insereOrdenado(&lista, 0, 5);

    printf("Lista após ordenação:\n");
    imprimeLista(lista);

    // Liberando a memória
    liberarLista(lista);
    return 0;
}
