#include <stdio.h>
#include <complex.h>
#include <fenv.h>

/**
 * Diretivas de ponto flutuante do padrão C:
 *
 * 1. #pragma STDC FENV_ACCESS:
 * - ON: Indica que o código acessa/modifica o ambiente de ponto flutuante (FPU), como flags
 *   de exceções (FE_DIVBYZERO, FE_OVERFLOW) ou modos de arredondamento. Desativa otimizações
 *   que poderiam ignorar o estado da FPU.
 * - OFF: Permite otimizações livres, assumindo que o estado da FPU não é alterado.
 * - Uso: Cálculos sensíveis (ex.: sistemas embarcados, simulações numéricas) onde o estado
 *   da FPU afeta resultados.
 * - Suporte: Padrão C (C99/C11/C17/C23), suportado por MSVC, GCC, Clang.
 * - Flags recomendadas: -frounding-math, -fexceptions (GCC); /fp:strict (MSVC).
 *
 * 2. #pragma STDC FP_CONTRACT:
 * - ON: Permite fusão de operações de ponto flutuante (ex.: a * b + c) em uma instrução FMA
 *   (*fused multiply-add*), aumentando eficiência, mas podendo reduzir precisão.
 * - OFF: Mantém operações separadas, preservando precisão.
 * - Uso: Controle de precisão vs. desempenho em cálculos numéricos.
 * - Suporte: Padrão C, suportado por MSVC, GCC, Clang.
 * - Flags: -mfma (GCC) habilita FMA; -ffp-contract=fast|on|off controla fusão.
 *
 * 3. #pragma STDC CX_LIMITED_RANGE:
 * - ON: Permite otimizações em números complexos assumindo intervalos limitados, evitando
 *   verificações de overflow/underflow.
 * - OFF: Cálculos conservadores, sem suposições de intervalo.
 * - Uso: Otimizar operações com números complexos em aplicações numéricas.
 * - Suporte: Padrão C, suportado por MSVC, GCC, Clang.
 *
 * Boas práticas:
 * - Use FENV_ACCESS ON apenas em blocos onde o estado da FPU é necessário.
 * - Use FP_CONTRACT OFF para máxima precisão em cálculos críticos.
 * - Use CX_LIMITED_RANGE ON apenas quando os valores complexos estão em intervalos seguros.
 * - Teste com flags como -frounding-math (GCC) ou /fp:strict (MSVC) para conformidade.
 *
 * Compilação:
 * - GCC: gcc -std=c17 -Wall -mfma -frounding-math -fexceptions -o programa pragma-stdc.c
 * - MSVC: cl /fp:strict pragma_stdc.c
 * - Depuração: gcc -E pragma_stdc.c (verifica pré-processamento)
 */

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif
#pragma STDC FENV_ACCESS ON

void testarPontoFlutuante(void)
{
    feclearexcept(FE_ALL_EXCEPT); // Limpa flags de exceções

    volatile double x = 0.0;
    volatile double y = 1.0 / x; // Divisão por zero

    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Divisão por zero detectada!\n");
    }
    if (fetestexcept(FE_OVERFLOW))
    {
        printf("Overflow detectado!\n");
    }
    if (fetestexcept(FE_INVALID))
    {
        printf("Operação inválida detectada!\n");
    }
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#pragma STDC FP_CONTRACT OFF

double calcular(double a, double b, double c)
{
    return a * b + c; // Operações separadas, sem FMA
}

#pragma STDC CX_LIMITED_RANGE ON

int main(int argc, char **argv)
{
    testarPontoFlutuante();

    double r = calcular(1.5, 2.0, 3.0);
    printf("Resultado: %.1f\n", r);

    double complex z = 1.0 + 2.0 * I;
    double complex w = z * conj(z); // |z|^2 = 1^2 + 2^2 = 5
    printf("Resultado complexo: %.2f + %.2fi\n", creal(w), cimag(w));

    return 0;
}
