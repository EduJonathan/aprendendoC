#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZETABLEHASH 10

/**
 * Um mapa (ou dicionário) é uma estrutura de dados associativa que pode ser implementada
 * por tabelas de hash ou árvores balanceadas (como árvores binárias de busca), dependendo
 * do requisito de desempenho. mapas e dicionários são frequentemente usados como sinônimos
 * em muitos contextos de programação, mas dependendo da linguagem e do paradigma de
 * implementação, pode haver pequenas diferenças.
 *
 * Map podem ser mais focados em tipos de dados mais gerais e podem ter diferentes
 * implementações de acordo com a linguagem (como árvores binárias de busca, tabelas de hash,
 * ou outras implementações).
 * Dicionários, particularmente em Python e outras linguagens de alto nível,
 * são uma implementação específica de mapa, normalmente com base em tabelas de hash.
 *
 * Em resumo, mapas e dicionários são conceitualmente a mesma coisa — estruturas de dados
 * que armazenam pares chave-valor — mas o nome utilizado depende da linguagem de programação.
 */

#ifndef MAP_H
#define MAP_H

/**
 * @struct map
 * @brief Estrutura que representa um nó de uma lista encadeada para armazenar um par chave-valor.
 *
 * Cada nó contém uma chave (do tipo string), um valor (do tipo char) e um ponteiro para o próximo nó.
 */
typedef struct map
{
    char *key;        /**< A chave associada ao par chave-valor. */
    char value;       /**< O valor associado à chave. */
    struct map *next; /**< Ponteiro para o próximo nó na lista encadeada. */
} Map;

#endif

#ifndef TABLE_H
#define TABLE_H

/**
 * @struct Tabela
 * @brief Estrutura que representa a tabela de hash.
 *
 * A tabela de hash contém um vetor de ponteiros para listas encadeadas,
 * cada lista armazena pares chave-valor.
 */
typedef struct Tabela
{
    Map *tabela[SIZETABLEHASH]; /**< Vetor de ponteiros para as listas encadeadas da tabela. */
} Table;

#endif

/**
 * @brief Inicializa a tabela de hash, definindo todas as posições como NULL.
 *
 * A função percorre o vetor de tabelas e define todas as posições como NULL,
 * indicando que as listas estão vazias.
 *
 * @param table Ponteiro para a tabela de hash a ser inicializada.
 */
void inicializaMap(Table *table)
{
    for (int i = 0; i < SIZETABLEHASH; i++)
    {
        table->tabela[i] = NULL;
    }
}

/**
 * @brief Função hash simples que calcula um índice para a chave fornecida.
 *
 * A função percorre os caracteres da chave, somando seus valores ASCII, e
 * retorna um índice dentro dos limites da tabela de hash.
 *
 * @param key A chave a ser processada para calcular o índice.
 * @return O índice calculado para a tabela de hash.
 */
unsigned int funcaoHash(char *key)
{
    unsigned int hash = 0;

    // Calcula o valor ASCII de cada caractere da chave
    while (*key)
    {
        hash += *key++;
    }

    return hash % SIZETABLEHASH;
}

/**
 * @brief Insere um novo par chave-valor na tabela de hash.
 *
 * A função insere o par chave-valor na posição da tabela determinada pela função hash.
 * Se já houver um elemento com a mesma chave, o novo par é inserido no
 * início da lista encadeada.
 *
 * @param table Ponteiro para a tabela de hash onde o par chave-valor será inserido.
 * @param key A chave a ser inserida.
 * @param value O valor associado à chave.
 */
void insereMap(Table *table, char *key, char *value)
{
    unsigned int index = funcaoHash(key);
    Map *novo = (Map *)malloc(sizeof(Map));

    novo->key = strdup(key);
    novo->value = *value;
    novo->next = table->tabela[index];
    table->tabela[index] = novo;
}

/**
 * @brief Busca um valor na tabela de hash dado um chave.
 *
 * A função percorre a lista encadeada na posição determinada pelo hash da chave,
 * e retorna o valor associado à chave, caso a chave seja encontrada.
 *
 * @param table Ponteiro para a tabela de hash onde a busca será realizada.
 * @param key A chave a ser buscada.
 * @return O valor associado à chave, ou NULL caso a chave não seja encontrada.
 */
char *buscaMap(Table *table, char *key)
{
    unsigned int index = funcaoHash(key);
    Map *atual = table->tabela[index];

    while (atual)
    {
        if (strcmp(atual->key, key) == 0)
        {
            return &atual->value;
        }
        atual = atual->next;
    }

    return NULL;
}

/**
 * @brief Exibe todos os pares chave-valor presentes na tabela de hash.
 *
 * A função percorre cada índice da tabela de hash e exibe os pares
 * chave-valor armazenados nas listas encadeadas de cada posição.
 *
 * @param table Ponteiro para a tabela de hash a ser exibida.
 */
void exibirMap(Table *table)
{
    for (int i = 0; i < SIZETABLEHASH; i++)
    {
        Map *atual = table->tabela[i];
        printf("[%d]: ", i);

        while (atual)
        {
            printf("(%s: %c)\n", atual->key, atual->value);
            atual = atual->next;
        }
    }

    printf("NULL\n");
}

/**
 * @brief Libera a memória alocada para a tabela de hash.
 *
 * A função percorre a tabela e, para cada lista encadeada, libera a memória
 * alocada para as chaves, valores e os nós da lista.
 *
 * @param table Ponteiro para a tabela de hash a ser liberada.
 */
void liberarMap(Table *table)
{
    for (int i = 0; i < SIZETABLEHASH; i++)
    {
        Map *atual = table->tabela[i];

        while (atual)
        {
            Map *prox = atual;
            atual = atual->next;
            free(prox->key);
            free(prox);
        }
    }
}

int main(int argc, char **argv)
{
    Table *tabela = (Table *)malloc(sizeof(Table));
    inicializaMap(tabela);

    // Insere pares chave-valor na tabela
    insereMap(tabela, "key1", "A");
    insereMap(tabela, "key2", "B");
    insereMap(tabela, "key3", "C");

    // Exibe o conteúdo da tabela
    exibirMap(tabela);

    // Realiza busca e imprime o resultado
    char *busca = buscaMap(tabela, "key2");
    printf("Busca: %s\n", busca ? busca : "Nao encontrado");

    // Libera a memória alocada
    liberarMap(tabela);
    free(tabela);

    return 0;
}
