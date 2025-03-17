#include <stdio.h>
#include <stdbool.h>

#define INF 9999
#define MAX 10

/**
 * @brief Implementação do algoritmo de Dijkstra para encontrar os caminhos mais
 * curtos em um grafo.
 *
 * @param graph Matriz de adjacência representando o grafo.
 * @param n Número de vértices no grafo.
 * @param startNode Vértice inicial para o cálculo do caminho mínimo.
 * @return Retorna true se a execução do algoritmo for bem-sucedida.
 */
bool dijkstra(int graph[MAX][MAX], int n, int startNode)
{
    int custo[MAX][MAX]; // Matriz de custos (distâncias mínimas)
    int distance[MAX];   // Vetor de distâncias mínimas para cada vértice
    int pred[MAX];       // Vetor de predecessores de cada vértice
    bool visited[MAX];   // Vetor de vértices visitados
    int contador = 0;    // Contador de vértices visitados
    int DistanciaMinima; // Distância mínima
    int nextNode;        // Próximo nó a ser visitado

    // Inicializando a matriz de custos
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                custo[i][j] = INF; // Arestas inexistentes têm custo infinito
            }
            else
            {
                custo[i][j] = graph[i][j]; // Arestas existentes têm o custo definido
            }
        }
    }

    // Inicializando os vetores de distâncias e predecessores
    for (int i = 0; i < n; i++)
    {
        distance[i] = custo[startNode][i]; // Distância inicial a partir do nó de origem
        pred[i] = startNode;               // O predecessor de cada vértice é o startNode
        visited[i] = false;                // Nenhum vértice foi visitado inicialmente
    }

    distance[startNode] = 0;   // O custo do nó de origem para si mesmo é 0
    visited[startNode] = true; // Marca o nó de origem como visitado
    contador = -1;             // Inicializa o contador

    // Executa o algoritmo de Dijkstra
    while (contador < n - 1)
    {
        DistanciaMinima = INF; // Inicializa a distância mínima com infinito
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < DistanciaMinima && !visited[i])
            {
                DistanciaMinima = distance[i]; // Atualiza a distância mínima
                nextNode = i;                  // Atualiza o próximo nó
            }
        }

        // Marca o próximo nó como visitado
        visited[nextNode] = true;

        // Atualiza as distâncias para os vizinhos do próximo nó
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                if (DistanciaMinima + custo[nextNode][j] < distance[j])
                {
                    distance[j] = DistanciaMinima + custo[nextNode][j]; // Atualiza a distância
                    pred[j] = nextNode;                                 // Atualiza o predecessor
                }
            }
        }
        
        // Incrementa o contador de vértices visitados
        contador++; 
    }

    // Exibe os resultados (distâncias e caminhos)
    for (int i = 0; i < n; i++)
    {
        printf("O custo para o vértice %d é: %d\n", i, distance[i]);
        printf("Caminho: %d ", i);

        int j = i;

        // Exibe o caminho a partir do vértice 'i' até o nó inicial
        while (j != startNode)
        {
            printf("<- %d ", j);
            j = pred[j];
        }

        printf("<- %d\n", startNode);
    }

    // Retorna verdadeiro indicando que o algoritmo foi executado com sucesso
    return true;
}

int main(int argc, char **argv)
{
    int graph[MAX][MAX] = {
        {0, 10, 0, 30, 0, 0},
        {10, 0, 50, 0, 0, 0},
        {0, 50, 0, 20, 10, 0},
        {30, 0, 20, 0, 60, 0},
        {0, 0, 10, 60, 0, 30},
        {0, 0, 0, 0, 30, 0}};

    int numVertices = 6;
    int startNode = 0; // O vértice inicial (por exemplo, 0)

    dijkstra(graph, numVertices, startNode);

    return 0;
}
