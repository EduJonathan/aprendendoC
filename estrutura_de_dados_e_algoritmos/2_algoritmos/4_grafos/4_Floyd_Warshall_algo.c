#include <stdio.h>
#include <limits.h>

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
void floyd_warshall(int graph[10][10], int n)
{
    // Iteração para cada vértice k como vértice intermediário
    // Itera pelos vértices intermediários
    for (int k = 0; k < n; k++)
    {
        // Itera pelos vértices de origem
        for (int i = 0; i < n; i++)
        {
            // Itera pelos vértices de destino
            for (int j = 0; j < n; j++)
            {
                // Se existir um caminho mais curto, atualize a distância
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    int vertices = 0;
    int edges = 0;

    // Solicita o número de vértices
    printf("Numero de vertices: ");
    scanf("%d", &vertices);

    // Solicita o número de arestas
    printf("Numero de arestas: ");
    scanf("%d", &edges);

    // Inicializa a matriz de adjacência
    int graph[vertices][vertices]; // Matriz de adjacência do grafo

    // Inicializa o grafo com "infinito" (INT_MAX), exceto na diagonal que é 0
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
            {
                // A distância de um vértice para ele mesmo é 0
                graph[i][j] = 0;
            }
            else
            {
                // A distância entre vértices não conectados é infinita
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Coleta os dados das arestas
    for (int i = 0; i < edges; i++)
    {
        int origem = 0, destino = 0, peso = 0;

        // Solicita o vértice de origem da aresta
        printf("\nDigite o vértice de origem da aresta %d: ", i + 1);
        scanf("%d", &origem);

        // Solicita o vértice de destino da aresta
        printf("\nDigite o vértice de destino da aresta %d: ", i + 1);
        scanf("%d", &destino);

        // Solicita o peso da aresta
        printf("\nDigite o peso da aresta %d: ", i + 1);
        scanf("%d", &peso);

        // Atualiza o peso da aresta na matriz de adjacência
        graph[origem][destino] = peso;
    }

    // Exibe a matriz do grafo inicial
    printf("Matriz do input dos dados:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == INT_MAX)
            {
                printf("INF "); // Imprime "INF" para distâncias infinitas
            }
            else
            {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    // Aplica o algoritmo de Floyd-Warshall
    floyd_warshall(graph, vertices);

    // Exibe a matriz resultante após a execução do algoritmo
    printf("Matriz do Floyd-Warshall:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == INT_MAX)
            {
                printf("INF "); // Imprime "INF" para distâncias infinitas
            }
            else
            {
                printf("%d ", graph[i][j]);
            }

            printf("\n");
        }

        // Exibe os caminhos mínimos entre os vértices
        printf("O caminho mínimo entre os vertices são:\n");
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (i != j)
                {
                    printf("\n <%d %d> = ", i, j);

                    if (graph[i][j] == INT_MAX)
                    {
                        // Se não houver caminho, imprime "INF"
                        printf("INF");
                    }
                    else
                    {
                        printf("%d", graph[i][j]);
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}
