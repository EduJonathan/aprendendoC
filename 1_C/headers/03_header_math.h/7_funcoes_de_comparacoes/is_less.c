#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isless(): Verifica se o primeiro número de ponto flutuante é estritamente menor que o segundo.
 *
 * SINTAXE: #define isless(x, y);
 *
 * @param _X Primeiro valor de ponto flutuante para comparação.
 * @param _Y Segundo valor de ponto flutuante para comparação.
 *
 * @return Retorna um valor não zero (verdadeiro) se _X for estritamente menor que _Y,
 * caso contrário retorna 0 (falso).
 *
 * @note Se qualquer valor for NaN, a comparação retorna falso, pois NaN não é comparável.
 */

/**
 * @brief Verifica se o primeiro valor é estritamente menor que outro.
 *
 * @param _X Valor de ponto flutuante a ser comparado.
 * @param _Y Valor de ponto flutuante com o qual `_X` é comparado.
 * @return Retorna true se `_X` for estritamente menor que `_Y` e false caso contrário.
 */
bool eMenor(double _X, double _Y)
{
    bool resultado = isless(_X, _Y);
    printf(" %lf %s menor que %lf\n", _X, resultado ? "é" : "não é", _Y);
    return resultado;
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    eMenor(x, y);
    return 0;
}
