#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó da lista encadeada.
 *
 * Cada nó contém um valor inteiro e um ponteiro para o próximo nó.
 */
struct Node
{
    int valor;         /**< Valor armazenado no nó. */
    struct Node *prox; /**< Ponteiro para o próximo nó da lista. */
};

/**
 * @brief Insere um novo elemento no final da lista encadeada.
 *
 * @param[in,out] inicio Ponteiro para o ponteiro do início da lista.
 * @param[in] valor Valor a ser inserido na lista.
 */
void inserir(struct Node **inicio, int valor)
{
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    novo->valor = valor;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        struct Node *temp = *inicio;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

/**
 * @brief Exibe todos os elementos da lista encadeada.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 */
void exibirLista(struct Node *inicio)
{
    printf("Lista: ");
    while (inicio != NULL)
    {
        printf("%d -> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

/**
 * @brief Libera toda a memória alocada para a lista encadeada.
 *
 * @param[in] inicio Ponteiro para o início da lista.
 */
void liberarLista(struct Node *inicio)
{
    struct Node *temp;
    while (inicio != NULL)
    {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    struct Node *lista = NULL;

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);

    exibirLista(lista);

    liberarLista(lista);

    return 0;
}
