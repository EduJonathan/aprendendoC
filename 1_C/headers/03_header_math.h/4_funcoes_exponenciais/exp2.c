#include <stdio.h>
#include <math.h>

/**
 * exp2(): calcula o exponencial com base 2.
 *
 * SINTAXE: double exp2(double _X);
 *
 * @param _X Número para o qual calcular o exponencial com base 2.
 * @return O exponencial com base 2 de _X.
 */

/**
 * @brief Calcula o exponencial base 2 de x para tipo float.
 *
 * Esta função calcula \(2^x\) para valores do tipo float utilizando a função `exp2f`.
 *
 * @param x Valor para o qual calcular o exponencial base 2.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial base 2 de x, arredondado para o tipo float.
 *
 * @note A função `exp2f` é usada para calcular o exponencial base 2 de um número do tipo float.
 */
float return_exp2F(float x, const char *dataType)
{
    float exp2F = exp2f(x);
    printf(" exp2F(%f) = %f, retornando: %s\n", x, exp2F, dataType);
    return exp2F;
}

/**
 * @brief Calcula o exponencial base 2 de x para tipo double.
 *
 * Esta função calcula \(2^x\) para valores do tipo double utilizando a função `exp2`.
 *
 * @param x Valor para o qual calcular o exponencial base 2.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial base 2 de x, arredondado para o tipo double.
 *
 * @note A função `exp2` é usada para calcular o exponencial base 2 de um número do tipo double.
 */
double return_exp2D(double x, const char *dataType)
{
    double exp2D = exp2(x);
    printf(" exp2D(%lf) = %lf, retornando: %s\n", x, exp2D, dataType);
    return exp2D;
}

/**
 * @brief Calcula o exponencial base 2 de x para tipo long double.
 *
 * Esta função calcula \(2^x\) para valores do tipo long double utilizando a função `exp2l`.
 *
 * @param x Valor para o qual calcular o exponencial base 2.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial base 2 de x, arredondado para o tipo long double.
 *
 * @note A função `exp2l` é usada para calcular o exponencial base 2 de um número do tipo long double.
 */
long double return_exp2LD(long double x, const char *dataType)
{
    long double exp2LD = exp2l(x);
    printf(" exp2LD(%Lf) = %Lf, retornando: %s\n", x, exp2LD, dataType);
    return exp2LD;
}

int main(int argc, char **argv)
{
    float fexp2 = return_exp2F(2.0F, "tipo float");
    double dexp2 = return_exp2D(3.0, "tipo double");
    long double ldexp2 = return_exp2LD(1.5L, "tipo long double");
    return 0;
}
