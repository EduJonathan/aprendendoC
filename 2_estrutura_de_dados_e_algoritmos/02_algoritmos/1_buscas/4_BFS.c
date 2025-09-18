#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int *itens;   // Array dinâmico para armazenar os itens
    int front;    // Índice do início da fila
    int rear;     // Índice do fim da fila
    int capacity; // Capacidade total da fila
} fila;

/**
 * @brief Inicializa a fila com a capacidade especificada.
 */
fila *initQueue(int capacity)
{
    fila *queue = (fila *)malloc(sizeof(fila));
    if (queue == NULL)
    {
        printf("Erro: Falha na alocação de memória para a fila.\n");
        return NULL;
    }

    queue->itens = (int *)malloc(capacity * sizeof(int));
    if (queue->itens == NULL)
    {
        printf("Erro: Falha na alocação de memória para os itens da fila.\n");
        free(queue);
        return NULL;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

/**
 * @brief Libera a memória alocada para a fila.
 */
void freeQueue(fila *queue)
{
    if (queue != NULL)
    {
        free(queue->itens);
        free(queue);
    }
}

/**
 * Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a fila.
 * @return Retorna true se a fila estiver vazia, caso contrário, retorna false.
 */
bool isEmpty(fila *queue)
{
    return queue->rear < queue->front;
}

/**
 * Remove um item da fila.
 *
 * @param queue Ponteiro para a fila.
 * @return O item removido da fila.
 */
int remover(fila *queue)
{
    if (isEmpty(queue))
    {
        printf("Erro: Fila vazia.\n");
        return -1; // Valor sentinela para erro
    }
    return queue->itens[queue->front++];
}

/**
 * Insere um valor na fila.
 *
 * @param queue Ponteiro para a fila.
 * @param valor O valor a ser inserido.
 */
void insert(fila *queue, int valor)
{
    if (queue->rear == queue->capacity - 1)
    {
        printf("Estouro: a fila está cheia.\n");
        return;
    }
    queue->itens[++(queue->rear)] = valor;
}

/**
 * Realiza uma busca sequencial para encontrar um valor na fila.
 *
 * @param queue Ponteiro para a fila.
 * @param chave O valor a ser procurado.
 * @return A posição do valor na fila, ou -1 se não encontrado.
 */
int sequential(fila *queue, int chave)
{
    int i = 0;
    while (i <= queue->rear) // Alterado para verificar até o último índice válido
    {
        if (chave == queue->itens[i])
        {
            return i;
        }
        i++;
    }
    return -1;
}

/**
 * @brief Aloca uma matriz de adjacência dinamicamente.
 */
int **allocateGraph(int v)
{
    int **adj = (int **)malloc(v * sizeof(int *));
    if (adj == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < v; i++)
    {
        adj[i] = (int *)calloc(v, sizeof(int)); // Inicializa com 0
        if (adj[i] == NULL)
        {
            printf("Erro: Falha na alocação de memória.\n");
            for (int j = 0; j < i; j++)
            {
                free(adj[j]);
            }
            free(adj);
            return NULL;
        }
    }
    return adj;
}

/**
 * @brief Libera a memória alocada para a matriz de adjacência.
 */
void freeGraph(int **adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        free(adj[i]);
    }
    free(adj);
}

/**
 * @brief Realiza a Busca em Largura (BFS) em um grafo.
 *
 * A Busca em Largura (BFS) é um algoritmo de busca em grafos que explora todos os
 * vértices de um grafo por níveis, começando de um vértice inicial. Ela visita todos
 * os vizinhos de um nó antes de passar para os nós mais distantes.
 *
 * É útil para encontrar o caminho mais curto em grafos não ponderados, onde todos os
 * passos entre nós têm o mesmo peso. Utiliza uma fila (FIFO) para garantir a exploração
 * por camadas.
 *
 * Complexidade:
 *
 * - Tempo:  O(V + E), onde V é o número de vértices e E o número de arestas.
 *
 * - Espaço: O(V), para armazenar a fila e o vetor de visitados.
 *
 * @param key O vértice de início da busca.
 * @param adj Matriz de adjacência do grafo.
 * @param v Número de vértices no grafo.
 */
void BFS(int start, int **adj, int v, int *visitados)
{
    fila *queue = initQueue(v); // Capacidade da fila igual ao número de vértices
    if (queue == NULL)
    {
        return;
    }

    insert(queue, start);
    visitados[start] = 1;

    while (!isEmpty(queue))
    {
        int current = remover(queue);
        printf("%d ", current);

        for (int i = 0; i < v; i++)
        {
            if (adj[current][i] == 1 && visitados[i] == 0)
            {
                insert(queue, i);
                visitados[i] = 1;
            }
        }
    }
    freeQueue(queue);
}

/**
 * @brief Executa BFS em todos os vértices para garantir que todos sejam visitados.
 */
void BFSAll(int **adj, int v)
{
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        return;
    }

    printf("Resultado da BFS:\n");
    for (int i = 0; i < v; i++)
    {
        if (visitados[i] == 0)
        {
            printf("Componente conexa começando em %d: ", i);
            BFS(i, adj, v, visitados);
            printf("\n");
        }
    }
    free(visitados);
}

int main(int argc, char **argv)
{
    int v = 0, e = 0, start_vertex = 0;

    // Solicita o número de vértices
    printf("Digite o número de vértices: ");
    if (scanf("%d", &v) != 1 || v <= 0)
    {
        printf("Erro: Número de vértices deve ser positivo.\n");
        return 1;
    }

    // Solicita o número de arestas
    printf("Digite o número de arestas: ");
    if (scanf("%d", &e) != 1 || e < 0)
    {
        printf("Erro: Número de arestas deve ser não-negativo.\n");
        return 1;
    }

    // Aloca a matriz de adjacência
    int **adj = allocateGraph(v);
    if (adj == NULL)
    {
        return 1;
    }

    // Solicita as arestas
    printf("Digite as arestas (formato: vértice_origem vértice_destino):\n");
    for (int i = 0; i < e; i++)
    {
        int src = 0, dest = 0;
        printf("Aresta %d: ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2 || src < 0 || src >= v || dest < 0 || dest >= v)
        {
            printf("Erro: Vértices inválidos.\n");
            freeGraph(adj, v);
            return 1;
        }
        adj[src][dest] = 1; // Grafo não direcionado
        adj[dest][src] = 1;
    }

    // Solicita o vértice inicial
    printf("Digite o vértice inicial para BFS (0 a %d): ", v - 1);
    if (scanf("%d", &start_vertex) != 1 || start_vertex < 0 || start_vertex >= v)
    {
        printf("Erro: Vértice inicial inválido.\n");
        freeGraph(adj, v);
        return 1;
    }

    // Executa BFS para o vértice inicial
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        freeGraph(adj, v);
        return 1;
    }
    printf("Resultado da BFS a partir do vértice %d: ", start_vertex);
    BFS(start_vertex, adj, v, visitados);
    printf("\n");

    // Executa BFS para todos os vértices (para grafos desconexos)
    BFSAll(adj, v);

    // Libera memória
    free(visitados);
    freeGraph(adj, v);
    return 0;
}
