#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isgreater: Verifica se um número de ponto flutuante é estritamente maior que outro.
 *
 * SINTAXE: #define isgreater(x,y);
 *
 * @param _X Primeiro valor de ponto flutuante para comparação.
 * @param _Y Segundo valor de ponto flutuante para comparação.
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
    if (isgreater(_X, _Y))
    {
        printf(" x é maior que y\n");
        return true;
    }
    else
    {
        printf(" x não é maior que y\n");
        return false;
    }
}

int main(int argc, char **argv)
{
    double x = 5.0, y = 3.0;

    qualMaiorValor(x, y);
    return 0;
}
