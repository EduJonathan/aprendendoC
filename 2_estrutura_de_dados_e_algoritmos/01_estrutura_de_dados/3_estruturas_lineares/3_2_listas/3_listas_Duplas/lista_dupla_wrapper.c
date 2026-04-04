#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um elemento da lista duplamente encadeada.
 *
 * Cada elemento contém um valor (data) e ponteiros para o próximo e o anterior elemento.
 */
typedef struct element
{
    int data;             /**< Valor armazenado no elemento */
    struct element *next; /**< Ponteiro para o próximo elemento */
    struct element *prev; /**< Ponteiro para o elemento anterior */
} Element;

/**
 * @brief Estrutura que representa uma lista duplamente encadeada.
 *
 * Contém um ponteiro para o primeiro e o último elemento, além de controlar a quantidade de elementos.
 */
typedef struct list
{
    unsigned int size; /**< Quantidade de elementos na lista */
    Element *first;    /**< Ponteiro para o primeiro elemento da lista */
    Element *last;     /**< Ponteiro para o último elemento da lista */
} List;

/**
 * @brief Cria uma nova lista vazia.
 *
 * Aloca memória para a lista e inicializa seus atributos.
 *
 * @return Ponteiro para a lista recém-criada, ou NULL em caso de falha.
 */
List *list_create(void)
{
    List *list = malloc(sizeof(List));
    if (!list)
    {
        fprintf(stderr, "Erro ao alocar memória para a lista!\n");
        return NULL;
    }
    list->size  = 0;
    list->first = NULL;
    list->last  = NULL;
    printf("Lista criada com sucesso.\n");
    return list;
}

/**
 * @brief Adiciona um novo elemento ao final da lista.
 *
 * Cria um novo elemento com o valor especificado e o insere no final da lista.
 *
 * @param list Ponteiro para a lista onde o elemento será inserido.
 * @param data Valor do elemento a ser adicionado.
 */
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
        list->last  = new_element;
        printf("Nó com valor %d inserido na posição 0 (primeiro elemento).\n", data);
    }
    else
    {
        list->last->next = new_element;
        list->last       = new_element;
        printf("Nó com valor %d inserido na posição %d (final da lista).\n", data, list->size);
    }

    list->size++;
}

/**
 * @brief Imprime os elementos da lista do início ao fim.
 *
 * Percorre a lista do primeiro para o último elemento e imprime seus valores.
 *
 * @param list Ponteiro para a lista a ser impressa.
 */
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

/**
 * @brief Imprime os elementos da lista do fim ao início.
 *
 * Percorre a lista do último para o primeiro elemento e imprime seus valores.
 *
 * @param list Ponteiro para a lista a ser impressa.
 */
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

/**
 * @brief Libera toda a memória alocada para a lista e seus elementos.
 *
 * Percorre a lista, libera cada elemento e, em seguida, libera a estrutura da lista.
 *
 * @param list Ponteiro para a lista a ser liberada.
 */
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
        current       = current->next;
        free(temp);
        count++;
    }

    free(*list);
    *list = NULL;

    printf("\nMemória liberada com sucesso (%d elementos removidos).\n", count);
}

int main(int argc, char **argv)
{
    List *list = list_create();
    if (!list)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < 15; i++)
    {
        list_append(list, (i + 1) * 10);
    }

    printf("Lista em ordem normal:\n");
    list_print_forward(list);

    printf("\nLista em ordem reversa:\n");
    list_print_reverse(list);

    list_free(&list);

    return 0;
}
