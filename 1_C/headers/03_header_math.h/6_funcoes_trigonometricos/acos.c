#include <stdio.h>
#include <math.h>

/**
 * acos(double _X): Calcula o arco cosseno de um ângulo em radianos.
 *
 * SINTAXE: double acos(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco cosseno
 * @return O arco cosseno de x.
 *
 * Parâmetros (x)   | valor do retorno
 * -------------------------------------
 * x = [-1, +1]     | [-π / 2, +π / 2] em radianos
 * -1 > x or x > 1  | NaN (not a number)
 * x = 1            | 0 em radianos
 * x = 0            | 0 em radianos
 * x = -1           | π em radianos
 */

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo float.
 *
 * @note A função `acosf` é usada para calcular o arco cosseno de um número do tipo float.
 */
float return_acosf(float x, const char *dataType)
{
    float acosF = acosf(x);
    printf(" acosf(%f) = %f em radianos, retornando : %s\n", x, acosF, dataType);
    return acosF;
}

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo double.
 *
 * @note A função `acos` é usada para calcular o arco cosseno de um número do tipo double.
 */
double return_acosD(double x, const char *dataType)
{
    double acosD = acos(x);
    printf(" acosD(%lf) = %lf em radianos, retornando : %s\n", x, acosD, dataType);
    return acosD;
}

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `acosl` é usada para calcular o arco cosseno de um número do tipo long double.
 */
long double return_acosLD(long double x, const char *dataType)
{
    long double acosLD = acosl(x);
    printf(" acosLD(%LF) = %LF em radianos, retornando : %s\n", x, acosLD, dataType);
    return acosLD;
}

int main(int argc, char **argv)
{
    float facosx = return_acosf(0.5F, "tipo float");
    double dAcosX = return_acosD(0.3, "tipo double");
    long double Ldacosx = return_acosLD(0.7L, "tipo long double");
    return 0;
}
