#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isnan(): Verifica se um número de ponto flutuante é NaN (Not a Number).
 *
 * SINTAXE: #define isnan(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 * 
 * @return Retorna um valor não zero (verdadeiro) se _X for NaN, 
 * caso contrário retorna 0 (falso).
 *
 * @note NaN ocorre em operações indefinidas, como a tentativa de calcular a raiz quadrada de um número negativo.
 */


/**
 * @brief Verifica se um valor de ponto flutuante é um NaN (Not a Number).
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 * @return Retorna `true` se `_X` for NaN, e `false` caso contrário.
 */
bool eUmNumero(double _X)
{
    bool resultado = isnan(_X);
    printf(" O valor %lf é um NAN? %s\n", _X, resultado ? "SIM" : "NÃO");
    return resultado;
}

int main(int argc, char **argv)
{
    double regularNumber = 42.0;
    double notANumber = sqrt(-1.0); // Tentativa de calcular a raiz quadrada de um número negativo

    eUmNumero(regularNumber);
    eUmNumero(notANumber);
    return 0;
}
