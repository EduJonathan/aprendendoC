#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura de uma arvore binária de busca (BST)
 *
 * Esta estrutura armazena um valor, um ponteiro para o filho esquerdo
 * e um ponteiro para o filho direito
 */
typedef struct node
{
    int data;           /**< O valor armazenado na arvore */
    struct node *left;  /**< Ponteiro para o filho esquerdo */
    struct node *right; /**< Ponteiro para o filho direito */
} TREE;

#endif

/**
 * @brief Cria um novo nó na árvore.
 *
 * @param data O valor a ser armazenado no nó.
 * @return Ponteiro para o nó criado.
 */
TREE *createNode(int data)
{
    TREE *node = (TREE *)malloc(sizeof(TREE)); // Aloca memória para o nó
    node->data = data;                         // Atribui o valor ao nó
    node->left = NULL;                         // Inicializa os ponteiros esquerdo para NULL
    node->right = NULL;                        // Inicializa os ponteiros direito para NULL
    return node;                               // Retorna o nó criado
}

/**
 * @brief Insere um novo nó na árvore.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param data O valor a ser armazenado no nó.
 * @return Ponteiro para a raiz da árvore.
 */
TREE *insert(TREE *root, int data)
{
    if (root == NULL)
    {
        // Se a raiz for NULL, cria um novo nó
        return createNode(data);
    }
    if (data < root->data)
    {
        // Caso contrário, insere o nó na subárvore esquerda
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        // Caso contrário, insere o nó na subárvore direita
        root->right = insert(root->right, data);
    }
    return root; // Retorna a raiz da árvore
}

/**
 * @brief Função recursiva que imprime a árvore de forma visual.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param space Quantidade de espaços (indentação) para deslocar os níveis da árvore.
 */
void printTree(TREE *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    // Aumenta o espaço para os filhos à direita
    space += 5;

    // Primeiro, imprime o filho direito
    printTree(root->right, space);

    // Imprime o valor do nó com a indentação correspondente
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }

    printf("%d\n", root->data);

    // Em seguida, imprime o filho esquerdo
    printTree(root->left, space);
}

/**
 * @brief Realiza uma travessia em ordem (in-order) na árvore e imprime os valores.
 *
 * @param root Ponteiro para a raiz da árvore.
 */
void inOrder(TREE *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

/**
 * @brief Libera a memória alocada para a árvore.
 *
 * @param root Ponteiro para a raiz da árvore.
 */
void liberarArvore(TREE *root)
{
    if (root == NULL)
    {
        return;
    }

    liberarArvore(root->left);
    liberarArvore(root->right);
    free(root);
}

int main(int argc, char **argv)
{
    TREE *root = NULL;

    // Inserindo elementos na árvore
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 8);

    // Imprimindo a árvore de forma visual
    printf("Árvore binária (visual):\n");
    printTree(root, 0);

    printf("\n------------------------------------\n");

    // Exibindo os valores da árvore em ordem
    printf("\nIn-order traversal: ");
    inOrder(root);
    printf("\n");

    // Liberando a memória alocada para a árvore
    liberarArvore(root);

    return 0;
}
