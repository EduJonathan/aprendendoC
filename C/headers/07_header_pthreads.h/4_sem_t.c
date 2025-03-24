#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX 100 /**< Número máximo de filósofos */

/**
 * @brief Estrutura que representa um filósofo.
 *
 * Cada filósofo possui um identificador único, o número total de filósofos e os semáforos
 * que representam os garfos compartilhados entre os filósofos.
 */
typedef struct
{
    int id;            /**< Identificador único do filósofo */
    int n;             /**< Número total de filósofos */
    sem_t *chopsticks; /**< Semáforos representando os garfos */
} Philosopher;

/**
 * @brief Função que simula a ação de um filósofo pensando e comendo.
 *
 * O Problema dos Filósofos é um problema clássico de sincronização e concorrência.
 * O problema descreve uma situação em que vários filósofos sentam-se à mesa de jantar(circular) e 
 * alternam entre pensar e comer. Para comer, um filósofo precisa de dois garfos, mas os garfos são
 * compartilhados entre os filósofos, criando um problema de deadlock (interbloqueio) e
 * starvation (fome). O filósofo pega dois garfos, come e, em seguida, solta os garfos.
 * Isso é repetido 5 vezes. A função utiliza semáforos para garantir que os garfos sejam usados
 * de maneira segura.
 *
 * @param arg Ponteiro para a estrutura Philosopher contendo as informações do filósofo.
 * @return NULL
 */
void *thread_func(void *arg)
{
    Philosopher *philosopher = (Philosopher *)arg;
    int id = philosopher->id;
    int n = philosopher->n;
    sem_t *chopsticks = philosopher->chopsticks;

    for (int i = 0; i < 5; ++i)
    {
        // Pegando os garfos
        sem_wait(&chopsticks[id]);
        sem_wait(&chopsticks[(id + 1) % n]);

        printf("\nPhilosopher %d -> Começou a comer", id);
        sleep(1); // Simula o tempo comendo
        printf("\nPhilosopher %d -> Terminando de comer", id);

        // Liberando os garfos
        sem_post(&chopsticks[id]);
        sem_post(&chopsticks[(id + 1) % n]);

        sleep(1); // Simula o tempo pensando
    }

    return NULL;
}

int main(int argc, char **argv)
{
    int n;
    printf("\nEntre com a quantidade de filosofos: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Numero máximo excedido de filosofos!\n");
        return 1;
    }

    pthread_t threads[MAX];
    sem_t chopsticks[MAX];
    Philosopher philosophers[MAX];

    // Inicializa os semáforos (garfos disponíveis)
    for (int i = 0; i < n; ++i)
    {
        if (sem_init(&chopsticks[i], 0, 1) == -1)
        {
            perror("Semaphore initialization failed");
            exit(1);
        }
    }

    // Criando threads para os filósofos
    for (int i = 0; i < n; ++i)
    {
        philosophers[i].id = i;
        philosophers[i].n = n;
        philosophers[i].chopsticks = chopsticks;

        if (pthread_create(&threads[i], NULL, thread_func, &philosophers[i]) != 0)
        {
            perror("Thread creation failed");
            exit(1);
        }
    }

    // Esperando todas as threads terminarem
    for (int i = 0; i < n; ++i)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Thread join failed");
            exit(1);
        }
    }

    printf("\n\nTodos os filosofos terminaram de comer.\n");

    // Destruindo os semáforos
    for (int i = 0; i < n; ++i)
    {
        if (sem_destroy(&chopsticks[i]) == -1)
        {
            perror("Semaphore destruction failed");
            exit(1);
        }
    }

    /**
     * O tipo sem_t é um tipo de dado utilizado em programação concorrente para representar
     * semáforos, que são uma ferramenta de sincronização. Semáforos são frequentemente usados
     * para controlar o acesso a recursos compartilhados em sistemas multi-thread. Eles podem
     * ser binários (com valor 0 ou 1) ou contadores (que podem ter valores maiores), sendo
     * utilizados para coordenar a execução de threads. E suas funções:
     *
     * int sem_init(sem_t *sem, int pshared, unsigned int value): Inicializa um semáforo com
     * um valor inicial.
     *
     * int sem_wait(sem_t *sem): A thread bloqueia até que o semáforo esteja disponível
     * (valor > 0), diminuindo o valor do semáforo.
     *
     * int sem_post(sem_t *sem): Aumenta o valor do semáforo e, se houver threads bloqueadas,
     * uma delas será desbloqueada.
     *
     * int sem_destroy(sem_t *sem): Destrói o semáforo e libera seus recursos.
     *
     * Dentre outras
     */

    return 0;
}
