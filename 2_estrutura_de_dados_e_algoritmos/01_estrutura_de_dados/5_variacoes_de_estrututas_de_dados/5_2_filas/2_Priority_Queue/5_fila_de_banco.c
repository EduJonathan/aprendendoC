#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct SenhaData
 * @brief Representa os dados de uma senha do banco.
 */
typedef struct
{
    char *senha; /**< Código da senha, ex.: "S121". */
    char *tipo;  /**< Tipo de cliente, ex.: "Normal" ou "Prioritário". */
} SenhaData;

/**
 * @struct Node
 * @brief Nó da fila de prioridade (lista duplamente encadeada).
 */
typedef struct node
{
    void *data;        /**< Ponteiro genérico para os dados armazenados. */
    int priority;      /**< Prioridade: maior valor = maior prioridade. */
    struct node *next; /**< Próximo nó na fila. */
    struct node *prev; /**< Nó anterior na fila. */
} Node;

/**
 * @struct PriorityQueue
 * @brief Estrutura que representa a fila de prioridade.
 */
typedef struct Priority_Queue
{
    Node *front; /**< Ponteiro para o primeiro nó (maior prioridade). */
    Node *rear;  /**< Ponteiro para o último nó (menor prioridade). */
    int size;    /**< Quantidade de elementos na fila. */
} PriorityQueue;

/**
 * @brief Cria uma fila de prioridade vazia.
 * @return Ponteiro para a nova PriorityQueue.
 */
PriorityQueue *createPriorityQueue()
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
    return pq;
}

/**
 * @brief Insere um elemento na fila de acordo com sua prioridade.
 * @param pq Ponteiro para a fila de prioridade.
 * @param data Ponteiro genérico para os dados a serem inseridos.
 * @param priority Valor da prioridade (maior = mais urgente).
 */
void enqueue(PriorityQueue *pq, void *data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (pq->size == 0)
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else if (priority > pq->front->priority)
    {
        newNode->next = pq->front;
        pq->front->prev = newNode;
        pq->front = newNode;
    }
    else
    {
        Node *current = pq->front;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        else
        {
            pq->rear = newNode;
        }
        current->next = newNode;
    }
    pq->size++;
}

/**
 * @brief Remove e retorna o elemento de maior prioridade da fila.
 * @param pq Ponteiro para a fila de prioridade.
 * @return Ponteiro genérico para os dados removidos, ou NULL se vazia.
 */
void *dequeue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Fila vazia!\n");
        return NULL;
    }

    Node *temp = pq->front;
    void *data = temp->data;

    pq->front = pq->front->next;
    if (pq->front != NULL)
    {
        pq->front->prev = NULL;
    }
    else
    {
        pq->rear = NULL;
    }

    free(temp);
    pq->size--;
    return data;
}

/**
 * @brief Libera toda a memória utilizada pela fila de prioridade.
 * @param pq Ponteiro para a fila a ser liberada.
 *
 * @note Esta função chama free() para cada elemento retornado por dequeue().
 *       Se os dados apontados por @c data também tiverem sido alocados
 *       dinamicamente, é responsabilidade do chamador garantir que a
 *       desalocação seja apropriada.
 */
void freePriorityQueue(PriorityQueue *pq)
{
    while (pq->size > 0)
    {
        free(dequeue(pq));
    }
    free(pq);
}

/**
 * @brief Imprime no console o estado atual da fila, da frente para o fim.
 * @param pq Ponteiro para a fila de prioridade.
 */
void printQueue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Fila vazia.\n");
        return;
    }
    Node *current = pq->front;
    printf("Fila atual (da frente para o fim):\n");
    while (current != NULL)
    {
        SenhaData *senha = (SenhaData *)current->data;
        printf("- Senha: %s (%s), Prioridade: %d\n",
               senha->senha, senha->tipo, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    PriorityQueue *filaBanco = createPriorityQueue();

    SenhaData s121 = {"S121", "Normal"};
    SenhaData s122 = {"S122", "Normal"};
    SenhaData p001 = {"P001", "Prioritário (Idoso/Gestante)"};

    printf("Adicionando senha S121 (normal, prioridade 0)...\n");
    enqueue(filaBanco, &s121, 0);
    printQueue(filaBanco);

    printf("Adicionando senha S122 (normal, prioridade 0)...\n");
    enqueue(filaBanco, &s122, 0);
    printQueue(filaBanco);

    printf("Atendendo S121...\n");
    SenhaData *atendida = (SenhaData *)dequeue(filaBanco);
    printf("Atendida: %s (%s)\n\n", atendida->senha, atendida->tipo);

    printf("Chega senha P001 (prioritário, prioridade 1)...\n");
    enqueue(filaBanco, &p001, 1);
    printQueue(filaBanco);

    printf("Atendendo próximo...\n");
    atendida = (SenhaData *)dequeue(filaBanco);
    printf("Atendida: %s (%s)\n\n", atendida->senha, atendida->tipo);

    printf("Atendendo próximo...\n");
    atendida = (SenhaData *)dequeue(filaBanco);
    printf("Atendida: %s (%s)\n\n", atendida->senha, atendida->tipo);

    freePriorityQueue(filaBanco);
    return 0;
}
