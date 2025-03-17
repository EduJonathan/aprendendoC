#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 // Número de vértices no grafo

/**
 * @brief Verifica se um vértice v pode ser incluído na posição atual do caminho.
 *
 * @param v Vértice a ser incluído no caminho.
 * @param graph Grafo representado como uma matriz de adjacência.
 * @param path Caminho atual.
 * @param pos Posição atual no caminho.
 * @return Retorna true se o vértice v puder ser incluído na posição atual do caminho.
 */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    // Verifica se o vértice v está adjacente ao último vértice no caminho
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }

    // Verifica se o vértice v já foi incluído no caminho
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Função recursiva para encontrar um ciclo Hamiltoniano em um grafo.
 *
 * @param graph Matriz de adjacência representando o grafo.
 * @param path Vetor que será usado para armazenar o caminho do ciclo.
 * @param pos Posição atual no vetor de caminho.
 * @return Retorna true se encontrar um ciclo Hamiltoniano, caso contrário false.
 */
bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    // Se todos os vértices forem incluídos no caminho
    if (pos == V)
    {
        // Verifica se existe uma aresta entre o último vértice e o primeiro vértice
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Tenta incluir cada vértice no caminho
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            // Recursivamente tenta continuar o caminho
            if (hamCycleUtil(graph, path, pos + 1))
            {
                return true;
            }

            // Desfaz a escolha
            path[pos] = -1;
        }
    }

    return false;
}

/**
 * @brief Imprime um ciclo Hamiltoniano.
 *
 * @param path Array contendo a sequência de vértices do ciclo Hamiltoniano.
 */
void printSolution(int path[])
{
    printf("A seguir está um ciclo Hamiltoniano:\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d ", path[i]);
    }

    // Finaliza o ciclo retornando ao primeiro vértice
    printf("%d\n", path[0]);
}

/**
 * @brief Verifica se existe um ciclo Hamiltoniano em um grafo.
 *
 * @param graph Matriz de adjacência representando o grafo.
 * @return Retorna true se existir um ciclo Hamiltoniano, caso contrário false.
 */
bool hamCycle(bool graph[V][V])
{
    int *path = (int *)malloc(V * sizeof(int));

    // Inicializa o caminho com -1 (nenhum vértice incluído inicialmente)
    for (int i = 0; i < V; i++)
    {
        path[i] = -1;
    }

    // Começa o caminho com o vértice 0
    path[0] = 0;

    // Tenta encontrar o ciclo Hamiltoniano
    if (hamCycleUtil(graph, path, 1) == false)
    {
        printf("Não existe ciclo Hamiltoniano no grafo.\n");
        free(path); // Libera a memória alocada
        return false;
    }

    // Caso encontre, imprime a solução
    printSolution(path);
    free(path); // Libera a memória alocada
    return true;
}

int main(int argc, char **argv)
{
    // Grafo de exemplo (5 vértices)
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}};

    // Chama a função hamCycle para verificar se existe um ciclo Hamiltoniano
    hamCycle(graph);

    return 0;
}
