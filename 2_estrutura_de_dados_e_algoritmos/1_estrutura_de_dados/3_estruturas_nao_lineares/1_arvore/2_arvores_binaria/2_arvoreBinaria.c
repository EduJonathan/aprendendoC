#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Representa um nó na árvore binária.
 *
 * Cada nó contém um valor inteiro e ponteiros para seus filhos esquerdo e direito.
 */
struct node
{
    int value;          /**< O valor armazenado no nó. */
    struct node *left;  /**< Ponteiro para o filho esquerdo do nó. */
    struct node *right; /**< Ponteiro para o filho direito do nó. */
};

/**
 * @brief A raiz da árvore binária (variável global).
 *
 * Esta variável armazena o ponteiro para o nó raiz da árvore binária.
 */
struct node *root = NULL; /**< A raiz da árvore binária, inicializada como NULL. */

/**
 * @brief Cria um novo nó com um valor fornecido.
 *
 * Aloca memória para um novo nó, inicializa seu valor e define seus filhos como NULL.
 *
 * @param value O valor a ser armazenado no novo nó.
 * @return Um ponteiro para o novo nó criado.
 */
struct node *newNode(int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Cria uma árvore binária com valores predefinidos.
 *
 * Esta função cria manualmente uma árvore binária com a seguinte estrutura:
 *
 *         10
 *        /  \
 *       5    15
 *      / \   /  \
 *     2   6 12  20
 */
void createTree(void)
{
    root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
}

/**
 * @brief Imprime a travessia em pré-ordem da árvore.
 *
 * A travessia em pré-ordem significa que o nó atual é processado primeiro, depois
 * a subárvore esquerda e, finalmente, a subárvore direita.
 *
 * @param node A raiz da árvore ou subárvore a ser percorrida.
 */
void preOrder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->value);
        preOrder(node->left);
        preOrder(node->right);
    }
}

/**
 * @brief Encontra e imprime os valores mínimo e máximo na árvore.
 *
 * O valor mínimo é encontrado ao seguir os ponteiros do filho esquerdo até atingir
 * um nó folha. O valor máximo é encontrado ao seguir os ponteiros do filho direito.
 *
 * @param node A raiz da árvore ou subárvore para encontrar o mínimo e o máximo.
 */
void min_and_max(struct node *node)
{
    if (node == NULL)
    {
        printf("A árvore está vazia.\n");
        return;
    }

    // Encontrando o valor mínimo
    while (node->left != NULL)
    {
        // Seguindo os ponteiros do filho esquerdo
        node = node->left;
    }
    printf("Mínimo: %d\n", node->value);

    node = root; // Resetando para a raiz

    // Encontrando o valor máximo
    while (node->right != NULL)
    {
        // Seguindo os ponteiros do filho direito
        node = node->right;
    }

    printf("Máximo: %d\n", node->value);
}

/**
 * @brief Libera a memória alocada para toda a árvore.
 *
 * Esta função libera recursivamente a memória dos filhos esquerdo e direito e,
 * por fim, libera a memória do nó atual.
 *
 * @param node O nó atual a ser liberado.
 */
void freeTree(struct node *node)
{
    if (node != NULL)
    {
        freeTree(node->left);
        freeTree(node->right);
        free(node); // Liberando o nó atual
    }
}

int main(int argc, char **argv)
{
    // Criando uma árvore binária
    createTree();

    // Realizando a travessia em pré-ordem
    printf("Travessia em pré-ordem: ");
    preOrder(root);
    printf("\n");

    // Encontrando e imprimindo os valores mínimo e máximo
    min_and_max(root);

    // Liberando a memória alocada
    freeTree(root);

    return 0;
}
