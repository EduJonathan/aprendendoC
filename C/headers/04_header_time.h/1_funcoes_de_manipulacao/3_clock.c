#include <stdio.h>
#include <time.h>

/**
 * clock(): Função da biblioteca de manipulação de tempo (time.h) que retorna o tempo de
 * CPU em clock_t.O clock_t serve para medir o tempo de CPU consumido por um programa,
 * mas o que você deseja é introduzir uma pausa ou atraso entre as execuções.
 *
 * SINTAXE: clock_t clock(void);
 * @return Retorna um valor de clock_t que representa o tempo de CPU em milissegundos.
 *
 * CLOCKS_PER_SEC: Constante da biblioteca time.h que representa o número de clocks por segundo.
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
    clock_t start_time, current_time;

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
