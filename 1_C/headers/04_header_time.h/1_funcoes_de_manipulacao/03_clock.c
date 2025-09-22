#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * clock(): Retorna o tempo de CPU consumido pelo programa, expresso em unidades de `clock_t`.
 * Esse valor representa o tempo de CPU utilizado desde o início da execução do programa.
 *
 * SINTAXE: clock_t clock(void);
 *
 * @return: Retorna um valor do tipo `clock_t`, representando o tempo de CPU consumido pelo
 *          programa em unidades de "clock ticks".
 *
 * @note Importante:
 * - O valor retornado pela função `clock()` é o número de "clock ticks" consumidos pela
 *   execução do programa até o momento da chamada.
 * 
 * - Para converter o valor de `clock_t` para segundos, use a constante `CLOCKS_PER_SEC`.
 * 
 * - A função mede o tempo de CPU, não o tempo real de execução do programa.
 */

/**
 * @brief Cria um atraso de aproximadamente um determinado número de milissegundos.
 *
 * Esta função utiliza a função `clock()` para criar um atraso que simula a espera
 * de um tempo específico em milissegundos. A precisão depende da implementação
 * de `clock()` no sistema e pode não ser exata em sistemas com alta carga de CPU.
 *
 * @param delay_ms O tempo de atraso desejado, em milissegundos.
 */
void delay_ms(unsigned delay_ms)
{
    clock_t start_time = 0, current_time = 0;

    // Marca o tempo de início
    start_time = clock();

    // Loop de espera até que o tempo de atraso tenha passado
    do
    {
        // Marca o tempo atual
        current_time = clock();
    } while (((current_time - start_time) * 1000 / CLOCKS_PER_SEC) < delay_ms);
}

int main(int argc, char **argv)
{
    // Loop para mostrar números a cada 2 milissegundos
    for (int i = 0; i < 11; i++)
    {
        // Exibe o número
        printf("%d\n", i);

        // Chama a função delay_ms para introduzir um atraso de 2 milissegundos
        delay_ms(2000); // Atraso de 2000 milissegundos
    }
    return 0;
}
