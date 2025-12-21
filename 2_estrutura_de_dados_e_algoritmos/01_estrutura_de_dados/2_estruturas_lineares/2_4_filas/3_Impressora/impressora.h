#ifndef PRINTER_QUEUE_H
#define PRINTER_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um trabalho de impressão.
 *
 * Armazena informações sobre um trabalho de impressão, como tipo do documento,
 * número total de páginas, intervalo de páginas a imprimir e ponteiro para o próximo.
 */
typedef struct Trabalho
{
    char type[50];    /**< Tipo do documento (ex.: livro, pdf, foto). */
    int total_pages;  /**< Número total de páginas do documento. */
    int start_page;   /**< Página inicial a ser impressa. */
    int end_page;     /**< Página final a ser impressa. */
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

/**
 * @brief Inicializa a fila de impressão.
 *
 * Configura os ponteiros de frente e trás como NULL, indicando uma fila vazia.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
void initializeQueue(Queue *queue);

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
bool addTarefa(Queue *queue, const char *type, int total_pages, int start_page, int end_page);

/**
 * @brief Imprime um intervalo de páginas do trabalho na frente da fila.
 *
 * Imprime as páginas do intervalo especificado (start_page até end_page) do trabalho
 * na frente da fila, simulando o tempo de impressão com sleep(2). Remove o trabalho após a impressão.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
void printInterval(Queue *queue);

/**
 * @brief Imprime todas as páginas do trabalho na frente da fila.
 *
 * Imprime todas as páginas do documento na frente da fila, simulando o tempo de impressão
 * com sleep(2). Remove o trabalho após a impressão.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
void printFull(Queue *queue);

/**
 * @brief Libera toda a memória alocada para a fila de impressão.
 *
 * Desaloca todos os trabalhos da fila e a estrutura da fila.
 *
 * @param queue Ponteiro para a fila de impressão.
 */
void freeQueue(Queue *queue);

#endif
