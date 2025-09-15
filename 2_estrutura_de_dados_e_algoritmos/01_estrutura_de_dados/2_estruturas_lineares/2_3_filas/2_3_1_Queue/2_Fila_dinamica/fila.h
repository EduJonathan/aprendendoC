#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa um nó da fila encadeada.
 *
 * Contém um valor float e um ponteiro para o próximo nó.
 */
typedef struct Node
{
    float value;       /**< Valor armazenado no nó. */
    struct Node *next; /**< Ponteiro para o próximo nó. */
} Node;

/**
 * @brief Estrutura que representa uma fila encadeada.
 *
 * Armazena ponteiros para o início e o fim da fila (FIFO).
 */
typedef struct Queue
{
    Node *front; /**< Ponteiro para o início da fila. */
    Node *rear;  /**< Ponteiro para o fim da fila. */
} Queue;

/**
 * @brief Cria uma nova fila vazia.
 *
 * Aloca memória para a estrutura da fila e inicializa os ponteiros como NULL.
 *
 * @return Ponteiro para a nova fila criada ou NULL em caso de falha.
 */
Queue *createQueue(void);

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a fila.
 * @return true se a fila estiver vazia ou NULL, false caso contrário.
 */
bool isEmpty(Queue *queue);

/**
 * @brief Insere um elemento no fim da fila.
 *
 * @param queue Ponteiro para a fila.
 * @param value Valor float a ser inserido.
 */
void enqueue(Queue *queue, float value);

/**
 * @brief Remove e retorna o elemento do início da fila.
 *
 * Se a fila estiver vazia, retorna NAN e exibe uma mensagem.
 *
 * @param queue Ponteiro para a fila.
 * @return Valor removido ou NAN se a fila estiver vazia.
 */
float dequeue(Queue *queue);

/**
 * @brief Libera toda a memória alocada para a fila.
 *
 * Desaloca todos os nós e a estrutura da fila.
 *
 * @param queue Ponteiro para a fila.
 */
void freeQueue(Queue *queue);

/**
 * @brief Imprime os elementos da fila.
 *
 * Exibe os valores do início ao fim da fila. Se a fila estiver vazia, exibe uma mensagem.
 *
 * @param queue Ponteiro para a fila.
 */
void printQueue(Queue *queue);

#endif
