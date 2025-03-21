#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isunordered: Verifica se pelo menos um dos números é NaN.
 *
 * SINTAXE: #define isunordered(x, y);
 *
 * @param _X Primeiro valor de ponto flutuante a ser verificado.
 * @param _Y Segundo valor de ponto flutuante a ser verificado.
 */

/**
 * @brief Verifica se pelo menos um dos dois números é NaN (Not a Number).
 *
 * @param _X Primeiro valor de ponto flutuante a ser verificado.
 * @param _Y Segundo valor de ponto flutuante a ser verificado.
 * @return Retorna `true` se pelo menos um dos valores for NaN, e `false` caso contrário.
 */
bool isUnor(double _X, double _Y)
{
    if (isunordered(_X, _Y))
    {
        printf(" Um dos números é NaN\n");
        return true;
    }
    else
    {
        printf(" Nenhum dos números é NaN\n");
        return false;
    }
}

int main(int argc, char **argv)
{
    double x = 5.0, y = sqrt(-1.0);

    isUnor(x, y);
    return 0;
}
