#include <stdio.h>
#include <stdbool.h>

#define V 4           ///< Número de vértices no grafo
#define INFINITY 9999 ///< Valor usado para representar infinito

/**
 * @brief Matriz de adjacência representando o grafo.
 *
 * Cada posição graph[i][j] representa o peso da aresta entre os vértices i e j.
 */
int graph[V][V] = {
    {0, 5, 1, 2},
    {5, 0, 3, 3},
    {1, 3, 0, 4},
    {2, 3, 4, 0},
};

/**
 * @brief Estrutura que armazena informações para o algoritmo de Prim.
 *
 * Utilizando a implementação do algoritmo de Prim para encontrar uma Árvore Geradora Mínima (MST)
 * em um grafo não direcionado com pesos.
 *
 */
typedef struct
{
    bool visitado; ///< Marca se o vértice foi visitado
    int key;       ///< Peso mínimo para adicionar o vértice à MST
    int pai;       ///< Pai do vértice na MST
} Prim;

/**
 * @brief Inicializa os valores da estrutura Prim.
 *
 * Define todos os vértices como não visitados, define as chaves como infinito
 * e o pai como -1. O vértice inicial (0) tem chave igual a 0.
 *
 * @param primArray Array de estruturas Prim a ser inicializado
 */
void inicializar(Prim primArray[V])
{
    for (int i = 0; i < V; i++)
    {
        primArray[i].visitado = false;
        primArray[i].key = INFINITY;
        primArray[i].pai = -1;
    }
    primArray[0].key = 0;
}

/**
 * @brief Executa o algoritmo de Prim para gerar a árvore geradora mínima (MST).
 *
 * A cada iteração, escolhe o vértice com menor chave não visitado
 * e atualiza as chaves dos vértices adjacentes.
 *
 * @param primArray Array de estruturas Prim que será preenchido com a MST
 */
void primMST(Prim primArray[V])
{
    for (int count = 0; count < V; count++)
    {
        int minKey = INFINITY;
        int u = -1;

        // Encontra o vértice não visitado com menor chave
        for (int i = 0; i < V; i++)
        {
            if (!primArray[i].visitado && primArray[i].key < minKey)
            {
                minKey = primArray[i].key;
                u = i;
            }
        }

        if (u == -1)
            break; // Grafo desconexo

        primArray[u].visitado = true;

        // Atualiza os vértices adjacentes
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !primArray[v].visitado && graph[u][v] < primArray[v].key)
            {
                primArray[v].key = graph[u][v];
                primArray[v].pai = u;
            }
        }
    }
}

/**
 * @brief Imprime as arestas da árvore geradora mínima (MST).
 *
 * Para cada vértice (exceto a raiz), exibe a aresta que conecta o vértice ao seu pai.
 *
 * @param primArray Array de estruturas Prim contendo a MST
 */
void printMST(Prim primArray[V])
{
    printf("Aresta \tPeso\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", primArray[i].pai, i, graph[i][primArray[i].pai]);
    }
}

int main(int argc, char **argv)
{
    Prim primArray[V];
    inicializar(primArray);
    primMST(primArray);
    printMST(primArray);
    return 0;
}
