#include <stdio.h>
#include <stdlib.h>

/**
 * @struct node
 * @brief Nó de uma lista encadeada simples para armazenamento de colisões.
 * Cada nó armazena um par chave-valor e um ponteiro para o próximo elemento que resultou no mesmo índice de hash (colisão).
 */
typedef struct node
{
    int key;           /**< Chave única do elemento. */
    int value;         /**< Valor associado à chave. */
    struct node *next; /**< Ponteiro para o próximo nó em caso de colisão. */
} HashNode;

/**
 * @struct table
 * @brief Estrutura principal da Tabela Hash.
 * Utiliza um array de ponteiros (buckets) onde cada posição aponta para o início de uma lista ligada de HashNodes.
 */
typedef struct table
{
    HashNode **table; /**< Vetor de buckets (ponteiros para nós). */
    int size;         /**< Capacidade total da tabela (número de buckets). */
} HashTable;

/**
 * @brief Calcula o índice na tabela para uma determinada chave.
 * Utiliza o método da divisão com um ajuste para garantir que chaves negativas mapeiem para índices positivos válidos.
 * 
 * @param key A chave inteira a ser processada.
 * @param table_size O tamanho atual da tabela hash.
 * @return O índice calculado no intervalo [0, table_size - 1].
 */
int hashFunction(int key, int table_size)
{
    return (key % table_size + table_size) % table_size;
}

/**
 * @brief Inicializa uma nova tabela hash.
 * Aloca a estrutura da tabela e o array de buckets, inicializando todos os ponteiros de colisão como NULL.
 * 
 * @param size O tamanho desejado para a tabela.
 * @return Ponteiro para a HashTable criada ou NULL em caso de erro de memória.
 */
HashTable *initHashTable(int size)
{
    if (size <= 0)
    {
        printf("Erro: Tamanho da tabela deve ser positivo.\n");
        return NULL;
    }

    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL)
    {
        printf("Erro: Falha na alocação de memória para a tabela.\n");
        return NULL;
    }

    ht->table = (HashNode **)calloc(size, sizeof(HashNode *));
    if (ht->table == NULL)
    {
        printf("Erro: Falha na alocação de memória para os buckets.\n");
        free(ht);
        return NULL;
    }
    ht->size = size;
    return ht;
}

/**
 * @brief Desaloca toda a memória da tabela, incluindo todos os nós de colisão.
 * 
 * @param ht Ponteiro para a tabela hash a ser destruída.
 */
void freeHashTable(HashTable *ht)
{
    if (ht == NULL)
        return;

    for (int i = 0; i < ht->size; i++)
    {
        HashNode *current = ht->table[i];
        while (current != NULL)
        {
            HashNode *temp = current;
            current        = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

/**
 * @brief Insere ou atualiza um par chave-valor na tabela.
 * Se a chave já existir em seu respectivo bucket, o valor é atualizado.
 * Caso contrário, um novo nó é inserido no início da lista (encadeamento).
 *
 * @param ht Ponteiro para a tabela hash.
 * @param key Chave de busca.
 * @param value Valor a ser armazenado.
 */
void insert(HashTable *ht, int key, int value)
{
    if (ht == NULL)
        return;

    int index = hashFunction(key, ht->size);
    HashNode *current = ht->table[index];

    // Busca se a chave já existe para atualizar
    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("Aviso: Chave %d atualizada para %d.\n", key, value);
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Inserção de novo nó no início da lista do bucket
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    if (new_node == NULL)
        return;

    new_node->key    = key;
    new_node->value  = value;
    new_node->next   = ht->table[index];
    ht->table[index] = new_node;
}

/**
 * @brief Busca um elemento na tabela a partir de sua chave.
 * 
 * @param ht Ponteiro para a tabela hash.
 * @param key Chave a ser procurada.
 * @return Ponteiro para o HashNode encontrado ou NULL se a chave não existir.
 */
HashNode *search(HashTable *ht, int key)
{
    if (ht == NULL)
        return NULL;

    int index         = hashFunction(key, ht->size);
    HashNode *current = ht->table[index];

    while (current != NULL)
    {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

/**
 * @brief Remove um nó da tabela com base na chave fornecida.
 * Localiza o bucket via hash e percorre a lista ligada para ajustar os ponteiros e liberar a memória do nó removido.
 * 
 * @param ht Ponteiro para a tabela hash.
 * @param key Chave do elemento a ser removido.
 */
void removeKey(HashTable *ht, int key)
{
    if (ht == NULL)
        return;

    int index = hashFunction(key, ht->size);
    HashNode *current = ht->table[index];
    HashNode *prev    = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
                ht->table[index] = current->next;
            else
                prev->next = current->next;

            free(current);
            printf("Chave %d removida.\n", key);
            return;
        }
        prev    = current;
        current = current->next;
    }
    printf("Chave %d não encontrada.\n", key);
}

int main(int argc, char **argv)
{
    int table_size = 0;

    // Solicita o tamanho da tabela
    printf("Digite o tamanho da tabela hash: ");
    if (scanf("%d", &table_size) != 1 || table_size <= 0)
    {
        printf("Erro: Tamanho da tabela deve ser positivo.\n");
        return 1;
    }

    // Inicializa a tabela hash
    HashTable *ht = initHashTable(table_size);
    if (ht == NULL)
    {
        return 1;
    }

    // Solicita o número de pares chave-valor
    int n = 0;
    printf("Digite o número de pares chave-valor a inserir: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Erro: Número de pares deve ser não-negativo.\n");
        freeHashTable(ht);
        return 1;
    }

    // Insere pares chave-valor
    for (int i = 0; i < n; i++)
    {
        int key = 0, value = 0;
        printf("Digite a chave e o valor do par %d: ", i + 1);
        if (scanf("%d %d", &key, &value) != 2)
        {
            printf("Erro: Entrada inválida para o par %d.\n", i + 1);
            freeHashTable(ht);
            return 1;
        }
        insert(ht, key, value);
    }

    // Busca uma chave
    int search_key = 0;
    printf("Digite a chave para buscar: ");
    if (scanf("%d", &search_key) != 1)
    {
        printf("Erro: Chave inválida.\n");
        freeHashTable(ht);
        return 1;
    }

    HashNode *node = search(ht, search_key);
    if (node != NULL)
    {
        printf("Chave: %d, Valor: %d\n", node->key, node->value);
    }
    else
    {
        printf("Chave %d não encontrada.\n", search_key);
    }

    // Remove uma chave (exemplo)
    printf("Digite a chave para remover: ");
    if (scanf("%d", &search_key) != 1)
    {
        printf("Erro: Chave inválida.\n");
        freeHashTable(ht);
        return 1;
    }
    removeKey(ht, search_key);

    // Libera a memória
    freeHashTable(ht);
    return 0;
}
