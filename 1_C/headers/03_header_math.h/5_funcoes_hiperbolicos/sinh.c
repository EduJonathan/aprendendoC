#include <stdio.h>
#include <math.h>

/**
 * sinh(double): calcula o seno hiperbólico de um ângulo em radianos.
 *
 * SINTAXE: double sinh(double _X);
 *
 * @param _X Valor a ser informado para calcular o seno hiperbólico
 * @return O seno hiperbólico de x, no tipo double
 *
 * Parâmetro (x) | Valor do retorno
 * -------------------------------------
 * x = [0, +inf] | [0, +inf]
 * x >= 1        | número maior ou igual a 1(em radianos)
 * x < 1         | NaN (not a number)
 */

/**
 * @brief Calcula o seno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo float.
 * @note A função `sinhf` é usada para calcular o seno hiperbólico de um número do tipo float.
 */
float return_sinhF(float x, const char *dataType)
{
    float sinhF = sinhf(x);
    printf("sinhF(%f) = %f, retornando: %s\n", x, sinhF, dataType);
    return sinhF;
}

/**
 * @brief Calcula o seno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo double.
 * @note A função `sinh` é usada para calcular o seno hiperbólico de um número do tipo double.
 */
double return_sinhD(double x, const char *dataType)
{
    double sinhD = sinh(x);
    printf("sinhD(%lf) = %lf, retornando: %s\n", x, sinhD, dataType);
    return sinhD;
}

/**
 * @brief Calcula o seno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo long double.
 * @note A função `sinhl` é usada para calcular o seno hiperbólico de um número do tipo long double.
 */
long double return_sinhLD(long double x, const char *dataType)
{
    long double sinhLD = sinhl(x);
    printf("sinhLD(%LF) = %LF, retornando: %s\n", x, sinhLD, dataType);
    return sinhLD;
}

int main(int argc, char **argv)
{
    float fsinh = return_sinhF(1.5F, "tipo float");
    double dsinh = return_sinhD(2.5, "tipo double");
    long double ldsinh = return_sinhLD(3.5L, "tipo long double");
    return 0;
}
