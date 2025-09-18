#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó de uma árvore binária de busca balanceada.
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
 * @return Ponteiro para o nó criado ou NULL em caso de falha na alocação.
 */
ArvoreBalanceada *novoNo(int value)
{
    ArvoreBalanceada *no = (ArvoreBalanceada *)malloc(sizeof(ArvoreBalanceada));
    if (no == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
    no->valor = value;
    no->left = NULL;
    no->right = NULL;
    return no;
}

/**
 * @brief Balanceia uma árvore binária a partir de um array ordenado.
 *
 * Constrói uma BST balanceada usando o valor central do array como raiz.
 * O array deve estar ordenado em ordem crescente, e duplicatas não são tratadas.
 *
 * @param arr Array ordenado contendo os valores para a árvore.
 * @param begin Índice inicial do array.
 * @param last Índice final do array.
 * @return Ponteiro para a raiz da árvore balanceada ou NULL se o array for inválido.
 */
ArvoreBalanceada *balancearArvore(int *arr, int begin, int last)
{
    if (arr == NULL || begin > last || begin < 0)
    {
        return NULL;
    }

    // Encontra o meio do array de forma segura
    int middle = begin + (last - begin) / 2;

    // Cria um novo nó com o valor do meio
    ArvoreBalanceada *temp = novoNo(arr[middle]);
    if (temp == NULL)
    {
        return NULL;
    }

    // Constrói as subárvores esquerda e direita recursivamente
    temp->left = balancearArvore(arr, begin, middle - 1);
    temp->right = balancearArvore(arr, middle + 1, last);
    return temp;
}

/**
 * @brief Exibe a árvore em pré-ordem (raiz, esquerda, direita).
 *
 * Visita o nó raiz primeiro, seguido da subárvore esquerda e da subárvore direita,
 * exibindo os valores sem espaço extra no final.
 *
 * @param tree Ponteiro para a raiz da árvore.
 * @param is_first Indica se é o primeiro nó a ser impresso (evita espaço inicial).
 */
void exibirPreOrdem(ArvoreBalanceada *tree, int is_first)
{
    if (tree == NULL)
    {
        return;
    }

    printf("%d", tree->valor);
    if (!is_first || tree->left || tree->right)
    {
        printf(" ");
    }
    exibirPreOrdem(tree->left, 0);
    exibirPreOrdem(tree->right, 0);
}

/**
 * @brief Libera a memória de uma árvore binária.
 *
 * Percorre a árvore recursivamente e libera a memória de todos os nós,
 * evitando vazamentos de memória.
 *
 * @param tree Ponteiro para a raiz da árvore.
 */
void liberarArvore(ArvoreBalanceada *tree)
{
    if (tree == NULL)
    {
        return;
    }
    liberarArvore(tree->left);
    liberarArvore(tree->right);
    free(tree);
}

int main(int argc, char **argv)
{
    // Array ordenado
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Constrói a árvore balanceada
    ArvoreBalanceada *root = balancearArvore(arr, 0, size - 1);
    if (root == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação da árvore\n");
        return EXIT_FAILURE;
    }

    // Exibe a árvore em pré-ordem
    printf("Árvore balanceada (pré-ordem): ");
    exibirPreOrdem(root, 1);
    printf("\n");

    // Libera a memória alocada para a árvore
    liberarArvore(root);

    return 0;
}
