#include <stdio.h>
#include <stdlib.h>
#include "function_lista.h"

int list_size(const Node *head)
{
    int count = 0;
    const Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void list_free(Node **head)
{
    Node *current = *head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("\nMemória liberada com sucesso!\n");
}

void list_insert_front(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
    printf("\nNó com valor %d inserido na posição 0 (início da lista).\n", new_node->data);
}

void list_insert_back(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        printf("\nNó com valor %d inserido na posição 0 (lista estava vazia).\n", new_node->data);
    }
    else
    {
        Node *last_node = *head;
        int pos = 0;

        while (last_node->next != NULL)
        {
            last_node = last_node->next;
            pos++;
        }

        last_node->next = new_node;
        new_node->prev = last_node;

        printf("\nNó com valor %d inserido na posição %d (final da lista).\n", new_node->data, pos + 1);
    }
}

void list_insert_after(Node **head, int value, int pos)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;

    if (*head == NULL)
    {
        if (pos == 0)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            *head = new_node;
            printf("\nNó com valor %d inserido na posição 0 (lista estava vazia).\n", new_node->data);
        }
        else
        {
            printf("\nErro: lista vazia. Posição %d inválida.\n", pos);
            free(new_node);
        }
        return;
    }

    Node *temp = *head;
    int current_pos = 0;
    while (current_pos < pos && temp != NULL)
    {
        temp = temp->next;
        current_pos++;
    }

    if (temp == NULL)
    {
        printf("\nErro: posição %d inválida. Inserção não realizada.\n", pos);
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
    new_node->prev = temp;

    printf("\nNó com valor %d inserido após a posição %d (nova posição: %d).\n", value, pos, pos + 1);
}

void list_remove_front(Node **head)
{
    if (*head == NULL)
    {
        printf("\nErro: a lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    Node *temp = *head;
    int value = temp->data;
    *head = temp->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("\nNó com valor %d removido da posição 0 (início da lista).\n", value);
}

void list_remove_back(Node **head)
{
    if (*head == NULL)
    {
        printf("\nErro: a lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    Node *temp = *head;
    int pos = 0;

    while (temp->next != NULL)
    {
        temp = temp->next;
        pos++;
    }

    int value = temp->data;

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(temp);
    printf("\nNó com valor %d removido da posição %d (final da lista).\n", value, pos);
}

void list_remove_value(Node **head, int value)
{
    if (*head == NULL)
    {
        printf("\nErro: a lista está vazia.\n");
        return;
    }

    Node *temp = *head;
    int pos = 0;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL)
    {
        printf("\nNó com valor %d não encontrado na lista.\n", value);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("\nNó com valor %d removido da posição %d.\n", value, pos);
}

void list_print(const Node *head)
{
    if (head == NULL)
    {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\nConteúdo da lista:\n");

    const Node *temp = head;
    int index = 0;

    while (temp != NULL)
    {
        printf("Posição %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }

    printf("Tamanho atual da lista: %d\n", index);
}
