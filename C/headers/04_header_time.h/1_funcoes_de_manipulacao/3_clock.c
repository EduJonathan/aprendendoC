#include <stdio.h>
#include <string.h>
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

#define MAX_N 1000

// Variáveis globais para contagem
int contador_recursivo = 0;
int contador_memoizado = 0;
unsigned long long cache[MAX_N]; // Usar unsigned long long para evitar overflow

void inicializar_cache()
{
    for (int i = 0; i < MAX_N; i++)
    {
        cache[i] = 0;
    }
}

// Versão recursiva pura
unsigned long long fatorial_recursivo(int n)
{
    contador_recursivo++;

    if (n <= 1)
        return 1;

    return n * fatorial_recursivo(n - 1);
}

// Versão iterativa
unsigned long long fatorial_iterativo(int n)
{
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

/**
 * @brief Calcula o fatorial de um número inteiro positivo usando memotização.
 *
 * Memoização (ou memoization): É uma técnica de otimização que armazena resultados de
 * chamadas caras de funções para reutilizá-los quando as mesmas entradas ocorrerem novamente,
 * evitando recálculos e reduzindo melhor a chamadas na recursão. É como um "cache" para funções.
 *
 * @param n O número inteiro positivo para o qual o fatorial será calculado.
 * @return O fatorial de n.
 */
// Versão com memoização
unsigned long long fatorial_memoizado(int n)
{
    contador_memoizado++;

    if (n <= 1)
        return 1;

    if (cache[n] != 0)
        return cache[n];

    cache[n] = n * fatorial_memoizado(n - 1);
    return cache[n];
}

void medir_tempo(unsigned long long (*funcao)(int), int n, const char *nome)
{
    // Reinicia contadores
    if (strcmp(nome, "Recursivo") == 0)
        contador_recursivo = 0;
    if (strcmp(nome, "Memoização") == 0)
    {
        contador_memoizado = 0;
        inicializar_cache();
    }

    clock_t inicio = clock();
    unsigned long long resultado = funcao(n);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 10000000;

    printf("\nMétodo: %s\n", nome);
    printf("Fatorial(%d) = %llu\n", n, resultado);
    printf("Tempo execução: %lf milissegundos\n", tempo_ms);

    if (strcmp(nome, "Recursivo") == 0)
        printf("Chamadas recursivas: %d\n", contador_recursivo);
    else if (strcmp(nome, "Memoização") == 0)
        printf("Chamadas recursivas: %d\n", contador_memoizado);
    else
        printf("Chamada iterativa (0)\n");
}

int main(int argc, char **argv)
{
    // Loop para mostrar números a cada 2 milissegundos
    for (int i = 0; i < 11; i++)
    {
        // Exibe o número
        printf("%d\n", i);

        // Chama a função delay_ms para introduzir um atraso de 2 milissegundos
        delay_ms(1000); // Atraso de 2000 milissegundos
    }

    printf("-----------------------\n");

    int n = 0;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Número inválido.\n");
        return 1;
    }

    medir_tempo(fatorial_recursivo, n, "Recursivo");
    medir_tempo(fatorial_iterativo, n, "Iterativo");
    medir_tempo(fatorial_memoizado, n, "Memoização");

    return 0;
}
