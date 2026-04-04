#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura para representar um nó de uma lista circular.
 *
 * Cada nó contém um valor e um ponteiro para o próximo nó, formando um ciclo contínuo
 * onde o último nó aponta para o primeiro.
 */
typedef struct node
{
    int value;         /**< Valor armazenado no nó */
    struct node *next; /**< Ponteiro para o próximo nó */
} Node;

/**
 * @brief Verifica se a lista circular está vazia.
 *
 * @param head Ponteiro para a cabeça da lista.
 * @return bool Verdadeiro se a lista está vazia, falso caso contrário.
 */
bool list_is_empty(const Node *head) { return head == NULL; }

/**
 * @brief Obtém o tamanho atual da lista
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
int get_list_size(const Node *head)
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

/**
 * @brief Insere um elemento no final da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 */
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
        last->next     = new_node;
        *head          = new_node;
    }

    printf("Elemento %d inserido na posição 0 (início da lista circular).\n", value);
}

/**
 * @brief Insere um elemento no final da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 */
void list_insert_back(Node **head, int value)
{
    int pos = get_list_size(*head);

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

/**
 * @brief Insere um elemento em uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param value Valor a ser inserido.
 * @param position Posição onde o valor deve ser inserido (começando de 0).
 */
void list_insert_at(Node **head, int value, int position)
{
    if (position < 0)
    {
        printf("Posição inválida! Deve ser não negativa.\n");
        return;
    }

    int current_size = get_list_size(*head);

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

/**
 * @brief Remove o primeiro nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
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

/**
 * @brief Remove o último nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_remove_back(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    Node *current = *head;
    Node *prev    = NULL;
    int pos       = 0;

    while (current->next != *head)
    {
        prev    = current;
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

/**
 * @brief Remove um nó em uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param position Posição do nó a ser removido (começando de 0).
 */
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

    int current_size = get_list_size(*head);
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
    Node *prev    = NULL;

    for (int i = 0; i < position; ++i)
    {
        prev    = current;
        current = current->next;
    }

    int removed_value = current->value;
    prev->next = current->next;
    free(current);

    printf("Elemento %d removido da posição %d da lista circular.\n", removed_value, position);
}

/**
 * @brief Busca um elemento na lista circular.
 *
 * @param head Ponteiro para a cabeça da lista.
 * @param value Valor a ser buscado.
 * @return bool Verdadeiro se o valor for encontrado, falso caso contrário.
 */
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

/**
 * @brief Exibe todos os elementos da lista circular.
 *
 * @param head Ponteiro para a cabeça da lista.
 */
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

/**
 * @brief Libera a memória de todos os nós da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void list_free(Node **head)
{
    if (*head == NULL)
    {
        printf("A lista já está vazia.\n");
        return;
    }

    Node *current = *head;
    Node *first   = *head;
    int count     = 0;

    do
    {
        Node *temp = current;
        current    = current->next;

        free(temp);
        count++;
    } while (current != first);

    *head = NULL;
    printf("Memória da lista circular liberada (%d elementos removidos).\n", count);
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    int option = 0, value = 0, position = 0;

    while (true)
    {
        printf("\n=== Menu de Opções ===\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir em posição específica\n");
        printf("4 - Exibir lista\n");
        printf("5 - Remover no início\n");
        printf("6 - Remover no final\n");
        printf("7 - Remover em posição específica\n");
        printf("8 - Buscar elemento\n");
        printf("9 - Sair\n");
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

            printf("Digite a posição onde deseja inserir: ");
            if (scanf("%d", &position) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_at(&head, value, position);
            break;

        case 4:
            list_print(head);
            break;

        case 5:
            list_remove_front(&head);
            break;

        case 6:
            list_remove_back(&head);
            break;

        case 7:
            printf("Digite a posição do elemento que deseja remover: ");
            if (scanf("%d", &position) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }
            
            list_remove_at(&head, position);
            break;

        case 8:
            printf("Digite o valor a ser buscado: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            if (list_search(head, value))
            {
                printf("O elemento %d foi encontrado na lista.\n", value);
            }
            else
            {
                printf("O elemento %d não foi encontrado na lista.\n", value);
            }
            break;

        case 9:
            list_free(&head);
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        while (getchar() != '\n'); // Limpa buffer
    }

    // Caso a opção 9 não seja escolhida
    list_free(&head);

    return 0;
}
