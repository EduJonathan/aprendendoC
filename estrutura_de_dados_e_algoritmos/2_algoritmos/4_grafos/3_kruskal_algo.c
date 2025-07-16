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
void createGraph(Edge graph[], int *numVertices, int *numEdges)
{
    printf("\n\t>>CRIANDO GRAFO<<\n");

    printf("Digite a quantidade de vertices: ");
    scanf("%d", numVertices);

    printf("Digite a quantidade de arestas: ");
    scanf("%d", numEdges);

    for (int i = 0; i < *numEdges; i++)
    {
        printf("Digite o vértice de origem da aresta %d: ", i + 1);
        scanf("%d", &graph[i].startVertex);

        printf("Digite o vértice de destino da aresta %d: ", i + 1);
        scanf("%d", &graph[i].endVertex);

        printf("Digite o custo da aresta %d: ", i + 1);
        scanf("%d", &graph[i].weight);
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
void Union(int parent[], int rank[], int vertex1, int vertex2)
{
    int root1 = find(parent, vertex1);
    int root2 = find(parent, vertex2);

    // Se eles são de diferentes conjuntos, faça a união
    if (root1 != root2)
    {
        // União por rank (para manter a árvore equilibrada)
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
void kruskal(Edge graph[], int numVertices, int numEdges)
{
    // Ordena as arestas por custo em ordem crescente
    qsort(graph, numEdges, sizeof(Edge), compare);

    // Vetor para armazenar o representante de cada conjunto
    int parent[numVertices];
    int rank[numVertices];

    // Inicializa cada vértice como seu próprio representante
    for (int i = 0; i < numVertices; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_cost = 0;
    int mst_edges = 0; // Número de arestas na MST

    printf("\n\t>>ÁRVORE GERADORA MÍNIMA (MST) - ALGORITMO DE KRUSKAL<<\n");

    // Processa as arestas, tentando adicionar à árvore geradora mínima
    for (int i = 0; i < numEdges && mst_edges < numVertices - 1; i++)
    {
        int vertex1 = graph[i].startVertex;
        int vertex2 = graph[i].endVertex;
        int cost = graph[i].weight;

        // Verifica se adicionar a aresta forma um ciclo
        if (find(parent, vertex1) != find(parent, vertex2))
        {
            // Se não formar ciclo, adiciona à MST
            printf("Aresta: %d - %d, Custo: %d\n", vertex1, vertex2, cost);
            mst_cost += cost;
            Union(parent, rank, vertex1, vertex2);
            mst_edges++;
        }
    }

    // Se a MST não tiver o número necessário de arestas
    if (mst_edges != numVertices - 1)
    {
        printf("A árvore geradora mínima não pode ser formada. O grafo pode não ser conexo.\n");
    }

    printf("Custo total da árvore geradora mínima: %d\n", mst_cost);
}

int main(int argc, char **argv)
{
    Edge graph[20] = {0}; // Supondo no máximo 20 arestas
    int numVertices = 0, numEdges = 0;

    createGraph(graph, &numVertices, &numEdges);

    // Chamando a função para encontrar a MST
    kruskal(graph, numVertices, numEdges);

    return 0;
}
