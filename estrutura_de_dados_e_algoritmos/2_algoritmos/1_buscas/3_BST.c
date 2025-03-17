#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Este código implementa uma árvore binária de busca (BST) simples com as operações de
 * inserção, exibição (em ordem) e cálculo do intervalo de colunas. Cada nó na árvore contém
 * um valor inteiro e um índice de coluna. As operações básicas incluem a inserção de um valor
 * na árvore, exibição dos valores da árvore e o cálculo das colunas mínima e máxima.
 */

/**
 * @struct binary_tree_node
 * @brief Estrutura que representa um nó da árvore binária de busca (BST).
 *
 * Cada nó contém:
 * - um valor inteiro (`valor`),
 * - o índice da coluna (`coluna`),
 * - ponteiros para os filhos esquerdo e direito (`left` e `right`).
 */
typedef struct binary_tree_node
{
    int valor;                      ///< Valor armazenado no nó.
    int coluna;                     ///< Índice da coluna do nó.
    struct binary_tree_node *left;  ///< Ponteiro para o filho esquerdo.
    struct binary_tree_node *right; ///< Ponteiro para o filho direito.
} binaryTree;

/**
 * @brief Cria um novo nó com o valor fornecido.
 *
 * Aloca memória para um novo nó e inicializa seu valor, coluna e filhos.
 *
 * @param valor O valor do nó.
 * @return Um ponteiro para o novo nó criado.
 */
binaryTree *criarArvore(int valor)
{
    binaryTree *new = (binaryTree *)malloc(sizeof(binaryTree));
    new->valor = valor;
    new->coluna = 0; ///< A raiz começa na coluna 0.
    new->left = NULL;
    new->right = NULL;
    return new;
}

/**
 * @brief Insere um valor na árvore binária de busca (BST).
 *
 * A inserção segue a lógica da BST: se o valor é menor que o valor do nó atual,
 * ele é inserido na subárvore esquerda; se o valor é maior, ele é inserido na subárvore direita.
 *
 * @param new O nó a ser inserido.
 * @param tree O nó atual (onde a inserção será feita).
 */
void insert(binaryTree *new, binaryTree *tree)
{
    if (new->valor < tree->valor) // Se o valor é menor, insira à esquerda
    {
        if (tree->left == NULL)
        {
            tree->left = new;
            new->coluna = tree->coluna - 1; ///< Coluna diminui à esquerda
        }
        else
        {
            insert(new, tree->left);
        }
    }
    else if (new->valor > tree->valor) // Se o valor é maior, insira à direita
    {
        if (tree->right == NULL)
        {
            tree->right = new;
            new->coluna = tree->coluna + 1; ///< Coluna aumenta à direita
        }
        else
        {
            insert(new, tree->right);
        }
    }
}

/**
 * @brief Exibe os valores da árvore em ordem (in-order).
 *
 * A função percorre a árvore em ordem (in-order) e imprime os valores de cada nó.
 * A ordem de exibição é: subárvore esquerda, nó atual, subárvore direita.
 *
 * @param tree A árvore (ou subárvore) a ser exibida.
 */
void displayTree(binaryTree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    displayTree(tree->left);      // Exibe a subárvore esquerda
    printf("->%d ", tree->valor); // Exibe o valor do nó atual
    displayTree(tree->right);     // Exibe a subárvore direita
}

/**
 * @brief Calcula os valores mínimo e máximo das colunas.
 *
 * Esta função percorre a árvore e atualiza os valores de `min` e `max` com os
 * índices das colunas mínimas e máximas, respectivamente.
 *
 * @param tree A árvore (ou subárvore) a ser analisada.
 * @param min Ponteiro para o valor mínimo da coluna.
 * @param max Ponteiro para o valor máximo da coluna.
 */
void colunas(binaryTree *tree, int *min, int *max)
{
    if (tree == NULL)
    {
        return;
    }

    // Atualiza o valor mínimo
    if (tree->coluna < *min)
    {
        *min = tree->coluna;
    }
    // Atualiza o valor máximo
    if (tree->coluna > *max)
    {
        *max = tree->coluna;
    }

    // Percorre as subárvores
    colunas(tree->left, min, max);
    colunas(tree->right, min, max);
}

/**
 * @brief Exibe o intervalo de colunas da árvore.
 *
 * Esta função imprime o intervalo de colunas, que é calculado pelas funções
 * `min` e `max`.
 */
void printColumnRange(int min, int max)
{
    printf("Intervalo de colunas: %d até %d\n", min, max);
}

int main(int argc, char **argv)
{
    // Inicializa as variáveis min e max
    int min = INT_MAX, max = INT_MIN;

    // Criação dos nós
    binaryTree *root = criarArvore(10); // Nó raiz
    binaryTree *node1 = criarArvore(5);
    binaryTree *node2 = criarArvore(15);
    binaryTree *node3 = criarArvore(3);
    binaryTree *node4 = criarArvore(7);
    binaryTree *node5 = criarArvore(12);
    binaryTree *node6 = criarArvore(17);

    // Inserção dos nós na árvore
    insert(node1, root);
    insert(node2, root);
    insert(node3, root);
    insert(node4, root);
    insert(node5, root);
    insert(node6, root);

    // Exibe a árvore
    displayTree(root);
    printf("\n");

    // Calcula e exibe o intervalo de colunas
    colunas(root, &min, &max);
    printColumnRange(min, max);

    return 0;
}
