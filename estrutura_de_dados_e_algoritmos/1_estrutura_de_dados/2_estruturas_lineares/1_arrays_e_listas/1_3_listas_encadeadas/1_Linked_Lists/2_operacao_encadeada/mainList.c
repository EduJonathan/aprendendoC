#include "operacoes.h"

int main(int argc, char **argv)
{
    // Declare lista como um ponteiro para no
    struct no *lista = NULL;

    // Inserindo elementos na lista
    insereNoPrimeiroElemento(&lista, 1, 10);
    insereNoPrimeiroElemento(&lista, 2, 20);
    insereNoPrimeiroElemento(&lista, 3, 30);

    // Imprimindo a lista
    printf("Lista após inserção inicial:\n");
    imprimeLista(lista);

    printf("\n-----------------------\n");

    // Inserindo mais elementos
    insereNoPrimeiroElemento(&lista, 4, 40);
    insereNoPrimeiroElemento(&lista, 5, 50);

    // Imprimindo a lista após mais inserções
    printf("Lista após novas inserções:\n");
    imprimeLista(lista);

    printf("\n-----------------------\n");

    // Buscando um elemento
    int chaveProcurada = 3;
    struct no *elemento = encontrarElemento(lista, chaveProcurada);

    if (elemento != NULL)
    {
        printf("\nElemento com chave %d encontrado: (%d, %d)\n", chaveProcurada, elemento->chave, elemento->dado);
    }
    else
    {
        printf("\nElemento com chave %d não encontrado.\n", chaveProcurada);
    }

    printf("\n-----------------------\n");

    // Ordenando a lista
    ordernarLista(lista);

    printf("\nLista após ordenação:\n");
    imprimeLista(lista);

    // Liberando a memória
    struct no *aux = NULL;

    while (lista != NULL)
    {
        aux = lista;         // Guarda o ponteiro do nó atual
        lista = lista->prox; // Avança para o próximo nó
        free(aux);           // Libera a memória do nó atual
    }

    return 0;
}
