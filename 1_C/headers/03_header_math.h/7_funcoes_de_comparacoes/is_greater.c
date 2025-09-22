#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isgreater(): Verifica se um número de ponto flutuante é estritamente maior que outro.
 *
 * SINTAXE: #define isgreater(x, y);
 *
 * @param _X O primeiro número de ponto flutuante a ser comparado.
 * @param _Y O segundo número de ponto flutuante a ser comparado.
 *
 * @return Retorna um valor não zero (verdadeiro) se _X for maior que _Y, caso contrário retorna 0 (falso).
 *         Se qualquer um dos valores for NaN, retorna falso, pois NaN não é comparável.
 *
 * @note A função lida corretamente com NaN e infinito. A comparação retorna verdadeiro apenas quando _X > _Y.
 */

/**
 * @brief Verifica se um número de ponto flutuante é estritamente maior que outro.
 *
 * @param _X Primeiro valor de ponto flutuante para comparação.
 * @param _Y Segundo valor de ponto flutuante para comparação.
 * @return `true` se `_X` é maior que `_Y`, `false` caso contrário.
 */
bool qualMaiorValor(double _X, double _Y)
{
    bool resultado = isgreater(_X, _Y);
    printf(" %lf %s maior que %lf\n", _X, resultado ? "é" : "não é", _Y);
    return resultado;
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    qualMaiorValor(x, y);
    return 0;
}
