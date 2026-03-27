#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @struct GRAFO
 * @brief Estrutura de um grafo ponderado.
 */
typedef struct
{
    int nVertices; ///< Número de vértices do grafo.
    int **arestas; ///< Matriz de adjacência que armazena os pesos das arestas.
} GRAFO;

/**
 * @brief Inicializa um grafo com um número especificado de vértices.
 *
 * @param nVertices Número de vértices do grafo.
 * @return Ponteiro para a estrutura GRAFO, ou NULL em caso de erro.
 */
GRAFO *inicializarGrafo(int nVertices)
{
    if (nVertices <= 0)
        return NULL;

    GRAFO *grafo = (GRAFO *)malloc(sizeof(GRAFO));
    if (!grafo)
        return NULL;

    grafo->nVertices = nVertices;
    grafo->arestas = (int **)malloc(nVertices * sizeof(int *));
    if (!grafo->arestas)
    {
        free(grafo);
        return NULL;
    }

    for (int i = 0; i < nVertices; i++)
    {
        grafo->arestas[i] = (int *)calloc(nVertices, sizeof(int)); // inicializa com 0
        if (!grafo->arestas[i])
        {
            // Libera o que já foi alocado
            for (int j = 0; j < i; j++)
                free(grafo->arestas[j]);
            free(grafo->arestas);
            free(grafo);
            return NULL;
        }
    }
    return grafo;
}

/**
 * @brief Adiciona uma aresta ponderada entre dois vértices no grafo.
 *
 * @param grafo Ponteiro para a estrutura GRAFO.
 * @param origem Índice do vértice de origem.
 * @param destino Índice do vértice de destino.
 * @param peso Peso da aresta entre os vértices.
 * @return true se a aresta foi adicionada com sucesso, false em caso de erro.
 */
bool adicionarAresta(GRAFO *grafo, int origem, int destino, int peso)
{
    if (!grafo || origem < 0 || destino < 0 || origem >= grafo->nVertices || destino >= grafo->nVertices || peso <= 0)
    {
        return false;
    }
    grafo->arestas[origem][destino] = peso;
    return true;
}

/**
 * @brief Retorna o índice do vértice com a menor distância que ainda não foi visitado.
 *
 * @param distancia Array com as distâncias mínimas dos vértices até a origem.
 * @param visitado Array indicando se o vértice foi visitado.
 * @param n Número total de vértices.
 * @return Índice do vértice com a menor distância, ou -1 se todos os vértices foram visitados.
 */
int minDistance(const int *distancia, const bool *visitado, int n)
{
    int minVal = INT_MAX;
    int minInd = -1;

    for (int v = 0; v < n; v++)
    {
        if (!visitado[v] && distancia[v] < minVal)
        {
            minVal = distancia[v];
            minInd = v;
        }
    }
    return minInd;
}

/**
 * @brief Imprime as distâncias mínimas de todos os vértices até a origem.
 *
 * @param distancia Array com as distâncias mínimas dos vértices.
 * @param n Número total de vértices.
 */
void printDistancias(const int *distancia, int n, int src)
{
    printf("\n=== Distâncias mínimas a partir do vértice %d ===\n", src);
    printf("Vértice\tDistância\n");
    printf("-----------------\n");
    for (int i = 0; i < n; i++)
    {
        if (distancia[i] == INT_MAX)
            printf("%d\t∞\n", i);
        else
            printf("%d\t%d\n", i, distancia[i]);
    }
}

/**
 * @brief Imprime o caminho mais curto entre a origem e o vértice destino.
 *
 * @param anterior Array contendo os vértices anteriores no caminho mais curto.
 * @param destino Índice do vértice de destino.
 */
void imprimirCaminho(int *anterior, int destino)
{
    if (anterior[destino] == -1)
    {
        printf("%d", destino);
        return;
    }
    imprimirCaminho(anterior, anterior[destino]);
    printf(" -> %d", destino);
}

/**
 * @brief Executa o algoritmo de Dijkstra para encontrar as distâncias mínimas de
 * todos os vértices a partir de um vértice de origem.
 *
 * O algoritmo segue a estratégia gananciosa(Greedy_Algorithm) ao escolher, a cada iteração,
 * o vértice com a menor distância (custo) conhecida que ainda não foi processado.
 * O algoritmo então atualiza as distâncias de seus vizinhos e repete esse processo até que
 * todas as distâncias mínimas sejam determinadas.
 *
 * @param grafo Ponteiro para a estrutura GRAFO.
 * @param src Índice do vértice de origem.
 */
void dijkstra(const GRAFO *grafo, int src)
{
    if (!grafo || src < 0 || src >= grafo->nVertices)
    {
        printf("Erro: Vértice de origem inválido.\n");
        return;
    }

    int V = grafo->nVertices;
    int *distancia = (int *)malloc(V * sizeof(int));
    bool *visitado = (bool *)malloc(V * sizeof(bool));
    int *anterior  = (int *)malloc(V * sizeof(int));

    if (!distancia || !visitado || !anterior)
    {
        printf("Erro: Falha na alocação de memória.\n");
        free(distancia);
        free(visitado);
        free(anterior);
        return;
    }

    // Inicialização
    for (int i = 0; i < V; i++)
    {
        distancia[i] = INT_MAX;
        visitado[i]  = false;
        anterior[i]  = -1;
    }
    distancia[src] = 0;

    // Relaxamento das arestas (V-1 vezes)
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(distancia, visitado, V);
        if (u == -1)
            break; // não há mais vértices alcançáveis

        visitado[u] = true;

        // Atualiza as distâncias dos vizinhos de u
        for (int v = 0; v < V; v++)
        {
            if (!visitado[v] &&
                grafo->arestas[u][v] != 0 && // existe aresta
                distancia[u] != INT_MAX && distancia[u] + grafo->arestas[u][v] < distancia[v])
            {
                distancia[v] = distancia[u] + grafo->arestas[u][v];
                anterior[v] = u;
            }
        }
    }

    // Exibe resultados
    printDistancias(distancia, V, src);

    printf("\n=== Caminhos mais curtos ===\n");
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            printf("De %d até %d: ", src, i);
            if (distancia[i] == INT_MAX)
            {
                printf("Não existe caminho\n");
            }
            else
            {
                imprimirCaminho(anterior, i);
                printf("  (custo: %d)\n", distancia[i]);
            }
        }
    }

    free(distancia);
    free(visitado);
    free(anterior);
}

/**
 * @brief Libera a memória alocada para o grafo.
 *
 * @param grafo Ponteiro para a estrutura GRAFO.
 */
void liberarGrafo(GRAFO *grafo)
{
    if (!grafo)
        return;
        
    for (int i = 0; i < grafo->nVertices; i++)
    {
        free(grafo->arestas[i]);
    }
    free(grafo->arestas);
    free(grafo);
}

int main(int argc, char **argv)
{
    GRAFO *grafo = inicializarGrafo(6);
    if (!grafo)
    {
        printf("Erro ao inicializar o grafo.\n");
        return EXIT_FAILURE;
    }

    // Adicionando as arestas (grafo direcionado)
    adicionarAresta(grafo, 0, 1, 4);
    adicionarAresta(grafo, 0, 2, 2);
    adicionarAresta(grafo, 1, 2, 3);
    adicionarAresta(grafo, 1, 3, 2);
    adicionarAresta(grafo, 2, 3, 3);
    adicionarAresta(grafo, 2, 4, 1);
    adicionarAresta(grafo, 3, 5, 1);
    adicionarAresta(grafo, 4, 5, 2);

    printf("Executando Dijkstra a partir do vértice 0...\n");
    dijkstra(grafo, 0);

    liberarGrafo(grafo);

    return 0;
}
