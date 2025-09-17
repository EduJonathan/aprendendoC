#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Enum para representar os tipos de dados suportados.
 */
typedef enum
{
    TYPE_INT,    /**< Inteiro */
    TYPE_CHAR,   /**< Caractere */
    TYPE_STRING, /**< Cadeia de caracteres (string) */
    TYPE_DOUBLE  /**< Número de ponto flutuante (double) */
} DataType;

/**
 * @brief Estrutura que representa um nó da fila encadeada.
 *
 * Contém um ponteiro genérico para o valor, um identificador do tipo
 * e um ponteiro para o próximo nó.
 */
typedef struct Node
{
    void *value;       /**< Ponteiro para o valor armazenado. */
    DataType type;     /**< Tipo do valor armazenado. */
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
 * @param value Ponteiro para o valor a ser inserido.
 * @param type Tipo do valor a ser inserido.
 */
void enqueue(Queue *queue, void *value, DataType type);

/**
 * @brief Remove e retorna o elemento do início da fila.
 *
 * Se a fila estiver vazia, retorna NULL e exibe uma mensagem.
 *
 * @param queue Ponteiro para a fila.
 * @param type Ponteiro para armazenar o tipo do valor removido.
 * @return Ponteiro para o valor removido ou NULL se a fila estiver vazia.
 */
void *dequeue(Queue *queue, DataType *type);

/**
 * @brief Libera toda a memória alocada para a fila.
 *
 * Desaloca todos os nós e a estrutura da fila, incluindo os valores armazenados.
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

/**
 * @brief Imprime um valor de acordo com seu tipo.
 *
 * @param value Ponteiro para o valor.
 * @param type Tipo de dado do valor.
 */
void printValue(void *value, DataType type);

/**
 * @brief Função auxiliar para ler um valor de acordo com o tipo de dado.
 *
 * Aloca memória para o valor e o lê do usuário.
 *
 * @param type Tipo de dado do valor.
 * @param value Ponteiro para armazenar o valor alocado.
 * @return 1 em caso de sucesso, 0 em caso de falha.
 */
int readValue(DataType type, void **value);

#endif
