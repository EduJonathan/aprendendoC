#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct node
{
    int key;
    int value;
} HashNode;

typedef struct table
{
    HashNode *table[TABLE_SIZE];
} HashTable;

/**
 * @brief Função de hash
 *
 * @param key Chave a ser usada na função
 */
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

/**
 * @brief Função para inicializar a tabela hash
 *
 * @param ht Tabela hash
 */
void initHashTable(HashTable *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
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
    int index = hashFunction(key);

    // Alocar memória para o nó
    ht->table[index] = (HashNode *)malloc(sizeof(HashNode));
    ht->table[index]->key = key;
    ht->table[index]->value = value;
}

/**
 * @brief Função para buscar um valor pela chave
 *
 * @param ht Tabela hash
 * @param key Chave a ser buscada
 * @return HashNode* Ponteiro para o nó encontrado
 * @note A busca por hashing usa uma tabela de dispersão (hash table) para mapear chaves
 * de dados para posições em um array. Cada elemento tem um "hash" que aponta diretamente
 * para sua posição na tabela, Usada quando é necessário realizar buscas rápidas e frequentes
 * em grandes conjuntos de dados.
 */
HashNode *search(HashTable *ht, int key)
{
    int index = hashFunction(key);
    
    if (ht->table[index] != NULL && ht->table[index]->key == key)
    {
        return ht->table[index];
    }
    
    // Não encontrado
    return NULL; 
}

int main(int argc, char **argv)
{
    HashTable ht;
    initHashTable(&ht); // Inicializar a tabela hash

    // Inserir valores
    insert(&ht, 10, 100);
    insert(&ht, 20, 200);
    insert(&ht, 30, 300);

    // Buscar e imprimir valor associado à chave 20
    HashNode *node = search(&ht, 20);

    if (node != NULL)
    {
        printf("Chave: %d, Valor: %d\n", node->key, node->value);
    }
    return 0;
}
