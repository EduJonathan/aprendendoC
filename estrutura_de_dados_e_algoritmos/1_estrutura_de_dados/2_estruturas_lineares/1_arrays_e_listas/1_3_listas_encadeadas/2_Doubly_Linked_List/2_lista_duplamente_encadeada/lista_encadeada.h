#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura de um nó de uma lista duplamente encadeada.
 *
 * Cada nó contém um valor (data), um ponteiro para o nó anterior (prev)
 * e um ponteiro para o próximo nó (next).
 */
struct node
{
    int data;          ///< Valor armazenado no nó.
    struct node *prev; ///< Ponteiro para o nó anterior.
    struct node *next; ///< Ponteiro para o próximo nó.
};

/**
 * @brief Libera toda a memória alocada para os nós da lista.
 *
 * Esta função percorre a lista e libera a memória de cada nó. Ao final,
 * a memória de toda a lista é liberada e a função imprime uma mensagem.
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
void liberarMemoria(struct node *head)
{
    struct node *temp = NULL;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nMemória liberada com sucesso!\n");
}

/**
 * @brief Insere um novo nó no início da lista.
 *
 * Esta função cria um novo nó com o valor especificado e o insere no início da lista.
 * Caso a lista esteja vazia, o nó se torna o primeiro e o último nó da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param valor O valor a ser armazenado no novo nó.
 */
void inserirNoInicio(struct node **head, int valor)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return;
    }

    newNode->data = valor;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("\nNó %d inserido no início!\n", newNode->data);
}

/**
 * @brief Insere um novo nó no final da lista.
 *
 * Esta função cria um novo nó com o valor especificado e o insere no final da lista.
 * Caso a lista esteja vazia, o nó se torna o primeiro e o último nó da lista.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param valor O valor a ser armazenado no novo nó.
 */
void inserirNoFinal(struct node **head, int valor)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return;
    }

    newNode->data = valor;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        struct node *lastNode = *head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    printf("\nNó %d inserido no final!\n", newNode->data);
}

/**
 * @brief Insere um nó após um nó específico na lista.
 *
 * Esta função cria um novo nó com o valor especificado e o insere após a posição indicada.
 * Se a posição fornecida for inválida, a operação não será realizada.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param valor O valor a ser armazenado no novo nó.
 * @param pos A posição após a qual o novo nó será inserido (começando de 0).
 */
void insertAfter(struct node **head, int valor, int pos)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;

    if (newNode == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return;
    }

    newNode->data = valor;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        // Percorre até a posição especificada
        for (int i = 0; i < pos; i++)
        {
            if (temp == NULL)
            {
                printf("\nPosição inválida!\n");
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("\nNó %d inserido depois do nó %d!\n", newNode->data, temp->data);
    }
}

/**
 * @brief Deleta o nó do início da lista.
 *
 * Esta função remove o primeiro nó da lista. Se a lista estiver vazia, imprime uma mensagem de erro.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
void deletarNoInicio(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }

    struct node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("\nNó do início deletado!\n");
}

/**
 * @brief Deleta o nó do final da lista.
 *
 * Esta função remove o último nó da lista. Se a lista estiver vazia, imprime uma mensagem de erro.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 */
void deletarNoFinal(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }

    struct node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL; // Lista só tinha um nó
    }

    free(temp);
    printf("\nNó do final deletado!\n");
}

/**
 * @brief Deleta um nó específico baseado no valor fornecido.
 *
 * Esta função remove o nó que contém o valor especificado.
 * Se o valor não for encontrado, imprime uma mensagem de erro.
 *
 * @param head Ponteiro para o ponteiro do primeiro nó da lista.
 * @param value O valor do nó a ser removido.
 */
void delecaoEspecifica(struct node **head, int value)
{
    if (*head == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }

    struct node *temp = *head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nNó com valor %d não encontrado!\n", value);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next; // Está deletando o primeiro nó
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("\nNó com valor %d deletado!\n", value);
}

/**
 * @brief Exibe todos os elementos da lista.
 *
 * Esta função percorre a lista duplamente encadeada e exibe os valores de cada nó.
 * Se a lista estiver vazia, imprime uma mensagem informando que a lista está vazia.
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
void exibirLista(struct node *head)
{
    if (head == NULL)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        struct node *temp = head;
        printf("\nLista: ");
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

#endif
