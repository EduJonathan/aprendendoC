#include <stdio.h>
#include <math.h>

/**
 * @brief Variável volátil - pode ser alterada de forma imprevisível
 *
 * O modificador 'volatile' informa ao compilador que esta variável pode ser alterada
 * por fatores externos ao fluxo normal do programa (hardware, interrupções, threads, etc.)
 * Isso previne otimizações que poderiam assumir que o valor não muda entre acessos.
 */

// Exemplo de uso do modificador 'volatile' em C
volatile int contador_sistema = 0;

/**
 * @brief Variável volátil - pode ser alterada por hardware externo
 *
 * Usada para simular um registrador de hardware ou variável compartilhada
 * que pode ser modificada assincronamente.
 */
volatile double sensor_value = 0.0;

/**
 * @brief Calcula a média móvel simples
 *
 * @param values Array de valores
 * @param n Número de elementos
 * @return Média dos valores
 *
 * Fórmula: SMA = (x₁ + x₂ + ... + xₙ) / n
 */
double simple_moving_average(volatile double *values, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += values[i]; // Acesso volátil - não será otimizado
    }
    return sum / n;
}

/**
 * @brief Calcula o valor RMS (Root Mean Square)
 *
 * @param values Array de valores
 * @param n Número de elementos
 * @return Valor RMS
 *
 * Fórmula: RMS = √((x₁² + x₂² + ... + xₙ²)/n)
 */
double root_mean_square(volatile double *values, int n)
{
    double sum_squares = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum_squares += values[i] * values[i];
    }
    return sqrt(sum_squares / n);
}

/**
 * @brief Filtro de suavização exponencial
 *
 * @param input Valor atual do sensor (volátil)
 * @param prev Valor anterior filtrado
 * @param alpha Fator de suavização (0 < α < 1)
 * @return Valor filtrado
 *
 * Fórmula: yₙ = αxₙ + (1-α)yₙ₋₁
 */
double exponential_smoothing(volatile double input, double prev, double alpha)
{
    return alpha * input + (1.0 - alpha) * prev;
}

int main(int argc, char **argv)
{
    /**
     * Situações típicas de uso para volatile:
     * 1. Registradores de hardware que mudam de valor
     * 2. Variáveis compartilhadas entre threads
     * 3. Variáveis modificadas em handlers de interrupção
     */

    // Simulando leituras de sensor voláteis
    volatile double sensor_readings[5] = {1.2, 1.4, 1.3, 1.5, 1.6};

    // 1. Cálculo da Média Móvel Simples
    double sma = simple_moving_average(sensor_readings, 5);
    printf("Média móvel simples: %.2f\n", sma);

    // 2. Cálculo do Valor RMS
    double rms = root_mean_square(sensor_readings, 5);
    printf("Valor RMS: %.2f\n", rms);

    // 3. Filtro de Suavização Exponencial
    double filtered = sensor_readings[0]; // Valor inicial
    for (int i = 1; i < 5; i++)
    {
        filtered = exponential_smoothing(sensor_readings[i], filtered, 0.3);
        printf("Leitura %d filtrada: %.2f\n", i, filtered);
    }

    // 4. Demonstração de variável volátil sendo modificada externamente
    volatile int hardware_counter = 0;
    printf("\nSimulando contador de hardware:\n");

    for (int i = 0; i < 5; i++)
    {
        // Em um sistema real, isso seria modificado por uma interrupção ou hardware
        hardware_counter++; // Simula incremento assíncrono

        // Fórmula: conversão para valor físico
        double physical_value = hardware_counter * 0.25; // Fator de escala
        printf("Contador: %d → Valor físico: %.2f\n", hardware_counter, physical_value);
    }

    // Simulação: o hardware pode modificar este contador a qualquer momento
    contador_sistema++; // O compilador não otimizará este acesso

    printf("--------------------------------------\n");

    printf("\nValor atual do contador volátil: %d\n", contador_sistema);

    // Exemplo de onde o volatile faz diferença:
    while (contador_sistema < 10)
    {
        // Sem volatile, o compilador poderia otimizar isso para um loop infinito
        // assumindo que contador_sistema nunca muda
    }

    return 0;
}
