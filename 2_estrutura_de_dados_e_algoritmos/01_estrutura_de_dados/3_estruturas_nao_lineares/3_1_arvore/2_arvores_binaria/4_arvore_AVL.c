#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura de um nó da árvore AVL.
 *
 * Cada nó contém uma chave (key), ponteiros para os filhos esquerdo e direito, e a altura do nó.
 * A Árvore AVL é uma árvore binária de busca com auto-balanceamento, garantindo que o fator
 * de balanceamento (diferença de altura entre subárvores) esteja entre -1 e 1.
 *
 * Propriedades de uma Árvore AVL
 *
 * - Estrutura de Árvore Binária de Pesquisa (BST)
 *
 * - Fator de Balanceamento
 *
 * - Altura da Árvore
 *
 * - Rebalanceamento
 */
struct Node
{
    int key;            /**< A chave do nó */
    struct Node *left;  /**< Ponteiro para o filho esquerdo */
    struct Node *right; /**< Ponteiro para o filho direito */
    int height;         /**< A altura do nó */
};

/**
 * @brief Calcula a altura de um nó.
 *
 * @param N O nó cuja altura será calculada.
 * @return A altura do nó. Retorna 0 se o nó for NULL.
 */
int height(struct Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->height;
}

/**
 * @brief Retorna o valor máximo entre dois números inteiros.
 *
 * @param a O primeiro número.
 * @param b O segundo número.
 * @return O valor máximo entre a e b.
 */
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Cria um novo nó na árvore AVL.
 *
 * Aloca memória para um novo nó e inicializa seus campos.
 *
 * @param key O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó ou NULL em caso de falha na alocação.
 */
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        return NULL;
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

/**
 * @brief Realiza uma rotação à direita no nó fornecido.
 *
 * Usada para balancear a árvore quando está inclinada para a esquerda.
 *
 * @param y O nó onde a rotação será realizada.
 * @return O novo nó raiz após a rotação.
 */
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maximo(height(y->left), height(y->right)) + 1;
    x->height = maximo(height(x->left), height(x->right)) + 1;
    return x;
}

/**
 * @brief Realiza uma rotação à esquerda no nó fornecido.
 *
 * Usada para balancear a árvore quando está inclinada para a direita.
 *
 * @param x O nó onde a rotação será realizada.
 * @return O novo nó raiz após a rotação.
 */
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maximo(height(x->left), height(x->right)) + 1;
    y->height = maximo(height(y->left), height(y->right)) + 1;
    return y;
}

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * O fator de balanceamento é a diferença entre a altura da subárvore esquerda
 * e a altura da subárvore direita.
 *
 * @param N O nó cujo fator de balanceamento será calculado.
 * @return O fator de balanceamento.
 */
int getBalance(struct Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

/**
 * @brief Insere um novo nó na árvore AVL e realiza balanceamento.
 *
 * Insere a chave na posição correta e rebalanceia a árvore se necessário.
 * Chaves duplicadas são ignoradas.
 *
 * @param node A raiz da árvore ou subárvore.
 * @param key A chave do novo nó.
 * @return A nova raiz da árvore ou subárvore após a inserção.
 */
struct Node *insertNode(struct Node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }

    if (key < node->key)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertNode(node->right, key);
    }
    else
    {
        return node; // Ignora duplicatas
    }

    node->height = 1 + maximo(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Rotação à direita (LL)
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Rotação à esquerda (RR)
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Rotação esquerda-direita (LR)
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Rotação direita-esquerda (RL)
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

/**
 * @brief Encontra o nó de valor mínimo em uma subárvore.
 *
 * @param node A raiz da subárvore.
 * @return O nó de valor mínimo na subárvore ou NULL se a subárvore for vazia.
 */
struct Node *minValueNode(struct Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    struct Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/**
 * @brief Deleta um nó da árvore AVL e realiza balanceamento.
 *
 * Remove o nó com a chave especificada e rebalanceia a árvore se necessário.
 *
 * @param root A raiz da árvore ou subárvore.
 * @param key A chave do nó a ser deletado.
 * @return A nova raiz da árvore ou subárvore após a remoção.
 */
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Nó com um filho ou sem filhos
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Nó com dois filhos
        struct Node *temp = minValueNode(root->right);
        if (temp == NULL)
        {
            return root; // Não deveria ocorrer, mas evita falhas
        }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    root->height = 1 + maximo(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Rotação à direita (LL)
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Rotação esquerda-direita (LR)
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Rotação à esquerda (RR)
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Rotação direita-esquerda (RL)
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

/**
 * @brief Realiza um percurso pré-ordem da árvore e imprime as chaves dos nós.
 *
 * Imprime as chaves em ordem pré-ordem (raiz, esquerda, direita) sem espaço extra no final.
 *
 * @param root A raiz da árvore ou subárvore.
 * @param is_first Indica se é o primeiro nó a ser impresso (evita espaço inicial).
 */
void printPreOrder(struct Node *root, int is_first)
{
    if (root != NULL)
    {
        printf("%d", root->key);
        if (!is_first || root->left || root->right)
        {
            printf(" ");
        }
        printPreOrder(root->left, 0);
        printPreOrder(root->right, 0);
    }
}

/**
 * @brief Libera a memória alocada para a árvore AVL.
 *
 * Percorre a árvore recursivamente e libera a memória de todos os nós.
 *
 * @param root A raiz da árvore ou subárvore.
 */
void freeTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(int argc, char **argv)
{
    struct Node *root = NULL;

    // Inserindo nós
    root = insertNode(root, 2);
    if (root == NULL)
    {
        fprintf(stderr, "Erro: Falha na inserção do nó raiz\n");
        return EXIT_FAILURE;
    }
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    // Imprimindo a árvore em pré-ordem
    printf("Árvore em ordem pré-ordem: ");
    if (root == NULL)
    {
        printf("Árvore vazia\n");
    }
    else
    {
        printPreOrder(root, 1);
        printf("\n");
    }

    // Removendo o nó com chave 3
    root = deleteNode(root, 3);

    // Imprimindo a árvore após a remoção
    printf("Após a exclusão de 3: ");
    if (root == NULL)
    {
        printf("Árvore vazia\n");
    }
    else
    {
        printPreOrder(root, 1);
        printf("\n");
    }

    // Liberando a memória
    freeTree(root);

    return 0;
}
