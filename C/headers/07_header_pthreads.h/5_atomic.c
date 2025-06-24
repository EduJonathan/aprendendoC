#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>

typedef struct Node
{
    int value;
    _Atomic(struct Node *) next;
} NODE;

typedef struct
{
    _Atomic(NODE *) head;
    _Atomic(NODE *) tail;
} LockFreeQueue;

void initQueue(LockFreeQueue *queue)
{
    NODE *dummy = malloc(sizeof(NODE));
    dummy->next = NULL;
    atomic_store(&queue->head, dummy);
    atomic_store(&queue->tail, dummy);
}

int enqueue(LockFreeQueue *queue, int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;

    NODE *oldTail;
    while (1)
    {
        oldTail = atomic_load(&queue->tail);
        NODE *next = atomic_load(&oldTail->next);
        if (next == NULL)
        {
            if (atomic_compare_exchange_weak(&oldTail->next, &next, newNode))
            {
                break;
            }
        }
        else
        {
            atomic_compare_exchange_weak(&queue->tail, &oldTail, next);
        }
    }
    atomic_compare_exchange_weak(&queue->tail, &oldTail, newNode);
    return 1;
}

int dequeue(LockFreeQueue *queue, int *value)
{
    NODE *oldHead;
    while (1)
    {
        oldHead = atomic_load(&queue->head);
        NODE *next = atomic_load(&oldHead->next);
        if (next == NULL)
        {
            return 0;
        }
        if (atomic_compare_exchange_weak(&queue->head, &oldHead, next))
        {
            *value = next->value;
            free(oldHead);
            return 1;
        }
    }
}

void *producer(void *q)
{
    LockFreeQueue *queue = (LockFreeQueue *)q;
    for (int i = 0; i < 3; i++)
    {
        enqueue(queue, i);
    }
    return NULL;
}

void *consumer(void *q)
{
    LockFreeQueue *queue = (LockFreeQueue *)q;
    int d;
    for (int i = 0; i < 3;)
    {
        if (dequeue(queue, &d))
        {
            printf("Dequeued: %d\n", d);
            i++;
        }
    }
    return NULL;
}

int main(int argc, char **argv)
{
    LockFreeQueue queue;
    initQueue(&queue);

    pthread_t p1, p2;
    pthread_create(&p1, NULL, producer, &queue);
    pthread_create(&p2, NULL, consumer, &queue);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    /**
     * Compile e execute este código com:
     * gcc -std=c11 -o nomeDoArquivo arquivo.c -lpthread
     *
     * Este exemplo demonstra uma fila lock-free (sem bloqueio) usando
     * operações atômicas. A fila é inicializada com um nó "dummy" (fictício)
     * e as operações de enfileiramento e desenfileiramento são realizadas
     * usando operações atômicas para garantir a segurança em um ambiente
     *
     * atomic: O tipo _Atomic é usado para declarar variáveis que podem ser acessadas
     * de múltiplas threads sem a necessidade de bloqueios explícitos. Ele garante
     * que as operações de leitura e escrita nessas variáveis sejam atômicas,
     * ou seja, não podem ser interrompidas por outras threads, evitando condições de corrida
     * e garantindo a consistência dos dados.
     * _Atomic é frequentemente usado em estruturas de dados lock-free, onde múltiplas threads
     * podem acessar e modificar os dados simultaneamente sem a necessidade de bloqueios.
     * Suas funções são criadas apartir de macros e são utilizadas para garantir que as
     * operações em variáveis atômicas sejam seguras em um ambiente concorrente.
     */
    return 0;
}
