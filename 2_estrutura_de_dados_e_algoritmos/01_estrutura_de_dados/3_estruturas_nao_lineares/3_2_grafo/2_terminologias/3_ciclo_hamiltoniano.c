#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura que representa um grafo não direcionado.
 *
 * O grafo é representado por uma matriz de adjacência dinâmica.
 * A matriz é eficiente para grafos densos, com complexidade de espaço O(V²)
 * e complexidade de tempo O(1) para verificar arestas.
 */
typedef struct Grafo
{
    int numVertices;  /**< Número de vértices no grafo */
    bool **matrizAdj; /**< Matriz de adjacência */
} Grafo;

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * @param numVertices Número de vértices (deve ser maior que 0).
 * @return Ponteiro para o grafo criado ou NULL em caso de falha.
 */
Grafo *criarGrafo(int numVertices)
{
    if (numVertices <= 0)
    {
        fprintf(stderr, "Erro: Número de vértices deve ser maior que 0\n");
        return NULL;
    }

    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o grafo\n");
        return NULL;
    }

    g->numVertices = numVertices;
    g->matrizAdj = (bool **)malloc(numVertices * sizeof(bool *));
    if (g->matrizAdj == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a matriz\n");
        free(g);
        return NULL;
    }

    for (int i = 0; i < numVertices; i++)
    {
        g->matrizAdj[i] = (bool *)calloc(numVertices, sizeof(bool));
        if (g->matrizAdj[i] == NULL)
        {
            fprintf(stderr, "Erro: Falha na alocação de memória para a linha %d\n", i);
            for (int j = 0; j < i; j++)
            {
                free(g->matrizAdj[j]);
            }
            free(g->matrizAdj);
            free(g);
            return NULL;
        }
    }
    return g;
}

/**
 * @brief Verifica se um vértice pode ser incluído no caminho.
 *
 * @param v Vértice a ser incluído (índice 0 a numVertices-1).
 * @param g Grafo representado como uma matriz de adjacência.
 * @param path Caminho atual.
 * @param pos Posição atual no caminho.
 * @return true se o vértice pode ser incluído, false caso contrário.
 */
bool isSafe(int v, Grafo *g, int path[], int pos)
{
    if (g == NULL || v < 0 || v >= g->numVertices || pos < 1 || pos >= g->numVertices)
    {
        return false;
    }

    if (!g->matrizAdj[path[pos - 1]][v])
    {
        return false;
    }

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
 * @brief Função recursiva para encontrar um ciclo Hamiltoniano.
 *
 * @param g Grafo representado como uma matriz de adjacência.
 * @param path Vetor que armazena o caminho do ciclo.
 * @param pos Posição atual no caminho.
 * @return true se um ciclo Hamiltoniano é encontrado, false caso contrário.
 */
bool encontrarCicloHamiltonianoUtil(Grafo *g, int path[], int pos)
{
    if (g == NULL)
    {
        return false;
    }

    if (pos == g->numVertices)
    {
        return g->matrizAdj[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < g->numVertices; v++)
    {
        if (isSafe(v, g, path, pos))
        {
            path[pos] = v;
            if (encontrarCicloHamiltonianoUtil(g, path, pos + 1))
            {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

/**
 * @brief Imprime um ciclo Hamiltoniano usando caracteres (A, B, etc.).
 *
 * @param g Grafo.
 * @param path Array contendo a sequência de vértices do ciclo.
 */
void imprimirSolucao(Grafo *g, int path[])
{
    if (g == NULL)
    {
        return;
    }

    printf("Ciclo Hamiltoniano encontrado:\n");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("%c ", 'A' + path[i]);
    }
    printf("%c\n", 'A' + path[0]);
}

/**
 * @brief Imprime a matriz de adjacência do grafo.
 *
 * @param g Grafo.
 */
void imprimirMatrizAdj(Grafo *g)
{
    if (g == NULL)
    {
        printf("Grafo vazio\n");
        return;
    }

    printf("Matriz de Adjacência do Grafo:\n");

    printf("X |");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf(" %c", 'A' + i);
    }
    printf("\n--+");
    
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < g->numVertices; i++)
    {
        printf("%c |", 'A' + i);
        for (int j = 0; j < g->numVertices; j++)
        {
            printf(" %d", g->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se existe um ciclo Hamiltoniano no grafo.
 *
 * @param g Grafo.
 * @return true se existe um ciclo Hamiltoniano, false caso contrário.
 */
bool encontrarCicloHamiltoniano(Grafo *g)
{
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Grafo nulo\n");
        return false;
    }

    int *path = (int *)malloc(g->numVertices * sizeof(int));
    if (path == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o caminho\n");
        return false;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        path[i] = -1;
    }
    path[0] = 0;

    if (!encontrarCicloHamiltonianoUtil(g, path, 1))
    {
        printf("Não existe ciclo Hamiltoniano no grafo.\n");
        free(path);
        return false;
    }

    imprimirSolucao(g, path);
    free(path);
    return true;
}

/**
 * @brief Libera a memória alocada para o grafo.
 *
 * @param g Grafo.
 */
void liberarGrafo(Grafo *g)
{
    if (g == NULL)
    {
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        free(g->matrizAdj[i]);
    }
    free(g->matrizAdj);
    free(g);
}

int main(int argc, char **argv)
{
    // Cria grafo com 5 vértices
    Grafo *g = criarGrafo(5);
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do grafo\n");
        return EXIT_FAILURE;
    }

    // Inicializa a matriz de adjacência (grafo de exemplo)
    bool graph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}};
        
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            g->matrizAdj[i][j] = graph[i][j];
        }
    }

    // Imprime a matriz de adjacência
    imprimirMatrizAdj(g);

    // Busca ciclo Hamiltoniano
    encontrarCicloHamiltoniano(g);

    // Libera memória
    liberarGrafo(g);
    return 0;
}
