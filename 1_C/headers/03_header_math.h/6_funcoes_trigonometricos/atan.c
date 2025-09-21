#include <stdio.h>
#include <math.h>

/**
 * atan (double _X): calcula o arco tangente de um ângulo em radianos
 * tan-1(x) in range [-pi / 2, +pi / 2].
 *
 * SINTAXE: double atan(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco tangente
 * @return O arco tangente de x, no tipo double
 *
 * Parâmetro (x)    | valor do retorno
 * -------------------------------------
 * x = [-inf, +inf] | [-π / 2, +π / 2] em radianos
 * x = 0            | 0 em radianos
 * x = inf          | NaN (not a number)
 */

/**
 * @brief Calcula o arco tangente (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo float.
 *
 * @note A função `atanf` é usada para calcular o arco tangente de um número do tipo float.
 */
float return_atanF(float x, const char *dataType)
{
    float atanF = atanf(x);
    printf(" atanF(%f) = %f em radianos, retornando: %s\n", x, atanF, dataType);
    return atanF;
}

/**
 * @brief Calcula o arco tangente (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo double.
 *
 * @note A função `atan` é usada para calcular o arco tangente de um número do tipo double.
 */
double return_atanD(double x, const char *dataType)
{
    double atanD = atan(x);
    printf(" atanD(%lf) = %lf em radianos, retornando: %s\n", x, atanD, dataType);
    return atanD;
}

/**
 * @brief Calcula o arco tangente (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `atanl` é usada para calcular o arco tangente de um número do tipo long double.
 */
long double return_atanLD(long double x, const char *dataType)
{
    long double atanLD = atanl(x);
    printf(" atanLD(%LF) = %LF em radianos, retornando: %s\n", x, atanLD, dataType);
    return atanLD;
}

int main(int argc, char **argv)
{
    float fatan = return_atanF(0.5F, "tipo float");
    double datan = return_atanD(0.9, "tipo double");
    long double Ldatan = return_atanLD(0.7L, "tipo long double");
    return 0;
}
