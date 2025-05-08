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
    int tamanho = 0;
    while (lista != NULL)
    {
        tamanho++;
        lista = lista->prox;
    }
    return tamanho;
}

/**
 * @brief Insere um nó na lista de forma ordenada (em ordem crescente de "dado").
 *
 * @param lista Ponteiro para o ponteiro do primeiro nó da lista (para poder modificar a lista original).
 * @param chave Chave do novo nó.
 * @param valor Valor de dado do novo nó.
 */
void insereOrdenado(struct no **lista, int chave, int valor)
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));
    if (novo == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return;
    }

    novo->chave = chave;
    novo->dado = valor;

    // Se a lista estiver vazia ou o valor a ser inserido é menor que o primeiro elemento
    if (*lista == NULL || (*lista)->dado > valor)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    struct no *atual = *lista;

    // Encontre a posição correta na lista
    while (atual->prox != NULL && atual->prox->dado < valor)
    {
        atual = atual->prox;
    }

    // Insira o novo nó após 'atual'
    novo->prox = atual->prox;
    atual->prox = novo;
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
    printf("\n{");
    while (aux != NULL)
    {
        printf(" (%d, %d) ", aux->chave, aux->dado);
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
    if (!novo) // Verifica se a alocação foi bem-sucedida
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
    if (listaVazia(lista))
        return NULL;

    struct no *aux = lista;
    lista = lista->prox; // Avança o ponteiro da lista
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
    struct no *aux = lista, *anterior = NULL;

    while (aux != NULL && aux->chave != key)
    {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
        return lista; // Não encontrou a chave

    if (anterior == NULL) // Caso o nó a ser removido seja o primeiro
    {
        lista = aux->prox;
    }
    else
    {
        anterior->prox = aux->prox;
    }

    free(aux); // Libera o nó removido
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
    while (lista != NULL)
    {
        if (lista->chave == key)
        {
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

/**
 * @brief Libera toda a memória alocada para a lista.
 *
 * Itera sobre a lista e libera cada nó alocado dinamicamente.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 */
void liberarLista(struct no *lista)
{
    struct no *aux = NULL;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free(aux); // Libera o nó
    }
}

#endif
