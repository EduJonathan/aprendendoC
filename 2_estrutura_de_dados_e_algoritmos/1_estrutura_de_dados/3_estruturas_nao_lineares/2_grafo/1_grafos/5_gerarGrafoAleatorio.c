#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 15
#define MAX_ARESTAS 10

/**
 * @brief Estrutura que representa uma aresta no grafo.
 */
typedef struct Aresta
{
    int destino;
    struct Aresta *proxima;
} ARESTAS;

/**
 * @brief Estrutura que representa um vertice no grafo.
 */
typedef struct VERTICES
{
    ARESTAS *arestas;
} VERTICES;

/**
 * @brief Inicializa o grafo com um número de vértices aleatório.
 *
 * @param numeroDeVertices Número de vértices do grafo.
 * @return Ponteiro para o grafo alocado.
 */
VERTICES *criarGrafo(int numeroDeVertices)
{
    VERTICES *grafo = (VERTICES *)malloc(sizeof(VERTICES) * numeroDeVertices);

    if (grafo == NULL)
    {
        printf("Falha ao alocar memória para o grafo!\n");
        exit(1);
    }

    // Inicializa as listas de adjacência de cada vértice
    for (int i = 0; i < numeroDeVertices; i++)
    {
        grafo[i].arestas = NULL;
    }
    return grafo;
}

/**
 * @brief Cria uma aresta aleatória entre dois vértices no grafo.
 *
 * @param grafo Grafo a ser modificado.
 * @param numeroDeVertices Número de vértices no grafo.
 * @param numeroDeArestas Número de arestas que podem ser criadas.
 */
void criarArestas(VERTICES *grafo, int numeroDeVertices, int numeroDeArestas)
{
    for (int i = 0; i < numeroDeVertices; i++)
    {
        printf("Vértice %d: ", i);

        for (int j = 0; j < numeroDeArestas; j++)
        {
            if (rand() % 2 == 1)
            {
                // Adiciona uma aresta aleatória
                int destino = rand() % numeroDeVertices;
                ARESTAS *novaAresta = (ARESTAS *)malloc(sizeof(ARESTAS));

                if (novaAresta == NULL)
                {
                    printf("Falha ao alocar memória para aresta!\n");
                    exit(1);
                }

                novaAresta->destino = destino;
                novaAresta->proxima = grafo[i].arestas;
                grafo[i].arestas = novaAresta;

                printf("-> %d ", destino);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para o grafo.
 *
 * @param grafo Grafo a ser desalocado.
 * @param numeroDeVertices Número de vértices no grafo.
 */
void liberarGrafo(VERTICES *grafo, int numeroDeVertices)
{
    for (int i = 0; i < numeroDeVertices; i++)
    {
        ARESTAS *aresta = grafo[i].arestas;

        while (aresta != NULL)
        {
            ARESTAS *temp = aresta;
            aresta = aresta->proxima;
            free(temp);
        }
    }
    free(grafo);
}

int main(int argc, char **argv)
{
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Gera um número aleatório entre 1 e MAX_VERTICES para o número de vértices
    int numeroDeVertices = rand() % MAX_VERTICES + 1;

    // Gera um número aleatório entre 1 e MAX_ARESTAS para o número de arestas
    int numeroDeArestas = rand() % MAX_ARESTAS + 1;

    printf("Total de vertices: %d\t e total de arestas: %d\n", numeroDeVertices, numeroDeArestas);

    // Cria o grafo com uma lista de adjacências
    VERTICES *grafo = criarGrafo(numeroDeVertices);

    // Cria as arestas aleatórias
    criarArestas(grafo, numeroDeVertices, numeroDeArestas);

    // Libera a memória do grafo
    liberarGrafo(grafo, numeroDeVertices);

    return 0;
}
