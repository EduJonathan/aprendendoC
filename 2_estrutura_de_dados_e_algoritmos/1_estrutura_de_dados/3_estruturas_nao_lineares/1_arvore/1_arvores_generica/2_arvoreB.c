#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 10 /**< Tamanho máximo do array de dados */

#ifndef NODE_H
#define NODE_H

/**
 * @struct node
 * @brief Estrutura que representa um nó da árvore binária.
 *
 * Arvore Binária Cada nó contém um caractere (dados) e dois ponteiros para seus filhos
 * esquerdo  e direito. A estrutura node representa um nó de uma árvore binária com operações
 * de travessia (pre-order, in-order e post-order). Este programa cria uma árvore binária a
 * partir de um array de caracteres e realiza as três travessias mais comuns em árvores binárias:
 * pre-order, in-order e post-order.
 */
struct node
{
    char data;          /**< Dados armazenados no nó */
    struct node *left;  /**< Ponteiro para o filho esquerdo */
    struct node *right; /**< Ponteiro para o filho direito */
};

#endif

/**
 * @brief Cria um novo nó para a árvore binária.
 *
 * Esta função aloca memória para um novo nó e retorna o ponteiro para o nó criado.
 *
 * @return Ponteiro para o nó recém-criado.
 */
struct node *newNode(void) { return (struct node *)malloc(sizeof(struct node)); }

/**
 * @brief Inicializa um nó com os dados fornecidos e seus filhos.
 *
 * Esta função cria um novo nó com os dados fornecidos e
 * estabelece os ponteiros para os filhos esquerdo e direito.
 *
 * @param data Dados a serem armazenados no nó.
 * @param left Ponteiro para o filho esquerdo.
 * @param right Ponteiro para o filho direito.
 * @return Ponteiro para o nó inicializado.
 */
struct node *initNode(char data, struct node *left, struct node *right)
{
    struct node *node = newNode();
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

/**
 * @brief Cria uma árvore binária a partir de um array de dados.
 *
 * Esta função cria uma árvore binária de forma recursiva,
 * com base no índice de um array de dados. A árvore é construída
 * utilizando o índice do array para determinar a estrutura da árvore binária.
 *
 * @param data Array de dados para a árvore.
 * @param i Índice atual no array para criar o nó.
 * @param size Tamanho total do array.
 * @return Ponteiro para a raiz da árvore binária.
 */
struct node *criarArvore(char data[], int i, size_t size)
{
    if (i >= size)
    {
        return NULL;
    }

    return initNode(data[i],
                    criarArvore(data, 2 * i + 1, size),
                    criarArvore(data, 2 * i + 2, size));
}

/**
 * @brief Realiza uma travessia pre-order na árvore binária.
 *
 * Na travessia pre-order, a ordem é: visita o nó atual,
 * depois a subárvore esquerda, e finalmente a subárvore direita.
 *
 * @param root Ponteiro para a raiz da árvore binária.
 */
void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

/**
 * @brief Realiza uma travessia in-order na árvore binária.
 *
 * Na travessia in-order, a ordem é: visita a subárvore esquerda,
 * depois o nó atual, e finalmente a subárvore direita.
 *
 * @param root Ponteiro para a raiz da árvore binária.
 */
void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

/**
 * @brief Realiza uma travessia post-order na árvore binária.
 *
 * Na travessia post-order, a ordem é: visita a subárvore esquerda,
 * depois a subárvore direita, e finalmente o nó atual.
 *
 * @param root Ponteiro para a raiz da árvore binária.
 */
void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

/**
 * @brief Libera a memória alocada para a árvore binária.
 *
 * A função libera recursivamente a memória de todos os nós da árvore binária,
 * começando pelos filhos e finalizando com a raiz.
 *
 * @param root Ponteiro para a raiz da árvore binária.
 */
void freeTree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root); /**< Libera o nó atual */
}

int main(int argc, char **argv)
{
    char data[MAX] = {'g', 'd', 'i', 'b', 'f', 'h', 'j', 'a', 'c', 'e'};

    struct node *root = criarArvore(data, 0, MAX);
    assert(root != NULL);

    printf("Pre-Order: ");
    preOrder(root);
    printf("\n---------------------------------\n");

    printf("\nIn-Order: ");
    inOrder(root);
    printf("\n---------------------------------\n");

    printf("\nPost-Order: ");
    postOrder(root);

    freeTree(root);
    return 0;
}
