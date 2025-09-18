#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Algoritmo de Bellman-Ford - Caminho Mínimo com Pesos Negativos
 * O algoritmo de Bellman-Ford resolve o problema de caminho mais curto a partir
 * de uma única fonte em grafos com **pesos negativos**, e também detecta ciclos negativos.
 *
 * Ao contrário do Dijkstra, ele não usa estrutura de prioridade e é
 * baseado em **relaxamento iterativo**:
 * - Para cada aresta, tenta relaxar a distância de um vértice para outro.
 * - Repete esse processo V - 1 vezes (onde V é o número de vértices).
 * - Após isso, uma iteração extra pode detectar ciclos negativos.
 *
 * Aplicações:
 * - Financeiro (verificação de arbitragem de moedas)
 * - Redes com penalidades
 * - Sistemas que toleram valores negativos em custos
 *
 * COMPLEXIDADE:
 * - TEMPO: O(V * E)
 * - ESPAÇO: O(V)
 *
 * @note Mais lento que Dijkstra, mas mais poderoso por suportar pesos negativos
 * e detectar ciclos negativos.
 */

/**
 * @struct Edge
 * @brief Estrutura que representa uma aresta do grafo.
 *
 * Cada aresta tem um vértice de origem (src), um vértice de destino (dest) e um peso (weight).
 */
struct Edge
{
    int src;    /**< Vértice de origem da aresta */
    int dest;   /**< Vértice de destino da aresta */
    int weight; /**< Peso da aresta */
};

/**
 * @struct Graph
 * @brief Estrutura que representa um grafo.
 *
 * O grafo tem um número de vértices (vertices), um número de arestas (edges),
 * e um vetor de arestas (edge).
 */
struct Graph
{
    int vertices;      /**< Número de vértices do grafo */
    int edges;         /**< Número de arestas do grafo */
    struct Edge *edge; /**< Vetor de arestas */
};

/**
 * @brief Cria um grafo com o número de vértices e arestas especificado.
 *
 * @param v Número de vértices do grafo.
 * @param e Número de arestas do grafo.
 * @return Um ponteiro para a estrutura do grafo criada.
 */
struct Graph *criarGrafo(int v, int e)
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->vertices = v;
    g->edges = e;
    g->edge = (struct Edge *)malloc(e * sizeof(struct Edge));
    return g;
}

/**
 * @brief Imprime as distâncias dos vértices a partir da fonte.
 *
 * @param dist Vetor de distâncias dos vértices.
 * @param n Número de vértices.
 */
void printGraph(int dist[], int n)
{
    printf("Vértices \t Distâncias\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

/**
 * @brief Implementação do algoritmo de Bellman-Ford.
 *
 * Este algoritmo encontra as distâncias mínimas de um vértice fonte a todos os outros
 * vértices em um grafo com arestas de pesos negativos.
 *
 * @param g Ponteiro para o grafo.
 * @param src Vértice de origem (fonte).
 */
void bellmanFordAlgoritmo(struct Graph *g, int src)
{
    int V = g->vertices;
    int E = g->edges;
    int *distancias = (int *)malloc(V * sizeof(int));

    if (distancias == NULL)
    {
        printf("Falha na alocação de memória\n");
        return;
    }

    for (int i = 0; i < V; i++)
    {
        distancias[i] = INT_MAX;
    }
    distancias[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int peso = g->edge[j].weight;

            if (distancias[u] != INT_MAX && distancias[u] + peso < distancias[v])
            {
                distancias[v] = distancias[u] + peso;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = g->edge[i].src;
        int v = g->edge[i].dest;
        int peso = g->edge[i].weight;

        if (distancias[u] != INT_MAX && distancias[u] + peso < distancias[v])
        {
            printf("O grafo possui ciclo de peso negativos\n");
            free(distancias);
            return;
        }
    }

    printGraph(distancias, V);
    free(distancias);
}

int main(int argc, char **argv)
{
    int V = 5;                              /**< Número de vértices no grafo */
    int E = 8;                              /**< Número de arestas no grafo */
    struct Graph *grafo = criarGrafo(V, E); /**< Cria o grafo */

    // Adiciona as arestas ao grafo
    grafo->edge[0].src = 0;
    grafo->edge[0].dest = 0;
    grafo->edge[0].weight = 6;

    grafo->edge[1].src = 0;
    grafo->edge[1].dest = 2;
    grafo->edge[1].weight = 4;

    grafo->edge[2].src = 1;
    grafo->edge[2].dest = 2;
    grafo->edge[2].weight = 3;

    grafo->edge[3].src = 1;
    grafo->edge[3].dest = 3;
    grafo->edge[3].weight = 2;

    grafo->edge[4].src = 1;
    grafo->edge[4].dest = 4;
    grafo->edge[4].weight = 2;

    grafo->edge[5].src = 3;
    grafo->edge[5].dest = 2;
    grafo->edge[5].weight = 5;

    grafo->edge[6].src = 3;
    grafo->edge[6].dest = 1;
    grafo->edge[6].weight = 1;

    grafo->edge[7].src = 4;
    grafo->edge[7].dest = 3;
    grafo->edge[7].weight = 2;

    bellmanFordAlgoritmo(grafo, 0); /**< Chama o algoritmo de Bellman-Ford a partir do vértice 0 */
    free(grafo->edge);
    free(grafo);
    return 0;
}
