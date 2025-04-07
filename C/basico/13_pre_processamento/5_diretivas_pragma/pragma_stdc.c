#include <stdio.h>
#include <complex.h>
#include <fenv.h>

/**
 * #pragma STDC FENV_ACCESS ON => Indica que a função precisa de acesso ao estado da FPU.
 * Isso pode ser útil ao trabalhar com exceções de ponto flutuante e arredondamento.
 *
 * #pragma STDC FENV_ACCESS OFF => Permite ao compilador otimizar expressões de ponto
 * flutuante livremente, assumindo que o estado da FPU não será alterado.
 *
 * Por que usar?
 * Em cálculos sensíveis, onde o estado da FPU afeta os resultados.
 * Para capturar e tratar erros de ponto flutuante corretamente.
 * Em sistemas embarcados que fazem cálculos numéricos críticos.
 */
#pragma STDC FENV_ACCESS ON

void testarPontoFlutuante()
{
    feclearexcept(FE_ALL_EXCEPT); // Limpa flags anteriores

    /*
     * Usamos volatile para evitar que o compilador otimize a operação e remova a divisão,
     * o que impediria o teste funcionar.
     */
    volatile double x = 0.0;
    volatile double y = 1.0 / x; // Aqui há divisão por zero (em tempo de execução)

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

/**
 * Controla a fusão de operações de ponto flutuante (ex: a * b + c → pode ser
 * fundido em uma instrução FMA). Com FP_CONTRACT ON, o compilador pode usar instruções
 * como FMA (fused multiply-add). Com OFF, cada operação é mantida separada, o que pode
 * preservar precisão em certas situações.
 */
#pragma STDC FP_CONTRACT OFF

double calcular(double a, double b, double c)
{
    return a * b + c; // Se FP_CONTRACT estiver ON, pode virar uma única instrução FMA
}

/**
 * Permite ao compilador assumir limites de intervalo ao otimizar expressões com números complexos.
 * Com ON, o compilador pode fazer otimizações assumindo que não há overflow/underflow em certas
 * partes dos números complexos.
 */
#pragma STDC CX_LIMITED_RANGE ON

int main(int argc, char **argv)
{
    testarPontoFlutuante();

    double r = calcular(1.5, 2.0, 3.0);
    printf("Resultado: %f\n", r);

    double complex z = 1.0 + 2.0 * I;
    double complex w = z * conj(z);
    printf("Resultado: %.2f + %.2fi\n", creal(w), cimag(w));
    return 0;
}
