#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

/**
 * @brief Insere um nó no início da lista
 *
 * @param head Ponteiro para a cabeça da lista
 * @param valorParaInserir Valor a ser inserido
 */
void inserirNoInicio(struct node **head, int valorParaInserir)
{
    // Aloca memória para o novo nó
    struct node *novoNo = (struct node *)malloc(sizeof(struct node));

    if (novoNo == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return;
    }

    novoNo->data = valorParaInserir; // Define o valor do novo nó
    novoNo->prev = NULL;             // O nó anterior de um nó inserido no início é NULL

    if (*head == NULL)
    {
        novoNo->next = NULL; // O nó seguinte de um nó inserido no início é NULL
        *head = novoNo;      // Atualiza a cabeça
    }
    else
    {
        novoNo->next = *head;   // O novo nó aponta para o primeiro nó
        (*head)->prev = novoNo; // O nó anterior do primeiro nó é o novo nó
        *head = novoNo;         // A cabeça agora é o novo nó
    }
    printf("O nó %d foi inserido com sucesso no início!\n", valorParaInserir);
}

/**
 * @brief Insere um nó no final da lista
 *
 * @param head Ponteiro para a cabeça da lista
 * @param valorParaInserir Valor a ser inserido
 */
void inserirNoFinal(struct node **head, int valorParaInserir)
{
    // Aloca memória para o novo nó
    struct node *novoNo = (struct node *)malloc(sizeof(struct node));

    if (novoNo == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return;
    }

    novoNo->data = valorParaInserir;
    novoNo->next = NULL; // O próximo nó será NULL, pois é o final da lista

    struct node *temp = *head;

    // Verifica se a lista está vazia
    if (*head == NULL)
    {
        novoNo->prev = NULL; // O nó anterior é NULL
        *head = novoNo;      // A cabeça agora é o novo nó
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next; // Percorre a lista
        }
        temp->next = novoNo; // O nó seguinte é o novo nó
        novoNo->prev = temp; // O nó anterior será o último nó da lista
    }
    printf("O nó %d foi inserido com sucesso no final!\n", valorParaInserir);
}

/**
 * @brief Remove o nó do início da lista
 *
 * @param head Ponteiro para a cabeça da lista
 */
void removerNoInicio(struct node **head)
{
    struct node *temp = *head;

    if (*head == NULL)
    {
        printf("A lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    *head = (*head)->next; // A cabeça passa a ser o próximo nó

    if (*head != NULL)
    {
        // O novo primeiro nó não terá nó anterior
        (*head)->prev = NULL;
    }
    free(temp); // Libera o nó removido
    printf("O nó %d foi removido do início com sucesso!\n", temp->data);
}

/**
 * @brief Remove o nó do final da lista
 *
 * @param head Ponteiro para a cabeça da lista
 */
void removerNoFinal(struct node **head)
{
    struct node *temp = *head;

    if (*head == NULL)
    {
        printf("A lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    while (temp->next != NULL)
    {
        // Percorre até o último nó
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        // O penúltimo nó aponta para NULL
        temp->prev->next = NULL;
    }

    if (temp == *head)
    {
        // Se a lista tinha apenas um nó, a cabeça será NULL
        *head = NULL;
    }
    free(temp); // Libera o nó removido
    printf("O nó %d foi removido do final com sucesso!\n", temp->data);
}

/**
 * @brief Remove um nó específico com base no valor
 *
 * @param head Ponteiro para a cabeça da lista
 * @param valorParaDeletar Valor do nó a ser removido
 */
void delecaoEspecifica(struct node **head, int valorParaDeletar)
{
    struct node *temp = *head;

    if (*head == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Encontra o nó a ser deletado
    while (temp != NULL && temp->data != valorParaDeletar)
    {
        // Atualiza o ponteiro temporário
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Valor não encontrado na lista.\n");
        return;
    }

    // Caso o nó a ser deletado seja a cabeça
    if (temp == *head)
    {
        // Atualiza a cabeça
        *head = temp->next;

        // Caso a lista tenha apenas um nó
        if (*head != NULL)
        {
            // Atualiza o ponteiro "prev" do primeiro nó
            (*head)->prev = NULL;
        }
    }
    else
    {
        // Caso o nó a ser deletado seja um nó intermediário
        temp->prev->next = temp->next;

        // Caso o nó a ser deletado seja o penúltimo nó
        if (temp->next != NULL)
        {
            // Atualiza o ponteiro "next" do nó anterior ao nó a ser deletado
            temp->next->prev = temp->prev;
        }
    }
    free(temp); // Libera o nó removido
    printf("Nó com valor %d removido da lista!\n", valorParaDeletar);
}

/**
 * @brief Imprime os elementos da lista
 *
 * @param head Ponteiro para a cabeça da lista
 */
void imprimir(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Liberar memória
 *
 * @param head informar a lista
 */
void liberarLista(struct node **head)
{
    struct node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

#endif
