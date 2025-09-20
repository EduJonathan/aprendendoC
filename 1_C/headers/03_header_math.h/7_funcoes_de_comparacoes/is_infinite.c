#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isinfinite: é usada para verificar se um número de ponto flutuante é infinito
 * (positivo ou negativo).
 *
 * SINTAXE: #define isinfinite(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 */

/**
 * @brief Verifica se o valor é infinito.
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 * @return Retorna true se o valor for infinito e false caso contrário.
 */
bool eInfinito(double _X)
{
    bool resultado = isfinite(_X);
    printf(" O valor %lf é infinito? %s\n", _X, resultado ? "SIM" : "NÃO");
    return resultado;
}

int main(int argc, char **argv)
{
    double finiteNumber = 42.0;
    double positiveInfinity = 1.0 / 0.0;  // Infinito positivo
    double negativeInfinity = -1.0 / 0.0; // Infinito negativo

    eInfinito(finiteNumber);
    eInfinito(positiveInfinity);
    eInfinito(negativeInfinity);
    return 0;
}
