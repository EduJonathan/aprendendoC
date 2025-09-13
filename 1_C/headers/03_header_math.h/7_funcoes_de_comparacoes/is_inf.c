#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * isinf: verifica se um valor é infinito.
 *
 * SINTAXE: #define isinf(x);
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 */

/**
 * @brief Verificando se o valor é infinito.
 *
 * @param _X Valor de ponto flutuante a ser verificado.
 * @return Nenhum valor retornado. Apenas imprime uma mensagem indicando se o valor é infinito ou não.
 */
bool eInfinito(double _X)
{
    if (isinf(_X))
    {
        printf(" O valor é infinito\n");
    }
    else
    {
        printf(" O valor não é infinito\n");
    }
}

int main(int argc, char **argv)
{
    double value = 1.0 / 0.0;

    eInfinito(value);
    return 0;
}
