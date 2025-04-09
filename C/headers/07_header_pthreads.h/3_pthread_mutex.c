#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

/**
 * Algoritmo de Escalonamento: First Come, First Served (FCFS) É um escalonador não preemptivo,
 * onde o processo que chega primeiro é executado primeiro. Neste código, utilizamos threads
 * para calcular os tempos de espera e de turnaround dos processos, e mutexes para proteger
 * a atualização das variáveis globais de tempo médio.
 * ------------------------------------------------------------
 * - O processo que chega primeiro é executado primeiro.
 * - Execução não preemptiva: um processo não pode ser interrompido antes de terminar.
 * - Simples de implementar, mas pode causar o "Convoy Effect"
 * (processos curtos esperando processos longos).
 * - Os tempos de espera e turnaround são calculados com base na ordem de chegada dos processos.
 * Cada processo é tratado por uma thread que calcula seu tempo de espera (WT) e turnaround (TAT).
 * Mutex é utilizado para sincronizar a atualização dos valores globais de tempo médio.
 */

/**
 * @struct thread_args
 * @brief Estrutura para passar os parâmetros e resultados para as threads.
 *
 * Esta estrutura contém os parâmetros necessários para calcular o tempo de espera (waiting time)
 * e de turnaround (turnaround time) dos processos em execução, além das variáveis globais que
 * mantêm os resultados acumulados.
 */
typedef struct
{
    int process_id;         /**< ID do processo */
    int *a;                 /**< Vetor de tempos de chegada */
    int *b;                 /**< Vetor de burst times */
    int *w;                 /**< Vetor de tempos de espera */
    int *t;                 /**< Vetor de tempos de turnaround */
    int *g;                 /**< Vetor de tempos de chegada acumulados */
    float *att;             /**< Acumulador do tempo de turnaround total */
    float *awt;             /**< Acumulador do tempo de espera total */
    pthread_mutex_t *mutex; /**< Mutex para proteger as atualizações das variáveis compartilhadas */
} thread_args;

/**
 * @brief Função para calcular o tempo de espera e o tempo de turnaround para um processo específico.
 *
 * Esta função é executada em cada thread e calcula os tempos de espera e de turnaround
 * para um processo, de acordo com o algoritmo FCFS. O tempo de chegada acumulado e o tempo de
 * execução são calculados com base no tempo de chegada do processo e no tempo de burst.
 *
 * @param args Ponteiro para a estrutura thread_args que contém os parâmetros necessários.
 * @return NULL
 */
void *calculate_times(void *args)
{
    thread_args *data = (thread_args *)args;
    int i = data->process_id;

    // Calcular o tempo de chegada (g[i]) e o tempo de espera (w[i])
    if (i == 0)
    {
        data->g[i] = data->a[i]; // O primeiro processo começa na sua chegada
    }
    else
    {
        data->g[i] = data->g[i - 1] + data->b[i - 1]; // Os outros começam após o processo anterior
    }

    // Tempo de espera = Tempo de chegada - Tempo de chegada do processo
    data->w[i] = data->g[i] - data->a[i];

    // Tempo de turnaround = Tempo de término - Tempo de chegada
    data->t[i] = data->g[i] + data->b[i] - data->a[i];

    // Protegendo as atualizações das variáveis globais
    pthread_mutex_lock(data->mutex);
    *data->awt += data->w[i];
    *data->att += data->t[i];
    pthread_mutex_unlock(data->mutex);
    return NULL;
}

int main(int argc, char **argv)
{
    int n,
        a[MAX_PROCESSES],
        b[MAX_PROCESSES],
        w[MAX_PROCESSES],
        t[MAX_PROCESSES],
        g[MAX_PROCESSES];

    pthread_t threads[MAX_PROCESSES];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    float att = 0, awt = 0;

    // Entrada de dados
    printf("Entre com número de processos: ");
    scanf("%d", &n);

    printf("Enter the burst times\n");
    for (int i = 0; i < n; i++)
    {
        printf(">> Insira o %d burst time: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the arrival times\n");
    for (int i = 0; i < n; i++)
    {
        printf(">> Insira o %d time arrival: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Criação das threads para calcular os tempos
    for (int i = 0; i < n; i++)
    {
        thread_args *args = (thread_args *)malloc(sizeof(thread_args));
        args->process_id = i;
        args->a = a;
        args->b = b;
        args->w = w;
        args->t = t;
        args->g = g;
        args->att = &att;
        args->awt = &awt;
        args->mutex = &mutex;

        // Criando a thread
        pthread_create(&threads[i], NULL, calculate_times, (void *)args);
    }

    // Aguardar todas as threads terminarem
    for (int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Calcular as médias
    awt /= n;
    att /= n;

    // Exibir os resultados
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\tP%d\t\t%d\t\t%d\n", i + 1, w[i], t[i]);
    }

    printf("\nThe average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    // Destruir o mutex
    pthread_mutex_destroy(&mutex);
    return 0;

    /**
     * @brief Funções principais do pthread_mutex_t:
     *
     * O pthread_mutex_t é um tipo de variável utilizado para implementar mutexes
     * (mutual exclusion, ou exclusão mútua) em programas multithreaded, que ajudam a
     * controlar o acesso concorrente a recursos compartilhados. Dentre ele, suas funções
     * principais são:
     *
     * - int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr): Inicializa
     * um mutex.
     *
     * - int pthread_mutex_destroy(pthread_mutex_t *mutex): Destrói o mutex.
     *
     * - int pthread_mutex_lock(pthread_mutex_t *mutex): Bloqueia o mutex
     * (aguarda até que ele esteja disponível).
     *
     * - int pthread_mutex_unlock(pthread_mutex_t *mutex): Libera o mutex, permitindo que
     * outras threads o acessem.
     *
     * - int pthread_mutex_trylock(pthread_mutex_t *mutex): Tenta bloquear o mutex sem
     * esperar, retornando imediatamente se não puder ser bloqueado.
     */
}
