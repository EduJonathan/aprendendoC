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
 */
typedef struct binary_tree_node
{
    int valor;                      ///< Valor armazenado no nó.
    int coluna;                     ///< Índice da coluna do nó.
    struct binary_tree_node *left;  ///< Ponteiro para o filho esquerdo.
    struct binary_tree_node *right; ///< Ponteiro para o filho direito.
} binaryTree;

/**
 * @brief Cria e inicializa um novo nó da árvore.
 *
 * Aloca memória dinâmica e define os valores iniciais. A coluna é definida como 0 por padrão, sendo ajustada apenas durante a inserção.
 *
 * @param valor O valor inteiro a ser armazenado.
 * @return Ponteiro para o novo nó ou NULL em caso de falha na alocação.
 */
binaryTree *criarArvore(int valor)
{
    binaryTree *new = (binaryTree *)malloc(sizeof(binaryTree));
    if (new == NULL)
    {
        printf("Erro: Falha na alocação de memória para o nó.\n");
        return NULL;
    }
    new->valor  = valor;
    new->coluna = 0; // Inicializado, mas será ajustado na inserção
    new->left   = NULL;
    new->right  = NULL;
    return new;
}

/**
 * @brief Libera recursivamente toda a memória alocada para a árvore.
 * 
 * @param tree Ponteiro para o nó raiz da árvore ou subárvore.
 */
void freeTree(binaryTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

/**
 * @brief Insere um novo nó na árvore seguindo as regras de uma BST.
 *
 * Além de organizar os valores, calcula o índice da coluna:
 * - Filho à esquerda: coluna do pai - 1.
 * - Filho à direita: coluna do pai + 1.
 *
 * @param new_node O novo nó pré-alocado a ser inserido.
 * @param root O nó atual da árvore onde a comparação será feita.
 * @note Se o valor já existir, o novo nó é liberado da memória para evitar vazamentos.
 */
void insert(binaryTree *new, binaryTree *tree)
{
    if (new == NULL || tree == NULL)
    {
        printf("Erro: Nó inválido para inserção.\n");
        return;
    }

    if (new->valor < tree->valor)
    {
        if (tree->left == NULL)
        {
            tree->left  = new;
            new->coluna = tree->coluna - 1;
        }
        else
        {
            insert(new, tree->left);
        }
    }
    else if (new->valor > tree->valor)
    {
        if (tree->right == NULL)
        {
            tree->right = new;
            new->coluna = tree->coluna + 1;
        }
        else
        {
            insert(new, tree->right);
        }
    }
    else
    {
        printf("Aviso: Valor %d já existe na árvore, ignorando inserção.\n", new->valor);
        free(new); // Libera o nó duplicado
    }
}

/**
 * @brief Percorre a árvore em ordem (In-order) e imprime os valores.
 * A sequência seguida é: Esquerda -> Raiz -> Direita.
 * 
 * @param tree Ponteiro para a raiz da árvore.
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
 * @brief Identifica os limites horizontais (colunas) da árvore.
 *
 * Percorre toda a árvore para encontrar o menor e o maior índice de coluna atribuído aos nós.
 *
 * @param tree Ponteiro para a raiz.
 * @param min Ponteiro para armazenar o menor índice encontrado.
 * @param max Ponteiro para armazenar o maior índice encontrado.
 */
void colunas(binaryTree *tree, int *min, int *max)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->coluna < *min)
    {
        *min = tree->coluna;
    }

    if (tree->coluna > *max)
    {
        *max = tree->coluna;
    }
    colunas(tree->left,  min, max);
    colunas(tree->right, min, max);
}

/**
 * @brief Imprime o intervalo formatado das colunas.
 * 
 * @param min Valor mínimo das colunas.
 * @param max Valor máximo das colunas.
 */
void printColumnRange(int min, int max)
{
    printf("Intervalo de colunas: %d até %d\n", min, max);
}

int main(int argc, char **argv)
{
    int n = 0;

    // Solicita o número de nós
    printf("Digite o número de nós a inserir: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Erro: Número de nós deve ser não-negativo.\n");
        return 1;
    }

    if (n == 0)
    {
        printf("Árvore vazia. Intervalo de colunas: nenhum\n");
        return 0;
    }

    // Cria a raiz
    int root_val = 0;
    printf("Digite o valor da raiz: ");
    if (scanf("%d", &root_val) != 1)
    {
        printf("Erro: Valor inválido para a raiz.\n");
        return 1;
    }

    binaryTree *root = criarArvore(root_val);
    if (root == NULL)
    {
        return 1;
    }

    // Insere os demais nós
    for (int i = 1; i < n; i++)
    {
        int val = 0;
        printf("Digite o valor do nó %d: ", i + 1);
        if (scanf("%d", &val) != 1)
        {
            printf("Erro: Valor inválido para o nó %d.\n", i + 1);
            freeTree(root);
            return 1;
        }

        binaryTree *new = criarArvore(val);
        if (new == NULL)
        {
            freeTree(root);
            return 1;
        }
        insert(new, root);
    }

    // Exibe a árvore
    printf("Árvore em ordem: ");
    displayTree(root);
    printf("\n");

    // Calcula e exibe o intervalo de colunas
    int min = INT_MAX, max = INT_MIN;
    colunas(root, &min, &max);
    if (min == INT_MAX && max == INT_MIN)
    {
        printf("Árvore vazia. Intervalo de colunas: nenhum\n");
    }
    else
    {
        printColumnRange(min, max);
    }

    // Libera a memória da árvore
    freeTree(root);
    return 0;
}
