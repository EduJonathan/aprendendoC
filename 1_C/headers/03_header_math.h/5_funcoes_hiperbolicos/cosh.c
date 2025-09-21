#include <stdio.h>
#include <math.h>

/**
 * cosh(double): calcula o cosseno hiperbólico de um ângulo em radianos.
 *
 * SINTAXE: double cosh(double _X);
 * @param _X Valor a ser informado para calcular o cosseno hiperbólico
 * @return O cosseno hiperbólico de x, no tipo double
 *
 * Parâmetro (x) | Valor do retorno
 * -------------------------------------
 * x = [0, +inf] | [1, +inf]
 * x >= 1        | número maior ou igual a 1(em radianos)
 * x < 1         | NaN (not a number)
 */

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo float.
 *
 * @note A função `coshf` é usada para calcular o cosseno hiperbólico de um número do tipo float.
 */
float return_coshF(float x, const char *dataType)
{
    float coshF = coshf(x);
    printf(" coshF(%f) = %f, retornando: %s\n", x, coshF, dataType);
    return coshF;
}

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo double.
 *
 * @note A função `cosh` é usada para calcular o cosseno hiperbólico de um número do tipo double.
 */
double return_coshD(double x, const char *dataType)
{
    double coshD = cosh(x);
    printf(" coshD(%lf) = %lf, retornando: %s\n", x, coshD, dataType);
    return coshD;
}

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo long double.
 *
 * @note A função `coshl` é usada para calcular o cosseno hiperbólico de um número do tipo
 * long double.
 */
long double return_coshLD(long double x, const char *dataType)
{
    long double coshLD = coshl(x);
    printf(" coshLD(%LF) = %LF, retornando: %s\n", x, coshLD, dataType);
    return coshLD;
}

int main(int argc, char **argv)
{
    float fcosh = return_coshF(2.0F, "tipo float");
    double dcosh = return_coshD(3.0, "tipo double");
    long double ldcosh = return_coshLD(4.0L, "tipo long double");
    return 0;
}
