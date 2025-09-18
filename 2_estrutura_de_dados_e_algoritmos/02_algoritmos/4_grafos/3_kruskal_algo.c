#include <stdio.h>
#include <stdlib.h>

/**
 * Algoritmo de Kruskal - Árvore Geradora Mínima (MST)
 *
 * O algoritmo de Kruskal é um algoritmo clássico para encontrar a **Árvore Geradora Mínima (MST)**
 * em um grafo ponderado e conexo. A MST é um subconjunto das arestas que conecta todos os vértices
 * do grafo com o menor peso total possível e **sem formar ciclos**.
 *
 * O funcionamento do algoritmo é baseado na ideia de:
 * - Ordenar todas as arestas em ordem crescente de peso.
 * - Adicionar as menores arestas à MST, desde que não formem ciclos.
 * - Usar uma estrutura **Union-Find (Disjoint Set Union)** para detectar ciclos eficientemente.
 *
 * Aplicações:
 * - Redes de computadores e telecomunicações (minimizar o custo de conexões)
 * - Roteamento de circuitos
 * - Construção de estradas e infraestrutura mínima
 *
 * PRÉ-REQUISITOS:
 * - Grafo não direcionado, ponderado.
 * - Pode ser desconexo (neste caso, Kruskal encontrará uma floresta geradora mínima).
 *
 * COMPLEXIDADE:
 * - TEMPO: O(E log E), onde E é o número de arestas (ordenar as arestas + operações de união/busca).
 * - ESPAÇO: O(V), onde V é o número de vértices (para a estrutura Union-Find).
 *
 * @note Para grafos densos, Prim pode ser mais eficiente com a estrutura certa (como heap).
 */

#define INF 999

typedef struct edge
{
    int startVertex; ///< Vértice de origem da aresta
    int endVertex;   ///< Vértice de destino da aresta
    int weight;      ///< Peso ou custo da aresta
} Edge;

/**
 * @brief Função para ordenar as arestas pelo custo, utilizada no algoritmo de Kruskal.
 *
 * @param a Ponteiro para o primeiro elemento a ser comparado.
 * @param b Ponteiro para o segundo elemento a ser comparado.
 * @return Um valor negativo se a primeira aresta for menor, zero se forem iguais,
 * ou um valor positivo se a segunda for menor.
 */
int compare(const void *a, const void *b) { return ((Edge *)a)->weight - ((Edge *)b)->weight; }

/**
 * @brief Função para criar o grafo e suas arestas.
 *
 * Solicita ao usuário a quantidade de vértices e arestas e os detalhes das arestas,
 * e armazena essas informações no vetor de arestas.
 */
void createGraph(Edge **graph, int *numVertices, int *numEdges)
{
    printf("\n\t>>CRIANDO GRAFO<<\n");

    // Input number of vertices
    printf("Digite a quantidade de vertices: ");
    if (scanf("%d", numVertices) != 1 || *numVertices <= 0)
    {
        printf("Erro: Número de vértices deve ser positivo.\n");
        *numVertices = 0;
        *numEdges = 0;
        return;
    }

    // Input number of edges
    printf("Digite a quantidade de arestas: ");
    if (scanf("%d", numEdges) != 1 || *numEdges < 0)
    {
        printf("Erro: Número de arestas deve ser não-negativo.\n");
        *numVertices = 0;
        *numEdges = 0;
        return;
    }

    // Allocate memory for edges
    *graph = (Edge *)malloc(*numEdges * sizeof(Edge));
    if (*graph == NULL)
    {
        printf("Erro: Falha na alocação de memória para as arestas.\n");
        *numVertices = 0;
        *numEdges = 0;
        return;
    }

    // Input edge details
    for (int i = 0; i < *numEdges; i++)
    {
        printf("Digite o vértice de origem da aresta %d (0 a %d): ", i + 1, *numVertices - 1);
        if (scanf("%d", &(*graph)[i].startVertex) != 1 || (*graph)[i].startVertex < 0 || (*graph)[i].startVertex >= *numVertices)
        {
            printf("Erro: Vértice de origem inválido.\n");
            free(*graph);
            *graph = NULL;
            *numVertices = 0;
            *numEdges = 0;
            return;
        }

        printf("Digite o vértice de destino da aresta %d (0 a %d): ", i + 1, *numVertices - 1);
        if (scanf("%d", &(*graph)[i].endVertex) != 1 || (*graph)[i].endVertex < 0 || (*graph)[i].endVertex >= *numVertices)
        {
            printf("Erro: Vértice de destino inválido.\n");
            free(*graph);
            *graph = NULL;
            *numVertices = 0;
            *numEdges = 0;
            return;
        }

        printf("Digite o custo da aresta %d: ", i + 1);
        if (scanf("%d", &(*graph)[i].weight) != 1)
        {
            printf("Erro: Custo inválido.\n");
            free(*graph);
            *graph = NULL;
            *numVertices = 0;
            *numEdges = 0;
            return;
        }
    }
}

/**
 * @brief Função para encontrar o representante do conjunto de um vértice.
 *
 * Utiliza a técnica de "caminho comprimido" para otimizar a busca.
 *
 * @param parent Vetor que mantém o representante de cada conjunto.
 * @param vertex O vértice a ser verificado.
 * @return O representante do conjunto do vértice.
 */
int find(int parent[], int vertex)
{
    if (parent[vertex] != vertex)
    {
        parent[vertex] = find(parent, parent[vertex]); // Caminho comprimido
    }
    return parent[vertex];
}

/**
 * @brief Função para unir dois conjuntos no algoritmo de Kruskal.
 *
 * Une dois conjuntos com base no representante de cada conjunto.
 *
 * @param parent Vetor de pais que mantém o conjunto disjunto.
 * @param rank Vetor que mantém o "rank" para otimização da união.
 * @param vertex1 O vértice de origem.
 * @param vertex2 O vértice de destino.
 */
void Union(int *parent, int *rank, int vertex1, int vertex2)
{
    int root1 = find(parent, vertex1);
    int root2 = find(parent, vertex2);

    if (root1 != root2)
    {
        if (rank[root1] < rank[root2])
        {
            parent[root1] = root2;
        }
        else if (rank[root1] > rank[root2])
        {
            parent[root2] = root1;
        }
        else
        {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

/**
 * @brief Função que executa o algoritmo de Kruskal para encontrar a árvore geradora mínima.
 *
 * A função ordena as arestas pelo custo e utiliza o algoritmo de Kruskal para
 * formar a árvore geradora mínima, evitando ciclos e conectando todos os vértices.
 *
 * @param graph Vetor de arestas do grafo.
 * @param numVertices Número de vértices.
 * @param numEdges Número de arestas.
 *
 * @note O algoritmo de Kruskal utiliza a tecnica de "caminho comprimido" para otimizar a busca.
 * na teoria dos grafos o algoritmo utiliza para encontrar a arvore geradora minima(AGM).
 * AGM é um subgrafo que conecta todos os vertices do grafo original e utilizando apenas um
 * subconjunto das arestas, de forma que a soma dos pesos dessas arestas seja sempre menor
 * possível.
 */
void kruskal(Edge *graph, int numVertices, int numEdges)
{
    if (graph == NULL || numVertices <= 0 || numEdges < 0)
    {
        printf("Erro: Grafo inválido ou não inicializado.\n");
        return;
    }

    // Allocate memory for parent and rank arrays
    int *parent = (int *)malloc(numVertices * sizeof(int));
    int *rank = (int *)malloc(numVertices * sizeof(int));
    if (parent == NULL || rank == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        free(parent);
        free(rank);
        return;
    }

    // Initialize parent and rank arrays
    for (int i = 0; i < numVertices; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    qsort(graph, numEdges, sizeof(Edge), compare);

    int mst_cost = 0;
    int mst_edges = 0;

    printf("\n\t>>ÁRVORE GERADORA MÍNIMA (MST) - ALGORITMO DE KRUSKAL<<\n");

    // Process edges to form MST
    for (int i = 0; i < numEdges && mst_edges < numVertices - 1; i++)
    {
        int vertex1 = graph[i].startVertex;
        int vertex2 = graph[i].endVertex;
        int cost = graph[i].weight;

        if (find(parent, vertex1) != find(parent, vertex2))
        {
            printf("Aresta: %d - %d, Custo: %d\n", vertex1, vertex2, cost);
            mst_cost += cost;
            Union(parent, rank, vertex1, vertex2);
            mst_edges++;
        }
    }

    // Check if MST was formed
    if (mst_edges != numVertices - 1)
    {
        printf("A árvore geradora mínima não pode ser formada. O grafo pode não ser conexo.\n");
    }
    else
    {
        printf("Custo total da árvore geradora mínima: %d\n", mst_cost);
    }

    // Free allocated memory
    free(parent);
    free(rank);
}

int main(int argc, char **argv)
{
    Edge *graph = NULL;
    int numVertices = 0, numEdges = 0;

    createGraph(&graph, &numVertices, &numEdges);
    if (graph == NULL)
    {
        printf("Erro ao criar o grafo.\n");
        return 1;
    }

    kruskal(graph, numVertices, numEdges);
    free(graph);
    return 0;
}
