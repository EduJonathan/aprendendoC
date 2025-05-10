#include <stdio.h>
#include <stdlib.h>

#define V 6 ///< Número de vértices no grafo

/**
 * @struct Aresta
 * @brief Representa uma aresta no grafo com origem, destino e peso.
 */
typedef struct
{
    int origem;
    int destino;
    int peso;
} Aresta;

/**
 * @struct Subconjunto
 * @brief Representa um subconjunto usado para Union-Find.
 */
typedef struct
{
    int pai;  ///< Pai do vértice no conjunto
    int rank; ///< Altura do subconjunto (usado para balanceamento)
} Subconjunto;

// Lista de arestas do grafo
Aresta arestas[] = {
    {0, 1, 4},
    {0, 2, 1},
    {0, 3, 4},
    {1, 2, 3},
    {1, 4, 3},
    {2, 4, 1},
    {3, 4, 5},
    {3, 5, 7},
    {4, 5, 8}};

/// Número de arestas calculado automaticamente
#define E (sizeof(arestas) / sizeof(arestas[0]))

/**
 * @brief Função de comparação usada para ordenar arestas pelo peso (qsort).
 * @param a Ponteiro para a primeira aresta.
 * @param b Ponteiro para a segunda aresta.
 * @return Diferença entre os pesos das arestas.
 */
int compararArestas(const void *a, const void *b)
{
    return ((Aresta *)a)->peso - ((Aresta *)b)->peso;
}

/**
 * @brief Encontra o representante (pai) de um conjunto com compressão de caminho.
 * @param subconj Vetor de subconjuntos.
 * @param i Índice do vértice.
 * @return Representante do conjunto.
 */
int encontrar(Subconjunto subconj[], int i)
{
    if (subconj[i].pai != i)
        subconj[i].pai = encontrar(subconj, subconj[i].pai);
    return subconj[i].pai;
}

/**
 * @brief Une dois subconjuntos diferentes (Union by Rank).
 * @param subconj Vetor de subconjuntos.
 * @param x Índice do primeiro subconjunto.
 * @param y Índice do segundo subconjunto.
 */
void unir(Subconjunto subconj[], int x, int y)
{
    int xroot = encontrar(subconj, x);
    int yroot = encontrar(subconj, y);

    if (subconj[xroot].rank < subconj[yroot].rank)
    {
        subconj[xroot].pai = yroot;
    }
    else if (subconj[xroot].rank > subconj[yroot].rank)
    {
        subconj[yroot].pai = xroot;
    }
    else
    {
        subconj[yroot].pai = xroot;
        subconj[xroot].rank++;
    }
}

/**
 * @brief Executa o algoritmo de Kruskal para encontrar a Árvore Geradora Mínima.
 *
 * Este programa constrói uma MST a partir de um grafo não direcionado e ponderado,
 * utilizando o algoritmo de Kruskal com estrutura Union-Find (conjuntos disjuntos).
 */
void kruskalMST()
{
    Aresta resultado[V - 1]; ///< Vetor que armazena o resultado final da MST
    int e = 0;               // índice para resultado[]
    int i = 0;               // índice para arestas ordenadas
    int custoTotal = 0;

    qsort(arestas, E, sizeof(Aresta), compararArestas);

    Subconjunto *subconj = (Subconjunto *)malloc(V * sizeof(Subconjunto));
    if (!subconj)
    {
        printf("Erro na alocação de memória.\n");
        return;
    }

    // Inicializa subconjuntos
    for (int v = 0; v < V; v++)
    {
        subconj[v].pai = v;
        subconj[v].rank = 0;
    }

    // Constrói a MST
    while (e < V - 1 && i < E)
    {
        Aresta prox = arestas[i++];
        int x = encontrar(subconj, prox.origem);
        int y = encontrar(subconj, prox.destino);

        if (x != y)
        {
            resultado[e++] = prox;
            custoTotal += prox.peso;
            unir(subconj, x, y);
        }
    }

    if (e != V - 1)
    {
        printf("O grafo não é conexo. MST não encontrada.\n");
    }
    else
    {
        printf("Arestas da MST:\n");
        for (i = 0; i < e; i++)
        {
            printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino, resultado[i].peso);
        }
        printf("Custo total da MST: %d\n", custoTotal);
    }

    free(subconj);
}

int main(int argc, char **argv)
{
    kruskalMST();
    return 0;
}
