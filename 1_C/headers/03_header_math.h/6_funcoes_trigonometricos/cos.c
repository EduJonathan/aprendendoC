#include <stdio.h>
#include <math.h>

/**
 * cos(double _X): calcula o cosseno de um ângulo em radianos.
 *
 * SINTAXE: double cos(double _X);
 *
 * @param _X Valor a ser informado para calcular o cosseno
 * @return O cosseno de x.
 *
 * Parâmetro (x)	| valor do retorno
 * x = [-inf, +inf]	| [-1, +1]
 * x = 0		    | 1
 * x = inf		    | NaN (not a number)
 */

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo float.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo float.
 *
 * @note A função `cosf` é usada para calcular o cosseno de um ângulo em radianos do tipo float.
 */
float return_cosF(float x, const char *dataType)
{
    float cosF = cosf(x);
    printf("cosF(%f) = %f, retornando: %s\n", x, cosF, dataType);
    return cosF;
}

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo double.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo double.
 *
 * @note A função `cos` é usada para calcular o cosseno de um ângulo em radianos do tipo double.
 */
double return_cosD(double x, const char *dataType)
{
    double cosD = cos(x);
    printf("cosD(%lf) = %lf, retornando: %s\n", x, cosD, dataType);
    return cosD;
}

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo long double.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo long double.
 *
 * @note A função `cosl` é usada para calcular o cosseno de um ângulo em radianos do tipo long double.
 */
long double return_cosLD(long double x, const char *dataType)
{
    long double cosLD = cosl(x);
    printf("cosLD(%LF) = %LF, retornando: %s\n", x, cosLD, dataType);
    return cosLD;
}

int main(int argc, char **argv)
{
    float fcos = return_cosF(0.5F, "tipo float");
    double dcos = return_cosD(0.5, "tipo double");
    long double ldcos = return_cosLD(0.5L, "tipo long double");
    return 0;
}
