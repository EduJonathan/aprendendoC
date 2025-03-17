#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 10
#define MAX_VERTICES 10 // Definir o número máximo de vértices no grafo

typedef struct queue
{
    int front;
    int rear;
    int itens[QUEUE_SIZE];
} fila;

/**
 * Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a fila.
 * @return Retorna true se a fila estiver vazia, caso contrário, retorna false.
 */
bool isEmpty(fila *queue)
{
    return (queue->rear < queue->front) ? true : false;
}

/**
 * Remove um item da fila.
 *
 * @param queue Ponteiro para a fila.
 * @return O item removido da fila.
 */
int remover(fila *queue)
{
    return (queue->itens[(queue->front)++]);
}

/**
 * Insere um valor na fila.
 *
 * @param queue Ponteiro para a fila.
 * @param valor O valor a ser inserido.
 */
void insert(fila *queue, int valor)
{
    if (queue->rear == QUEUE_SIZE - 1)
    {
        printf("Estouro: elemento não pode ser inserido.\n");
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
 * Realiza a Busca em Largura (BFS) em um grafo.
 *
 * @param key O vértice de início da busca.
 * @param adj Matriz de adjacência do grafo.
 * @param v Número de vértices no grafo.
 *
 * @note A Busca em Largura (BFS) é um algoritmo de busca em grafos que explora todos os
 * vértices de um grafo de maneira por níveis, começando de um vértice inicial. Ele visita
 * todos os vizinhos de um nó antes de passar para os nós mais distantes.Útil para encontrar
 * o caminho mais curto em grafos não ponderados, onde todos os passos entre nós são
 * considerados iguais. O tempo de execução da BFS é O(V + E) V é o número de vértices e o
 * E é o número de arestas no grafo.
 */
void BFS(int key, int adj[MAX_VERTICES][MAX_VERTICES], int v)
{
    int visitados[MAX_VERTICES] = {0}; // Inicializa todos os vértices como não visitados
    fila queue;
    queue.rear = -1;
    queue.front = 0;

    // Enfileira o vértice inicial
    insert(&queue, key);
    visitados[key] = 1; // Marca o vértice inicial como visitado

    while (!isEmpty(&queue))
    {
        key = remover(&queue);
        printf("%d ", key); // Exibe o vértice atual

        // Verifica os vizinhos do vértice atual
        for (int i = 0; i < v; i++) // Alterado para percorrer os vértices corretamente
        {
            if (adj[key][i] == 1 && visitados[i] == 0 && sequential(&queue, i) == -1)
            {
                insert(&queue, i); // Enfileira o vizinho
                visitados[i] = 1;  // Marca o vizinho como visitado
            }
        }
    }
}

int main(int argc, char **argv)
{
    int adj[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0},
    };

    int v = 5;            // Número de vértices no grafo
    int start_vertex = 0; // Vértice de início para a BFS

    // Chama a função BFS a partir do vértice `start_vertex`
    BFS(start_vertex, adj, v);

    return 0;
}
