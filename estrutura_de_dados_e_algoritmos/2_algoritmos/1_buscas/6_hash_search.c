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
 * @brief Função para buscar um valor pela chave.
 *
 * A busca por hashing utiliza uma tabela de dispersão (hash table) para mapear chaves
 * de dados a posições em um array. Cada chave é transformada por uma função hash que
 * determina sua posição na tabela. É uma estrutura eficiente para buscas rápidas, desde
 * que a função hash seja bem distribuída e a colisão seja tratada adequadamente.
 *
 * Complexidade:
 * - Tempo: O(1) no caso médio e melhor caso; O(n) no pior caso (quando há muitas colisões).
 * - Espaço: O(n), onde n é o número de elementos armazenados na tabela hash.
 *
 * @param ht Tabela hash.
 * @param key Chave a ser buscada.
 * @return HashNode* Ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
HashNode *search(HashTable *ht, int key)
{
    int index = hashFunction(key);

    if (ht->table[index] != NULL && ht->table[index]->key == key)
    {
        return ht->table[index];
    }
    return NULL; // Não encontrado
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
