#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

/**
 * @struct ThreadParams
 *
 * @brief Estrutura para passar parâmetros para as threads
 */
typedef struct
{
    int id;           ///< ID da thread
    int problem_size; ///< Tamanho do problema a ser resolvido
    double *result;   ///< Ponteiro para armazenar o resultado do cálculo
} ThreadParams;

/**
 * @brief Calcula o tempo decorrido entre duas marcações de tempo
 *
 * @param start Tempo de início (struct timespec)
 * @param end Tempo de fim (struct timespec)
 * @return double Tempo decorrido em segundos
 */
double get_elapsed_time(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

/**
 * @brief Função O(1) - Tempo constante
 *
 * @param arg Ponteiro para ThreadParams
 * @return void* NULL
 *
 * Esta função executa uma operação com complexidade de tempo constante,
 * independente do tamanho da entrada.
 */
void *constant_time(void *arg)
{
    ThreadParams *params = (ThreadParams *)arg;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    *(params->result) = sqrt(params->problem_size) * 2.0;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = get_elapsed_time(start, end);

    printf("[Thread %d] O(1): size=%d, result=%.2f, time=%.6f sec\n",
           params->id, params->problem_size, *(params->result), elapsed);

    return NULL;
}

/**
 * @brief Função O(log n) - Tempo logarítmico
 *
 * @param arg Ponteiro para ThreadParams
 * @return void* NULL
 *
 * Esta função executa uma operação com complexidade de tempo logarítmico,
 * onde o tempo cresce proporcionalmente ao logaritmo do tamanho da entrada.
 */
void *logarithmic_time(void *arg)
{
    ThreadParams *params = (ThreadParams *)arg;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    double sum = 0.0;
    for (int i = 1; i <= params->problem_size; i *= 2)
    {
        sum += log(i + 1);
    }
    *(params->result) = sum;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = get_elapsed_time(start, end);

    printf("[Thread %d] O(log n): size=%d, result=%.2f, time=%.6f sec\n",
           params->id, params->problem_size, *(params->result), elapsed);

    return NULL;
}

/**
 * @brief Função O(n) - Tempo linear
 *
 * @param arg Ponteiro para ThreadParams
 * @return void* NULL
 *
 * Esta função executa uma operação com complexidade de tempo linear,
 * onde o tempo cresce proporcionalmente ao tamanho da entrada.
 */
void *linear_time(void *arg)
{
    ThreadParams *params = (ThreadParams *)arg;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    double sum = 0.0;
    for (int i = 0; i < params->problem_size; i++)
    {
        sum += log(i + 1);
    }
    *(params->result) = sum;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = get_elapsed_time(start, end);

    printf("[Thread %d] O(n): size=%d, result=%.2f, time=%.6f sec\n",
           params->id, params->problem_size, *(params->result), elapsed);

    return NULL;
}

/**
 * @brief Função O(n log n) - Tempo log-linear
 *
 * @param arg Ponteiro para ThreadParams
 * @return void* NULL
 *
 * Esta função executa uma operação com complexidade de tempo log-linear,
 * comum em algoritmos eficientes de ordenação como Merge Sort.
 */
void *loglinear_time(void *arg)
{
    ThreadParams *params = (ThreadParams *)arg;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    double sum = 0.0;
    for (int i = 0; i < params->problem_size; i++)
    {
        for (int j = 1; j <= params->problem_size; j *= 2)
        {
            sum += i * j;
        }
    }
    *(params->result) = sum;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = get_elapsed_time(start, end);

    printf("[Thread %d] O(n log n): size=%d, result=%.2f, time=%.6f sec\n",
           params->id, params->problem_size, *(params->result), elapsed);

    return NULL;
}

/**
 * @brief Função O(n²) - Tempo quadrático
 *
 * @param arg Ponteiro para ThreadParams
 * @return void* NULL
 *
 * Esta função executa uma operação com complexidade de tempo quadrático,
 * comum em algoritmos com loops aninhados.
 */
void *quadratic_time(void *arg)
{
    ThreadParams *params = (ThreadParams *)arg;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    double sum = 0.0;
    for (int i = 0; i < params->problem_size; i++)
    {
        for (int j = 0; j < params->problem_size; j++)
        {
            sum += i * j;
        }
    }
    *(params->result) = sum;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = get_elapsed_time(start, end);

    printf("[Thread %d] O(n^2): size=%d, result=%.2f, time=%.6f sec\n",
           params->id, params->problem_size, *(params->result), elapsed);

    return NULL;
}

/**
 * Este programa cria múltiplas threads para demonstrar diferentes complexidades
 * de algoritmos (O(1), O(log n), O(n), O(n log n), O(n²)) e mede seus tempos
 * de execução.
 */
int main(int argc, char **argv)
{
    const int NUM_THREADS = 5;
    const int BASE_SIZE = 1000;

    pthread_t threads[NUM_THREADS];
    ThreadParams params[NUM_THREADS];
    double results[NUM_THREADS];

    printf("Iniciando análise multithread com diferentes complexidades...\n\n");

    // Configuração dos parâmetros para cada thread
    params[0] = (ThreadParams){1, BASE_SIZE, &results[0]};
    params[1] = (ThreadParams){2, BASE_SIZE * 2, &results[1]};
    params[2] = (ThreadParams){3, BASE_SIZE * 2, &results[2]};
    params[3] = (ThreadParams){4, BASE_SIZE * 2, &results[3]};
    params[4] = (ThreadParams){5, BASE_SIZE / 2, &results[4]}; // Menor para O(n^2)

    // Criação das threads
    pthread_create(&threads[0], NULL, constant_time, &params[0]);
    pthread_create(&threads[1], NULL, logarithmic_time, &params[1]);
    pthread_create(&threads[2], NULL, linear_time, &params[2]);
    pthread_create(&threads[3], NULL, loglinear_time, &params[3]);
    pthread_create(&threads[4], NULL, quadratic_time, &params[4]);

    // Espera todas as threads terminarem
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nTodas as threads terminaram.\n");

    /**
     * Utilize gcc -o <nome_do_executavel> bigO.c -lpthread -lm para compilar
     * .\nome_do_executavel.exe
     */
    return 0;
}
