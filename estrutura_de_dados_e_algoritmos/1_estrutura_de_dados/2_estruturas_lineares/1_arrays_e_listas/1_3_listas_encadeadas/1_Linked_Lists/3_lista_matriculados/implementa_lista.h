#ifndef IMPLEMENTA_LISTA_H
#define IMPLEMENTA_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "definicoes_lista.h"

/**
 * @brief Inicializa uma lista encadeada vazia.
 *
 * @return Ponteiro para o primeiro nó da lista (NULL, indicando lista vazia).
 */
no *iniciar_lista(void)
{
    return NULL;
}

/**
 * @brief Insere um novo nó no início da lista encadeada.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @param matricula Matrícula do aluno a ser inserido.
 * @param notas Nota do aluno a ser inserida.
 * @return Ponteiro para o primeiro nó da lista após a inserção.
 */
no *insere_lista(no *lista, int matricula, float notas)
{
    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->mat = matricula;
    novo_no->nota = notas;
    novo_no->prox = lista;
    return novo_no;
}

/**
 * @brief Imprime os elementos da lista encadeada.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 */
void imprime_lista(no *lista)
{
    // Declara uma variável auxiliar para percorrer a lista
    no *i = NULL;

    // Percorre a lista e imprime os elementos
    for (i = lista; i != NULL; i = i->prox)
    {
        printf("Endereço: %p | Conteúdo: Matrícula: %d, Nota: %.2f, Próximo: %p\n", i, i->mat, i->nota, i->prox);
    }
}

/**
 * @brief Busca um nó na lista pelo número de matrícula.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @param matricula Matrícula do aluno a ser buscada.
 * @return Ponteiro para o nó encontrado ou NULL se não encontrado.
 */
no *busca(no *lista, int matricula)
{
    for (no *i = lista; i != NULL; i = i->prox)
    {
        if (i->mat == matricula)
        {
            return i;
        }
    }
    return NULL;
}
/**
 * @brief Libera toda a memória alocada para a lista encadeada.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @return Retorna NULL, indicando lista vazia após a liberação.
 */
no *libera(no *lista)
{
    no *aux = lista;
    no *proximo_no;
    while (aux != NULL)
    {
        proximo_no = aux->prox;
        free(aux);
        aux = proximo_no;
    }
    return iniciar_lista();
}

/**
 * @brief Remove um nó da lista pelo número de matrícula.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @param matricula Matrícula do aluno a ser removida.
 * @return Ponteiro para o primeiro nó da lista após a remoção.
 */
no *remover(no *lista, int matricula)
{
    no *anterior = NULL;
    no *atual = lista;

    while (atual != NULL && atual->mat != matricula)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return lista;
    }

    if (anterior == NULL)
    {
        lista = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    return lista;
}

#endif
