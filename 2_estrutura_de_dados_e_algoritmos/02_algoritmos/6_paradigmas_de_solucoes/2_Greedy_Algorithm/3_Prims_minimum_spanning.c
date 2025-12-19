#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INFINITY INT_MAX

/**
 * @brief Estrutura para armazenar informações do algoritmo de Prim.
 */
typedef struct
{
    bool visitado; // Marca se o vértice foi visitado
    int key;       // Peso mínimo para adicionar o vértice à MST
    int pai;       // Pai do vértice na MST
} Prim;

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

    int **graph = malloc(vertices * sizeof(int *));
    if (!graph)
        return NULL;

    for (int i = 0; i < vertices; i++)
    {
        graph[i] = malloc(vertices * sizeof(int));
        if (!graph[i])
        {
            // Libera memória alocada até agora
            for (int j = 0; j < i; j++)
                free(graph[j]);
            free(graph);
            return NULL;
        }
        
        // Inicializa a matriz com zeros
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

/**
 * @brief Inicializa a estrutura Prim para o algoritmo.
 *
 * @param primArray Array de estruturas Prim
 * @param vertices Número de vértices
 */
void inicializar(Prim *primArray, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        primArray[i].visitado = false;
        primArray[i].key = INFINITY;
        primArray[i].pai = -1;
    }
    primArray[0].key = 0; // Vértice inicial
}

/**
 * @brief Executa o algoritmo de Prim para encontrar a MST.
 *
 * @param primArray Array de estruturas Prim
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 * @return true se a MST foi gerada com sucesso, false se o grafo é desconexo
 */
bool primMST(Prim *primArray, int **graph, int vertices)
{
    for (int count = 0; count < vertices; count++)
    {
        int minKey = INFINITY;
        int minVertex = -1;

        // Encontra o vértice não visitado com menor chave
        for (int i = 0; i < vertices; i++)
        {
            if (!primArray[i].visitado && primArray[i].key < minKey)
            {
                minKey = primArray[i].key;
                minVertex = i;
            }
        }

        if (minVertex == -1)
        {
            fprintf(stderr, "Erro: Grafo desconexo detectado.\n");
            return false;
        }

        primArray[minVertex].visitado = true;

        // Atualiza os vértices adjacentes
        for (int adjVertex = 0; adjVertex < vertices; adjVertex++)
        {
            int weight = graph[minVertex][adjVertex];
            if (weight && !primArray[adjVertex].visitado && weight < primArray[adjVertex].key)
            {
                primArray[adjVertex].key = weight;
                primArray[adjVertex].pai = minVertex;
            }
        }
    }
    return true;
}

/**
 * @brief Calcula o peso total da MST.
 *
 * @param primArray Array de estruturas Prim
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 * @return Peso total da MST
 */
int calculateMSTWeight(Prim *primArray, int **graph, int vertices)
{
    int totalWeight = 0;
    for (int i = 1; i < vertices; i++)
    {
        totalWeight += graph[i][primArray[i].pai];
    }
    return totalWeight;
}

/**
 * @brief Imprime as arestas da MST e seu peso total.
 *
 * @param primArray Array de estruturas Prim
 * @param graph Matriz de adjacência
 * @param vertices Número de vértices
 */
void printMST(Prim *primArray, int **graph, int vertices)
{
    printf("Aresta \tPeso\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d \t%d\n", primArray[i].pai, i, graph[i][primArray[i].pai]);
    }
    printf("Peso total da MST: %d\n", calculateMSTWeight(primArray, graph, vertices));
}

int main(int argc, char **argv)
{
    int vertices = 4; // Número de vértices (pode ser lido do usuário)

    // Criação do grafo
    int **graph = createGraph(vertices);
    if (!graph)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para o grafo.\n");
        return 1;
    }

    // Exemplo de inicialização da matriz (pode ser lido de entrada)
    graph[0][0] = 0;
    graph[0][1] = 5;
    graph[0][2] = 1;
    graph[0][3] = 2;
    graph[1][0] = 5;
    graph[1][1] = 0;
    graph[1][2] = 3;
    graph[1][3] = 3;
    graph[2][0] = 1;
    graph[2][1] = 3;
    graph[2][2] = 0;
    graph[2][3] = 4;
    graph[3][0] = 2;
    graph[3][1] = 3;
    graph[3][2] = 4;
    graph[3][3] = 0;

    // Alocação do array Prim
    Prim *primArray = malloc(vertices * sizeof(Prim));
    if (!primArray)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para primArray.\n");
        freeGraph(graph, vertices);
        return 1;
    }

    // Execução do algoritmo
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
