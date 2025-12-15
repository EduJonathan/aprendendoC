#include <stdio.h>
#include <stdlib.h>
#include "lista_functions.h"

List *list_create(void)
{
    List *list = malloc(sizeof(List));
    if (!list)
    {
        fprintf(stderr, "Erro ao alocar memória para a lista!\n");
        return NULL;
    }
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    printf("Lista criada com sucesso.\n");
    return list;
}

void list_append(List *list, int data)
{
    if (!list)
    {
        fprintf(stderr, "Erro: lista inválida!\n");
        return;
    }

    Element *new_element = malloc(sizeof(Element));
    if (!new_element)
    {
        fprintf(stderr, "Erro ao alocar memória para o elemento!\n");
        exit(EXIT_FAILURE);
    }

    new_element->data = data;
    new_element->next = NULL;
    new_element->prev = list->last;

    if (list->size == 0)
    {
        list->first = new_element;
        list->last = new_element;
        printf("Nó com valor %d inserido na posição 0 (primeiro elemento).\n", data);
    }
    else
    {
        list->last->next = new_element;
        list->last = new_element;
        printf("Nó com valor %d inserido na posição %d (final da lista).\n", data, list->size);
    }

    list->size++;
}

void list_print_forward(const List *list)
{
    if (!list || list->size == 0)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nLista (sentido: início → fim):\n");
    const Element *current = list->first;
    int index = 0;
    while (current != NULL)
    {
        printf("Posição %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
    printf("Total de elementos: %d\n", list->size);
}

void list_print_reverse(const List *list)
{
    if (!list || list->size == 0)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nLista (sentido: fim → início):\n");
    const Element *current = list->last;
    int index = list->size - 1;
    while (current != NULL)
    {
        printf("Posição %d: %d\n", index, current->data);
        current = current->prev;
        index--;
    }
    printf("Total de elementos: %d\n", list->size);
}

void list_free(List **list)
{
    if (!list || !*list)
    {
        printf("Lista já está liberada ou é inválida.\n");
        return;
    }

    Element *current = (*list)->first;
    int count = 0;
    while (current != NULL)
    {
        Element *temp = current;
        current = current->next;
        free(temp);
        count++;
    }

    free(*list);
    *list = NULL;

    printf("\nMemória liberada com sucesso (%d elementos removidos).\n", count);
}
