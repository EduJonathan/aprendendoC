#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * @brief Cria uma nova lista vazia.
 *
 * Aloca memória para a lista e inicializa seus atributos.
 *
 * @return Ponteiro para a lista recém-criada.
 */
Lista *criarLista(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista)); // Aloca memória para a lista
    lista->quantidade = 0;                         // Inicializa a quantidade de elementos como 0
    lista->primeiroItem = NULL;                    // Inicializa o ponteiro para o primeiro item da lista
    lista->ultimoItem = NULL;                      // para o ultimo item da lista
    return lista;                                  // Retorna o ponteiro para a lista
}

/**
 * @brief Adiciona um novo elemento ao final da lista.
 *
 * Cria um novo elemento e o insere no final da lista.
 * Atualiza os ponteiros para o último item da lista.
 *
 * @param lista Ponteiro para a lista onde o elemento será inserido.
 * @param dado Valor do elemento a ser adicionado.
 */
void add(Lista *lista, int dado)
{
    // Cria um novo elemento, alocando na memória
    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));

    if (novoElemento == NULL)
    {
        printf("Erro ao alocar memória para o novo nó!\n");
        return;
    }

    novoElemento->dado = dado;                  // Insere o dado no novo elemento
    novoElemento->proximo = NULL;               // Define o ponteiro para o próximo elemento como NULL
    novoElemento->anterior = lista->ultimoItem; // Define o ponteiro para o elemento anterior

    // Se a lista estiver vazia, o novo elemento é o primeiro item da lista
    if (lista->quantidade == 0)
    {
        // Define o ponteiro para o primeiro item da lista
        lista->primeiroItem = novoElemento;
    }
    else
    {
        // Define o ponteiro para o ultimo item da lista
        lista->ultimoItem->proximo = novoElemento;
    }
    lista->ultimoItem = novoElemento; // Define o ponteiro para o ultimo item da lista
    lista->quantidade++;              // Incrementa a quantidade de itens da lista
}

/**
 * @brief Imprime os elementos da lista da cabeça para a cauda.
 *
 * Percorre a lista do primeiro para o último elemento e imprime seus valores.
 *
 * @param lista Ponteiro para a lista a ser impressa.
 */
void print(Lista *lista)
{
    // Percorre a lista
    Elemento *aux = lista->primeiroItem;

    // Imprime os elementos
    while (aux != NULL)
    {
        printf("Elemento: %d\n", aux->dado);
        aux = aux->proximo;
    }
    printf("\n");
}

/**
 * @brief Imprime os elementos da lista da cauda para a cabeça.
 *
 * Percorre a lista do último para o primeiro elemento e imprime seus valores.
 *
 * @param lista Ponteiro para a lista a ser impressa.
 */
void printReverse(Lista *lista)
{
    Elemento *aux = lista->ultimoItem;

    while (aux != NULL)
    {
        printf("Elemento: %d\n", aux->dado);
        aux = aux->anterior;
    }
    printf("\n");
}

/**
 * @brief Libera toda a memória alocada para os elementos da lista.
 *
 * Percorre a lista e libera os elementos, em seguida libera a memória da própria
 * estrutura de lista.
 *
 * @param lista Ponteiro para a lista a ser liberada.
 */
void liberarLista(Lista *lista)
{
    // Percorre a lista
    Elemento *aux = lista->primeiroItem;

    while (aux != NULL)
    {
        Elemento *temp = aux; // Armazena o nó atual
        aux = aux->proximo;   // Move para o próximo nó
        free(temp);           // Libera a memória do nó
    }
    free(lista); // Libera a memória da estrutura
}

#endif
