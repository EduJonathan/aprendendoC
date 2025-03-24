#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/**
 * @brief Representa um processo no escalonamento Round-Robin.
 */
typedef struct
{
    int id;             /**< Identificador único do processo */
    int burst_time;     /**< Tempo total necessário para execução */
    int remaining_time; /**< Tempo restante de execução */
} Process;

/**
 * @brief Estrutura para passar múltiplos argumentos para a thread de escalonamento.
 */
typedef struct
{
    Process *processos; /**< Array de processos */
    int n;              /**< Número total de processos */
    int time_slice;     /**< Quantum de tempo para execução */
} SchedulerArgs;

/**
 * @brief Função que implementa o algoritmo Round-Robin para escalonamento de processos.
 *
 * O Round-Robin é um algoritmo de escalonamento que distribui o tempo de CPU entre
 * os processos de forma equitativa, utilizando um quantum de tempo fixo (time slice).
 *
 * @param arg Ponteiro para a estrutura SchedulerArgs contendo os processos e parâmetros.
 * @return NULL após a execução do escalonador.
 */
void *round_robin(void *arg)
{
    SchedulerArgs *args = (SchedulerArgs *)arg;
    Process *processos = args->processos;
    int n = args->n;
    int time_slice = args->time_slice;
    int completed = 0;

    printf("\n[Iniciando escalonamento Round-Robin]\n");

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processos[i].remaining_time > 0)
            {
                int exec_time = (processos[i].remaining_time > time_slice) ? time_slice : processos[i].remaining_time;

                printf(">> Processo %d executando por %d unidades de tempo.\n", processos[i].id, exec_time);
                sleep(1); // Simula a execução do processo
                processos[i].remaining_time -= exec_time;

                if (processos[i].remaining_time == 0)
                {
                    printf(">> Processo %d concluído.\n", processos[i].id);
                    completed++;
                }
            }
        }
    }

    printf("\n[Escalonamento concluído]\n");
    return NULL;
}

int main(int argc, char **argv)
{
    int n = 0, time_slice = 0;

    printf(">> Entre com o número de processos: ");
    scanf("%d", &n);

    Process *processos = (Process *)malloc(n * sizeof(Process));

    printf(">> Digite o burst time para cada processo:\n");
    for (int i = 0; i < n; i++)
    {
        printf(">> Processo %d: ", i + 1);
        scanf("%d", &processos[i].burst_time);
        processos[i].id = i + 1;
        processos[i].remaining_time = processos[i].burst_time;
    }

    printf(">> Insira o time slice: ");
    scanf("%d", &time_slice);

    SchedulerArgs args;
    args.processos = processos;
    args.n = n;
    args.time_slice = time_slice;

    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, round_robin, (void *)&args);
    pthread_join(scheduler_thread, NULL);

    free(processos);
    return 0;

    /**
     * O tipo pthread_t é um tipo de dado usado na biblioteca POSIX Threads (pthreads)
     * para representar uma thread em sistemas Unix/Linux. Uma thread é a menor unidade
     * de execução dentro de um processo, compartilhando a mesma memória e recursos do processo
     * ao qual pertence, permitindo paralelismo, otimizando o desempenho em tarefas concorrentes.
     * Dentre eles, temos:
     *
     * pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg): Cria uma nova thread.
     * pthread_join(pthread_t thread, void **retval): Aguarda uma thread terminar.
     * pthread_exit(void *retval): Finaliza a thread atual.
     * pthread_self(): Retorna o identificador da thread atual.
     * Dentre várias outras encontrada no #include <pthread.h>
     */
}
