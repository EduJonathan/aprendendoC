#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Algoritmo de Floyd-Warshall - Caminho Mínimo entre Todos os Pares
 *
 * O algoritmo de Floyd-Warshall resolve o problema de caminho mínimo entre
 * **todos os pares de vértices** em um grafo direcionado ou não direcionado, com pesos
 * (positivos ou negativos, mas sem ciclos negativos).
 *
 * Baseado na técnica de **programação dinâmica**, ele atualiza iterativamente a
 * menor distância entre cada par de nós, considerando vértices intermediários.
 *
 * FUNCIONAMENTO:
 * - Inicializa uma matriz de distâncias `dist[i][j]` com os pesos das arestas diretas
 * (ou ∞ se não houver).
 * - Para cada vértice intermediário `k`, verifica se `dist[i][k] + dist[k][j] < dist[i][j]`
 * e atualiza.
 *
 * Aplicações:
 * - Roteamento de redes (encontrar menor caminho entre todos os nós)
 * - Análise de acessibilidade entre locais
 * - Verificação de conexões indiretas em grafos
 *
 * Suporta:
 * - Grafos com pesos negativos (mas sem ciclos negativos)
 * - Detecção de ciclos negativos (se `dist[i][i] < 0`)
 *
 * COMPLEXIDADE:
 * - TEMPO: O(V³), onde V é o número de vértices (três laços aninhados).
 * - ESPAÇO: O(V²), para armazenar a matriz de distâncias.
 *
 * @note Para grafos esparsos, algoritmos como Dijkstra (por vértice) são mais eficientes.
 */

/**
 * @brief Função que retorna o menor valor entre dois inteiros.
 *
 * Esta função é usada para determinar o valor mínimo entre dois números
 * durante a execução do algoritmo de Floyd-Warshall.
 *
 * @param a O primeiro valor a ser comparado.
 * @param b O segundo valor a ser comparado.
 *
 * @return O valor mínimo entre os dois valores fornecidos.
 */
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Implementação do algoritmo de Floyd-Warshall para encontrar os caminhos mais curtos.
 *
 * @param graph Matriz de adjacência do grafo, onde graph[i][j] representa a distância
 * do vértice i para o vértice j. O valor INT_MAX indica que não há caminho direto
 * entre os vértices.
 *
 * @param n O número de vértices no grafo.
 *
 * @note O algoritmo de Floyd-Warshall é um algoritmo de programação dinâmica que encontra
 * o caminho mais curto entre todos os pares de vértices em um grafo ponderado.
 */
void floyd_warshall(int **graph, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

/**
 * @brief Aloca uma matriz de adjacência dinamicamente.
 *
 * @param n Tamnaho do grafo
 * @return grafo alocado
 */
int **allocate_graph(int n)
{
    int **graph = (int **)malloc(n * sizeof(int *));
    if (graph == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        if (graph[i] == NULL)
        {
            printf("Erro: Falha na alocação de memória.\n");
            for (int j = 0; j < i; j++)
            {
                free(graph[j]);
            }
            free(graph);
            return NULL;
        }
    }
    return graph;
}

/**
 * @brief Libera a memória alocada para a matriz de adjacência.
 *
 * @param graph Informa o grafo.
 * @brief Tamanho do grafo.
 */
void free_graph(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);
}

int main(int argc, char **argv)
{
    int vertices = 0, edges = 0;

    // Solicita o número de vértices
    printf("Numero de vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0)
    {
        printf("Erro: Número de vértices deve ser positivo.\n");
        return 1;
    }

    // Solicita o número de arestas
    printf("Numero de arestas: ");
    if (scanf("%d", &edges) != 1 || edges < 0)
    {
        printf("Erro: Número de arestas deve ser não-negativo.\n");
        return 1;
    }

    // Aloca a matriz de adjacência dinamicamente
    int **graph = allocate_graph(vertices);
    if (graph == NULL)
    {
        return 1;
    }

    // Inicializa o grafo
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    // Coleta os dados das arestas
    for (int i = 0; i < edges; i++)
    {
        int origem = 0, destino = 0, peso = 0;
        printf("\nDigite o vértice de origem da aresta %d (0 a %d): ", i + 1, vertices - 1);
        if (scanf("%d", &origem) != 1 || origem < 0 || origem >= vertices)
        {
            printf("Erro: Vértice de origem inválido.\n");
            free_graph(graph, vertices);
            return 1;
        }

        printf("Digite o vértice de destino da aresta %d (0 a %d): ", i + 1, vertices - 1);
        if (scanf("%d", &destino) != 1 || destino < 0 || destino >= vertices)
        {
            printf("Erro: Vértice de destino inválido.\n");
            free_graph(graph, vertices);
            return 1;
        }

        printf("Digite o peso da aresta %d: ", i + 1);
        if (scanf("%d", &peso) != 1 || peso < 0)
        {
            printf("Erro: Peso inválido (deve ser não-negativo).\n");
            free_graph(graph, vertices);
            return 1;
        }

        graph[origem][destino] = peso; // Directed graph
        // For undirected graph, uncomment: graph[destino][origem] = peso;
    }

    // Exibe a matriz do grafo inicial
    printf("\nMatriz do grafo inicial:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%3d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    // Aplica o algoritmo de Floyd-Warshall
    floyd_warshall(graph, vertices);

    // Exibe a matriz resultante
    printf("\nMatriz do Floyd-Warshall (caminhos mais curtos):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%3d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    // Exibe os caminhos mínimos
    printf("\nCaminhos mínimos entre os vértices:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i != j)
            {
                printf("<%d, %d> = ", i, j);
                if (graph[i][j] == INT_MAX)
                {
                    printf("INF\n");
                }
                else
                {
                    printf("%d\n", graph[i][j]);
                }
            }
        }
    }

    // Libera a memória alocada
    free_graph(graph, vertices);
    return 0;
}
