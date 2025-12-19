#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 15
#define MAX_ARESTAS 10

/**
 * @brief Estrutura que representa uma aresta no grafo.
 */
typedef struct arestas
{
    int destino;             /**< Vértice de destino da aresta */
    struct arestas *proxima; /**< Ponteiro para a próxima aresta */
} Aresta;

/**
 * @brief Estrutura que representa um grafo direcionado.
 *
 * O grafo é composto por um número de vértices e um array de listas de adjacência.
 * A lista de adjacência é eficiente para grafos esparsos, com complexidade de espaço O(V + E)
 * e complexidade de tempo O(V) para verificar arestas no pior caso.
 */
typedef struct grafo
{
    int numVertices;     /**< Número de vértices no grafo */
    Aresta **adjacentes; /**< Array de listas de adjacência */
} Grafo;

/**
 * @brief Cria um novo nó de aresta com o vértice de destino especificado.
 *
 * @param destino O vértice de destino da aresta.
 * @return Ponteiro para a aresta criada ou NULL em caso de falha na alocação.
 */
Aresta *newAresta(int destino)
{
    Aresta *aresta = (Aresta *)malloc(sizeof(Aresta));
    if (aresta == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a aresta\n");
        return NULL;
    }
    aresta->destino = destino;
    aresta->proxima = NULL;
    return aresta;
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

    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    if (grafo == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o grafo\n");
        return NULL;
    }
    grafo->numVertices = numVertices;

    grafo->adjacentes = (Aresta **)malloc(numVertices * sizeof(Aresta *));
    if (grafo->adjacentes == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para as listas de adjacência\n");
        free(grafo);
        return NULL;
    }

    for (int i = 0; i < numVertices; i++)
    {
        grafo->adjacentes[i] = NULL;
    }
    return grafo;
}

/**
 * @brief Adiciona uma aresta direcionada de src para dest no grafo.
 *
 * @param grafo Grafo a ser modificado.
 * @param src Vértice de origem (deve estar entre 0 e numVertices-1).
 * @param dest Vértice de destino (deve estar entre 0 e numVertices-1).
 * @return 1 se a aresta foi adicionada com sucesso, 0 se inválida ou falha na alocação.
 */
int adicionarAresta(Grafo *grafo, int src, int dest)
{
    if (grafo == NULL || src < 0 || src >= grafo->numVertices || dest < 0 || dest >= grafo->numVertices || src == dest)
    {
        fprintf(stderr, "Erro: Índices de vértices inválidos, grafo nulo ou laço detectado\n");
        return 0;
    }

    // Verifica se a aresta já existe
    Aresta *current = grafo->adjacentes[src];
    while (current)
    {
        if (current->destino == dest)
        {
            return 0; // Aresta já existe
        }
        current = current->proxima;
    }

    // Adiciona a aresta
    Aresta *novaAresta = newAresta(dest);
    if (novaAresta == NULL)
    {
        return 0;
    }
    novaAresta->proxima = grafo->adjacentes[src];
    grafo->adjacentes[src] = novaAresta;
    return 1;
}

/**
 * @brief Adiciona arestas aleatórias ao grafo.
 *
 * Tenta adicionar até maxArestas arestas, evitando duplicatas e laços.
 *
 * @param grafo Grafo a ser modificado.
 * @param maxArestas Número máximo de arestas a adicionar.
 * @return Número de arestas efetivamente adicionadas.
 */
int adicionarArestasAleatorias(Grafo *grafo, int maxArestas)
{
    if (grafo == NULL)
    {
        fprintf(stderr, "Erro: Grafo nulo\n");
        return 0;
    }

    int arestasAdicionadas = 0;
    int maxPossiveis = grafo->numVertices * (grafo->numVertices - 1); // Máximo de arestas sem laços
    maxArestas = maxArestas < maxPossiveis ? maxArestas : maxPossiveis;

    while (arestasAdicionadas < maxArestas)
    {
        int src = rand() % grafo->numVertices;
        int dest = rand() % grafo->numVertices;
        if (adicionarAresta(grafo, src, dest))
        {
            arestasAdicionadas++;
        }
    }
    return arestasAdicionadas;
}

/**
 * @brief Imprime as listas de adjacência do grafo.
 *
 * @param grafo Grafo a ser impresso.
 */
void imprimirListasAdj(Grafo *grafo)
{
    if (grafo == NULL)
    {
        printf("Grafo vazio\n");
        return;
    }

    for (int i = 0; i < grafo->numVertices; i++)
    {
        printf("Lista de adjacência do vértice %d: ", i);
        Aresta *current = grafo->adjacentes[i];
        if (current == NULL)
        {
            printf("NULL");
        }
        else
        {
            while (current)
            {
                printf("%d", current->destino);
                if (current->proxima)
                {
                    printf(" ");
                }
                current = current->proxima;
            }
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para o grafo.
 *
 * @param grafo Grafo a ser desalocado.
 */
void liberarGrafo(Grafo *grafo)
{
    if (grafo == NULL)
    {
        return;
    }

    for (int i = 0; i < grafo->numVertices; i++)
    {
        Aresta *current = grafo->adjacentes[i];
        while (current)
        {
            Aresta *temp = current;
            current = current->proxima;
            free(temp);
        }
    }
    free(grafo->adjacentes);
    free(grafo);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int numVertices = rand() % MAX_VERTICES + 1;
    int maxArestas = rand() % MAX_ARESTAS + 1;

    printf("Total de vértices: %d\tTotal de arestas (tentativas): %d\n", numVertices, maxArestas);

    Grafo *grafo = criarGrafo(numVertices);
    if (grafo == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do grafo\n");
        return EXIT_FAILURE;
    }

    int arestasAdicionadas = adicionarArestasAleatorias(grafo, maxArestas);
    printf("Arestas efetivamente adicionadas: %d\n", arestasAdicionadas);

    imprimirListasAdj(grafo);

    liberarGrafo(grafo);
    return 0;
}
