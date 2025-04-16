#include <stdio.h>
#include <stdlib.h>

#ifndef NOADJACENTE_H
#define NOADJACENTE_H

/**
 * @brief Estrutura que representa um nó na lista de adjacência de um grafo.
 *
 * Cada nó na lista de adjacência contém um vértice e um ponteiro para o próximo nó.
 *
 * A lista de adjacência é uma representação comum de grafos, onde cada nó
 * representa um vértice e os nós adjacentes representam as arestas conectadas a ele.
 * A lista de adjacência é uma estrutura de dados eficiente para armazenar grafos esparsos,
 * onde o número de arestas é muito menor do que o número máximo possível de arestas.
 */
struct noAdjacente
{
    int vertice;              /**< Vértice conectado */
    struct noAdjacente *prox; /**< Ponteiro para o próximo nó na lista */
};

#endif

#ifndef LISTAADJACENTE_H
#define LISTAADJACENTE_H

/**
 * @brief Estrutura que representa a lista de adjacência de um grafo.
 *
 * A lista de adjacência é composta por uma lista de nós, onde cada nó representa
 * um vértice adjacente a um vértice específico.
 */
struct listaAdjacente
{
    struct noAdjacente *head; /**< Ponteiro para o primeiro nó da lista de adjacências */
};

#endif

#ifndef GRAFO_H
#define GRAFO_H

/**
 * @brief Estrutura que representa um grafo.
 *
 * O grafo é composto por um número de vértices e uma lista de adjacência para cada vértice.
 */
struct grafo
{
    int numVertices;                   /**< Número de vértices no grafo */
    struct listaAdjacente *adjacentes; /**< Array de listas de adjacência */
};

#endif

/**
 * @brief Cria um novo nó com o vértice especificado.
 *
 * Aloca memória para um novo nó e inicializa os valores do nó.
 *
 * @param vertice O vértice a ser armazenado no nó.
 * @return Ponteiro para o nó criado.
 */
struct noAdjacente *newNode(int vertice)
{
    // Aloca memória para o nó
    struct noAdjacente *node = (struct noAdjacente *)malloc(sizeof(struct noAdjacente));
    node->vertice = vertice;
    node->prox = NULL;
    return node;
}

/**
 * @brief Cria um grafo com o número de vértices especificado.
 *
 * Aloca memória para o grafo e inicializa as listas de adjacência de todos os vértices.
 *
 * @param numVertices O número de vértices no grafo.
 * @return Ponteiro para o grafo criado.
 */
struct grafo *criarGrafo(int numVertices)
{
    // Aloca memória para o grafo
    struct grafo *grafo = (struct grafo *)malloc(sizeof(struct grafo));
    grafo->numVertices = numVertices;
    grafo->adjacentes = (struct listaAdjacente *)malloc(sizeof(struct listaAdjacente) * numVertices);

    // Inicializa as listas de adjacência
    for (int i = 0; i < numVertices; i++)
    {
        // Inicializa a lista de adjacência com 0(NULL)
        grafo->adjacentes[i].head = NULL;
    }

    // Se a alocação não falhar, retorna o grafo com as listas de adjacência inicializadas com 0(NULL)
    return grafo;
}

/**
 * @brief Adiciona uma aresta entre dois vértices no grafo.
 *
 * Esta função cria uma aresta entre os vértices `src` e `dest`,
 * adicionando cada vértice na lista de adjacência do outro.
 * O grafo é considerado não direcionado.
 *
 * @param g Ponteiro para o grafo.
 * @param src Vértice de origem.
 * @param dest Vértice de destino.
 */
void adicionarAresta(struct grafo *g, int src, int dest)
{
    // Função auxiliar para adicionar uma aresta em uma lista de adjacência
    struct noAdjacente *node = newNode(dest);
    node->prox = g->adjacentes[src].head;
    g->adjacentes[src].head = node;

    node = newNode(src); // Aresta bidirecional
    node->prox = g->adjacentes[dest].head;
    g->adjacentes[dest].head = node;
}

/**
 * @brief Realiza a travessia do grafo e imprime as listas de adjacência.
 *
 * Esta função percorre todos os vértices do grafo e imprime suas
 * respectivas listas de adjacência.
 *
 * @param g Ponteiro para o grafo a ser percorrido.
 */
void transversal(struct grafo *g)
{
    for (int vertice = 0; vertice < g->numVertices; vertice++)
    {
        struct noAdjacente *check = g->adjacentes[vertice].head;
        printf("A lista de adjacência do vértice %d é: ", vertice);
        while (check)
        {
            printf("%d -> ", check->vertice);
            check = check->prox;
        }
        printf("NULL\n");
    }
}

/**
 * @brief Libera toda a memória alocada para o grafo.
 *
 * Esta função percorre todas as listas de adjacência e libera a memória dos nós,
 * além de liberar a memória do grafo e suas listas de adjacência.
 *
 * @param g Ponteiro para o grafo que será liberado.
 */
void liberarMemoria(struct grafo *g)
{
    // Libera a memória de cada lista de adjacência
    for (int i = 0; i < g->numVertices; i++)
    {
        // Ponteiro para o primeiro nó da lista
        struct noAdjacente *current = g->adjacentes[i].head;

        // Percorre a lista de adjacência e libera os nós
        while (current)
        {
            struct noAdjacente *temp = current;
            current = current->prox;
            free(temp); // Libera o nó
        }
    }

    // Libera a memória das listas de adjacência
    free(g->adjacentes);

    // Libera a memória do grafo
    free(g);
}

int main(int argc, char **argv)
{
    // Cria um grafo com 5 vértices
    struct grafo *g = criarGrafo(5);

    // Adiciona arestas ao grafo
    adicionarAresta(g, 0, 1);
    adicionarAresta(g, 0, 4);
    adicionarAresta(g, 1, 2);
    adicionarAresta(g, 1, 3);
    adicionarAresta(g, 1, 4);
    adicionarAresta(g, 2, 3);
    adicionarAresta(g, 3, 4);

    // Imprime as listas de adjacência
    transversal(g);

    // Libera a memória alocada para o grafo
    liberarMemoria(g);

    return 0;
}
