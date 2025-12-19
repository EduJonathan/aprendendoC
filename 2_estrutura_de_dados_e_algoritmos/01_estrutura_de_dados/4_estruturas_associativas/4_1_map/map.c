#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_TABLE_HASH 10

#ifndef MAP
#define MAP

/**
 * @struct Map
 * @brief Estrutura que representa um nó de uma lista encadeada para um par chave-valor.
 *
 * Cada nó contém uma chave (string), um valor (char) e um ponteiro para o próximo nó.
 */
typedef struct Mapa
{
    char *key;         /**< Chave associada ao par chave-valor */
    char value;        /**< Valor associado à chave */
    struct Mapa *next; /**< Ponteiro para o próximo nó */
} Map;

#endif

#ifndef TABLE
#define TABLE

/**
 * @struct Tabela
 * @brief Estrutura que representa uma tabela de hash.
 *
 * Contém um tamanho definido e um array de listas encadeadas para pares chave-valor.
 * A complexidade média para inserção e busca é O(1), mas pode ser O(n) no pior caso devido a colisões.
 */
typedef struct Tabela
{
    int tamanho;  /**< Tamanho da tabela de hash */
    Map **tabela; /**< Array de ponteiros para listas encadeadas */
} Tabela;

#endif

/**
 * @brief Cria uma tabela de hash com o tamanho especificado.
 *
 * Aloca memória para a tabela e inicializa todas as posições como NULL.
 *
 * @param tamanho Tamanho da tabela (deve ser maior que 0).
 * @return Ponteiro para a tabela criada ou NULL em caso de falha.
 */
Tabela *criarTabela(int tamanho)
{
    if (tamanho <= 0)
    {
        fprintf(stderr, "Erro: Tamanho da tabela deve ser maior que 0\n");
        return NULL;
    }

    Tabela *table = (Tabela *)malloc(sizeof(Tabela));
    if (table == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a tabela\n");
        return NULL;
    }

    table->tamanho = tamanho;
    table->tabela = (Map **)calloc(tamanho, sizeof(Map *));
    if (table->tabela == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o array da tabela\n");
        free(table);
        return NULL;
    }

    return table;
}

/**
 * @brief Calcula o índice de uma chave usando a função hash djb2.
 *
 * @param key Chave a ser processada.
 * @param tamanho Tamanho da tabela.
 * @return Índice calculado (0 a tamanho-1).
 */
unsigned int funcaoHash(const char *key, int tamanho)
{
    if (key == NULL)
    {
        return 0;
    }

    unsigned long hash = 5381;
    int c = 0;
    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % tamanho;
}

/**
 * @brief Insere um par chave-valor na tabela de hash.
 *
 * Insere no início da lista encadeada no índice calculado pela função hash.
 * Evita duplicatas atualizando o valor se a chave já existe.
 *
 * @param table Tabela de hash.
 * @param key Chave a ser inserida (não nula ou vazia).
 * @param value Valor associado.
 * @return 1 se a inserção foi bem-sucedida, 0 se falhou.
 */
int inserirPar(Tabela *table, const char *key, char value)
{
    if (table == NULL || key == NULL || *key == '\0')
    {
        fprintf(stderr, "Erro: Tabela nula, chave nula ou vazia\n");
        return 0;
    }

    unsigned int index = funcaoHash(key, table->tamanho);
    Map *atual = table->tabela[index];
    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            atual->value = value; // Atualiza valor se chave existe
            return 1;
        }
        atual = atual->next;
    }

    Map *novo = (Map *)malloc(sizeof(Map));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o nó\n");
        return 0;
    }

    novo->key = strdup(key);
    if (novo->key == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a chave\n");
        free(novo);
        return 0;
    }
    novo->value = value;
    novo->next = table->tabela[index];
    table->tabela[index] = novo;
    return 1;
}

/**
 * @brief Busca o valor associado a uma chave na tabela de hash.
 *
 * @param table Tabela de hash.
 * @param key Chave a ser buscada.
 * @return Valor associado ou '\0' se não encontrado.
 */
char buscarValor(Tabela *table, const char *key)
{
    if (table == NULL || key == NULL || *key == '\0')
    {
        return '\0';
    }

    unsigned int index = funcaoHash(key, table->tamanho);
    Map *atual = table->tabela[index];
    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            return atual->value;
        }
        atual = atual->next;
    }
    return '\0';
}

/**
 * @brief Exibe todos os pares chave-valor na tabela de hash.
 *
 * @param table Tabela de hash.
 */
void imprimirTabela(Tabela *table)
{
    if (table == NULL)
    {
        printf("Tabela vazia\n");
        return;
    }

    for (int i = 0; i < table->tamanho; i++)
    {
        printf("[%d]: ", i);
        Map *atual = table->tabela[i];
        if (atual == NULL)
        {
            printf("[]");
        }
        else
        {
            printf("[");
            while (atual)
            {
                printf("(%s: %c)", atual->key, atual->value);
                atual = atual->next;
                if (atual)
                {
                    printf(", ");
                }
            }
            printf("]");
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para a tabela de hash.
 *
 * @param table Tabela de hash.
 */
void liberarTabela(Tabela *table)
{
    if (table == NULL)
    {
        return;
    }

    for (int i = 0; i < table->tamanho; i++)
    {
        Map *atual = table->tabela[i];
        while (atual)
        {
            Map *temp = atual;
            atual = atual->next;
            free(temp->key);
            free(temp);
        }
        table->tabela[i] = NULL;
    }
    free(table->tabela);
    free(table);
}

int main(int argc, char **argv)
{
    Tabela *tabela = criarTabela(SIZE_TABLE_HASH);
    if (tabela == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação da tabela\n");
        return EXIT_FAILURE;
    }

    inserirPar(tabela, "key1", 'A');
    inserirPar(tabela, "key2", 'B');
    inserirPar(tabela, "key3", 'C');

    imprimirTabela(tabela);

    char busca = buscarValor(tabela, "key2");
    printf("Busca por 'key2': %c\n", busca ? busca : "Não encontrado"[0]);

    liberarTabela(tabela);
    return 0;
}
