#include <stdio.h>
#include <stdlib.h>

/**
 * huffman algo: O algoritmo de codificação de Huffman (Huffman Coding Algorithm)
 * utiliza o princípio de codificação de Huffman para codificar um texto.
 *
 * COMPLEXIDADE:
 * TEMPO: O(n), onde n é o tamanho do texto.
 *
 * ESPAÇO: O(n), onde n é o tamanho do texto.
 */

#define MAX_TREE_HT 100 ///< Altura máxima da árvore de Huffman.

/**
 * @brief Estrutura que representa um nó da árvore de Huffman.
 */
struct MinHeapNode
{
    char data;                 ///< Caractere armazenado no nó.
    unsigned freq;             ///< Frequência do caractere.
    struct MinHeapNode *left;  ///< Ponteiro para o filho esquerdo.
    struct MinHeapNode *right; ///< Ponteiro para o filho direito.
};

/**
 * @brief Estrutura que representa um min-heap (fila de prioridade).
 */
struct MinHeap
{
    unsigned size;              ///< Tamanho atual do min-heap.
    unsigned capacity;          ///< Capacidade máxima do min-heap.
    struct MinHeapNode **array; ///< Array de ponteiros para nós do min-heap.
};

/**
 * @brief Cria um novo nó da árvore de Huffman.
 *
 * @param data Caractere a ser armazenado no nó.
 * @param freq Frequência do caractere.
 * @return Ponteiro para o novo nó criado.
 */
struct MinHeapNode *newNode(char data, unsigned freq)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

/**
 * @brief Cria um min-heap com uma capacidade específica.
 *
 * @param capacity Capacidade máxima do min-heap.
 * @return Ponteiro para o min-heap criado.
 */
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

/**
 * @brief Troca dois nós do min-heap.
 *
 * @param a Ponteiro para o primeiro nó.
 * @param b Ponteiro para o segundo nó.
 */
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Função para manter a propriedade de min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @param idx Índice do nó a ser heapificado.
 */
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

/**
 * @brief Verifica se o tamanho do min-heap é 1.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @return 1 se o tamanho for 1, 0 caso contrário.
 */
int isSizeOne(struct MinHeap *minHeap) { return (minHeap->size == 1); }

/**
 * @brief Extrai o nó com a menor frequência do min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @return Ponteiro para o nó extraído.
 */
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

/**
 * @brief Insere um novo nó no min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @param minHeapNode Ponteiro para o nó a ser inserido.
 */
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

/**
 * @brief Constrói o min-heap a partir do array de nós.
 *
 * @param minHeap Ponteiro para o min-heap.
 */
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(minHeap, i);
    }
}

/**
 * @brief Imprime um array de inteiros.
 *
 * @param arr Array a ser impresso.
 * @param n Tamanho do array.
 */
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Verifica se um nó é uma folha.
 *
 * @param root Ponteiro para o nó.
 * @return 1 se for uma folha, 0 caso contrário.
 */
int isLeaf(struct MinHeapNode *root) { return !(root->left) && !(root->right); }

/**
 * @brief Cria e constrói um min-heap a partir dos dados fornecidos.
 *
 * @param data Array de caracteres.
 * @param freq Array de frequências correspondentes aos caracteres.
 * @param size Tamanho dos arrays.
 * @return Ponteiro para o min-heap criado.
 */
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
    {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

/**
 * @brief Constrói a árvore de Huffman.
 *
 * @param data Array de caracteres.
 * @param freq Array de frequências correspondentes aos caracteres.
 * @param size Tamanho dos arrays.
 * @return Ponteiro para a raiz da árvore de Huffman.
 */
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

/**
 * @brief Imprime os códigos de Huffman a partir da raiz da árvore.
 *
 * @param root Ponteiro para a raiz da árvore de Huffman.
 * @param arr Array para armazenar os códigos.
 * @param top Índice atual no array.
 */
void printCodes(struct MinHeapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

/**
 * @brief Função principal que constrói a árvore de Huffman e imprime os códigos.
 *
 * @param data Array de caracteres.
 * @param freq Array de frequências correspondentes aos caracteres.
 * @param size Tamanho dos arrays.
 */
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(int argc, char **argv)
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);
    return 0;
}
