#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de um nó da lista duplamente encadeada
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev) e um ponteiro
 * para o nó seguinte (next). Essa estrutura é útil para operações bidirecionais, como
 * percorrimento reverso, mas consome mais memória devido aos dois ponteiros por nó.
 */
typedef struct node
{
    int data;          /**< O valor armazenado no nó */
    struct node *next; /**< Ponteiro para o nó seguinte na lista */
    struct node *prev; /**< Ponteiro para o nó anterior na lista */
} Node;

/**
 * @brief Insere um nó no início da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido no novo nó.
 */
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

/**
 * @brief Insere um nó no final da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido no novo nó.
 */
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

/**
 * @brief Remove o nó do início da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
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

/**
 * @brief Remove o nó do final da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
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

/**
 * @brief Remove um nó específico com base no valor.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor do nó a ser removido.
 */
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

/**
 * @brief Imprime os elementos da lista.
 *
 * @param head Ponteiro para a cabeça da lista.
 */
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

/**
 * @brief Libera toda a memória alocada pela lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
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

int main(int argc, char **argv)
{
    Node *head = NULL; // A cabeça é local na função main

    // Testando a lista duplamente encadeada
    list_insert_front(&head, 10);
    list_insert_front(&head, 20);
    list_insert_back(&head, 30);
    list_insert_back(&head, 40);
    list_insert_back(&head, 50);

    printf("\nLista após inserções: ");
    list_print(head);

    printf("\n------------------------------------\n");
    list_remove_front(&head); // Deleta o nó inicial de valor 20

    printf("\n------------------------------------\n");
    printf("Lista após remoção do início: ");

    list_print(head);
    list_remove_back(&head); // Deleta o nó final de valor 50

    printf("\n------------------------------------\n");
    printf("Lista após remoção do final: ");

    list_print(head);
    list_remove_value(&head, 10); // Deleta o nó com o valor 10

    printf("\n------------------------------------\n");
    printf("Lista após deleção especificada: ");
    list_print(head);

    list_free(&head);

    return 0;
}
