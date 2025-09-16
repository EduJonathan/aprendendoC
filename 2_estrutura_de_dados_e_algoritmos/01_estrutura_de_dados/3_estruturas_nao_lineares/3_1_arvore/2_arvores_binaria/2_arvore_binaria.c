#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
 * @brief Cria um novo nó com um valor fornecido.
 *
 * Aloca memória para um novo nó, inicializa seu valor e define seus filhos como NULL.
 *
 * @param value O valor a ser armazenado no novo nó.
 * @return Um ponteiro para o novo nó criado ou NULL em caso de falha na alocação.
 */
struct node *newNode(int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Cria uma árvore binária com valores predefinidos.
 *
 * Cria manualmente uma árvore binária com a seguinte estrutura:
 *
 *         10
 *        /  \
 *       5    15
 *      / \   /  \
 *     2   6 12  20
 *
 * @param root Ponteiro para a raiz da árvore (modificado para apontar para a nova árvore).
 * @return Ponteiro para a raiz da árvore criada ou NULL em caso de falha.
 */
struct node *createTree(void)
{
    struct node *root = newNode(10);
    if (root == NULL)
    {
        return NULL;
    }
    
    root->left = newNode(5);
    if (root->left == NULL)
    {
        free(root);
        return NULL;
    }

    root->right = newNode(15);
    if (root->right == NULL)
    {
        free(root->left);
        free(root);
        return NULL;
    }

    root->left->left = newNode(2);
    if (root->left->left == NULL)
    {
        free(root->right);
        free(root->left);
        free(root);
        return NULL;
    }

    root->left->right = newNode(6);
    if (root->left->right == NULL)
    {
        free(root->left->left);
        free(root->right);
        free(root->left);
        free(root);
        return NULL;
    }

    root->right->left = newNode(12);
    if (root->right->left == NULL)
    {
        free(root->left->right);
        free(root->left->left);
        free(root->right);
        free(root->left);
        free(root);
        return NULL;
    }
    
    root->right->right = newNode(20);
    if (root->right->right == NULL)
    {
        free(root->right->left);
        free(root->left->right);
        free(root->left->left);
        free(root->right);
        free(root->left);
        free(root);
        return NULL;
    }
    return root;
}

/**
 * @brief Imprime a travessia em pré-ordem da árvore.
 *
 * A travessia em pré-ordem processa o nó atual, depois a subárvore esquerda e,
 * finalmente, a subárvore direita. Evita espaço extra no final da saída.
 *
 * @param node A raiz da árvore ou subárvore a ser percorrida.
 * @param is_first Indica se é o primeiro nó a ser impresso (evita espaço inicial).
 */
void preOrder(struct node *node, int is_first)
{
    if (node != NULL)
    {
        printf("%d", node->value);

        if (!is_first || node->left || node->right)
        {
            printf(" ");
        }
        preOrder(node->left, 0);
        preOrder(node->right, 0);
    }
}

/**
 * @brief Encontra os valores mínimo e máximo na árvore.
 *
 * Percorre a árvore recursivamente para encontrar o menor e o maior valor,
 * já que a árvore não é uma BST.
 *
 * @param node A raiz da árvore ou subárvore.
 * @param min Ponteiro para armazenar o valor mínimo encontrado.
 * @param max Ponteiro para armazenar o valor máximo encontrado.
 */
void min_and_max(struct node *node, int *min, int *max)
{
    if (node == NULL)
    {
        return;
    }

    // Atualiza mínimo e máximo com o valor do nó atual
    if (node->value < *min)
    {
        *min = node->value;
    }

    if (node->value > *max)
    {
        *max = node->value;
    }

    // Recursivamente percorre as subárvores
    min_and_max(node->left, min, max);
    min_and_max(node->right, min, max);
}

/**
 * @brief Libera a memória alocada para toda a árvore.
 *
 * Libera recursivamente a memória dos filhos esquerdo e direito e, por fim,
 * libera a memória do nó atual.
 *
 * @param node O nó atual a ser liberado.
 */
void freeTree(struct node *node)
{
    if (node != NULL)
    {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main(int argc, char **argv)
{
    // Criando uma árvore binária
    struct node *root = createTree();
    if (root == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação da árvore\n");
        return EXIT_FAILURE;
    }

    // Realizando a travessia em pré-ordem
    printf("Travessia em pré-ordem: ");
    preOrder(root, 1);
    printf("\n");

    // Encontrando e imprimindo os valores mínimo e máximo
    int min = INT_MAX;
    int max = INT_MIN;

    min_and_max(root, &min, &max);
    if (min == INT_MAX || max == INT_MIN)
    {
        printf("A árvore está vazia.\n");
    }
    else
    {
        printf("Mínimo: %d\n", min);
        printf("Máximo: %d\n", max);
    }

    // Liberando a memória alocada
    freeTree(root);

    return 0;
}
