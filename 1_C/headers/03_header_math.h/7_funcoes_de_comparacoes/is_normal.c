#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isnormal(): Verifica se um número de ponto flutuante é normal (não zero, subnormal, infinito ou NaN).
 *
 * SINTAXE: #define isnormal(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 *
 * @return Retorna um valor não zero (verdadeiro) se _X for um número normal,
 * caso contrário retorna 0 (falso).
 *
 * @note Um número é considerado normal se estiver dentro do intervalo de valores representáveis
 * e não for zero, subnormal, infinito ou NaN.
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
