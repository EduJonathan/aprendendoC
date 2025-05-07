#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // Dados armazenados no nó
    struct node *next; // Ponteiro para o próximo nó
};

/**
 * @brief Gera uma lista encadeada com 10 elementos.
 *
 * Esta função cria 10 nós e os insere no início da lista. O valor de cada nó
 * é o índice da iteração (0 a 9).
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista encadeada.
 */
void gerarLista(struct node **head)
{
    int num = 10;
    struct node *temp = NULL;

    for (int i = 0; i < num; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node)); // Aloca memória para o novo nó
        temp->data = i;                                    // Atribui o valor i ao nó

        if (*head == NULL)
        {
            *head = temp;         // Primeiro nó da lista
            (*head)->next = NULL; // Ponteiro next do primeiro nó aponta para NULL
        }
        else
        {
            temp->next = *head; // Insere no início
            *head = temp;       // Atualiza o ponteiro da cabeça
        }
    }
}

/**
 * @brief Calcula o tamanho da lista encadeada.
 *
 * Esta função calcula recursivamente o número de elementos na lista.
 *
 * @param head Ponteiro para o primeiro nó da lista encadeada.
 * @return int O tamanho da lista encadeada.
 */
int tamanhoDaListaRecursivo(struct node *head)
{
    if (head == NULL)
    {
        return 0; // Lista vazia, tamanho é 0
    }
    return 1 + tamanhoDaListaRecursivo(head->next); // Contagem recursiva
}

/**
 * @brief Libera toda a memória alocada pela lista encadeada.
 *
 * Esta função percorre a lista encadeada e libera a memória de cada nó.
 * Após a liberação, o ponteiro `head` é atualizado para NULL.
 *
 * @param head Ponteiro para o ponteiro da cabeça da lista encadeada.
 */
void liberarLista(struct node **head)
{
    struct node *temp = NULL;

    // Enquanto houver nós na lista, continue a liberar
    while (*head != NULL)
    {
        temp = *head;          // Salva o nó atual
        *head = (*head)->next; // Move o ponteiro head para o próximo nó
        free(temp);            // Libera o nó atual
    }
}

int main(int argc, char **argv)
{
    struct node *head = NULL;                                        // Inicializa a lista vazia
    gerarLista(&head);                                               // Gera a lista com 10 elementos
    printf("Tamanho da lista: %d\n", tamanhoDaListaRecursivo(head)); // Exibe o tamanho da lista
    liberarLista(&head);                                             // Libera a memória alocada pela lista
    return 0;
}
