#include <stdio.h>
#include <stdlib.h>

/**
 * Algoritmo de Huffman - Codificação de Texto
 *
 * O algoritmo de Huffman é um algoritmo de compressão sem perdas utilizado para
 * gerar uma codificação eficiente de caracteres com base na sua frequência
 * em um texto. Ele utiliza uma abordagem de árvore binária para construir uma
 * tabela de códigos, atribuindo códigos menores aos caracteres mais frequentes
 * e códigos maiores aos menos frequentes.
 *
 * Aplicações:
 * - Compressão de arquivos (ZIP, GZIP)
 * - Codificação de imagens e vídeos (JPEG, MP3)
 * - Compressão de dados em redes
 *
 * Funcionamento:
 * - Conta a frequência de cada caractere no texto.
 * - Cria uma árvore binária onde cada folha é um caractere e os nós intermediários
 *   têm uma soma das frequências dos seus filhos.
 * - Atribui um código binário para cada caractere, sendo os caracteres mais
 *   frequentes representados com códigos menores.
 * - A codificação gerada é otimizada para o tamanho total mais compacto possível.
 *
 * Restrições:
 * - A eficácia da codificação depende da distribuição de frequência dos caracteres.
 *   Se todos os caracteres aparecem com a mesma frequência, a compressão será ineficaz.
 *
 * COMPLEXIDADE:
 * - TEMPO: O(n log n), onde n é o número de caracteres distintos no texto (geralmente
 *   relacionado ao número de elementos a serem processados na árvore de Huffman).
 * - ESPAÇO: O(n), onde n é o tamanho do texto ou o número de caracteres únicos.
 *
 * @note O algoritmo de Huffman é eficiente para textos com uma grande variação
 * na frequência de caracteres, mas não oferece ganho em textos uniformemente distribuídos.
 */

#define MAX_TREE_HT 100 ///< Altura máxima da árvore de Huffman.

/**
 * @brief Estrutura que representa um nó da árvore de Huffman.
 */
typedef struct MinHeapNode
{
    char data;                 ///< Caractere armazenado no nó.
    unsigned freq;             ///< Frequência do caractere.
    struct MinHeapNode *left;  ///< Ponteiro para o filho esquerdo.
    struct MinHeapNode *right; ///< Ponteiro para o filho direito.
} MinHeapNode;

/**
 * @brief Estrutura que representa um min-heap (fila de prioridade).
 */
typedef struct MinHeap
{
    unsigned size;       ///< Tamanho atual do min-heap.
    unsigned capacity;   ///< Capacidade máxima do min-heap.
    MinHeapNode **array; ///< Array de ponteiros para nós do min-heap.
} MinHeap;

/**
 * @brief Cria um novo nó da árvore de Huffman.
 *
 * @param data Caractere a ser armazenado no nó.
 * @param freq Frequência do caractere.
 * @return Ponteiro para o novo nó criado.
 */
MinHeapNode *newNode(char data, unsigned freq)
{
    MinHeapNode *temp = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    if (!temp)
    {
        printf("Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

/**
 * @brief Cria um min-heap com uma capacidade específica.
 *
 * @param capacity Capacidade máxima do min-heap.
 * @return Ponteiro para o min-heap criado.
 */
MinHeap *createMinHeap(unsigned capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    if (!minHeap)
        exit(EXIT_FAILURE);

    minHeap->size     = 0;
    minHeap->capacity = capacity;
    minHeap->array    = (MinHeapNode **)malloc(capacity * sizeof(MinHeapNode *));
    if (!minHeap->array)
        exit(EXIT_FAILURE);

    return minHeap;
}

/**
 * @brief Troca dois nós do min-heap.
 *
 * @param a Ponteiro para o primeiro nó.
 * @param b Ponteiro para o segundo nó.
 */
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Função para manter a propriedade de min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @param idx Índice do nó a ser heapificado.
 */
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left     = 2 * idx + 1;
    int right    = 2 * idx + 2;

    if (left < (int)minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < (int)minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

/**
 * @brief Extrai o nó com a menor frequência do min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @return Ponteiro para o nó extraído.
 */
MinHeapNode *extractMin(MinHeap *minHeap)
{
    if (minHeap->size == 0)
        return NULL;

    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

/**
 * @brief Insere um novo nó no min-heap.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @param minHeapNode Ponteiro para o nó a ser inserido.
 */
void insertMinHeap(MinHeap *minHeap, MinHeapNode *node)
{
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

/**
 * @brief Constrói o min-heap a partir do array de nós.
 *
 * @param minHeap Ponteiro para o min-heap.
 */
void buildMinHeap(MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

/**
 * @brief Verifica se o tamanho do min-heap é 1.
 *
 * @param minHeap Ponteiro para o min-heap.
 * @return 1 se o tamanho for 1, 0 caso contrário.
 */
int isLeaf(MinHeapNode *root)
{
    return !(root->left) && !(root->right);
}

/**
 * @brief Constrói a árvore de Huffman.
 *
 * @param data Array de caracteres.
 * @param freq Array de frequências correspondentes aos caracteres.
 * @param size Tamanho dos arrays.
 * @return Ponteiro para a raiz da árvore de Huffman.
 */
MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode *left  = NULL,
                *right = NULL,
                *top   = NULL;

    MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    while (minHeap->size > 1)
    {
        left  = extractMin(minHeap);
        right = extractMin(minHeap);

        top        = newNode('$', left->freq + right->freq);
        top->left  = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    MinHeapNode *root = extractMin(minHeap);
    free(minHeap->array);
    free(minHeap);

    return root;
}

/**
 * @brief Imprime os códigos de Huffman a partir da raiz da árvore.
 *
 * @param root Ponteiro para a raiz da árvore de Huffman.
 * @param arr Array para armazenar os códigos.
 * @param top Índice atual no array.
 */
void printCodes(MinHeapNode *root, int arr[], int top)
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
        printf("  %c   | ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

/**
 * @brief Determina o comprimento (em bits) do código de Huffman de cada caractere.
 *
 * Percorre recursivamente a árvore de Huffman a partir da raiz e registra, para cada caractere presente nas folhas da árvore,
 * a profundidade em que * ele se encontra. Essa profundidade corresponde ao tamanho do código binário de Huffman atribuído ao caractere.
 *
 * O resultado é armazenado no vetor `codeLength`, onde cada posição corresponde ao caractere na mesma posição do vetor `data`.
 *
 * @param node Ponteiro para o nó atual da árvore de Huffman.
 * @param data Vetor contendo os caracteres originais utilizados na codificação.
 * @param size Quantidade de caracteres distintos (tamanho do vetor `data`).
 * @param codeLength Vetor onde será armazenado o comprimento do código de cada caractere.
 * @param depth Profundidade atual na árvore (número de bits do código até o nó).
 *
 * @note Esta função assume que os vetores `data` e `codeLength` possuem o mesmo tamanho.
 * @note A função deve ser chamada inicialmente com `depth = 0`.
 *
 * @complexity
 * - Tempo: O(n), onde n é o número de nós da árvore de Huffman.
 * - Espaço: O(h), onde h é a altura da árvore, devido à recursão.
 */
void getCodeLengths(MinHeapNode *node, char data[], int size, int codeLength[], int depth)
{
    if (!node)
        return;

    if (isLeaf(node))
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == node->data)
            {
                codeLength[i] = depth;
                break;
            }
        }
        return;
    }

    getCodeLengths(node->left,  data, size, codeLength, depth + 1);
    getCodeLengths(node->right, data, size, codeLength, depth + 1);
}

/**
 * @brief Calcula o tamanho comprimido em bits.
 *
 * @param root Ponteiro para a raiz da árvore de Huffman.
 * @param freq Array para armazenar os códigos.
 * @param data Array de caracteres.
 * @param size Tamanho dos arrays.
 */
unsigned calculateCompressedSize(MinHeapNode *root, char data[], int freq[], int size)
{
    int codeLength[size];
    for (int i = 0; i < size; i++)
        codeLength[i] = 0;

    getCodeLengths(root, data, size, codeLength, 0);

    unsigned totalBits = 0;
    for (int i = 0; i < size; i++)
        totalBits += freq[i] * codeLength[i];

    return totalBits;
}

void freeHuffmanTree(MinHeapNode *root)
{
    if (!root)
        return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
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
    printf("=== Codificação de Huffman ===\n\n");

    printf("Caractere | Frequência\n");
    printf("---------------------\n");
    for (int i = 0; i < size; i++)
        printf("    %c     |    %d\n", data[i], freq[i]);

    MinHeapNode *root = buildHuffmanTree(data, freq, size);

    printf("\nCódigos de Huffman:\n");
    printf("---------------------\n");
    printf("Char | Código\n");
    printf("---------------------\n");

    int arr[MAX_TREE_HT];
    printCodes(root, arr, 0);

    unsigned compressedBits = calculateCompressedSize(root, data, freq, size);
    printf("\nTamanho comprimido: %u bits\n", compressedBits);

    freeHuffmanTree(root);
}

int main(int argc, char **argv)
{
    char arr[]  = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[]  = {5, 9, 12, 13, 16, 45};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
