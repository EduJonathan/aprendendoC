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
    // Retorna NULL indicando lista vazia
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
    no *novo_no = (no *)malloc(sizeof(no)); // Aloca memória para um novo nó
    novo_no->mat = matricula;               // Define a matrícula do novo nó
    novo_no->nota = notas;                  // Define a nota do novo nó
    novo_no->prox = lista;                  // Liga o novo nó à lista existente
    return novo_no;                         // Retorna o novo nó como o início da lista
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
    // Declara uma variável auxiliar para percorrer a lista
    no *i = NULL;

    // Percorre a lista e verifica se o número de matrícula foi encontrado
    for (i = lista; i != NULL; i = i->prox)
    {
        // Verifica se o número de matrícula foi encontrado
        if (i->mat == matricula)
        {
            // Retorna o nó se encontrado
            return i;
        }
    }
    return NULL; // Retorna NULL se o número de matrícula não for encontrado
}

/**
 * @brief Libera toda a memória alocada para a lista encadeada.
 *
 * @param lista Ponteiro para o primeiro nó da lista.
 * @return Retorna NULL, indicando lista vazia após a liberação.
 */
no *libera(no *lista)
{
    // Declara uma variável auxiliar para percorrer a lista
    no *aux = NULL;
    no *proximo_no = NULL;
    lista = NULL;

    // Percorre a lista e libera cada nó
    while (aux != NULL)
    {
        proximo_no = aux->prox; // Armazena o nó seguinte
        free(aux);              // Libera o nó atual
        aux = proximo_no;       // Move para o próximo nó
    }
    return iniciar_lista(); // Retorna a lista vazia
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
    no *anterior = NULL; // Ponteiro para o nó anterior
    no *atual = lista;   // Ponteiro para percorrer a lista

    // Procura o nó na lista, guardando o nó anterior
    for (atual = lista; atual != NULL; atual = atual->prox)
    {
        if (atual->mat == matricula)
        {
            // Achou o nó com a matrícula especificada
            break;
        }
        else
        {
            // Atualiza o nó anterior
            anterior = atual;
        }
    }

    if (atual == NULL)
    {
        // Retorna a lista original se não encontrou o nó
        return lista;
    }
    else if (anterior == NULL)
    {
        // Remove o primeiro nó da lista
        lista = atual->prox;
    }
    else
    {
        // Remove um nó do meio da lista
        anterior->prox = atual->prox;
    }

    free(atual);  // Libera a memória do nó removido
    return lista; // Retorna a lista modificada
}

#endif
