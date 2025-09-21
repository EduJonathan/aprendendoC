#include <stdio.h>
#include <math.h>

/**
 * asin(double _X): calcula o arco seno de um ângulo em radianos
 *
 * SINTAXE: double asin(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco cosseno
 * @return O arco cosseno de x.
 *
 * Parâmetro (x)   | valor do retorno
 * -------------------------------------
 * x = [-1, +1]    | [-π / 2, +π / 2] in radianos
 * -1 > x or x > 1 | NaN (not a number)
 * x = 1           | 0 em radianos
 * x = 0           | 0 em radianos
 */

/**
 * @brief Calcula o arco seno (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo float.
 *
 * @note A função `asinf` é usada para calcular o arco seno de um número do tipo float.
 */
float return_asinF(float x, const char *dataType)
{
    float asinF = asinf(x);
    printf(" asinF(%f) = %f em radianos, retornando : %s\n", x, asinF, dataType);
    return asinF;
}

/**
 * @brief Calcula o arco seno (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo double.
 *
 * @note A função `asin` é usada para calcular o arco seno de um número do tipo double.
 */
double return_asinD(double x, const char *dataType)
{
    double asinD = asin(x);
    printf(" asinD(%lf) = %lf em radianos, retornando : %s\n", x, asinD, dataType);
    return asinD;
}

/**
 * @brief Calcula o arco seno (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `asinl` é usada para calcular o arco seno de um número do tipo long double.
 */
long double return_asinLD(long double x, const char *dataType)
{
    long double asinLD = asinl(x);
    printf(" asinLD(%LF) = %LF em radianos, retornando : %s\n", x, asinLD, dataType);
    return asinLD;
}

int main(int argc, char **argv)
{
    float facosx = return_asinF(0.5F, "tipo float");
    double dAcosX = return_asinD(0.9, "tipo double");
    long double Ldacosx = return_asinLD(0.7L, "tipo long double");
    return 0;
}
