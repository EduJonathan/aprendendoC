#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura de um nó da árvore AVL.
 *
 * Cada nó contém uma chave (key), ponteiros para os filhos esquerdo e direito, e a altura do nó.
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
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Cria um novo nó na árvore AVL.
 *
 * @param key O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó.
 */
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

/**
 * @brief Realiza uma rotação à direita no nó fornecido.
 *
 * A rotação à direita é realizada para balancear a árvore quando ela está muito
 * inclinada para a esquerda.
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

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/**
 * @brief Realiza uma rotação à esquerda no nó fornecido.
 *
 * A rotação à esquerda é realizada para balancear a árvore quando ela está muito
 * inclinada para a direita.
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

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * O fator de balanceamento é a diferença entre a altura da subárvore esquerda e a altura da subárvore direita.
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
 * @brief Insere um novo nó na árvore AVL e realiza as rotações necessárias para balanceá-la.
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
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

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
 * @return O nó de valor mínimo na subárvore.
 */
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/**
 * @brief Deleta um nó da árvore AVL e realiza as rotações necessárias para balanceá-la.
 *
 * @param root A raiz da árvore ou subárvore.
 * @param key A chave do nó a ser deletado.
 * @return A nova raiz da árvore ou subárvore após a remoção.
 */
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
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
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }

            free(temp);
        }
        else
        {
            struct Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

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
 * @param root A raiz da árvore ou subárvore.
 */
void printPreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main(int argc, char **argv)
{
    struct Node *root = NULL;

    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    printf("Árvore em ordem pré-ordem: ");
    printPreOrder(root);

    root = deleteNode(root, 3);

    printf("\nApós a exclusão de 3: ");
    printPreOrder(root);

    return 0;
}
