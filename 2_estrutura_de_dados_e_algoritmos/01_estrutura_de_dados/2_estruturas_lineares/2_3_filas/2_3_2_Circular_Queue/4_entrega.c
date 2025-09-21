#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/**
 * @struct Message
 * @brief Estrutura para representar uma mensagem genérica.
 */
typedef struct
{
    char *content; /**< Conteúdo da mensagem (ex: texto ou número do pedido). */
    char *type;    /**< Tipo da mensagem (ex: "Text" ou "Refund"). */
} Message;

/**
 * @struct CircularQueue
 * @brief Estrutura para representar uma fila circular.
 */
typedef struct
{
    void **items; /**< Array de ponteiros genéricos para os dados. */
    int front;    /**< Índice do início da fila. */
    int rear;     /**< Índice do fim da fila. */
    int size;     /**< Número atual de elementos na fila. */
    int capacity; /**< Capacidade máxima da fila. */
} CircularQueue;

/**
 * @brief Cria uma nova fila circular com a capacidade especificada.
 * @param capacity Capacidade máxima da fila.
 * @return Ponteiro para a nova fila circular, ou NULL se a alocação falhar.
 */
CircularQueue *createCircularQueue(int capacity)
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (queue == NULL)
        return NULL;

    queue->items = (void **)malloc(capacity * sizeof(void *));
    if (queue->items == NULL)
    {
        free(queue);
        return NULL;
    }

    queue->front = -1; // Fila vazia
    queue->rear = -1;  // Fila vazia
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

/**
 * @brief Verifica se a fila está vazia.
 * @param queue Ponteiro para a fila circular.
 * @return 1 se a fila estiver vazia, 0 caso contrário.
 */
int isEmpty(CircularQueue *queue)
{
    return queue->size == 0;
}

/**
 * @brief Verifica se a fila está cheia.
 * @param queue Ponteiro para a fila circular.
 * @return 1 se a fila estiver cheia, 0 caso contrário.
 */
int isFull(CircularQueue *queue)
{
    return queue->size == queue->capacity;
}

/**
 * @brief Adiciona um elemento à fila circular.
 * @param queue Ponteiro para a fila circular.
 * @param data Ponteiro genérico para o dado a ser enfileirado.
 * @return 1 se bem-sucedido, 0 se a alocação falhar ou a fila estiver cheia.
 * @note Se a fila estiver cheia, o elemento mais antigo é descartado.
 */
int enqueue(CircularQueue *queue, void *data)
{
    if (isFull(queue))
    {
        // Fila cheia: descarta o elemento mais antigo
        void *oldData = queue->items[queue->front];
        free(oldData); // Libera o dado antigo (neste exemplo, Message)
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->items[queue->rear] = data;
    queue->size++;
    return 1;
}

/**
 * @brief Remove e retorna o elemento da frente da fila circular.
 * @param queue Ponteiro para a fila circular.
 * @return Ponteiro genérico para o dado removido, ou NULL se a fila estiver vazia.
 */
void *dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Fila vazia!\n");
        return NULL;
    }

    void *data = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    if (isEmpty(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }

    return data;
}

/**
 * @brief Libera a memória da fila circular e seus elementos.
 * @param queue Ponteiro para a fila circular.
 * @note Todos os dados (void*) são liberados, assumindo que foram alocados dinamicamente.
 */
void freeCircularQueue(CircularQueue *queue)
{
    while (!isEmpty(queue))
    {
        void *data = dequeue(queue);
        free(data); // Libera o dado (Message)
    }
    free(queue->items);
    free(queue);
}

/**
 * @brief Processa e exibe uma mensagem da fila.
 * @param data Ponteiro genérico para a mensagem.
 */
void processMessage(void *data)
{
    Message *msg = (Message *)data;
    if (strcmp(msg->type, "Text") == 0)
    {
        printf("Mensagem de texto: %s\n", msg->content);
    }
    else if (strcmp(msg->type, "Refund") == 0)
    {
        printf("Solicitação de reembolso: %s\n", msg->content);
    }
}

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Cria uma fila circular com capacidade 3
    CircularQueue *queue = createCircularQueue(3);

    // Cria mensagens dinamicamente
    Message *msg1 = (Message *)malloc(sizeof(Message));
    msg1->content = strdup("Qual o prazo de entrega?");
    msg1->type = strdup("Text");

    Message *msg2 = (Message *)malloc(sizeof(Message));
    msg2->content = strdup("Problema com o pagamento");
    msg2->type = strdup("Text");

    Message *msg3 = (Message *)malloc(sizeof(Message));
    msg3->content = strdup("Pedido #1234 - Produto com defeito");
    msg3->type = strdup("Refund");

    Message *msg4 = (Message *)malloc(sizeof(Message));
    msg4->content = strdup("Quero cancelar meu pedido #5678");
    msg4->type = strdup("Refund");

    // Adiciona mensagens à fila
    printf("Enfileirando mensagens...\n");
    enqueue(queue, msg1);
    processMessage(msg1);
    enqueue(queue, msg2);
    processMessage(msg2);
    enqueue(queue, msg3);
    processMessage(msg3);

    // Fila cheia: adiciona msg4, que substitui msg1 (mais antiga)
    printf("\nFila cheia! Adicionando nova mensagem (descarta a mais antiga)...\n");
    enqueue(queue, msg4);
    processMessage(msg4);

    // Processa todas as mensagens restantes
    printf("\nProcessando mensagens restantes...\n");
    while (!isEmpty(queue))
    {
        void *data = dequeue(queue);
        processMessage(data);
        free(((Message *)data)->content);
        free(((Message *)data)->type);
        free(data);
    }

    freeCircularQueue(queue);
    return 0;
}
