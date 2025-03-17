#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 26 // A-Z => 26 letras
#define VERTICES 10   // Max vertices A-J

/**< Estrutura que representa uma aresta */
typedef struct Aresta
{
    char destino;        /**< Destino da aresta */
    int peso;            /**< Peso da aresta */
    struct Aresta *prox; /**< Ponteiro para a próxima aresta */
} aresta;

/**< Estrutura para representar um dicionário (hash table) de arestas */
typedef struct TabelaArestas
{
    aresta *adj; /**< Lista de arestas (para cada vértice) */
} TabelaArestas;

/**< Função de hash para mapear o vértice (letra) para um índice */
int hash(char vertice)
{
    // Mapeia 'A' para 0, 'B' para 1, ..., 'J' para 9
    return vertice - 'A';
}

/**
 * @brief Inicializa o dicionário (hash table)
 *
 * @param tabela Ponteiro para a tabela de arestas
 */
void initTabela(TabelaArestas tabela[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tabela[i].adj = NULL;
    }
}

/**
 * @brief Adiciona uma aresta ao grafo
 *
 * @param tabela Ponteiro para a tabela de arestas
 * @param origem Vértice de origem da aresta
 * @param destino Vértice de destino da aresta
 * @param peso Peso da aresta
 */
void addAresta(TabelaArestas tabela[], char origem, char destino, int peso)
{
    int indice = hash(origem); // Calcula o índice usando o hash

    aresta *novaAresta = (aresta *)malloc(sizeof(aresta)); // Aloca memória para a nova aresta
    novaAresta->destino = destino;                         // Define o destino da aresta
    novaAresta->peso = peso;                               // Define o peso da aresta
    novaAresta->prox = tabela[indice].adj;                 // A nova aresta aponta para o que já existia

    // Atualiza a lista de arestas para o vértice de orige
    tabela[indice].adj = novaAresta;
}

/**
 * @brief Imprime o grafo (hash table de arestas)
 *
 * @param tabela Ponteiro para a tabela de arestas
 */
void printTabela(TabelaArestas tabela[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tabela[i].adj != NULL)
        {
            printf("Vértice %c: ", 'A' + i); // Vértice representado por um caractere

            aresta *arestas = tabela[i].adj; // Ponteiro para a lista de arestas

            // Percorre a lista de arestas
            while (arestas != NULL)
            {
                printf("-> %c (Peso: %d) ", arestas->destino, arestas->peso);
                arestas = arestas->prox;
            }
            printf("\n");
        }
    }
}

int main(int argc, char **argv)
{
    // Cria a tabela de arestas
    TabelaArestas tabela[TABLE_SIZE];

    // Inicializa a tabela
    initTabela(tabela);

    // Adiciona algumas arestas ao grafo
    addAresta(tabela, 'A', 'B', 5);
    addAresta(tabela, 'A', 'C', 3);
    addAresta(tabela, 'B', 'C', 2);
    addAresta(tabela, 'C', 'A', 7);

    // Imprime o grafo
    printTabela(tabela);

    return 0;
}
