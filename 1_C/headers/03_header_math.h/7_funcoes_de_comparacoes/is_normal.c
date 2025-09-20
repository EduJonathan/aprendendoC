#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isnormal: verifica se um número de ponto flutuante é normal, o que significa que ele
 * não é zero, subnormal (denormal), infinito ou NaN (Not a Number).
 *
 * SINTAXE: #define isnormal(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 */

/**
 * @brief Verifica se um valor de ponto flutuante é um número normal.
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 * @return Retorna `true` se `_X` for um número normal, e `false` caso contrário.
 */
bool isAnormal(double _X)
{
    bool resultado = isnormal(_X);
    printf(" O valor %lf é normal? %s\n", _X, resultado ? "SIM" : "NÃO");
    return resultado;
}

int main(int argc, char **argv)
{
    double normalNumber = 42.0;
    double zero = 0.0;
    double subnormalNumber = 1.0e-308; // Um número subnormal

    isAnormal(normalNumber);
    isAnormal(zero);
    isAnormal(subnormalNumber);
    return 0;
}
