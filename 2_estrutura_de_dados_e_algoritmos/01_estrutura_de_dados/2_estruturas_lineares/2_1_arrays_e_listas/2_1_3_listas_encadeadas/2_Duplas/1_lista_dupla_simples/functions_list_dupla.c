#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void list_insert_front(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro na alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }

    printf("Nó com valor %d inserido na posição 0 (início da lista).\n", value);
}

void list_insert_back(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro na alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        printf("Nó com valor %d inserido na posição 0 (lista estava vazia).\n", value);
    }
    else
    {
        Node *current = *head;
        int pos = 0;
        while (current->next != NULL)
        {
            current = current->next;
            pos++;
        }
        current->next = new_node;
        new_node->prev = current;
        printf("Nó com valor %d inserido na posição %d (final da lista).\n", value, pos + 1);
    }
}

void list_remove_front(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    printf("Nó com valor %d removido da posição 0 (início da lista).\n", temp->data);
    free(temp);
}

void list_remove_back(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista está vazia. Nenhum nó para remover.\n");
        return;
    }

    Node *current = *head;
    int pos = 0;
    while (current->next != NULL)
    {
        current = current->next;
        pos++;
    }

    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    printf("Nó com valor %d removido da posição %d (final da lista).\n", current->data, pos);
    free(current);
}

void list_remove_value(Node **head, int value)
{
    if (*head == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    Node *current = *head;
    int pos = 0;
    while (current != NULL && current->data != value)
    {
        current = current->next;
        pos++;
    }

    if (current == NULL)
    {
        printf("Valor %d não encontrado na lista.\n", value);
        return;
    }

    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    printf("Nó com valor %d removido da posição %d da lista.\n", value, pos);
    free(current);
}

void list_print(const Node *head)
{
    if (head == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    const Node *current = head;
    int pos = 0;
    while (current != NULL)
    {
        printf("Posição %d: %d\n", pos, current->data);
        current = current->next;
        pos++;
    }
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
}
