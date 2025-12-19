#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERTICES 10

#ifndef ARESTA
#define ARESTA

/**
 * @brief Estrutura que representa uma aresta em um grafo direcionado.
 *
 * Contém o vértice de destino (caractere), o peso da aresta e um ponteiro para a próxima aresta.
 */
typedef struct arestas
{
    char destino;         /**< Vértice de destino da aresta (A a J) */
    int peso;             /**< Peso da aresta (ex.: distância ou custo) */
    struct arestas *prox; /**< Ponteiro para a próxima aresta */
} Aresta;

#endif

#ifndef GRAFO
#define GRAFO

/**
 * @brief Estrutura que representa um grafo direcionado.
 *
 * O grafo é composto por um número de vértices e um array de listas de adjacência.
 * A lista de adjacência é eficiente para grafos esparsos, com complexidade de espaço O(V + E)
 * e complexidade de tempo O(V) para verificar arestas no pior caso.
 */
typedef struct Grafo
{
    int numVertices; /**< Número de vértices no grafo */
    Aresta **adj;    /**< Array de listas de adjacência */
} Grafo;

#endif

/**
 * @brief Cria um novo grafo com o número de vértices especificado.
 *
 * Aloca memória para o grafo e inicializa as listas de adjacência com NULL.
 *
 * @param numVertices Número de vértices (deve ser maior que 0).
 * @return Ponteiro para o grafo criado ou NULL em caso de falha na alocação.
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
    g->adj = (Aresta **)malloc(numVertices * sizeof(Aresta *));
    if (g->adj == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para as listas de adjacência\n");
        free(g);
        return NULL;
    }

    for (int i = 0; i < numVertices; i++)
    {
        g->adj[i] = NULL;
    }
    return g;
}

/**
 * @brief Adiciona uma aresta direcionada ao grafo.
 *
 * @param g Ponteiro para o grafo.
 * @param origem Vértice de origem (caractere A a A+numVertices-1).
 * @param destino Vértice de destino (caractere A a A+numVertices-1).
 * @param peso Peso da aresta.
 * @return 1 se a aresta foi adicionada com sucesso, 0 se inválida ou falha na alocação.
 */
int addAresta(Grafo *g, char origem, char destino, int peso)
{
    if (g == NULL || origem < 'A' || origem >= 'A' + g->numVertices ||
        destino < 'A' || destino >= 'A' + g->numVertices || origem == destino)
    {
        fprintf(stderr, "Erro: Grafo nulo, vértices inválidos ou laço detectado\n");
        return 0;
    }

    int i = origem - 'A';
    Aresta *current = g->adj[i];
    while (current)
    {
        if (current->destino == destino)
        {
            return 0; // Aresta já existe
        }
        current = current->prox;
    }

    Aresta *novaAresta = (Aresta *)malloc(sizeof(Aresta));
    if (novaAresta == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a aresta\n");
        return 0;
    }
    novaAresta->destino = destino;
    novaAresta->peso = peso;
    novaAresta->prox = g->adj[i];
    g->adj[i] = novaAresta;
    return 1;
}

/**
 * @brief Imprime as listas de adjacência do grafo.
 *
 * Exibe as listas de adjacência de cada vértice, incluindo pesos.
 *
 * @param g Ponteiro para o grafo.
 */
void imprimirListasAdj(Grafo *g)
{
    if (g == NULL)
    {
        printf("Grafo vazio\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        printf("Vértice %c: ", 'A' + i);
        Aresta *current = g->adj[i];
        if (current == NULL)
        {
            printf("NULL");
        }
        else
        {
            while (current)
            {
                printf("%c(%d)", current->destino, current->peso);
                if (current->prox)
                {
                    printf(" ");
                }
                current = current->prox;
            }
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para o grafo.
 *
 * @param g Ponteiro para o grafo.
 */
void liberarGrafo(Grafo *g)
{
    if (g == NULL)
    {
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        Aresta *current = g->adj[i];
        while (current)
        {
            Aresta *temp = current;
            current = current->prox;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}

int main(int argc, char **argv)
{
    Grafo *g = criarGrafo(VERTICES);
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do grafo\n");
        return EXIT_FAILURE;
    }

    addAresta(g, 'A', 'B', 5);
    addAresta(g, 'A', 'C', 3);
    addAresta(g, 'B', 'C', 2);
    addAresta(g, 'C', 'A', 7);

    imprimirListasAdj(g);

    liberarGrafo(g);
    return 0;
}
