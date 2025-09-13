#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A tabela de hash é uma das estruturas de dados associativas mais comuns.
 * Ela usa uma função de hash para mapear as chaves para índices de um vetor (ou array),
 * onde os valores são armazenados. A função de hash calcula um índice com base na
 * chave fornecida.
 */

#define SIZE_TABLE_HASH 10

#ifndef NODE_H
#define NODE_H

/**
 * @struct No
 * @brief Estrutura que representa um nó em uma lista encadeada.
 *
 * Cada nó contém uma chave, um valor e um ponteiro para o próximo nó.
 */
typedef struct No
{
    char *key;       /**< A chave associada ao nó. */
    int value;       /**< O valor associado à chave. */
    struct No *prox; /**< Ponteiro para o próximo nó na lista encadeada. */
} Node;

#endif

#ifndef HASH_H
#define HASH_H

/**
 * @struct hash
 * @brief Estrutura que representa uma tabela de hash.
 *
 * A tabela de hash é composta por um vetor de ponteiros para nós.
 */
typedef struct hash
{
    Node *tabela[SIZE_TABLE_HASH]; /**< Vetor de ponteiros para os nós da tabela. */
} HashTable;

#endif

/**
 * @brief Inicializa a tabela de hash, definindo todos os índices como NULL.
 *
 * Esta função percorre o vetor da tabela de hash e
 * inicializa todos os elementos como NULL, indicando que as posições estão vazias.
 *
 * @param tabela Ponteiro para a tabela de hash a ser inicializada.
 */
void inicializaHashTable(HashTable *tabela)
{
    for (int i = 0; i < SIZE_TABLE_HASH; i++)
    {
        tabela->tabela[i] = NULL;
    }
}

/**
 * @brief Função hash simples que calcula um valor de hash a partir de uma chave.
 *
 * A função percorre a chave caractere por caractere, somando os
 * valores dos caracteres para gerar o valor do hash. O resultado é um número
 * que é então reduzido pelo tamanho da tabela para se ajustar ao índice.
 *
 * @param chave A chave a ser processada para calcular o hash.
 * @return O índice calculado para a tabela de hash.
 */
unsigned int functionHash(char *chave)
{
    unsigned int hash = 0;

    while (*chave)
    {
        hash += *chave++;
    }
    return hash % SIZE_TABLE_HASH;
}

/**
 * @brief Insere um novo par chave-valor na tabela de hash.
 *
 * Esta função cria um novo nó com a chave e valor fornecidos e o
 * insere na tabela de hash no índice correspondente. Caso já exista um nó na posição,
 * o novo nó é adicionado no início da lista encadeada.
 *
 * @param tabela Ponteiro para a tabela de hash onde o par será inserido.
 * @param key A chave associada ao valor.
 * @param valor O valor a ser associado à chave.
 */
void inserir(HashTable *tabela, char *key, int valor)
{
    unsigned int index = functionHash(key);
    Node *novo = (Node *)malloc(sizeof(Node));

    novo->key = strdup(key);
    novo->value = valor;
    novo->prox = tabela->tabela[index];
    tabela->tabela[index] = novo;
}

/**
 * @brief Busca um valor na tabela de hash, dado o valor da chave.
 *
 * A função percorre a lista encadeada no índice correspondente e
 * verifica se existe um nó com a chave fornecida. Caso encontrado,
 * retorna o valor associado à chave. Caso contrário, retorna -1.
 *
 * @param tabela Ponteiro para a tabela de hash onde a busca será realizada.
 * @param key A chave a ser buscada.
 * @return O valor associado à chave, ou -1 caso a chave não seja encontrada.
 */
int buscar(HashTable *tabela, char *key)
{
    unsigned int index = functionHash(key);
    Node *atual = tabela->tabela[index];

    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            return atual->value;
        }

        atual = atual->prox;
    }
    return -1;
}

/**
 * @brief Exibe todos os pares chave-valor presentes na tabela de hash.
 *
 * A função percorre cada índice da tabela e, caso existam nós no índice,
 * imprime a chave e o valor de cada nó.
 *
 * @param tabela Ponteiro para a tabela de hash a ser exibida.
 */
void exibir(HashTable *tabela)
{
    for (int i = 0; i < SIZE_TABLE_HASH; i++)
    {
        Node *atual = tabela->tabela[i];

        while (atual)
        {
            printf("(%s: %d)\n", atual->key, atual->value);
            atual = atual->prox;
        }
    }
}

int main(int argc, char **argv)
{
    // Aloca memória para a tabela de hash
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));

    if (ht == NULL)
    {
        printf("Falha na alocação de memória!\n");
        return 1; // Saída do programa caso falhe na alocação
    }

    // Inicializa a tabela de hash
    inicializaHashTable(ht);

    // Insere pares key-valor na tabela
    inserir(ht, "key1", 1);
    inserir(ht, "key2", 2);
    inserir(ht, "key3", 3);
    inserir(ht, "key4", 4);
    inserir(ht, "key5", 5);
    inserir(ht, "key6", 6);
    inserir(ht, "key7", 7);
    inserir(ht, "key8", 8);
    inserir(ht, "key9", 9);
    inserir(ht, "key10", 10);

    // Exibe o conteúdo da tabela de hash
    exibir(ht);

    // Realiza buscas e exibe os resultados
    printf("key: %s, Valor: %d\n", "key1", buscar(ht, "key1"));
    printf("key: %s, Valor: %d\n", "key2", buscar(ht, "key2"));

    // Libera a memória alocada para a tabela
    free(ht);

    return 0;
}
