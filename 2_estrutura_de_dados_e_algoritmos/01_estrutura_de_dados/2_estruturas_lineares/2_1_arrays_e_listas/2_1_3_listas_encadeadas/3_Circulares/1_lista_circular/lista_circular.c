#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_circular.h"

bool list_is_empty(const Node *head) { return head == NULL; }

int list_size(const Node *head)
{
    if (!head)
        return 0;

    int count = 0;
    const Node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

void list_insert_front(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        new_node->next = *head;
        last->next = new_node;
        *head = new_node;
    }

    printf("Elemento %d inserido na posição 0 (início da lista circular).\n", value);
}

void list_insert_back(Node **head, int value)
{
    int pos = list_size(*head);

    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head;
    }

    printf("Elemento %d inserido na posição %d (final da lista circular).\n", value, pos);
}

void list_insert_at(Node **head, int value, int position)
{
    if (position < 0)
    {
        printf("Posição inválida! Deve ser não negativa.\n");
        return;
    }

    int current_size = list_size(*head);

    if (position == 0)
    {
        list_insert_front(head, value);
        return;
    }
    else if (position == current_size)
    {
        list_insert_back(head, value);
        return;
    }
    else if (position > current_size)
    {
        printf("Posição inválida! A lista tem apenas %d elementos.\n", current_size);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;

    Node *current = *head;
    for (int i = 0; i < position - 1; ++i)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    printf("Elemento %d inserido na posição %d da lista circular.\n", value, position);
}

void list_remove_front(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    Node *temp = *head;
    int removed_value = temp->value;

    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }

    printf("Elemento %d removido da posição 0 (início da lista circular).\n", removed_value);
}

void list_remove_back(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    int pos = 0;

    while (current->next != *head)
    {
        prev = current;
        current = current->next;
        pos++;
    }

    int removed_value = current->value;

    if (prev == NULL) // apenas 1 elemento
    {
        free(current);
        *head = NULL;
    }
    else
    {
        prev->next = *head;
        free(current);
    }

    printf("Elemento %d removido da posição %d (final da lista circular).\n", removed_value, pos);
}

void list_remove_at(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    if (position < 0)
    {
        printf("Posição inválida! Deve ser não negativa.\n");
        return;
    }

    int current_size = list_size(*head);
    if (position >= current_size)
    {
        printf("Posição inválida! A lista tem apenas %d elementos.\n", current_size);
        return;
    }

    if (position == 0)
    {
        list_remove_front(head);
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    for (int i = 0; i < position; ++i)
    {
        prev = current;
        current = current->next;
    }

    int removed_value = current->value;
    prev->next = current->next;
    free(current);

    printf("Elemento %d removido da posição %d da lista circular.\n", removed_value, position);
}

bool list_search(const Node *head, int value)
{
    if (head == NULL)
        return false;

    const Node *current = head;

    do
    {
        if (current->value == value)
            return true;
        current = current->next;
    } while (current != head);

    return false;
}

void list_print(const Node *head)
{
    if (list_is_empty(head))
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    const Node *current = head;
    int index = 0;

    printf("Lista circular:\n");
    do
    {
        printf("Posição %d: %d\n", index++, current->value);
        current = current->next;
    } while (current != head);
    printf("Tamanho atual da lista: %d\n", index);
}

void list_free(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista já está vazia.\n");
        return;
    }

    Node *current = *head;
    Node *first = *head;
    int count = 0;

    do
    {
        Node *temp = current;
        current = current->next;
        free(temp);
        count++;
    } while (current != first);

    *head = NULL;
    printf("Memória da lista circular liberada (%d elementos removidos).\n", count);
}
