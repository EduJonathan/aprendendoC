#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

No *criarNo(TipoEvento tipo, void *dados, int diaSemana)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo->tipo = tipo;
    novo->dados = dados;
    novo->diaSemana = diaSemana;
    novo->proximo = NULL;
    return novo;
}

void inserirCircular(No **cabeca, No *novo)
{
    if (*cabeca == NULL)
    {
        *cabeca = novo;
        novo->proximo = *cabeca; // Circular: aponta para si mesmo
        return;
    }
    No *temp = *cabeca;
    while (temp->proximo != *cabeca)
    {
        temp = temp->proximo;
    }
    temp->proximo = novo;
    novo->proximo = *cabeca; // Fecha o ciclo
}

void imprimirAgenda(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Agenda vazia.\n");
        return;
    }

    No *temp = cabeca;
    do
    {
        printf("Dia %d: ", temp->diaSemana);
        switch (temp->tipo)
        {
        case TIPO_REUNIAO:
        {
            Reuniao *r = (Reuniao *)temp->dados;
            printf("Reunião - Título: %s, Horário: %s\n", r->titulo, r->horario);
            break;
        }
        case TIPO_LEMBRETE_PAGAMENTO:
        {
            LembretePagamento *lp = (LembretePagamento *)temp->dados;
            printf("Lembrete Pagamento - Valor: %.2f, Descrição: %s\n", lp->valor, lp->descricao);
            break;
        }
        case TIPO_ANIVERSARIO:
        {
            Aniversario *a = (Aniversario *)temp->dados;
            printf("Aniversário - Nome: %s, Data: %s\n", a->nome, a->data);
            break;
        }
        }
        temp = temp->proximo;
    } while (temp != cabeca);
}

void liberarAgenda(No *cabeca)
{
    if (cabeca == NULL)
        return;

    No *atual = cabeca;
    No *proximo = NULL;

    // Quebra o ciclo para evitar loop infinito
    No *temp = cabeca;
    while (temp->proximo != cabeca)
    {
        temp = temp->proximo;
    }
    temp->proximo = NULL;

    // Libera cada nó
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
