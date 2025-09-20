#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * ISNAN: é usada para verificar se um número de ponto flutuante é um NaN (Not a Number).
 * NaN é um valor especial que surge em operações indefinidas, como a tentativa de calcular a raiz
 * quadrada de um número negativo ou outras operações matemáticas inválidas.
 *
 * SINTAXE: #define isnan(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
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
