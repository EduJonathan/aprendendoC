#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TAMANHO_TABELA 10

/**
 * @struct No
 * @brief Estrutura que representa um nó em uma lista encadeada.
 *
 * Cada nó contém uma chave (string), um valor (int) e um ponteiro para o próximo nó.
 */
typedef struct No
{
    char *key;       /**< Chave associada ao nó */
    int value;       /**< Valor associado à chave */
    struct No *prox; /**< Ponteiro para o próximo nó */
} No;

/**
 * @struct TabelaHash
 * @brief Estrutura que representa uma tabela de hash.
 *
 * Usa encadeamento para tratar colisões, com complexidade média O(1) para inserção e busca.
 */
typedef struct TabelaHash
{
    No **tabela;       /**< Array de ponteiros para listas encadeadas */
    size_t capacidade; /**< Tamanho da tabela */
} TabelaHash;

/**
 * @brief Cria uma tabela de hash com a capacidade especificada.
 *
 * @param capacidade Tamanho da tabela (deve ser maior que 0).
 * @return Ponteiro para a tabela criada ou NULL em caso de falha.
 */
TabelaHash *criarTabelaHash(size_t capacidade)
{
    if (capacidade == 0)
    {
        fprintf(stderr, "Erro: Capacidade deve ser maior que 0\n");
        return NULL;
    }

    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    if (tabela == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a tabela\n");
        return NULL;
    }

    tabela->tabela = (No **)calloc(capacidade, sizeof(No *));
    if (tabela->tabela == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o array\n");
        free(tabela);
        return NULL;
    }

    tabela->capacidade = capacidade;
    for (size_t i = 0; i < capacidade; i++)
    {
        tabela->tabela[i] = NULL;
    }
    return tabela;
}

/**
 * @brief Calcula o índice de uma chave usando a função hash djb2.
 *
 * @param chave Chave a ser processada.
 * @param capacidade Tamanho da tabela.
 * @return Índice calculado (0 a capacidade-1).
 */
unsigned int calcularHash(const char *chave, size_t capacidade)
{
    if (chave == NULL)
    {
        return 0;
    }

    unsigned long hash = 5381;
    int c = 0;
    while ((c = *chave++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % capacidade;
}

/**
 * @brief Insere um par chave-valor na tabela de hash.
 *
 * Atualiza o valor se a chave já existe; caso contrário, adiciona um novo nó.
 * Complexidade: O(1) médio, O(n) pior caso.
 *
 * @param tabela Tabela de hash.
 * @param key Chave (não nula ou vazia).
 * @param valor Valor associado.
 * @return 1 se inserido/atualizado, 0 se falhou.
 */
int inserirPar(TabelaHash *tabela, const char *key, int valor)
{
    if (tabela == NULL || key == NULL || *key == '\0')
    {
        fprintf(stderr, "Erro: Tabela nula, chave nula ou vazia\n");
        return 0;
    }

    unsigned int index = calcularHash(key, tabela->capacidade);
    No *atual = tabela->tabela[index];
    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            atual->value = valor; // Atualiza valor existente
            return 1;
        }
        atual = atual->prox;
    }

    No *novo = (No *)malloc(sizeof(No));
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
    novo->value = valor;
    novo->prox = tabela->tabela[index];
    tabela->tabela[index] = novo;
    return 1;
}

/**
 * @brief Busca o valor associado a uma chave.
 *
 * @param tabela Tabela de hash.
 * @param key Chave a ser buscada.
 * @return Valor associado ou INT_MIN se não encontrado.
 */
int buscarValor(TabelaHash *tabela, const char *key)
{
    if (tabela == NULL || key == NULL || *key == '\0')
    {
        return INT_MIN;
    }

    unsigned int index = calcularHash(key, tabela->capacidade);
    No *atual = tabela->tabela[index];
    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            return atual->value;
        }
        atual = atual->prox;
    }
    return INT_MIN;
}

/**
 * @brief Imprime os pares chave-valor da tabela de hash.
 *
 * @param tabela Tabela de hash.
 */
void imprimirTabela(TabelaHash *tabela)
{
    if (tabela == NULL)
    {
        printf("Tabela vazia\n");
        return;
    }

    for (size_t i = 0; i < tabela->capacidade; i++)
    {
        printf("[%zu]: ", i);
        No *atual = tabela->tabela[i];
        if (atual == NULL)
        {
            printf("[]");
        }
        else
        {
            printf("[");
            while (atual)
            {
                printf("(%s: %d)", atual->key, atual->value);
                atual = atual->prox;
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
 * @param tabela Tabela de hash.
 */
void liberarTabelaHash(TabelaHash *tabela)
{
    if (tabela == NULL)
    {
        return;
    }

    for (size_t i = 0; i < tabela->capacidade; i++)
    {
        No *atual = tabela->tabela[i];
        while (atual)
        {
            No *temp = atual;
            atual = atual->prox;
            free(temp->key);
            free(temp);
        }
        tabela->tabela[i] = NULL;
    }
    free(tabela->tabela);
    free(tabela);
}

int main(int argc, char **argv)
{

    TabelaHash *ht = criarTabelaHash(TAMANHO_TABELA);
    if (ht == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação da tabela\n");
        return EXIT_FAILURE;
    }

    inserirPar(ht, "key1", 1);
    inserirPar(ht, "key2", 2);
    inserirPar(ht, "key3", 3);
    inserirPar(ht, "key4", 4);
    inserirPar(ht, "key5", 5);
    inserirPar(ht, "key6", 6);
    inserirPar(ht, "key7", 7);
    inserirPar(ht, "key8", 8);
    inserirPar(ht, "key9", 9);
    inserirPar(ht, "key10", 10);

    imprimirTabela(ht);

    printf("Chave 'key1': %d\n", buscarValor(ht, "key1"));
    printf("Chave 'key2': %d\n", buscarValor(ht, "key2"));
    printf("Chave 'key99': %d\n", buscarValor(ht, "key99"));

    liberarTabelaHash(ht);
    return 0;
}
