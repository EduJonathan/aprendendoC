#include <stdio.h>
#include <math.h>

/**
 * asinh(): calcula o arco seno hiperbólico de um ângulo em radianos.
 *
 * SINTAXE: double asinh(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco seno hiperbólico
 * @return O arco seno hiperbólico de x, no tipo double
 *
 * Parâmetro (x)	| valor do retorno
 * x = [-inf, +inf]	| [-π / 2, +π / 2] em radianos
 * -1 > x or x > 1	| NaN (not a number)
 */

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo float.
 * @note A função `asinhf` é usada para calcular o arcosseno hiperbólico de um número do tipo float.
 */
float return_asinhF(float x, const char *dataType)
{
    float asinhF = asinhf(x);
    printf(" asinhF(%f) = %f, retornando: %s\n", x, asinhF, dataType);
    return asinhF;
}

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo double.
 * @note A função `asinh` é usada para calcular o arcosseno hiperbólico de um número do tipo double.
 */
double return_asinhD(double x, const char *dataType)
{
    double asinhD = asinh(x);
    printf(" asinhD(%lf) = %lf, retornando: %s\n", x, asinhD, dataType);
    return asinhD;
}

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo long double.
 * @note A função `asinhl` é usada para calcular o arcosseno hiperbólico de um número do tipo
 * long double.
 */
long double return_asinhLD(long double x, const char *dataType)
{
    long double asinhLD = asinhl(x);
    printf(" asinhLD(%LF) = %LF, retornando: %s\n", x, asinhLD, dataType);
    return asinhLD;
}

int main(int argc, char **argv)
{
    float fasinh = return_asinhF(1.5F, "tipo float");
    double dasinh = return_asinhD(2.5, "tipo double");
    long double ldasinh = return_asinhLD(3.5L, "tipo long double");
    return 0;
}
