#include <stdio.h>
#include <stdlib.h>

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @brief Estrutura que representa um grafo não direcionado.
 *
 * O grafo é composto por um número de vértices e uma matriz de adjacência.
 * A matriz de adjacência A[i][j] é 1 se há uma aresta entre os vértices i e j,
 * e 0 caso contrário.
 */
typedef struct grafo
{
    int numVertices; /**< Número de vértices no grafo */
    int **matrizAdj; /**< Matriz de adjacência */
} Grafo;

#endif

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * Aloca memória para o grafo e inicializa a matriz de adjacência com zeros.
 *
 * @param numVertices O número de vértices no grafo (deve ser maior que 0).
 * @return Ponteiro para o grafo criado ou NULL em caso de falha na alocação.
 */
Grafo *criarGrafo(int numVertices)
{
    if (numVertices <= 0)
    {
        fprintf(stderr, "Erro: Número de vértices deve ser maior que 0\n");
        return NULL;
    }

    // Aloca memória para o grafo
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    if (grafo == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o grafo\n");
        return NULL;
    }
    grafo->numVertices = numVertices;

    // Aloca memória para a matriz de adjacência
    grafo->matrizAdj = (int **)malloc(numVertices * sizeof(int *));
    if (grafo->matrizAdj == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a matriz\n");
        free(grafo);
        return NULL;
    }

    for (int i = 0; i < numVertices; i++)
    {
        grafo->matrizAdj[i] = (int *)malloc(numVertices * sizeof(int));
        if (grafo->matrizAdj[i] == NULL)
        {
            fprintf(stderr, "Erro: Falha na alocação de memória para a linha %d\n", i);
            for (int j = 0; j < i; j++)
            {
                free(grafo->matrizAdj[j]);
            }
            free(grafo->matrizAdj);
            free(grafo);
            return NULL;
        }
    }

    // Inicializa a matriz de adjacência com 0 (sem arestas)
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            grafo->matrizAdj[i][j] = 0;
        }
    }
    return grafo;
}

/**
 * @brief Adiciona uma aresta entre dois vértices no grafo não direcionado.
 *
 * Marca as posições A[src][dest] e A[dest][src] como 1 na matriz de adjacência.
 *
 * @param g Ponteiro para o grafo.
 * @param src Vértice de origem (deve estar entre 0 e numVertices-1).
 * @param dest Vértice de destino (deve estar entre 0 e numVertices-1).
 * @return 1 se a aresta foi adicionada com sucesso, 0 se os índices são inválidos.
 */
int adicionarAresta(Grafo *g, int src, int dest)
{
    if (g == NULL || src < 0 || src >= g->numVertices || dest < 0 || dest >= g->numVertices)
    {
        fprintf(stderr, "Erro: Índices de vértices inválidos ou grafo nulo\n");
        return 0;
    }

    // Marca ambas as posições na matriz para grafo não direcionado
    g->matrizAdj[src][dest] = 1;
    g->matrizAdj[dest][src] = 1;
    return 1;
}

/**
 * @brief Imprime a matriz de adjacência do grafo.
 *
 * Exibe a matriz de adjacência com índices de vértices nas linhas e colunas.
 *
 * @param g Ponteiro para o grafo.
 */
void imprimirMatrizAdj(Grafo *g)
{
    if (g == NULL)
    {
        printf("Grafo vazio\n");
        return;
    }

    printf("Matriz de Adjacência do Grafo:\n");

    // Imprime as colunas (vértices 0, 1, 2, etc.)
    printf("X |");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf(" %d", i);
    }
    
    printf("\n--+");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("--");
    }
    printf("\n");

    // Imprime as linhas da matriz
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < g->numVertices; j++)
        {
            printf(" %d", g->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Libera toda a memória alocada para o grafo.
 *
 * Libera a memória da matriz de adjacência e da estrutura do grafo.
 *
 * @param g Ponteiro para o grafo que será liberado.
 */
void liberarGrafo(Grafo *g)
{
    if (g == NULL)
    {
        return;
    }

    // Libera a memória da matriz de adjacência
    for (int i = 0; i < g->numVertices; i++)
    {
        free(g->matrizAdj[i]);
    }
    free(g->matrizAdj);

    // Libera a memória do grafo
    free(g);
}

int main(int argc, char **argv)
{
    // Cria um grafo com 5 vértices
    Grafo *g = criarGrafo(5);
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do grafo\n");
        return EXIT_FAILURE;
    }

    // Adiciona arestas ao grafo
    adicionarAresta(g, 0, 1);
    adicionarAresta(g, 0, 4);
    adicionarAresta(g, 1, 2);
    adicionarAresta(g, 1, 3);
    adicionarAresta(g, 1, 4);
    adicionarAresta(g, 2, 3);
    adicionarAresta(g, 3, 4);

    // Imprime a matriz de adjacência
    imprimirMatrizAdj(g);

    // Libera a memória alocada para o grafo
    liberarGrafo(g);

    return 0;
}
