#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
 * @brief Função executada pela primeira thread (task1).
 *
 * Realiza uma contagem de 1 a 5 e imprime na tela o valor da contagem.
 *
 * @param arg Ponteiro para dados adicionais (não utilizado, deve ser nulo). *
 * @return NULL (não retorna nenhum valor significativo).
 */
void *task1(void *arg)
{
    // Contagem de 1 a 5
    for (int i = 1; i <= 5; i++)
    {
        printf("Thread 1 - Contagem: %d\n", i);
    }

    // Encerra a execução da thread
    return NULL;
}

/**
 * @brief Função executada pela segunda thread (task2).
 *
 * Realiza uma contagem de 10 a 15 e imprime na tela o valor da contagem.
 *
 * @param arg Ponteiro para dados adicionais (não utilizado, deve ser nulo). *
 * @return NULL (não retorna nenhum valor significativo).
 */
void *task2(void *arg)
{
    // Contagem de 10 a 15
    for (int i = 10; i <= 15; i++)
    {
        printf("Thread 2 - Contagem: %d\n", i);
    }

    // Encerra a execução da thread
    return NULL;
}

// Cada função de thread utiliza pthread_exit(NULL) para encerrar sua execução.
int main(int argc, char **argv)
{
    // pthread_create: Cria as threads e atribui-lhes as funções associadas (task1 e task2).
    // pthread_join: espera das Threads Terminarem: Espera que cada thread termine sua execução.

    // Declaração das threads
    pthread_t thread1, thread2;

    // Verifica se a criação de cada thread foi bem-sucedida.
    if (pthread_create(&thread1, NULL, task1, NULL) != 0)
    {
        perror("Erro ao criar a thread 1\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, task2, NULL) != 0)
    {
        perror("Erro ao criar a thread 2\n");
        exit(EXIT_FAILURE);
    }

    // Verifica se a espera de cada thread foi bem-sucedida.
    if (pthread_join(thread1, NULL) != 0)
    {
        perror("Erro ao aguardar a thread 1\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        perror("Erro ao aguardar a thread 2\n");
        exit(EXIT_FAILURE);
    }

    printf("Programa principal Concluído.\n");

    /**
     * @note Caso você esteja executando seu programa e não funcionar aconselho
     * compilar e executar para melhor execução principalmente das threads.
     * Como compilar? No terminal
     *
     * "C:\Users\NomeDeSuaMaquina\Documents\aprendendoC\C\headers\07_header_pthreads.h>"
     * gcc -o philosopher philosopher.c -pthread
     */
    return 0;
}
