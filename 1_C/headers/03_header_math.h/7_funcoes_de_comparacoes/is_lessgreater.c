#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * islessgreater: Verifica se o primeiro número é menor ou maior que o segundo.
 *
 * SINTAXE: #define islessgreater(x, y);
 *
 * @param x Primeiro valor de ponto flutuante para comparação.
 * @param y Segundo valor de ponto flutuante para comparação.
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
    if (islessgreater(_X, _Y))
    {
        printf(" %lf é menor ou maior que %lf\n", _X, _Y);
        return true;
    }
    else
    {
        printf(" %lf não é nem menor nem maior que %lf\n", _X, _Y);
        return false;
    }
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    isMenorOuMaior(x, y);
    return 0;
}
