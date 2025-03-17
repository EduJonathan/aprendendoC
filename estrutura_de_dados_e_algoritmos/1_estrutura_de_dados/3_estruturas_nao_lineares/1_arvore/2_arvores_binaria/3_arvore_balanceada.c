#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó de uma árvore binária.
 */
typedef struct BinaryTree
{
    int valor;                /**< Valor armazenado no nó */
    struct BinaryTree *left;  /**< Ponteiro para o nó filho à esquerda */
    struct BinaryTree *right; /**< Ponteiro para o nó filho à direita */
} ArvoreBalanceada;

/**
 * @brief Cria um novo nó com um valor especificado.
 *
 * Aloca memória dinamicamente para um nó e inicializa seus valores.
 *
 * @param value Valor a ser armazenado no nó.
 * @return Ponteiro para o nó criado.
 */
ArvoreBalanceada *novoNo(int value)
{
    ArvoreBalanceada *no = (ArvoreBalanceada *)malloc(sizeof(ArvoreBalanceada));

    if (no == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    no->valor = value;
    no->left = NULL;
    no->right = NULL;
    return no;
}

/**
 * @brief Balanceia uma árvore binária a partir de um array ordenado.
 *
 * A árvore é construída de forma que fique balanceada, ou seja, o valor
 * do nó raiz é o valor médio do array, e os elementos à esquerda e à direita
 * formam subárvores balanceadas.
 *
 * @param arr Array ordenado contendo os valores para a árvore.
 * @param begin Índice inicial do array.
 * @param last Índice final do array.
 * @return Ponteiro para a raiz da árvore balanceada.
 */
ArvoreBalanceada *balancearArvore(int *arr, int begin, int last)
{
    if (begin > last)
        return NULL;

    // Encontra o meio do array
    int middle = (begin + last) / 2;

    // Cria um novo nó com o valor do meio
    ArvoreBalanceada *temp = novoNo(arr[middle]);

    // Constrói as subárvores esquerda e direita recursivamente
    temp->left = balancearArvore(arr, begin, middle - 1);
    temp->right = balancearArvore(arr, middle + 1, last);

    return temp;
}

/**
 * @brief Exibe a árvore em pré-ordem (raiz, esquerda, direita).
 *
 * A função visita o nó raiz primeiro, seguido da subárvore esquerda e da
 * subárvore direita, exibindo os valores dos nós.
 *
 * @param tree Ponteiro para a raiz da árvore.
 */
void exibirArvore(ArvoreBalanceada *tree)
{
    if (tree == NULL)
    {
        return;
    }

    printf("%d->", tree->valor); // Visita a raiz
    exibirArvore(tree->left);    // Visita a subárvore esquerda
    exibirArvore(tree->right);   // Visita a subárvore direita
}

/**
 * @brief Libera a memória de uma árvore binária.
 *
 * A função percorre a árvore de forma recursiva e libera a memória de todos
 * os nós da árvore, evitando vazamentos de memória.
 *
 * @param tree Ponteiro para a raiz da árvore.
 */
void liberarArvore(ArvoreBalanceada *tree)
{
    if (tree == NULL)
    {
        return;
    }

    // Libera as subárvores
    liberarArvore(tree->left);
    liberarArvore(tree->right);

    // Libera o nó atual
    free(tree);
}

int main(int argc, char **argv)
{
    // Array ordenado
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Constrói a árvore balanceada
    ArvoreBalanceada *root = balancearArvore(arr, 0, size - 1);

    // Exibe a árvore em pré-ordem
    printf("Árvore balanceada (pré-ordem): ");
    exibirArvore(root);
    printf("\n");

    // Libera a memória alocada para a árvore
    liberarArvore(root);

    return 0;
}
