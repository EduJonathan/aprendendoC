#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Algoritmo de Dijkstra - Caminho Mínimo a Partir de um Único Fonte
 *
 * O algoritmo de Dijkstra encontra o caminho mais curto entre um vértice de origem e
 * todos os outros vértices em um grafo com arestas de **peso não-negativo**. Utiliza
 * uma abordagem gulosa com **fila de prioridade (min-heap)** para sempre expandir o nó
 * mais próximo ainda não processado.
 *
 * Aplicações:
 * - GPS e rotas (Google Maps, Waze)
 * - Roteamento de redes (como OSPF)
 * - Planejamento de caminhos em IA e jogos
 *
 * Funcionamento:
 * - Inicializa as distâncias da origem para ∞, exceto a origem (0).
 * - Usa uma estrutura de dados eficiente (heap/priority queue) para sempre escolher o
 * vértice com menor distância conhecida.
 * - Relaxa as arestas adjacentes e atualiza a fila.
 *
 * Restrições:
 * - Não funciona corretamente com arestas de peso negativo (pode subestimar distâncias).
 *
 * COMPLEXIDADE:
 * - TEMPO: O((V + E) log V) usando heap binário
 * - ESPAÇO: O(V + E)
 *
 * @note É mais eficiente que Bellman-Ford em grafos densos com pesos positivos.
 */

#define INF INT_MAX / 2 // Valor grande, mas seguro contra overflow
#define MAX_VERTICES 20

/**
 * @brief Implementação do algoritmo de Dijkstra para encontrar os caminhos mais
 * curtos em um grafo.
 *
 * @param graph Matriz de adjacência representando o grafo.
 * @param n Número de vértices no grafo.
 * @param startNode Vértice inicial para o cálculo do caminho mínimo.
 * @return Retorna true se a execução do algoritmo for bem-sucedida.
 */
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int start)
{
    int distance[MAX_VERTICES];
    int predecessor[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    // Inicialização
    for (int i = 0; i < n; i++)
    {
        distance[i]    = INF;
        predecessor[i] = -1;
        visited[i]     = false;
    }

    distance[start] = 0;

    // Processa todos os vértices
    for (int count = 0; count < n; count++)
    {
        // Encontra o vértice não visitado com menor distância
        int minDist = INF;
        int u       = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < minDist)
            {
                minDist = distance[i];
                u = i;
            }
        }

        // Se não há mais vértices alcançáveis, termina
        if (u == -1)
            break;

        visited[u] = true;

        // Relaxa todas as arestas saindo de u
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                distance[u] != INF && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                predecessor[v] = u;
            }
        }
    }

    // ====================== EXIBIÇÃO DOS RESULTADOS ======================
    printf("=== Resultados do Algoritmo de Dijkstra ===\n");
    printf("Origem: vértice %d\n\n", start);

    for (int i = 0; i < n; i++)
    {
        if (i == start)
            continue;

        printf("Para o vértice %d: ", i);

        if (distance[i] == INF)
        {
            printf("Inalcançável (∞)\n");
            continue;
        }

        printf("Distância = %d | Caminho: ", distance[i]);

        // Reconstrói o caminho do destino até a origem
        int path[MAX_VERTICES];
        int count   = 0;
        int current = i;

        while (current != -1)
        {
            path[count++] = current;
            current = predecessor[current];
        }

        // Imprime o caminho na ordem correta (origem → destino)
        for (int j = count - 1; j >= 0; j--)
        {
            printf("%d", path[j]);
            if (j > 0)
                printf(" -> ");
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Grafo de exemplo (matriz de adjacência)
    int exemplo[6][6] = {
        {0, 10, 0, 30, 0, 0},
        {10, 0, 50, 0, 0, 0},
        {0, 50, 0, 20, 10, 0},
        {30, 0, 20, 0, 60, 0},
        {0, 0, 10, 60, 0, 30},
        {0, 0, 0, 0, 30, 0}
    };

    int n     = 6;
    int start = 0;

    // Copia o exemplo para o grafo
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = exemplo[i][j];
        }
    }
    
    printf("=== Algoritmo de Dijkstra - Caminho Mínimo ===\n\n");
    dijkstra(graph, n, start);

    return 0;
}
