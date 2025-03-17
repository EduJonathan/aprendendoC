#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERTICES 10

#ifndef ARESTA_H
#define ARESTA_H

/**< Estrutura que representa uma aresta */
typedef struct Aresta
{
    char destino;        /**< Destino da aresta */
    int peso;            /**< Peso da aresta */
    struct Aresta *prox; /**< Ponteiro para a próxima aresta */
} aresta;

#endif

#ifndef GRAFO_H
#define GRAFO_H

/**< Estrutura que representa um grafo */
typedef struct Grafo
{
    aresta *adj[VERTICES]; /**< Matriz de adjacência */
} grafo;

#endif

/**
 * @brief Inicializa o grafo
 *
 * Função para inicializar o grafo
 *
 * @param g Ponteiro para o grafo
 */
void initGrafo(grafo *g)
{
    for (int i = 0; i < VERTICES; i++)
    {
        g->adj[i] = NULL;
    }
}

/**
 * @brief Adiciona uma aresta ao grafo
 *
 * Função para adicionar uma aresta ao grafo
 *
 * @param g Ponteiro para o grafo
 * @param origem Origem da aresta
 * @param destino Destino da aresta
 * @param peso Peso da aresta
 */
void addAresta(grafo *g, char origem, char destino, int peso)
{
    int i = origem - 'A';                                  // Converte o caractere da origem para um inteiro
    aresta *novaAresta = (aresta *)malloc(sizeof(aresta)); // Aloca memória para a nova aresta
    novaAresta->destino = destino;                         // Define o destino da aresta
    novaAresta->peso = peso;                               // Define o peso da aresta
    novaAresta->prox = g->adj[i];                          // Define o ponteiro para a primeira aresta da lista
    g->adj[i] = novaAresta;                                // Define o ponteiro para a primeira aresta da lista
}

/**
 * @brief Imprime o grafo na tela
 *
 * @param g Ponteiro para o grafo
 */
void printGrafo(grafo *g)
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (g->adj[i])
        {
            printf("Vertice %c: ", 'A' + i);

            // ponteiro para o primeiro elemento da lista
            aresta *arestas = g->adj[i];

            while (arestas != NULL)
            {
                printf("-> %c (Peso: %d)  ", arestas->destino, arestas->peso);
                arestas = arestas->prox;
            }
            printf("\n");
        }
    }
}

/**
 * @brief Libera a memória alocada para o grafo
 *
 * Função para liberar a memória das arestas do grafo
 *
 * @param g Ponteiro para o grafo
 */
void freeGrafo(grafo *g)
{
    for (int i = 0; i < VERTICES; i++)
    {
        // Armazena o ponteiro para a primeira aresta
        aresta *arestas = g->adj[i];

        // Libera a memória das arestas
        while (arestas != NULL)
        {
            aresta *temp = arestas;  // Armazena o ponteiro para a aresta atual
            arestas = arestas->prox; // Move o ponteiro para a próxima aresta
            free(temp);              // Libera a memória da aresta
        }
    }
}

int main(int argc, char **argv)
{
    grafo g;

    // Inicializa o grafo
    initGrafo(&g);

    // Adiciona as arestas
    addAresta(&g, 'A', 'B', 5);
    addAresta(&g, 'A', 'C', 3);
    addAresta(&g, 'B', 'C', 2);
    addAresta(&g, 'C', 'A', 7);

    // Imprime o grafo
    printGrafo(&g);

    // Libera a memória alocada
    freeGrafo(&g);
    return 0;
}
