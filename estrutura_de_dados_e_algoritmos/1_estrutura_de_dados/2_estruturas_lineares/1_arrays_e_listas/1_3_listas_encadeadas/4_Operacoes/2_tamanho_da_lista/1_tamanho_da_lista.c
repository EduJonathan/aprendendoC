#include <stdio.h>
#include <stdlib.h>

/** O tamanho de uma lista refere-se ao número de elementos presentes na lista */

/**
 * @brief Estrutura que representa um nó de uma lista encadeada.
 */
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
 * @brief Calcula o tamanho da lista encadeada de forma iterativa.
 *
 * Esta função percorre a lista encadeada iterativamente, contando o número de elementos.
 *
 * @param head Ponteiro para o primeiro nó da lista encadeada.
 * @return size_t O tamanho da lista encadeada.
 */
size_t tamanhoDaLista(struct node *head)
{
    size_t tamanho = 0;
    struct node *current = head;

    while (current != NULL)
    {
        tamanho++;               // Conta o nó
        current = current->next; // Move para o próximo nó
    }
    return tamanho;
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
    struct node *head = NULL;                                // Inicializa a lista vazia
    gerarLista(&head);                                       // Gera a lista com 10 elementos
    printf("Tamanho da lista: %zu\n", tamanhoDaLista(head)); // Exibe o tamanho da lista
    liberarLista(&head);                                     // Libera a memória alocada pela lista
    return 0;
}
