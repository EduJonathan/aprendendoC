#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    clock_t cpu_inicio = clock();
    time_t real_inicio = 0;
    time(&real_inicio);

    // trecho que iremos calcular o tempo de trabalho + wait
    for (int i = 0; i < 1000000; i++); // CPU-bound
    sleep(1); // Espera 1 segundo (I/O)

    // Contabiliza o tempo de CPU
    printf("TEMPO DE CPU %6.2f segundos\n", (double)(clock() - cpu_inicio) / CLOCKS_PER_SEC);

    // Contabiliza o tempo real (incluindo o tempo de espera)
    printf("TEMPO REAL: %.2f segundos", difftime(time(NULL), real_inicio));

    /**
     * Clock é utilizado para medir o tempo de CPU(calculos intensivos), tendo uma precisão
     * mais alta, exemplo se o programa ficar esperando um input como scanf, esse tempo não 
     * será contabilizado entre, graças a CPU-bound. A CPU-bound é um tipo de operação que 
     * utiliza apenas a CPU para realizar cálculos, sem depender de outros recursos como disco 
     * ou rede.
     *
     * Enquanto o time_t é utilizado para medir o tempo real (incluindo o I/O/waits),
     * tendo uma precisão menor de cerca de 1 segundo.
     * "I" -> input, "O" -> output, "waits" são períodos de inatividade onde o processo
     * não está usando a CPU (Exe.: esperando por I/O).
     */
    return 0;
}
