#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

/**
 * @brief Estrutura para armazenar informações do algoritmo de Prim.
 */
typedef struct
{
    bool visitado; // Marca se o vértice foi visitado
    int key;       // Peso mínimo para adicionar o vértice à MST
    int pai;       // Pai do vértice na MST
} PrimNode;

/**
 * @brief Cria e inicializa a matriz de adjacência dinamicamente.
 *
 * @param vertices Número de vértices do grafo
 * @return Ponteiro para a matriz alocada, ou NULL em caso de falha
 */
int **createGraph(int vertices)
{
    if (vertices <= 0)
        return NULL;

    int **graph = (int **)malloc(vertices * sizeof(int *));
    if (!graph)
        return NULL;

    for (int i = 0; i < vertices; i++)
    {
        graph[i] = (int *)malloc(vertices * sizeof(int));
        if (!graph[i])
        {
            // Libera memória parcial
            for (int j = 0; j < i; j++)
                free(graph[j]);
            free(graph);
            return NULL;
        }

        // Inicializa com 0 (sem aresta)
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    return graph;
}

/**
 * @brief Libera a memória da matriz de adjacência.
 *
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 */
void freeGraph(int **graph, int vertices)
{
    if (!graph)
        return;

    for (int i = 0; i < vertices; i++)
    {
        free(graph[i]);
    }
    free(graph);
}

void printGraph(int **graph, int vertices)
{
    printf("\nMatriz de Adjacência:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Inicializa a estrutura Prim para o algoritmo.
 *
 * @param primArray Array de estruturas Prim
 * @param vertices Número de vértices
 */
void inicializar(PrimNode *primArray, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        primArray[i].visitado = false;
        primArray[i].key      = INF;
        primArray[i].pai      = -1;
    }
    primArray[0].key = 0; // Começamos pelo vértice 0
}

/**
 * @brief ncontra o vértice não visitado com a menor chave (key)
 *
 * @param primArray Array de estruturas Prim
 * @param vertices Número de vértices
 */
int encontrarMinimo(PrimNode *primArray, int vertices)
{
    int minKey    = INF;
    int minVertex = -1;

    for (int i = 0; i < vertices; i++)
    {
        if (!primArray[i].visitado && primArray[i].key < minKey)
        {
            minKey = primArray[i].key;
            minVertex = i;
        }
    }
    return minVertex;
}

/**
 * @brief Executa o algoritmo de Prim para encontrar a MST.
 *
 * @param primArray Array de estruturas Prim
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 * @return true se a MST foi gerada com sucesso, false se o grafo é desconexo
 */
bool primMST(PrimNode *primArray, int **graph, int vertices)
{
    for (int count = 0; count < vertices; count++)
    {
        int u = encontrarMinimo(primArray, vertices);

        if (u == -1)
        {
            fprintf(stderr, "Erro: Grafo desconexo! Não foi possível construir MST.\n");
            return false;
        }

        primArray[u].visitado = true;

        // Atualiza as chaves dos vértices adjacentes
        for (int v = 0; v < vertices; v++)
        {
            int weight = graph[u][v];
            if (weight > 0 && !primArray[v].visitado && weight < primArray[v].key)
            {
                primArray[v].key = weight;
                primArray[v].pai = u;
            }
        }
    }
    return true;
}

/**
 * @brief Imprime as arestas da MST e seu peso total.
 *
 * @param primArray Array de estruturas Prim
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 */
void printMST(PrimNode *primArray, int **graph, int vertices)
{
    printf("\n=== Árvore Geradora Mínima (MST) - Algoritmo de Prim ===\n\n");
    printf("Aresta\t\tPeso\n");
    printf("---------------------\n");

    int totalWeight = 0;

    for (int i = 1; i < vertices; i++)
    {
        int pai  = primArray[i].pai;
        int peso = graph[i][pai];
        printf("%d -- %d\t\t%d\n", pai, i, peso);
        totalWeight += peso;
    }

    printf("---------------------\n");
    printf("Peso total da MST: %d\n", totalWeight);
}

int main(int argc, char **argv)
{
    int vertices = 5; // Alterado para 5 para demonstrar melhor o algoritmo
    int **graph  = createGraph(vertices);

    if (!graph)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para o grafo.\n");
        return 1;
    }

    // Exemplo de grafo não direcionado (matriz simétrica)
    graph[0][1] = graph[1][0] = 2;
    graph[0][3] = graph[3][0] = 6;
    graph[1][2] = graph[2][1] = 3;
    graph[1][3] = graph[3][1] = 8;
    graph[1][4] = graph[4][1] = 5;
    graph[2][4] = graph[4][2] = 7;
    graph[3][4] = graph[4][3] = 9;

    printf("Executando Algoritmo de Prim...\n");

    // Aloca estrutura do Prim
    PrimNode *primArray = (PrimNode *)malloc(vertices * sizeof(PrimNode));
    if (!primArray)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para Prim.\n");
        freeGraph(graph, vertices);
        return 1;
    }

    inicializar(primArray, vertices);

    if (primMST(primArray, graph, vertices))
    {
        printMST(primArray, graph, vertices);
    }

    // Liberação de memória
    freeGraph(graph, vertices);
    free(primArray);

    return 0;
}
