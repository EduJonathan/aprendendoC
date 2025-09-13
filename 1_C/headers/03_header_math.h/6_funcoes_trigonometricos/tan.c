#include <stdio.h>
#include <math.h>

/**
 * tan (double _X): calcula a tangente de um ângulo em radianos.
 *
 * SINTAXE: double tan(double _X);
 *
 * @param _X Valor a ser informado para calcular a tangente
 * @return A tangente de x, no tipo double
 *
 * Parâmetro (x)	| valor do retorno
 * x = [-inf, +inf]	| [-1, +1]
 * x = 0		    | 0
 * x = inf		    | NaN (not a number)
 */

/**
 * @brief Calcula a tangente de um ângulo do tipo float.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo float.
 * 
 * @note A função `tanf` é usada para calcular a tangente de um número do tipo float.
 */
float return_tanF(float x, const char *dataType)
{
    float tanF = tanf(x);
    printf("tanF(%f) = %f, retornando: %s\n", x, tanF, dataType);
    return tanF;
}

/**
 * @brief Calcula a tangente de um ângulo do tipo double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo double.
 * 
 * @note A função `tan` é usada para calcular a tangente de um número do tipo double.
 */
double return_tanD(double x, const char *dataType)
{
    double tanD = tan(x);
    printf("tanD(%lf) = %lf, retornando: %s\n", x, tanD, dataType);
    return tanD;
}

/**
 * @brief Calcula a tangente de um ângulo do tipo long double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo long double.
 * 
 * @note A função `tanl` é usada para calcular a tangente de um número do tipo long double.
 */
long double return_tanLD(long double x, const char *dataType)
{
    long double tanLD = tanl(x);
    printf("tanLD(%LF) = %LF, retornando: %s\n", x, tanLD, dataType);
    return tanLD;
}

int main(int argc, char **argv)
{
    float ftan = return_tanF(0.5F, "tipo float");
    double dtan = return_tanD(0.5, "tipo double");
    long double ldtan = return_tanLD(0.5L, "tipo long double");
    return 0;
}
