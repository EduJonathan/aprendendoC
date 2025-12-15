#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura que representa uma fila circular dinâmica.
 *
 * A fila circular permite reutilizar espaços removidos, otimizando o uso de memória.
 * Essa versão usa alocação dinâmica com capacidade definida em tempo de execução.
 */
typedef struct
{
    int front;     /**< Índice do primeiro elemento */
    int rear;      /**< Índice do último elemento */
    int count;     /**< Quantidade de elementos armazenados */
    int capacity;  /**< Capacidade máxima da fila */
    int *elements; /**< Vetor de elementos da fila */
} CircularQueue;

/**
 * @brief Inicializa a fila circular com a capacidade informada.
 *
 * @param queue Ponteiro para a estrutura da fila
 * @param capacidade Tamanho máximo da fila
 * @return true se a fila foi inicializada com sucesso, false caso contrário
 */
bool inicializarFila(CircularQueue *queue, int capacidade)
{
    if (capacidade <= 0)
        return false;
    queue->capacity = capacidade;
    queue->elements = (int *)calloc(capacidade, sizeof(int));
    
    if (queue->elements == NULL)
        return false;
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return true;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a estrutura da fila
 * @return true se a fila estiver vazia, false caso contrário
 */
bool filaVazia(CircularQueue *queue)
{
    return queue->count == 0;
}

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param queue Ponteiro para a estrutura da fila
 * @return true se a fila estiver cheia, false caso contrário
 */
bool filaCheia(CircularQueue *queue)
{
    return queue->count == queue->capacity;
}

/**
 * @brief Insere um elemento na fila circular.
 *
 * @param queue Ponteiro para a estrutura da fila
 * @param elemento Valor a ser inserido
 * @return true se a inserção foi bem-sucedida, false se a fila estiver cheia
 */
bool inserir(CircularQueue *queue, int elemento)
{
    if (filaCheia(queue))
        return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = elemento;
    queue->count++;
    return true;
}

/**
 * @brief Remove o elemento do início da fila.
 *
 * @param queue Ponteiro para a estrutura da fila
 * @param elemento Ponteiro onde o valor removido será armazenado
 * @return true se a remoção foi bem-sucedida, false se a fila estiver vazia
 */
bool remover(CircularQueue *queue, int *elemento)
{
    if (filaVazia(queue))
        return false;
    *elemento = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    return true;
}

/**
 * @brief Exibe todos os elementos da fila na ordem correta.
 *
 * @param queue Ponteiro para a estrutura da fila
 */
void exibirFila(CircularQueue *queue)
{
    if (filaVazia(queue))
    {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");
    for (int i = 0, pos = queue->front; i < queue->count; i++, pos = (pos + 1) % queue->capacity)
    {
        printf("%d ", queue->elements[pos]);
    }
    printf("\n");
}

/**
 * @brief Libera os recursos alocados pela fila.
 *
 * @param queue Ponteiro para a estrutura da fila
 */
void liberarFila(CircularQueue *queue)
{
    free(queue->elements);
    queue->elements = NULL;
    queue->capacity = 0;
    queue->count = 0;
    queue->front = 0;
    queue->rear = -1;
}

int main(int argc, char **argv)
{
    CircularQueue fila = {0};
    if (!inicializarFila(&fila, 5))
    {
        printf("Erro ao inicializar a fila!\n");
        return 1;
    }

    inserir(&fila, 10);
    inserir(&fila, 15);
    inserir(&fila, 20);
    inserir(&fila, 25);
    inserir(&fila, 30);
    exibirFila(&fila);

    int elemento = 0;
    if (remover(&fila, &elemento))
    {
        printf("Elemento removido: %d\n", elemento);
    }
    exibirFila(&fila);

    if (!inserir(&fila, 35))
    {
        printf("Fila cheia! Não é possível inserir 35.\n");
    }
    exibirFila(&fila);

    liberarFila(&fila);
    return 0;
}
