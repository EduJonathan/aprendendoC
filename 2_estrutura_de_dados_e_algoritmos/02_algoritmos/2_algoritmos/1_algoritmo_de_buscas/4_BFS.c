#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct queue
 * @brief Estrutura de uma fila simples baseada em array dinâmico.
 */
typedef struct queue
{
    int *itens;   /**< Ponteiro para o array de elementos */
    int front;    /**< Índice do primeiro elemento (frente) */
    int rear;     /**< Índice do último elemento (final) */
    int capacity; /**< Capacidade máxima alocada */
} fila;

/**
 * @brief Inicializa uma nova fila com a capacidade especificada.
 * 
 * @param capacity A capacidade total de elementos que a fila pode conter.
 * @return Ponteiro para a fila criada ou NULL em caso de erro de alocação.
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
    queue->front    = 0;
    queue->rear     = -1;
    queue->capacity = capacity;
    return queue;
}

/**
 * @brief Libera toda a memória associada à estrutura da fila.
 * 
 * @param queue Ponteiro para a fila a ser destruída.
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
 * @brief Verifica se a fila não possui elementos.
 * 
 * @param queue Ponteiro para a fila.
 * @return Retorna true se a fila estiver vazia, caso contrário, false.
 */
bool isEmpty(fila *queue)
{
    return queue->rear < queue->front;
}

/**
 * @brief Remove e retorna o elemento no início da fila (FIFO).
 * 
 * @param queue Ponteiro para a fila.
 * @return O valor inteiro removido ou -1 caso a fila esteja vazia.
 */
int remover(fila *queue)
{
    if (isEmpty(queue))
    {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    return queue->itens[queue->front++];
}

/**
 * @brief Insere um novo valor ao final da fila.
 * 
 * @param queue Ponteiro para a fila.
 * @param valor O valor inteiro a ser inserido.
 * @note Exibe uma mensagem de erro caso a capacidade máxima seja atingida.
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
 * @brief Realiza uma busca linear no array interno da fila.
 * 
 * @param queue Ponteiro para a fila.
 * @param chave O valor inteiro a ser buscado.
 * @return O índice da primeira ocorrência da chave ou -1 se não for encontrada.
 */
int sequential(fila *queue, int chave)
{
    int i = 0;
    while (i <= queue->rear)
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
 * @brief Aloca dinamicamente uma matriz de adjacência quadrada.
 * 
 * @param v Número de vértices (dimensão da matriz).
 * @return Ponteiro para a matriz de inteiros inicializada com zeros ou NULL em caso de erro.
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
        adj[i] = (int *)calloc(v, sizeof(int));

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
 * @brief Libera a memória de uma matriz de adjacência.
 * 
 * @param adj Ponteiro para a matriz de adjacência.
 * @param v Número de linhas (vértices) da matriz.
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
 * @brief Executa o algoritmo Breadth-First Search (BFS) a partir de um vértice.
 * * Explora os vértices por camadas (níveis), garantindo a visita a todos os vizinhos
 * de um nó antes de avançar. É ideal para encontrar o caminho mais curto em grafos sem pesos.
 * 
 * @param start O vértice de origem da busca.
 * @param adj Matriz de adjacência que representa o grafo.
 * @param v Número total de vértices no grafo.
 * @param visitados Vetor booleano/inteiro para controle de nós já visitados.
 */
void BFS(int start, int **adj, int v, int *visitados)
{
    fila *queue = initQueue(v);
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
 * @brief Garante a execução da BFS em todos os componentes do grafo.
 * Útil para grafos desconexos, garantindo que mesmo vértices isolados ou em subgrafos separados sejam processados.
 * 
 * @param adj Matriz de adjacência que representa o grafo.
 * @param v Número total de vértices no grafo.
 */
void BFSAll(int **adj, int v)
{
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        return;
    }

    printf("Resultado da BFS por componentes:\n");
    for (int i = 0; i < v; i++)
    {
        if (visitados[i] == 0)
        {
            printf("Componente começando em %d: ", i);
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
