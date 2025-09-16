#include <stdio.h>
#include <stdlib.h>

#ifndef NOADJACENTE_H
#define NOADJACENTE_H

/**
 * @brief Estrutura que representa um nó na lista de adjacência de um grafo.
 *
 * Cada nó contém um vértice e um ponteiro para o próximo nó.
 */
typedef struct noAdjacente
{
    int vertice;              /**< Vértice conectado */
    struct noAdjacente *prox; /**< Ponteiro para o próximo nó na lista */
} NoAdjacente;

#endif

#ifndef LISTAADJACENTE_H
#define LISTAADJACENTE_H

/**
 * @brief Estrutura que representa a lista de adjacência de um vértice.
 *
 * Contém um ponteiro para o primeiro nó da lista de adjacências.
 */
typedef struct listaAdjacente
{
    NoAdjacente *head; /**< Ponteiro para o primeiro nó da lista de adjacências */
} ListaAdjacente;

#endif

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @brief Estrutura que representa um grafo não direcionado.
 *
 * O grafo é composto por um número de vértices e um array de listas de adjacência.
 * A lista de adjacência é eficiente para grafos esparsos, com complexidade de espaço O(V + E)
 * e complexidade de tempo O(V) para verificar arestas no pior caso.
 */
typedef struct grafo
{
    int numVertices;          /**< Número de vértices no grafo */
    ListaAdjacente *adjacentes; /**< Array de listas de adjacência */
} Grafo;

#endif

/**
 * @brief Cria um novo nó com o vértice especificado.
 *
 * Aloca memória para um novo nó e inicializa seus valores.
 *
 * @param vertice O vértice a ser armazenado no nó.
 * @return Ponteiro para o nó criado ou NULL em caso de falha na alocação.
 */
NoAdjacente *newNode(int vertice)
{
    NoAdjacente *node = (NoAdjacente *)malloc(sizeof(NoAdjacente));
    if (node == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o nó\n");
        return NULL;
    }
    node->vertice = vertice;
    node->prox = NULL;
    return node;
}

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * Aloca memória para o grafo e inicializa as listas de adjacência com NULL.
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

    // Aloca memória para o array de listas de adjacência
    grafo->adjacentes = (ListaAdjacente *)malloc(numVertices * sizeof(ListaAdjacente));
    if (grafo->adjacentes == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para as listas de adjacência\n");
        free(grafo);
        return NULL;
    }

    // Inicializa as listas de adjacência com NULL
    for (int i = 0; i < numVertices; i++)
    {
        grafo->adjacentes[i].head = NULL;
    }

    return grafo;
}

/**
 * @brief Adiciona uma aresta entre dois vértices no grafo não direcionado.
 *
 * Adiciona cada vértice na lista de adjacência do outro.
 *
 * @param g Ponteiro para o grafo.
 * @param src Vértice de origem (deve estar entre 0 e numVertices-1).
 * @param dest Vértice de destino (deve estar entre 0 e numVertices-1).
 * @return 1 se a aresta foi adicionada com sucesso, 0 se os índices são inválidos ou grafo é nulo.
 */
int adicionarAresta(Grafo *g, int src, int dest)
{
    if (g == NULL || src < 0 || src >= g->numVertices || dest < 0 || dest >= g->numVertices)
    {
        fprintf(stderr, "Erro: Índices de vértices inválidos ou grafo nulo\n");
        return 0;
    }

    // Adiciona dest na lista de src
    NoAdjacente *node = newNode(dest);
    if (node == NULL)
    {
        return 0;
    }
    node->prox = g->adjacentes[src].head;
    g->adjacentes[src].head = node;

    // Adiciona src na lista de dest (grafo não direcionado)
    node = newNode(src);
    if (node == NULL)
    {
        // Desfaz a adição anterior para manter consistência
        g->adjacentes[src].head = node->prox;
        free(node);
        return 0;
    }
    node->prox = g->adjacentes[dest].head;
    g->adjacentes[dest].head = node;

    return 1;
}

/**
 * @brief Imprime as listas de adjacência do grafo.
 *
 * Exibe as listas de adjacência de cada vértice, sem setas extras no final.
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

    for (int vertice = 0; vertice < g->numVertices; vertice++)
    {
        printf("Lista de adjacência do vértice %d: ", vertice);
        
        NoAdjacente *check = g->adjacentes[vertice].head;
        if (check == NULL)
        {
            printf("NULL");
        }
        else
        {
            while (check)
            {
                printf("%d", check->vertice);
                if (check->prox)
                {
                    printf(" ");
                }
                check = check->prox;
            }
        }
        printf("\n");
    }
}

/**
 * @brief Libera toda a memória alocada para o grafo.
 *
 * Libera a memória de todas as listas de adjacência e da estrutura do grafo.
 *
 * @param g Ponteiro para o grafo que será liberado.
 */
void liberarGrafo(Grafo *g)
{
    if (g == NULL)
    {
        return;
    }

    // Libera cada lista de adjacência
    for (int i = 0; i < g->numVertices; i++)
    {
        NoAdjacente *current = g->adjacentes[i].head;
        while (current)
        {
            NoAdjacente *temp = current;
            current = current->prox;
            free(temp);
        }
    }

    // Libera o array de listas de adjacência
    free(g->adjacentes);

    // Libera a estrutura do grafo
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

    // Imprime as listas de adjacência
    imprimirListasAdj(g);

    // Libera a memória alocada para o grafo
    liberarGrafo(g);

    return 0;
}
