#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Estrutura para representar um trabalho de impressão.
 *
 * Armazena informações sobre um trabalho de impressão, como tipo do documento,
 * número total de páginas, intervalo de páginas a imprimir e ponteiro para o próximo.
 */
typedef struct Trabalho
{
    char type[50];         /**< Tipo do documento (ex.: livro, pdf, foto). */
    int total_pages;       /**< Número total de páginas do documento. */
    int start_page;        /**< Página inicial a ser impressa. */
    int end_page;          /**< Página final a ser impressa. */
    struct Trabalho *next; /**< Ponteiro para o próximo trabalho na fila. */
} Tarefa;

/**
 * @brief Estrutura para representar a fila de impressão.
 *
 * Contém ponteiros para o início (frente) e o fim (trás) da fila de trabalhos.
 */
typedef struct Queue
{
    Tarefa *front; /**< Ponteiro para o trabalho na frente da fila. */
    Tarefa *rear;  /**< Ponteiro para o trabalho no final da fila. */
} Queue;

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

/**
 * @brief Inicializa a fila de impressão.
 *
 * Configura os ponteiros de frente e trás como NULL, indicando uma fila vazia.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
void initializeQueue(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    queue->front = NULL;
    queue->rear  = NULL;
}

/**
 * @brief Adiciona um trabalho à fila de impressão.
 *
 * Cria um novo trabalho com o tipo, número total de páginas e intervalo de impressão
 * especificados, adicionando-o ao final da fila.
 *
 * @param queue Ponteiro para a fila de impressão.
 * @param type Tipo do documento (ex.: livro, pdf, foto).
 * @param total_pages Número total de páginas do documento.
 * @param start_page Página inicial a ser impressa.
 * @param end_page Página final a ser impressa.
 * @return true se o trabalho foi adicionado com sucesso, false caso contrário.
 */
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
    newTarefa->total_pages                       = total_pages;
    newTarefa->start_page                        = start_page;
    newTarefa->end_page                          = end_page;
    newTarefa->next                              = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newTarefa;
        queue->rear  = newTarefa;
    }
    else
    {
        queue->rear->next = newTarefa;
        queue->rear       = newTarefa;
    }

    printf("Trabalho de impressão adicionado: %s (%d páginas)\n", newTarefa->type, total_pages);
    return true;
}

/**
 * @brief Imprime um intervalo de páginas do trabalho na frente da fila.
 *
 * Imprime as páginas do intervalo especificado (start_page até end_page) do trabalho
 * na frente da fila, simulando o tempo de impressão com sleep(2). Remove o trabalho após a impressão.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
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

/**
 * @brief Imprime todas as páginas do trabalho na frente da fila.
 *
 * Imprime todas as páginas do documento na frente da fila, simulando o tempo de impressão
 * com sleep(2). Remove o trabalho após a impressão.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
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

/**
 * @brief Libera toda a memória alocada para a fila de impressão.
 *
 * Desaloca todos os trabalhos da fila e a estrutura da fila.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
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
    queue->rear  = NULL;
}

int main(int argc, char **argv)
{
    Queue queue;
    initializeQueue(&queue);

    addTarefa(&queue, "Livro", 24, 12, 14);
    addTarefa(&queue, "PDF",   10, 1,  10);
    addTarefa(&queue, "Foto",  1,  1,  1);

    printInterval(&queue);
    printFull(&queue);

    freeQueue(&queue);
    return 0;
}
