#include <stdio.h>
#include <math.h>

/**
 * sin(): calcula o seno de um ângulo em radianos.
 *
 * SINTAXE: float sin(float _X);
 *
 * @param _X Valor a ser informado para calcular o seno
 * @return O seno de x, no tipo float
 *
 * Parâmetro (x)    |	Valor do retorno
 * x = [-inf, +inf] | [-1, +1]
 * x = 0	        | 0
 * x = inf	        | NaN (not a number)
 */

/**
 * @brief Calcula o seno de um número do tipo float.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo float.
 *
 * @note A função `sinf` é usada para calcular o seno de um número do tipo float.
 */
float return_sinF(float x, const char *dataType)
{
    float sinF = sinf(x);
    printf("sinF(%f) = %f, retornando: %s\n", x, sinF, dataType);
    return sinF;
}

/**
 * @brief Calcula o seno de um número do tipo double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo double.
 *
 * @note A função `sin` é usada para calcular o seno de um número do tipo double.
 */
double return_sinD(double x, const char *dataType)
{
    double sinD = sin(x);
    printf("sinD(%lf) = %lf, retornando: %s\n", x, sinD, dataType);
    return sinD;
}

/**
 * @brief Calcula o seno de um número do tipo long double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo long double.
 *
 * @note A função `sinl` é usada para calcular o seno de um número do tipo long double.
 */
long double return_sinLD(long double x, const char *dataType)
{
    long double sinLD = sinl(x);
    printf("sinLD(%LF) = %LF, retornando: %s\n", x, sinLD, dataType);
    return sinLD;
}

int main(int argc, char **argv)
{
    float fsin = return_sinF(0.5F, "tipo float");
    double dsin = return_sinD(0.5, "tipo double");
    long double ldsin = return_sinLD(0.5L, "tipo long double");
    return 0;
}
