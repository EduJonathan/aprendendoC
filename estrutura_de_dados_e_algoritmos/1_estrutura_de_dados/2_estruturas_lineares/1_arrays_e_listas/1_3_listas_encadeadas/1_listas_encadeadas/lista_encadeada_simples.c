#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa uma lista encadeada
 *
 * LISTA ENCADEADA: É uma estrutura de dados dinâmica onde os elementos (chamados de nós) são
 * ligados entre si por ponteiros. Cada nó armazena um valor (dado) e o endereço do próximo nó
 * da lista. O primeiro nó é chamado de "cabeça" (head) e o último aponta para NULL.
 */
struct node
{
    int no;
    struct node *prox;
};

/**
 * @brief Exibe a lista encadeada
 *
 * @param no Informar ponteiro para estrutura para exibir os nós interligados
 */
void exibirLista(struct node *no)
{
    int i = 0;
    while (no != NULL)
    {
        printf("[%dº] no: %d -> ", i, no->no);
        no = no->prox; // Avança para o próximo nó
        i++;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    struct node *primeiro = NULL;
    struct node *segundo = NULL;
    struct node *terceiro = NULL;

    // Alocação dinâmica e preenchimento do primeiro nó
    primeiro = (struct node *)malloc(sizeof(struct node));
    if (primeiro == NULL)
    {
        printf("Erro ao alocar memória para o primeiro nó.\n");
        return 1;
    }
    primeiro->no = 10;
    primeiro->prox = NULL;

    // Alocação e preenchimento do segundo nó
    segundo = (struct node *)malloc(sizeof(struct node));
    if (segundo == NULL)
    {
        printf("Erro ao alocar memória para o segundo nó.\n");
        free(primeiro);
        return 1;
    }
    segundo->no = 20;
    segundo->prox = NULL;
    primeiro->prox = segundo; // Liga primeiro -> segundo

    // Alocação e preenchimento do terceiro nó
    terceiro = (struct node *)malloc(sizeof(struct node));
    if (terceiro == NULL)
    {
        printf("Erro ao alocar memória para o terceiro nó.\n");
        free(segundo);
        free(primeiro);
        return 1;
    }
    terceiro->no = 30;
    terceiro->prox = NULL;
    segundo->prox = terceiro; // Liga segundo -> terceiro

    // Exibe a lista encadeada
    printf("Conteúdo da lista encadeada:\n");
    exibirLista(primeiro);

    // Libera a memória alocada
    free(terceiro);
    free(segundo);
    free(primeiro);

    return 0;
}
