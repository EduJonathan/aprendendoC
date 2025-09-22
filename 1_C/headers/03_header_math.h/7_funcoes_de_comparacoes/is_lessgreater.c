#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * islessgreater(): Verifica se o primeiro número de ponto flutuante é estritamente menor ou maior que o segundo.
 *
 * SINTAXE: #define islessgreater(x, y);
 *
 * @param x Primeiro valor de ponto flutuante para comparação.
 * @param y Segundo valor de ponto flutuante para comparação.
 *
 * @return Retorna um valor não zero (verdadeiro) se x for estritamente menor ou maior que y,
 * caso contrário retorna 0 (falso).
 *
 * @note Se qualquer valor for NaN, a comparação retorna falso, pois NaN não é comparável.
 */

/**
 * @brief Verifica se um valor é estritamente menor ou maior que outro.
 *
 * @param _X Valor de ponto flutuante a ser comparado.
 * @param _Y Valor de ponto flutuante com o qual `_X` é comparado.
 * @return Retorna true se `_X` for estritamente menor ou maior que `_Y`, e false caso contrário.
 */
bool isMenorOuMaior(double _X, double _Y)
{
    bool resultado = islessgreater(_X, _Y);
    printf(" %lf %s menor ou maior que %lf\n", _X, resultado ? "é" : "não é", _Y);
    return resultado;
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    isMenorOuMaior(x, y);
    return 0;
}
