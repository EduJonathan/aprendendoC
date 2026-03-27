#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
typedef struct Edge
{
    int src;    /**< Vértice de origem da aresta */
    int dest;   /**< Vértice de destino da aresta */
    int weight; /**< Peso da aresta */
} Edge;

/**
 * @struct Graph
 * @brief Estrutura que representa um grafo.
 *
 * O grafo tem um número de vértices (vertices), um número de arestas (edges),
 * e um vetor de arestas (edge).
 */
typedef struct Graph
{
    int vertices;      /**< Número de vértices do grafo */
    int edges;         /**< Número de arestas do grafo */
    struct Edge *edge; /**< Vetor de arestas */
} Graph;

/**
 * @brief Cria um grafo com o número de vértices e arestas especificado.
 *
 * @param v Número de vértices do grafo.
 * @param e Número de arestas do grafo.
 * @return Um ponteiro para a estrutura do grafo criada.
 */
Graph *criarGrafo(int vertices, int edges)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (!g)
    {
        printf("Erro: Falha na alocação do grafo.\n");
        exit(EXIT_FAILURE);
    }

    g->vertices = vertices;
    g->edges    = edges;
    g->edge     = (Edge *)malloc(edges * sizeof(Edge));

    if (!g->edge)
    {
        printf("Erro: Falha na alocação das arestas.\n");
        free(g);
        exit(EXIT_FAILURE);
    }
    return g;
}

/**
 * @brief Função reponsável para adicionar nós no grafo
 * 
 * @param g informar a estrutura do grafo
 * @param idx Onde será indexado
 * @param src Caminho de partida da Aresta
 * @param dest Destino do Aresta
 * @param weight Peso da arestas
 */
void adicionarAresta(Graph *g, int idx, int src, int dest, int weight)
{
    g->edge[idx].src    = src;
    g->edge[idx].dest   = dest;
    g->edge[idx].weight = weight;
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

    int *distancia   = (int *)malloc(V * sizeof(int));
    int *predecessor = (int *)malloc(V * sizeof(int));

    if (!distancia || !predecessor)
    {
        printf("Erro: Falha na alocação de memória.\n");
        free(distancia);
        free(predecessor);
        return;
    }

    // Inicialização
    for (int i = 0; i < V; i++)
    {
        distancia[i] = INT_MAX;
        predecessor[i] = -1;
    }
    distancia[src] = 0;

    // Relaxamento |V| - 1 vezes
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u    = g->edge[j].src;
            int v    = g->edge[j].dest;
            int peso = g->edge[j].weight;

            // Relaxamento
            if (distancia[u] != INT_MAX && distancia[u] + peso < distancia[v])
            {
                distancia[v] = distancia[u] + peso;
                predecessor[v] = u;
            }
        }
    }

    // Verificação de ciclo negativo (iteração extra)
    bool cicloNegativo = false;
    for (int j = 0; j < E; j++)
    {
        int u    = g->edge[j].src;
        int v    = g->edge[j].dest;
        int peso = g->edge[j].weight;

        if (distancia[u] != INT_MAX && distancia[u] + peso < distancia[v])
        {
            cicloNegativo = true;
            break;
        }
    }

    if (cicloNegativo)
    {
        printf("ERRO: O grafo contém um ciclo de peso negativo!\n");
        printf("Os resultados não são confiáveis.\n");
        free(distancia);
        free(predecessor);
        return;
    }

    // EXIBIÇÃO DOS RESULTADOS
    printf("=== Algoritmo de Bellman-Ford ===\n");
    printf("Fonte: vértice %d\n\n", src);
    printf("Vértice\tDistância\tCaminho\n");
    printf("------------------------------------\n");

    for (int i = 0; i < V; i++)
    {
        if (distancia[i] == INT_MAX)
        {
            printf("%d\tInalcançável\t-\n", i);
            continue;
        }

        printf("%d\t%d\t\t", i, distancia[i]);

        // Reconstrói o caminho
        if (i == src)
        {
            printf("%d\n", src);
            continue;
        }

        int path[100]; // Buffer suficiente para a maioria dos grafos
        int count = 0;
        int atual = i;

        while (atual != -1 && count < 100)
        {
            path[count++] = atual;
            atual = predecessor[atual];
        }

        // Imprime caminho na ordem correta (origem -> destino)
        for (int j = count - 1; j >= 0; j--)
        {
            printf("%d", path[j]);
            if (j > 0)
                printf(" -> ");
        }
        printf("\n");
    }

    free(distancia);
    free(predecessor);
}

int main(int argc, char **argv)
{
    int V = 5;                              /**< Número de vértices no grafo */
    int E = 8;                              /**< Número de arestas no grafo */
    struct Graph *grafo = criarGrafo(V, E); /**< Cria o grafo */

    // Adiciona as arestas (src, dest, weight)
    adicionarAresta(grafo, 0, 0, 1, 5);
    adicionarAresta(grafo, 1, 0, 2, 4);
    adicionarAresta(grafo, 2, 1, 2, 3);
    adicionarAresta(grafo, 3, 1, 3, 2);
    adicionarAresta(grafo, 4, 1, 4, 6);
    adicionarAresta(grafo, 5, 2, 3, 5);
    adicionarAresta(grafo, 6, 3, 1, -1); // peso negativo (permitido)
    adicionarAresta(grafo, 7, 4, 3, 2);

    printf("Executando Bellman-Ford a partir do vértice 0...\n\n");
    bellmanFordAlgoritmo(grafo, 0);

    // Liberação de memória
    free(grafo->edge);
    free(grafo);
    return 0;
}
