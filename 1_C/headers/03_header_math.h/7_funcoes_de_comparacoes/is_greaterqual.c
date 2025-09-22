#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isgreaterequal(): Verifica se o primeiro número de ponto flutuante é maior ou igual ao segundo.
 *
 * SINTAXE: #define isgreaterequal(x, y);
 *
 * @param x Primeiro valor de ponto flutuante para comparação.
 * @param y Segundo valor de ponto flutuante para comparação.
 *
 * @return Retorna um valor não zero (verdadeiro) se x for maior ou igual a y, caso contrário retorna
 * 0 (falso). Se qualquer um dos valores for NaN, retorna falso, pois NaN não é comparável com
 * outros números.
 *
 * @note A função lida corretamente com NaN e infinito. Retorna verdadeiro quando x >= y.
 */

/**
 * @brief Verifica se o primeiro número é maior ou igual ao segundo.
 *
 * @param _X Primeiro valor de ponto flutuante para comparação.
 * @param _Y Segundo valor de ponto flutuante para comparação.
 * @return `true` se `_X` é maior ou igual a `_Y`, `false` caso contrário.
 */
bool maiorIgual(double _X, double _Y)
{
    bool resultado = isgreaterequal(_X, _Y);
    printf(" %lf %s maior ou igual a %lf\n", _X, resultado ? "é" : "não é", _Y);
    return resultado;
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    maiorIgual(x, y);
    return 0;
}
