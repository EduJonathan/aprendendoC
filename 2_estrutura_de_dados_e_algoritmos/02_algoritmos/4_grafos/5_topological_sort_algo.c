#include <stdio.h>
#include <stdlib.h>

/**
 * Algoritmo de Ordenação Topológica (Topological Sort)
 *
 * O algoritmo de ordenação topológica é utilizado para ordenar os vértices de um grafo
 * direcionado acíclico (DAG) de forma linear, de modo que para cada aresta (u → v), o vértice
 * u venha antes de v na ordenação.
 *
 * É amplamente aplicado em sistemas de dependência, como:
 * - Compilação de módulos (um arquivo depende de outro)
 * - Agendamento de tarefas com dependências
 * - Ordenação de pré-requisitos em disciplinas de um curso
 *
 * Existem duas abordagens principais:
 * - **DFS (Depth-First Search)**: Visita recursivamente os nós e empilha após
 * visitar todos os vizinhos.
 * - **Kahn's Algorithm**: Baseado em contagem de grau de entrada (in-degree), usando fila.
 *
 * Este exemplo usa **Kahn's Algorithm**, que é iterativo e baseado em BFS.
 *
 * @note O grafo deve ser um DAG (sem ciclos). Se houver ciclo, a ordenação topológica não é possível.
 *
 * COMPLEXIDADE:
 * - TEMPO: O(V + E), onde V é o número de vértices e E o número de arestas.
 * - ESPAÇO: O(V + E), para armazenar a estrutura do grafo e auxiliares.
 */

// Estrutura para representar um nó na lista de adjacência
typedef struct node
{
    int vertex;
    struct node *next;
} Node;

// Estrutura para representar o grafo
typedef struct
{
    int numVertices;
    Node **adjLists;
    int *inDegree; // Grau de entrada de cada vértice
} Graph;

/**
 * @brief Cria um novo nó para a lista de adjacência.
 *
 * @param v Vértice que o nó representa.
 * @return Ponteiro para o novo nó criado.
 */
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Cria e inicializa um grafo com um número especificado de vértices.
 *
 * @param vertices Número de vértices.
 * @return Ponteiro para o grafo criado.
 */
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));
    graph->inDegree = (int *)calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

/**
 * @brief Adiciona uma aresta direcionada do vértice src para dest.
 *
 * @param graph Ponteiro para o grafo.
 * @param src Vértice de origem.
 * @param dest Vértice de destino.
 */
void addEdge(Graph *graph, int src, int dest)
{
    // Adiciona aresta de src para dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Incrementa o grau de entrada do vértice de destino
    graph->inDegree[dest]++;
}

/**
 * @brief Realiza a ordenação topológica de um grafo usando o algoritmo de Kahn (BFS).
 *
 * O algoritmo processa os vértices com grau de entrada zero, reduz os graus dos vizinhos
 * e insere os novos vértices elegíveis na fila. Detecta ciclos ao final do processo.
 *
 * @param graph Ponteiro para o grafo a ser ordenado.
 *
 * @note Se o grafo contiver um ciclo, a ordenação topológica não será possível.
 */
void topologicalSort(Graph *graph)
{
    int *result = (int *)malloc(graph->numVertices * sizeof(int));
    int index = 0;

    // Fila para vértices com grau de entrada zero
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = -1;

    // Inicializa a fila com vértices de grau de entrada zero
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->inDegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    int count = 0; // Contador de vértices visitados

    while (front <= rear)
    {
        // Extrai vértice da frente da fila e adiciona ao resultado
        int u = queue[front++];
        result[index++] = u;

        // Percorre todos os vértices adjacentes
        Node *temp = graph->adjLists[u];
        while (temp != NULL)
        {
            int v = temp->vertex;

            // Reduz o grau de entrada e adiciona à fila se chegar a zero
            if (--graph->inDegree[v] == 0)
            {
                queue[++rear] = v;
            }

            temp = temp->next;
        }

        count++;
    }

    // Verifica se existe ciclo
    if (count != graph->numVertices)
    {
        printf("O grafo contém um ciclo! Ordenação topológica não é possível.\n");
        free(result);
        free(queue);
        return;
    }

    // Imprime a ordenação topológica
    printf("Ordenação Topológica: ");
    for (int i = 0; i < index; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(queue);
}

// Função para liberar a memória do grafo
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp != NULL)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->inDegree);
    free(graph);
}

int main(int argc, char **argv)
{
    // Exemplo de grafo (DAG)
    int vertices = 6;
    Graph *graph = createGraph(vertices);

    // Adiciona arestas
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    // Executa a ordenação topológica
    topologicalSort(graph);

    // Libera memória
    freeGraph(graph);

    return 0;
}
