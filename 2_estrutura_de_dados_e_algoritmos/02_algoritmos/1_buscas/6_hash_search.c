#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

/**
 * @brief Estrutura para um nó da tabela hash (contém chave, valor e ponteiro para próximo nó).
 */
typedef struct node
{
    int key;
    int value;
    struct node *next; // Para lidar com colisões (encadeamento)
} HashNode;

/**
 * @brief Estrutura para a tabela hash.
 */
typedef struct table
{
    HashNode **table; // Array de ponteiros para HashNode
    int size;         // Tamanho da tabela
} HashTable;

/**
 * @brief Função de hash
 *
 * @param key Chave a ser usada na função
 */
int hashFunction(int key, int table_size)
{
    // Garante que o índice seja não-negativo
    return (key % table_size + table_size) % table_size;
}

/**
 * @brief Função para inicializar a tabela hash
 *
 * @param ht Tabela hash
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
        printf("Erro: Falha na alocação de memória para a tabela.\n");
        free(ht);
        return NULL;
    }
    ht->size = size;
    return ht;
}

/**
 * @brief Libera a memória alocada para a tabela hash.
 */
void freeHashTable(HashTable *ht)
{
    if (ht == NULL)
    {
        return;
    }
    
    for (int i = 0; i < ht->size; i++)
    {
        HashNode *current = ht->table[i];
        while (current != NULL)
        {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

/**
 * @brief Função para inserir um par chave-valor
 *
 * @param ht Tabela hash
 * @param key Chave a ser inserida
 * @param value Valor a ser inserido
 */
void insert(HashTable *ht, int key, int value)
{
    if (ht == NULL)
    {
        printf("Erro: Tabela hash não inicializada.\n");
        return;
    }
    int index = hashFunction(key, ht->size);

    // Verifica se a chave já existe
    HashNode *current = ht->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("Aviso: Chave %d já existe, atualizando valor para %d.\n", key, value);
            current->value = value; // Atualiza o valor
            return;
        }
        current = current->next;
    }

    // Aloca novo nó
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    if (new_node == NULL)
    {
        printf("Erro: Falha na alocação de memória para o nó.\n");
        return;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = ht->table[index]; // Insere no início da lista
    ht->table[index] = new_node;
}

/**
 * @brief Função para buscar um valor pela chave.
 *
 * A busca por hashing utiliza uma tabela de dispersão (hash table) para mapear chaves
 * de dados a posições em um array. Cada chave é transformada por uma função hash que
 * determina sua posição na tabela. É uma estrutura eficiente para buscas rápidas, desde
 * que a função hash seja bem distribuída e a colisão seja tratada adequadamente.
 *
 * Complexidade:
 *
 * - Tempo: O(1) no caso médio e melhor caso; O(n) no pior caso (quando há muitas colisões).
 *
 * - Espaço: O(n), onde n é o número de elementos armazenados na tabela hash.
 *
 * @param ht Tabela hash.
 * @param key Chave a ser buscada.
 * @return HashNode* Ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
HashNode *search(HashTable *ht, int key)
{
    if (ht == NULL)
    {
        printf("Erro: Tabela hash não inicializada.\n");
        return NULL;
    }

    int index = hashFunction(key, ht->size);
    HashNode *current = ht->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL; // Não encontrado
}
/**
 * @brief Remove um par chave-valor da tabela hash.
 */
void removeKey(HashTable *ht, int key)
{
    if (ht == NULL)
    {
        printf("Erro: Tabela hash não inicializada.\n");
        return;
    }

    int index = hashFunction(key, ht->size);
    HashNode *current = ht->table[index];
    HashNode *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                ht->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Chave %d removida.\n", key);
            return;
        }
        prev = current;
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
