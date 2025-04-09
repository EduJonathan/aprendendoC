#ifndef IMPLEMENTACAO_H
#define IMPLEMENTACAO_H

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
 * @brief Cria uma lista encadeada a partir de entradas do usuário.
 *
 * A função solicita ao usuário que insira valores para formar uma lista encadeada.
 * O processo continua até que o usuário decida parar.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * A lista será criada no endereço apontado por `head`.
 */
void createLista(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *rear = NULL;
    int Continuar = 0;
    int numero = 0;

    do
    {
        printf("Digite um valor: ");
        scanf("%d", &numero);

        // Aloca memória para o novo nó
        temp = (struct Node *)malloc(sizeof(struct Node));

        // Verifica se a alocação de memória falhou
        if (temp == NULL)
        {
            printf("Erro ao alocar memória!\n");
            return; // Sai da função se não for possível alocar memória.
        }

        temp->data = numero; // Armazena o valor digitado no nó
        temp->next = NULL;   // Não ha nenhum nó seguinte

        // Insere o novo nó na cabeça da lista
        if (*head == NULL)
        {
            // Primeiro nó da lista
            *head = temp;
        }
        else
        {
            // Conecta o nó anterior ao novo nó
            rear->next = temp;
        }

        // Atualiza o "rear" para o último nó inserido
        rear = temp;

        printf("Deseja continuar? 1 - Sim | 0 - Não: ");
        scanf("%d", &Continuar);
    } while (Continuar != 0);
}

/**
 * @brief Exibe os elementos da lista encadeada.
 *
 * A função percorre a lista encadeada e imprime todos os elementos armazenados nela.
 *
 * @param head Ponteiro para o primeiro nó da lista.
 */
void printLista(struct Node *head)
{
    // Verifica se a lista está vazia
    if (head == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Percorre a lista e imprime os valores
    printf("Elementos da lista: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/**
 * @brief Reverte uma lista encadeada.
 *
 * A função reverte a ordem dos nós na lista encadeada, ajustando os ponteiros
 * `next` de forma a inverter a direção da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void reverseLista(struct Node **head)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Salva o próximo nó
        current->next = prev; // Inverte o ponteiro do nó atual
        prev = current;       // Move prev para o nó atual
        current = next;       // Move current para o próximo nó
    }

    // Atualiza a cabeça da lista para o último nó, agora o primeiro
    *head = prev;
}

/**
 * @brief Exemplo de função que imprime a lista revertendo os valores de forma recursiva
 *
 * @param head Ponteiro cabeça da lista.
 */
void reverseListaRecursiva(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    reverseListaRecursiva(head->next);
    printf("%d ", head->data);
}

/**
 * @brief Libera a memória alocada para a lista encadeada.
 *
 * A função percorre a lista e libera toda a memória alocada para cada nó da lista.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * Após a execução, `head` será atualizado para NULL.
 */
void liberaLista(struct Node **head)
{
    // Atribui ao *temp o ponteiro apontado por *head
    struct Node *temp = *head;

    // Percorre a lista e libera cada nó
    while (*head != NULL)
    {
        temp = *head;          // Salva o nó atual
        *head = (*head)->next; // Move o ponteiro para o próximo nó
        free(temp);            // Libera a memória do nó atual
    }
    *head = NULL; // Atualiza o ponteiro `head` para NULL
}

#endif
