#ifndef OPERACOES_LISTAS_H
#define OPERACOES_LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de um nó da lista encadeada.
 *
 * Esta estrutura contém um valor (dado), uma chave (key) e um ponteiro para o próximo nó.
 */
struct no
{
    int dado;        /**< Dados armazenados no nó */
    int chave;       /**< Chave que identifica o nó */
    struct no *prox; /**< Ponteiro para o próximo nó */
};

/**
 * @brief Verifica se a lista está vazia.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @return true Se a lista estiver vazia.
 * @return false Se a lista não estiver vazia.
 */
bool listaVazia(struct no *lista) { return (lista == NULL); }

/**
 * @brief Calcula o tamanho da lista.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @return O número de elementos na lista.
 */
int tamanhoLista(struct no *lista)
{
    struct no *aux = lista;
    int tamanho = 0;

    for (; aux != NULL; aux = aux->prox)
    {
        tamanho++;
    }

    return tamanho;
}

/**
 * @brief Ordena a lista encadeada em ordem crescente pelo campo dado.
 *
 * Utiliza o algoritmo de ordenação bolha (bubble sort) para ordenar os nós da lista.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 */
void ordernarLista(struct no *lista)
{
    struct no *aux = NULL;
    struct no *next = NULL;

    int size = tamanhoLista(lista);

    for (int i = 0; i < size - 1; i++)
    {
        aux = lista;
        next = lista->prox;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (aux->dado > next->dado)
            {
                // Troca os valores de dado e chave entre os nós
                int temp = aux->dado;
                aux->dado = next->dado;
                next->dado = temp;

                temp = aux->chave;
                aux->chave = next->chave;
                next->chave = temp;
            }

            aux = aux->prox;
            next = next->prox;
        }
    }
}

/**
 * @brief Imprime os elementos da lista.
 *
 * Exibe a lista no formato `{(chave1, dado1), (chave2, dado2), ...}`.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 */
void imprimeLista(struct no *lista)
{
    struct no *aux = lista;
    int i = 0;

    printf("\n{");
    while (aux != NULL)
    {
        printf("\n Elemento %d: (%d, %d) \n", i, aux->chave, aux->dado);
        i++;
        aux = aux->prox;
    }

    printf("}\n");
}

/**
 * @brief Insere um novo nó no início da lista.
 *
 * Cria um novo nó e o coloca na frente da lista.
 *
 * @param lista Ponteiro para o ponteiro da lista (para poder modificar a lista original).
 * @param key Chave do novo nó.
 * @param valor Valor de dado do novo nó.
 */
void insereNoPrimeiroElemento(struct no **lista, int key, int valor)
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));

    if (novo == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return;
    }

    novo->chave = key;
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

/**
 * @brief Deleta o primeiro elemento da lista e retorna o nó deletado.
 *
 * Remove o nó no início da lista, retorna o nó deletado e a nova lista.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @return O nó deletado.
 */
struct no *deletarPrimeiroElemento(struct no *lista)
{
    struct no *aux = lista;

    if (listaVazia(lista))
    {
        return NULL;
    }

    lista = lista->prox;

    return aux;
}

/**
 * @brief Deleta um nó da lista dado a chave.
 *
 * Remove o nó com a chave especificada e retorna a nova lista.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @param key Chave do nó a ser removido.
 * @return A nova lista com o nó removido.
 */
struct no *deletar(struct no *lista, int key)
{
    struct no *aux = lista;
    struct no *anterior = NULL;

    if (listaVazia(lista))
    {
        return NULL;
    }

    while (aux != NULL && aux->chave != key)
    {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        return lista;
    }
    if (aux == lista)
    {
        lista = lista->prox;
    }
    else
    {
        anterior->prox = aux->prox;
    }

    return lista;
}

/**
 * @brief Encontra um nó com a chave fornecida.
 *
 * Busca um nó na lista pelo campo chave e retorna o nó encontrado.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @param key Chave do nó a ser encontrado.
 * @return O nó com a chave especificada, ou NULL se não encontrado.
 */
struct no *encontrarElemento(struct no *lista, int key)
{
    struct no *aux = lista;

    if (listaVazia(lista))
    {
        return NULL;
    }

    while (aux != NULL)
    {
        if (aux->chave == key)
        {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

#endif
