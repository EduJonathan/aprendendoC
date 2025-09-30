#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct no *criar_no(int valor)
{
    struct no *novo = malloc(sizeof(struct no));
    if (novo == NULL)
    {
        return NULL;
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

int inicializar_arvore(struct arvore *a)
{
    if (a == NULL)
    {
        return -1;
    }

    a->raiz = malloc(sizeof(struct no *));
    if (a->raiz == NULL)
    {
        return -1;
    }
    *(a->raiz) = NULL;
    return 0;
}

void liberar_arvore(struct no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int inserir(struct no **raiz, int valor)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (*raiz == NULL)
    {
        *raiz = criar_no(valor);
        return (*raiz != NULL) ? 0 : -1;
    }

    if (valor < (*raiz)->valor)
    {
        return inserir(&((*raiz)->esquerda), valor);
    }
    else if (valor > (*raiz)->valor)
    {
        return inserir(&((*raiz)->direita), valor);
    }
    else
    {
        // Valor já existe na árvore
        return 0;
    }
}

struct no *encontrar_minimo(struct no *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    while (raiz->esquerda != NULL)
    {
        raiz = raiz->esquerda;
    }
    return raiz;
}

int remover(struct no **raiz, int valor)
{
    if (raiz == NULL || *raiz == NULL)
    {
        return -1;
    }

    if (valor < (*raiz)->valor)
    {
        return remover(&((*raiz)->esquerda), valor);
    }
    else if (valor > (*raiz)->valor)
    {
        return remover(&((*raiz)->direita), valor);
    }
    else
    {
        // Nó encontrado
        if ((*raiz)->esquerda == NULL)
        {
            struct no *temp = *raiz;
            *raiz = (*raiz)->direita;
            free(temp);
        }
        else if ((*raiz)->direita == NULL)
        {
            struct no *temp = *raiz;
            *raiz = (*raiz)->esquerda;
            free(temp);
        }
        else
        {
            // Nó com dois filhos
            struct no *min = encontrar_minimo((*raiz)->direita);
            (*raiz)->valor = min->valor;
            return remover(&((*raiz)->direita), min->valor);
        }
        return 0;
    }
}

struct no *buscar(struct no *raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (valor == raiz->valor)
    {
        return raiz;
    }
    else if (valor < raiz->valor)
    {
        return buscar(raiz->esquerda, valor);
    }
    else
    {
        return buscar(raiz->direita, valor);
    }
}

void imprimir_em_ordem(struct no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    imprimir_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimir_em_ordem(raiz->direita);
}

void imprimir_pre_ordem(struct no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    printf("%d ", raiz->valor);
    imprimir_pre_ordem(raiz->esquerda);
    imprimir_pre_ordem(raiz->direita);
}

void imprimir_pos_ordem(struct no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    imprimir_pos_ordem(raiz->esquerda);
    imprimir_pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}
