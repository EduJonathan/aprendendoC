#include <stdio.h>
#include <math.h>

/**
 * acosh(double): calcula o arco cosseno hiperbólico de um ângulo em radianos
 * O parâmetro deve ser um valor double maior ou igual a 1.
 *
 * SINTAXE: double acosh(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco cosseno hiperbólico
 * @return O arco cosseno hiperbólico de x, no tipo double
 *
 * Parâmetro (x) | valor do retorno
 * -------------------------------------
 * x = [1, +inf] | [0, +π / 2] em radianos
 * x < 1         | NaN (not a number)
 */

/**
 * @brief Calcula o arcocosseno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o arcocosseno hiperbólico será calculado. Deve ser maior ou igual a 1.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcocosseno hiperbólico de x, no tipo float.
 *
 * @note A função `acoshf` é usada para calcular o arcocosseno hiperbólico de um número do tipo float.
 */
float return_acoshF(float x, const char *dataType)
{
    float acoshF = acoshf(x);
    printf(" acoshF(%f) = %f, retornando: %s\n", x, acoshF, dataType);
    return acoshF;
}

/**
 * @brief Calcula o arcocosseno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o arcocosseno hiperbólico será calculado. Deve ser maior ou igual a 1.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcocosseno hiperbólico de x, no tipo double.
 *
 * @note A função `acosh` é usada para calcular o arcocosseno hiperbólico de um número do tipo double.
 */
double return_acoshD(double x, const char *dataType)
{
    double acoshD = acosh(x);
    printf(" acoshD(%lf) = %lf, retornando: %s\n", x, acoshD, dataType);
    return acoshD;
}

/**
 * @brief Calcula o arcocosseno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o arcocosseno hiperbólico será calculado. Deve ser maior ou igual a 1.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcocosseno hiperbólico de x, no tipo long double.
 *
 * @note A função `acoshl` é usada para calcular o arcocosseno hiperbólico de um número
 * do tipo long double.
 */
long double return_acoshLD(long double x, const char *dataType)
{
    long double acoshLD = acoshl(x);
    printf(" acoshLD(%LF) = %LF, retornando: %s\n", x, acoshLD, dataType);
    return acoshLD;
}

int main(int argc, char **argv)
{
    float facosh = return_acoshF(2.0F, "tipo float");
    double dacosh = return_acoshD(3.0, "tipo double");
    long double ldacosh = return_acoshLD(4.0L, "tipo long double");
    return 0;
}
