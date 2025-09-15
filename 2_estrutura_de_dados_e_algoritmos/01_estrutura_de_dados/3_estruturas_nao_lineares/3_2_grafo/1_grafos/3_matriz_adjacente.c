#include <stdio.h>
#include <stdlib.h>

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @brief Estrutura que representa um grafo.
 *
 * O grafo é composto por um número de vértices e uma matriz de adjacência.
 * 
 * A matriz de adjacência é uma representação de um grafo onde cada célula A[i][j] indica 
 * se há uma aresta entre os vértices i e j. Se A[i][j] for 1, significa que há uma aresta
 * entre os vértices i e j. Caso contrário, se A[i][j] for 0, não há aresta entre eles.
 */
struct grafo
{
    int numVertices; /**< Número de vértices no grafo */
    int **matrizAdj; /**< Matriz de adjacência */
};

#endif

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * Aloca memória para o grafo e inicializa a matriz de adjacência.
 *
 * @param numVertices O número de vértices no grafo.
 * @return Ponteiro para o grafo criado.
 */
struct grafo *criarGrafo(int numVertices)
{
    // Aloca memória para o grafo
    struct grafo *grafo = (struct grafo *)malloc(sizeof(struct grafo));
    grafo->numVertices = numVertices;

    // Aloca memória para a matriz de adjacência (matriz de numVertices x numVertices)
    grafo->matrizAdj = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; i++)
    {
        grafo->matrizAdj[i] = (int *)malloc(numVertices * sizeof(int));
    }

    // Inicializa a matriz de adjacência com 0 (sem arestas)
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            grafo->matrizAdj[i][j] = 0;
        }
    }
    return grafo; // Se a alocação não falhar, retorna o grafo
}

/**
 * @brief Adiciona uma aresta entre dois vértices no grafo.
 *
 * Esta função cria uma aresta entre os vértices `src` e `dest`, e para
 * grafos não direcionados, marca as duas posições da matriz de adjacência:
 * A[src][dest] e A[dest][src].
 *
 * @param g Ponteiro para o grafo.
 * @param src Vértice de origem.
 * @param dest Vértice de destino.
 */
void adicionarAresta(struct grafo *g, int src, int dest)
{
    // Como o grafo é não direcionado, marca ambas as posições na matriz
    g->matrizAdj[src][dest] = 1;
    g->matrizAdj[dest][src] = 1; // Para grafos não direcionados
}

/**
 * @brief Realiza a travessia do grafo e imprime a matriz de adjacência.
 *
 * Esta função percorre todos os vértices do grafo e imprime a matriz de adjacência.
 *
 * @param g Ponteiro para o grafo a ser percorrido.
 */
void transversal(struct grafo *g)
{
    printf("Matriz de Adjacência do Grafo:\n");

    // Imprime as colunas (vertice 0, 1, 2, etc.)
    printf("X |  ");

    for (int i = 0; i < g->numVertices; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    printf("---------------\n");

    // Imprime as linhas da matriz
    for (int i = 0; i < g->numVertices; i++)
    {
        // Imprime o número do vértice (linha)
        printf("%d |  ", i);

        for (int j = 0; j < g->numVertices; j++)
        {
            // Imprime o valor da célula [i][j]
            printf("%d ", g->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Libera toda a memória alocada para o grafo.
 *
 * Esta função libera a memória da matriz de adjacência e do grafo.
 *
 * @param g Ponteiro para o grafo que será liberado.
 */
void liberarMemoria(struct grafo *g)
{
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
    struct grafo *g = criarGrafo(5);

    // Adiciona arestas ao grafo
    adicionarAresta(g, 0, 1);
    adicionarAresta(g, 0, 4);
    adicionarAresta(g, 1, 2);
    adicionarAresta(g, 1, 3);
    adicionarAresta(g, 1, 4);
    adicionarAresta(g, 2, 3);
    adicionarAresta(g, 3, 4);

    // Imprime a matriz de adjacência
    transversal(g);

    // Libera a memória alocada para o grafo
    liberarMemoria(g);

    return 0;
}
