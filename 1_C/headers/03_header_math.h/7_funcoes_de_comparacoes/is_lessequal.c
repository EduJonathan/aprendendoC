#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * islessequal(): Verifica se o primeiro número de ponto flutuante é menor ou igual ao segundo.
 *
 * SINTAXE: #define islessequal(x, y);
 *
 * @param x Primeiro valor de ponto flutuante para comparação.
 * @param y Segundo valor de ponto flutuante para comparação.
 *
 * @return Retorna um valor não zero (verdadeiro) se x for menor ou igual a y,
 * caso contrário retorna 0 (falso).
 *
 * @note Se qualquer valor for NaN, a comparação retorna falso, pois NaN não é comparável.
 */

/**
 * @brief Verifica se um valor é menor ou igual a outro.
 *
 * @param _X Valor de ponto flutuante a ser comparado.
 * @param _Y Valor de ponto flutuante com o qual `_X` é comparado.
 * @return Retorna true se `_X` for menor ou igual a `_Y` e false caso contrário.
 */
bool eMenorOuIgual(double _X, double _Y)
{
    bool resultado = islessequal(_X, _Y);
    printf(" %lf %s maior ou igual a %lf\n", _X, resultado ? "é" : "não é", _Y);
    return resultado;
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 5.0;
    eMenorOuIgual(x, y);

    double a = 5.0, b = 7.0;
    eMenorOuIgual(a, b);
    return 0;
}
