#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERTICES 10

/**
 * @struct Aresta
 * @brief Estrutura que representa uma aresta em um grafo direcionado.
 *
 * Contém o vértice de destino (caractere), o peso da aresta e um ponteiro para a próxima aresta.
 */
typedef struct arestas
{
    char destino;         /**< Vértice de destino (A a J) */
    int peso;             /**< Peso da aresta */
    struct arestas *prox; /**< Ponteiro para a próxima aresta */
} Aresta;

/**
 * @struct Grafo
 * @brief Estrutura que representa um grafo direcionado como uma tabela de hash.
 *
 * Usa listas de adjacência para armazenar arestas, com complexidade de espaço O(V + E)
 * e complexidade de tempo O(V) para verificar arestas no pior caso.
 */
typedef struct grafo
{
    int numVertices; /**< Número de vértices (máximo 26, A-Z) */
    Aresta **adj;    /**< Array de listas de adjacência */
} Grafo;

/**
 * @brief Calcula o índice de um vértice usando uma função hash simples.
 *
 * @param vertice Vértice (caractere A a Z).
 * @return Índice (0 a 25) ou -1 se inválido.
 */
int hash(char vertice)
{
    if (vertice < 'A' || vertice > 'Z')
    {
        return -1;
    }
    return vertice - 'A';
}

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * @param numVertices Número de vértices (máximo 26).
 * @return Ponteiro para o grafo ou NULL em caso de falha.
 */
Grafo *criarGrafo(int numVertices)
{
    if (numVertices <= 0 || numVertices > 26)
    {
        fprintf(stderr, "Erro: Número de vértices deve ser entre 1 e 26\n");
        return NULL;
    }

    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if (g == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o grafo\n");
        return NULL;
    }

    g->numVertices = numVertices;
    g->adj = (Aresta **)calloc(numVertices, sizeof(Aresta *));
    if (g->adj == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para as listas de adjacência\n");
        free(g);
        return NULL;
    }
    return g;
}

/**
 * @brief Adiciona uma aresta direcionada ao grafo.
 *
 * @param g Grafo.
 * @param origem Vértice de origem (A a A+numVertices-1).
 * @param destino Vértice de destino (A a A+numVertices-1).
 * @param peso Peso da aresta.
 * @return 1 se adicionada, 0 se inválida ou falha.
 */
int adicionarAresta(Grafo *g, char origem, char destino, int peso)
{
    if (g == NULL || origem < 'A' || origem >= 'A' + g->numVertices ||
        destino < 'A' || destino >= 'A' + g->numVertices || origem == destino)
    {
        fprintf(stderr, "Erro: Grafo nulo, vértices inválidos ou laço detectado\n");
        return 0;
    }

    int indice = hash(origem);
    if (indice < 0)
    {
        fprintf(stderr, "Erro: Vértice de origem inválido\n");
        return 0;
    }

    Aresta *atual = g->adj[indice];
    while (atual)
    {
        if (atual->destino == destino)
        {
            return 0; // Evita duplicatas
        }
        atual = atual->prox;
    }

    Aresta *novaAresta = (Aresta *)malloc(sizeof(Aresta));
    if (novaAresta == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a aresta\n");
        return 0;
    }
    novaAresta->destino = destino;
    novaAresta->peso = peso;
    novaAresta->prox = g->adj[indice];
    g->adj[indice] = novaAresta;
    return 1;
}

/**
 * @brief Imprime as listas de adjacência do grafo.
 *
 * @param g Grafo.
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
        Aresta *atual = g->adj[i];
        if (atual == NULL)
        {
            printf("[]");
        }
        else
        {
            printf("[");
            while (atual)
            {
                printf("%c(%d)", atual->destino, atual->peso);
                atual = atual->prox;
                if (atual)
                {
                    printf(", ");
                }
            }
            printf("]");
        }
        printf("\n");
    }
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
        Aresta *atual = g->adj[i];
        while (atual)
        {
            Aresta *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        g->adj[i] = NULL;
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

    adicionarAresta(g, 'A', 'B', 5);
    adicionarAresta(g, 'A', 'C', 3);
    adicionarAresta(g, 'B', 'C', 2);
    adicionarAresta(g, 'C', 'A', 7);

    imprimirListasAdj(g);

    liberarGrafo(g);
    return 0;
}
