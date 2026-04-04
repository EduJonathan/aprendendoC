#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de um nó da lista duplamente encadeada.
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev) e um ponteiro
 * para o nó seguinte (next). Essa estrutura suporta operações bidirecionais,
 * mas consome mais memória devido aos dois ponteiros por nó.
 */
typedef struct node
{
    int data;          /**< Valor armazenado no nó */
    struct node *prev; /**< Ponteiro para o nó anterior */
    struct node *next; /**< Ponteiro para o próximo nó */
} Node;

/**
 * @brief Exibe o tamanho da lista
 *
 * Pecorre toda a lista para verificar o tamanho da lista
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
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

/**
 * @brief Libera toda a memória alocada para os nós da lista.
 *
 * Percorre a lista e libera cada nó, definindo o ponteiro da cabeça como NULL.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
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
    printf("\nMemória liberada com sucesso!\n");
}

/**
 * @brief Insere um novo nó no início da lista.
 *
 * Cria um novo nó com o valor especificado e o insere no início da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 */
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

/**
 * @brief Insere um novo nó no final da lista.
 *
 * Cria um novo nó com o valor especificado e o insere no final da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 */
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

/**
 * @brief Insere um novo nó após uma posição específica na lista.
 *
 * Cria um novo nó com o valor especificado e o insere após a posição indicada.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor a ser armazenado no novo nó.
 * @param pos Posição após a qual o novo nó será inserido (começando de 0).
 */
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

/**
 * @brief Remove o nó do início da lista.
 *
 * Remove o primeiro nó da lista, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
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

/**
 * @brief Remove o nó do final da lista.
 *
 * Remove o último nó da lista, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
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

/**
 * @brief Remove um nó específico com base no valor.
 *
 * Remove o primeiro nó que contém o valor especificado, liberando sua memória.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value Valor do nó a ser removido.
 */
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

/**
 * @brief Exibe todos os elementos da lista.
 *
 * Percorre a lista e imprime os valores de cada nó em formato bidirecional.
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
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

int main(int argc, char **argv)
{
    Node *head = NULL;
    int option = 0, value = 0, pos = 0;

    while (true)
    {
        printf("\n=== Menu de Opções ===\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir após uma posição\n");
        printf("4 - Deletar do início\n");
        printf("5 - Deletar do final\n");
        printf("6 - Deletar nó específico\n");
        printf("7 - Exibir lista\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &option) != 1)
        {
            while (getchar() != '\n'); // Limpa buffer
            printf("Entrada inválida!\n");
            continue;
        }

        switch (option)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_front(&head, value);
            break;

        case 2:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_back(&head, value);
            break;

        case 3:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            printf("Digite a posição após a qual inserir: ");
            if (scanf("%d", &pos) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_after(&head, value, pos);
            break;

        case 4:
            list_remove_front(&head);
            break;

        case 5:
            list_remove_back(&head);
            break;

        case 6:
            printf("Digite o valor do nó a ser deletado: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_remove_value(&head, value);
            break;

        case 7:
            list_print(head);
            break;

        case 8:
            list_free(&head);
            return 0;

        default:
            printf("Opção inválida!\n");
        }
        while (getchar() != '\n'); // Limpa buffer
    }

    // Caso a opção 8 não for escolhida
    list_free(&head);
    return 0;
}
