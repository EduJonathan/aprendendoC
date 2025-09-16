#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura de uma árvore binária de busca (BST).
 *
 * Esta estrutura armazena um valor inteiro e ponteiros para os filhos esquerdo
 * e direito. Os valores menores são inseridos à esquerda, e os maiores à direita.
 */
typedef struct node
{
    int data;           /**< O valor armazenado no nó */
    struct node *left;  /**< Ponteiro para o filho esquerdo */
    struct node *right; /**< Ponteiro para o filho direito */
} TREE;

#endif

/**
 * @brief Cria um novo nó na árvore.
 *
 * Aloca memória para um novo nó, inicializa os ponteiros left e right como NULL
 * e atribui o valor fornecido.
 *
 * @param data O valor a ser armazenado no nó.
 * @return Ponteiro para o nó criado ou NULL em caso de falha na alocação.
 */
TREE *createNode(int data)
{
    TREE *node = (TREE *)malloc(sizeof(TREE));
    if (node == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Insere um novo nó na árvore binária de busca.
 *
 * Insere o valor na posição correta, mantendo a propriedade da BST.
 * Valores duplicados são ignorados.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param data O valor a ser inserido.
 * @return Ponteiro para a raiz da árvore ou NULL em caso de falha.
 */
TREE *insert(TREE *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root; // Ignora duplicatas
}

/**
 * @brief Imprime a árvore de forma visual.
 *
 * Exibe a árvore com indentação, mostrando o filho esquerdo acima e o direito abaixo.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param space Quantidade de espaços para indentação.
 */
void printTree(TREE *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    space += 4; // Reduzi para 4 para melhor alinhamento

    // Primeiro, imprime o filho esquerdo (acima)
    printTree(root->left, space);

    // Imprime o nó atual com indentação
    printf("\n");
    for (int i = 4; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Depois, imprime o filho direito (abaixo)
    printTree(root->right, space);
}

/**
 * @brief Realiza uma travessia in-order na árvore e imprime os valores.
 *
 * Imprime os valores em ordem crescente, sem espaço extra no final.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param is_first Indica se é o primeiro nó a ser impresso (evita espaço inicial).
 */
void inOrder(TREE *root, int is_first)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, is_first);
    printf("%d", root->data);
    if (!is_first || root->right)
    {
        printf(" ");
    }
    inOrder(root->right, 0);
}

/**
 * @brief Libera a memória alocada para a árvore.
 *
 * Libera recursivamente todos os nós da árvore.
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
    if (root == NULL)
    {
        fprintf(stderr, "Erro: Falha ao inserir o nó raiz\n");
        return EXIT_FAILURE;
    }
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 8);

    // Imprimindo a árvore de forma visual
    printf("Árvore binária (visual):\n");
    if (root == NULL)
    {
        printf("Árvore vazia\n");
    }
    else
    {
        printTree(root, 0);
    }

    printf("\n------------------------------------\n");

    // Exibindo os valores da árvore em ordem
    printf("In-order traversal: ");
    if (root == NULL)
    {
        printf("Árvore vazia\n");
    }
    else
    {
        inOrder(root, 1);
        printf("\n");
    }

    // Liberando a memória alocada para a árvore
    liberarArvore(root);

    return 0;
}
