#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t inicio, fim;
    time(&inicio); // Marca o início(tempo real)

    // Medindo tempo de um simples "olá mundo"
    printf("Olá, mundo");

    time(&fim); // Marca o fim(tempo real)

    // Dependendo da carga do sistema e da velocidade do processador, o tempo pode ser quase zero.
    printf("Tempo real : %lf segundos\n", difftime(fim, inicio));

    printf("---------------------------------------------");

    time_t start, end;
    time(&start); // Marca o início (tempo real)

    // Laço for para realizar uma tarefa repetitiva
    long sum = 0l;
    for (long i = 0; i < 1000000000; i++)
    {
        sum += i; // Soma simples
    }

    time(&end); // Marca o fim (tempo real)

    // Imprime o resultado e o tempo real de execução
    printf("\nSoma final: %ld\n", sum);
    printf("Tempo real: %lf segundos\n", difftime(end, start));
    return 0;
}
