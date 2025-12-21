#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "impressora.h"

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

void initializeQueue(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    queue->front = NULL;
    queue->rear = NULL;
}

bool addTarefa(Queue *queue, const char *type, int total_pages, int start_page, int end_page)
{
    if (queue == NULL || type == NULL || total_pages < 1 || start_page < 1 || end_page < start_page || end_page > total_pages)
    {
        printf("Erro: Parâmetros inválidos para o trabalho de impressão\n");
        return false;
    }

    Tarefa *newTarefa = malloc(sizeof(Tarefa));
    if (newTarefa == NULL)
    {
        printf("Erro ao alocar memória para o trabalho\n");
        return false;
    }

    strncpy(newTarefa->type, type, sizeof(newTarefa->type) - 1);
    newTarefa->type[sizeof(newTarefa->type) - 1] = '\0';
    newTarefa->total_pages = total_pages;
    newTarefa->start_page = start_page;
    newTarefa->end_page = end_page;
    newTarefa->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newTarefa;
        queue->rear = newTarefa;
    }
    else
    {
        queue->rear->next = newTarefa;
        queue->rear = newTarefa;
    }

    printf("Trabalho de impressão adicionado: %s (%d páginas)\n", newTarefa->type, total_pages);
    return true;
}

void printInterval(Queue *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        printf("Fila de impressão vazia!\n");
        return;
    }

    Tarefa *current = queue->front;
    printf("\nImprimindo: %s\n", current->type);
    for (int i = current->start_page; i <= current->end_page; i++)
    {
        printf("Imprimindo página %d...\n", i);
        sleep(2); // Simula tempo de impressão
    }
    printf("Impressão concluída!\n");

    queue->front = current->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(current);
}

void printFull(Queue *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        printf("Fila de impressão vazia!\n");
        return;
    }

    Tarefa *current = queue->front;
    printf("\nImprimindo documento completo: %s\n", current->type);
    for (int i = 1; i <= current->total_pages; i++)
    {
        printf("Imprimindo página %d...\n", i);
        sleep(2); // Simula tempo de impressão
    }
    printf("Impressão completa!\n");

    queue->front = current->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(current);
}

void freeQueue(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }

    Tarefa *current = queue->front;
    while (current != NULL)
    {
        Tarefa *next = current->next;
        free(current);
        current = next;
    }
    queue->front = NULL;
    queue->rear = NULL;
}
