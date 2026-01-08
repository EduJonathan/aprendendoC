#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

/**
 * @brief Representa um processo no escalonamento Round-Robin.
 */
typedef struct
{
    int id;              /**< Identificador único do processo */
    int burst_time;      /**< Tempo total necessário para execução */
    int remaining_time;  /**< Tempo restante de execução */
    int waiting_time;    /**< Tempo total de espera */
    int turnaround_time; /**< Tempo total do processo no sistema */
} Process;

/**
 * @brief Estrutura para passar múltiplos argumentos para a thread de escalonamento.
 */
typedef struct
{
    Process *processos; /**< Array de processos */
    int n;              /**< Número total de processos */
    int time_slice;     /**< Quantum de tempo para execução */
    int current_time;   /**< Tempo atual da simulação */
} SchedulerArgs;

// Variável global para controle de output
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 * @brief Função para imprimir com mutex (thread-safe)
 */
void safe_print(const char *message)
{
    pthread_mutex_lock(&print_mutex);
    printf("%s", message);
    pthread_mutex_unlock(&print_mutex);
}

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
    int current_time = 0;

    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "\n[Iniciando escalonamento Round-Robin]\n");
    safe_print(buffer);
    snprintf(buffer, sizeof(buffer), "Quantum: %d unidades de tempo\n", time_slice);
    safe_print(buffer);

    // Inicializar tempos de espera
    for (int i = 0; i < n; i++)
    {
        processos[i].waiting_time = 0;
        processos[i].turnaround_time = 0;
    }

    while (completed < n)
    {
        int all_idle = 1;

        for (int i = 0; i < n; i++)
        {
            if (processos[i].remaining_time > 0)
            {
                all_idle = 0;
                int exec_time = (processos[i].remaining_time > time_slice) ? time_slice : processos[i].remaining_time;

                snprintf(buffer, sizeof(buffer), "Tempo %d: Processo %d executando por %d unidades (restante: %d)\n",
                         current_time, processos[i].id, exec_time, processos[i].remaining_time - exec_time);

                safe_print(buffer);

                // Simula a execução do processo
                sleep(1);

                // Atualiza tempos
                current_time += exec_time;
                processos[i].remaining_time -= exec_time;

                // Atualiza tempos de espera para outros processos
                for (int j = 0; j < n; j++)
                {
                    if (j != i && processos[j].remaining_time > 0)
                    {
                        processos[j].waiting_time += exec_time;
                    }
                }

                if (processos[i].remaining_time == 0)
                {
                    processos[i].turnaround_time = current_time;
                    snprintf(buffer, sizeof(buffer), ">> Processo %d concluído (Turnaround: %d, Waiting: %d)\n", processos[i].id, processos[i].turnaround_time, processos[i].waiting_time);

                    safe_print(buffer);
                    completed++;
                }
            }
        }

        if (all_idle)
        {
            break;
        }
    }

    // Calcular estatísticas
    float avg_waiting = 0.0f, avg_turnaround = 0.0f;
    for (int i = 0; i < n; i++)
    {
        avg_waiting += processos[i].waiting_time;
        avg_turnaround += processos[i].turnaround_time;
    }
    avg_waiting /= n;
    avg_turnaround /= n;

    snprintf(buffer, sizeof(buffer), "\n[Escalonamento concluído]\n");
    safe_print(buffer);
    snprintf(buffer, sizeof(buffer), "Tempo total de execução: %d unidades\n", current_time);
    safe_print(buffer);
    snprintf(buffer, sizeof(buffer), "Tempo médio de espera: %.2f\n", avg_waiting);
    safe_print(buffer);
    snprintf(buffer, sizeof(buffer), "Tempo médio de turnaround: %.2f\n", avg_turnaround);
    safe_print(buffer);

    return NULL;
}

/**
 * @brief Função para exibir o resumo dos processos
 */
void display_process_summary(Process *processos, int n)
{
    printf("\n=== RESUMO DOS PROCESSOS ===\n");
    printf("PID\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n",
               processos[i].id,
               processos[i].burst_time,
               processos[i].waiting_time,
               processos[i].turnaround_time);
    }
}

int main(int argc, char **argv)
{
    int n = 0, time_slice = 0;

    printf("=== SIMULADOR ROUND-ROBIN ===\n\n");

    printf(">> Entre com o número de processos: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Erro: Número de processos inválido!\n");
        return 1;
    }

    if (n > 10)
    {
        printf("Aviso: Muitos processos podem causar demora na simulação.\n");
    }

    Process *processos = (Process *)malloc(n * sizeof(Process));
    if (processos == NULL)
    {
        printf("Erro: Falha na alocação de memória!\n");
        return 1;
    }

    printf(">> Digite o burst time para cada processo:\n");
    for (int i = 0; i < n; i++)
    {
        printf(">> Processo %d: ", i + 1);
        if (scanf("%d", &processos[i].burst_time) != 1 || processos[i].burst_time <= 0)
        {
            printf("Erro: Burst time inválido!\n");
            free(processos);
            return 1;
        }
        processos[i].id = i + 1;
        processos[i].remaining_time = processos[i].burst_time;
        processos[i].waiting_time = 0;
        processos[i].turnaround_time = 0;
    }

    printf(">> Insira o time slice (quantum): ");
    if (scanf("%d", &time_slice) != 1 || time_slice <= 0)
    {
        printf("Erro: Time slice inválido!\n");
        free(processos);
        return 1;
    }

    SchedulerArgs args;
    args.processos = processos;
    args.n = n;
    args.time_slice = time_slice;
    args.current_time = 0;

    printf("\nIniciando simulação...\n");

    pthread_t scheduler_thread;
    if (pthread_create(&scheduler_thread, NULL, round_robin, (void *)&args) != 0)
    {
        printf("Erro: Falha ao criar thread!\n");
        free(processos);
        return 1;
    }

    if (pthread_join(scheduler_thread, NULL) != 0)
    {
        printf("Erro: Falha ao aguardar thread!\n");
        free(processos);
        return 1;
    }

    // Exibir resumo final
    display_process_summary(processos, n);

    free(processos);
    pthread_mutex_destroy(&print_mutex);

    printf("\n=== SIMULAÇÃO CONCLUÍDA ===\n");
    return 0;

    // Para Compilar: gcc -Wall -Wextra -std=c17 -pthread -o round_robin 2_pthread.c
    // .\round_robin.exe

    /**
     * O tipo pthread_t é um tipo de dado usado na biblioteca POSIX Threads (pthreads)
     * para representar uma thread em sistemas Unix/Linux. Uma thread é a menor unidade
     * de execução dentro de um processo, compartilhando a mesma memória e recursos
     * do processo ao qual pertence, permitindo paralelismo, otimizando o desempenho
     * em tarefas concorrentes. Dentre eles, temos:
     *
     * pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg): Cria uma nova thread.
     *
     * pthread_join(pthread_t thread, void **retval): Aguarda uma thread terminar.
     *
     * pthread_exit(void *retval): Finaliza a thread atual.
     *
     * pthread_self(): Retorna o identificador da thread atual.
     * Dentre várias outras encontrada no #include <pthread.h>
     */
}
