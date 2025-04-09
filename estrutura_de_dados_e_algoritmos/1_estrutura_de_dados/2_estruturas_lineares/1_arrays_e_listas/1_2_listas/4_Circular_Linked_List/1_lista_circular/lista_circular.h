#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um nó de uma lista circular.
 * 
 * LISTA CIRCULAR é uma variação da lista encadeada onde o último nó não aponta para NULL, 
 * como nas listas tradicionais, mas sim para o primeiro nó da lista. Isso cria um ciclo, 
 * ou seja, ao tentar acessar o "próximo" de um nó que é o último, o ponteiro "próximo" 
 * aponta para o primeiro nó, formando um loop contínuo.
 */
typedef struct lista
{
    int value;          ///< Valor armazenado no nó.
    struct lista *next; ///< Ponteiro para o próximo nó.
} listaCircular;

/**
 * @brief Função para inserir um elemento no início da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param valor Valor a ser inserido.
 */
void inserirNoInicio(listaCircular **head, int valor)
{
    listaCircular *novoNo = (listaCircular *)malloc(sizeof(listaCircular));
    novoNo->value = valor;

    if (*head == NULL)
    {
        *head = novoNo;
        novoNo->next = *head;
    }
    else
    {
        listaCircular *temp = *head;

        while (temp->next != *head)
        {
            temp = temp->next;
        }

        novoNo->next = *head;
        *head = novoNo;
        temp->next = *head;
    }
    printf("O elemento %d foi inserido no início da lista circular.\n", valor);
}

/**
 * @brief Função para inserir um elemento no final da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param valor Valor a ser inserido.
 */
void inserirNoFinal(listaCircular **head, int valor)
{
    listaCircular *novoNo = (listaCircular *)malloc(sizeof(listaCircular));
    novoNo->value = valor;

    if (*head == NULL)
    {
        *head = novoNo;
        novoNo->next = *head;
    }
    else
    {
        listaCircular *temp = *head;

        while (temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = novoNo;
        novoNo->next = *head;
    }
    printf("O elemento %d foi inserido no final da lista circular.\n", valor);
}

/**
 * @brief Função para exibir todos os elementos da lista circular.
 *
 * @param head Ponteiro para a cabeça da lista.
 */
void exibirLista(listaCircular *head)
{
    listaCircular *temp = head;

    if (head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    do
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    } while (temp != head);
    printf("(início)\n");
}

/**
 * @brief Função para liberar a memória de todos os nós da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void liberarMemoria(listaCircular **head)
{
    listaCircular *temp = *head;
    listaCircular *aux = NULL;

    if (*head == NULL)
    {
        printf("A lista já está vazia.\n");
        return;
    }

    // Caso a lista tenha apenas um nó
    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        do
        {
            aux = temp;
            temp = temp->next;
            free(aux);
        } while (temp != *head);

        *head = NULL;
    }
    printf("Memória da lista liberada.\n");
}

/**
 * @brief Função para remover o primeiro nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void removerNoInicio(listaCircular **head)
{
    listaCircular *temp = *head;
    listaCircular *aux = NULL;

    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
    }
    else
    {
        if (temp->next == *head)
        {
            free(temp);
            *head = NULL;
        }
        else
        {
            while (temp->next != *head)
            {
                temp = temp->next;
            }

            aux = *head;
            *head = (*head)->next;
            temp->next = *head;
            free(aux);
        }
        printf("O elemento foi removido do início da lista circular.\n");
    }
}

/**
 * @brief Função para remover o último nó da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 */
void removerNoFinal(listaCircular **head)
{
    listaCircular *temp = *head;
    listaCircular *aux = NULL;

    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
    }
    else
    {
        if (temp->next == *head)
        {
            free(temp);
            *head = NULL;
        }
        else
        {
            while (temp->next != *head)
            {
                temp = temp->next;
            }

            aux = temp;
            temp = *head;
            *head = (*head)->next;
            aux->next = *head;
            free(temp);
        }        
        printf("O elemento foi removido do final da lista circular.\n");
    }
}

/**
 * @brief Função para inserir um elemento em uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param valor Valor a ser inserido.
 * @param posicao Posição onde o valor deve ser inserido.
 */
void inserirEmPosicao(listaCircular **head, int valor, int posicao)
{
    listaCircular *novoNo = (listaCircular *)malloc(sizeof(listaCircular));
    novoNo->value = valor;

    if (*head == NULL)
    {
        // Se a lista estiver vazia, insere como o único elemento
        *head = novoNo;
        novoNo->next = *head;
        printf("O elemento %d foi inserido na posição 0 (lista vazia).\n", valor);
    }
    else
    {
        listaCircular *temp = *head;
        int contador = 0;

        // Caso a posição seja 0, insere no início
        if (posicao == 0)
        {
            novoNo->next = *head;
            *head = novoNo;

            // Atualiza o último nó para apontar para o novo head
            while (temp->next != *head)
            {
                temp = temp->next;
            }
            temp->next = *head;

            printf("O elemento %d foi inserido no início da lista circular.\n", valor);
        }
        else
        {
            // Percorrer a lista até a posição desejada
            while (temp->next != *head && contador < posicao - 1)
            {
                temp = temp->next;
                contador++;
            }

            if (contador == posicao - 1)
            {
                // Insere o nó após a posição encontrada
                novoNo->next = temp->next;
                temp->next = novoNo;
                printf("O elemento %d foi inserido na posição %d da lista circular.\n", valor, posicao);
            }
            else
            {
                printf("Posição inválida! A lista tem menos que %d elementos.\n", posicao);
                free(novoNo);
            }
        }
    }
}

/**
 * @brief Função para remover um nó de uma posição específica da lista circular.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista.
 * @param posicao Posição do nó a ser removido.
 */
void removerEmPosicao(listaCircular **head, int posicao)
{
    listaCircular *temp1 = *head;
    listaCircular *temp2 = NULL;
    int contador = 0;

    if (*head == NULL)
    {
        printf("A lista circular está vazia!\n");
        return;
    }

    // Se a posição for 0, remove o primeiro nó
    if (posicao == 0)
    {
        // Se a lista tem apenas um elemento
        if (*head == (*head)->next)
        {
            free(*head);
            *head = NULL;
            printf("Elemento removido da posição 0 (lista com um único elemento).\n");
            return;
        }

        // Se a lista tem mais de um nó
        while (temp1->next != *head)
        {
            temp1 = temp1->next;
        }

        // Ajusta o head para o próximo nó e o último nó aponta para o novo head
        temp1->next = (*head)->next;
        free(*head);
        *head = temp1->next;
        printf("Elemento removido da posição 0 da lista circular.\n");
    }
    else
    {
        // Percorre a lista até a posição desejada
        while (temp1->next != *head && contador < posicao)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            contador++;
        }

        if (contador == posicao)
        {
            // Se o nó a ser removido não for o último
            temp2->next = temp1->next;
            free(temp1);
            printf("Elemento removido da posição %d da lista circular.\n", posicao);
        }
        else
        {
            printf("Posição inválida! A lista tem menos que %d elementos.\n", posicao);
        }
    }
}

#endif
