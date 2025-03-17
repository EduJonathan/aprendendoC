#include <stdio.h>
#include <math.h>

/**
 * log(double _X): calcula o logaritmo natural (ln) de x.
 *
 * SINTAXE: double log(double _X);
 *
 * @param _X Número do qual é calculado o logaritmo natural.
 * @return O logaritmo natural de _X.
 */

/**
 * @brief Calcula o logaritmo natural de x para tipo float.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo float.
 *
 * @note A função `logf` é usada para calcular o logaritmo natural para números do tipo float.
 */
float return_logF(float x, const char *dataType)
{
    float logF = logf(x);
    printf(" logF(%f) = %f, retornando: %s\n", x, logF, dataType);
    return logF;
}

/**
 * @brief Calcula o logaritmo natural de x para tipo double.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo double.
 *
 * @note A função `log` é usada para calcular o logaritmo natural para números do tipo double.
 */
double return_logD(double x, const char *dataType)
{
    double logD = log(x);
    printf(" logD(%lf) = %lf, retornando: %s\n", x, logD, dataType);
    return logD;
}

/**
 * @brief Calcula o logaritmo natural de x para tipo long double.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo long double.
 *
 * @note A função `logl` é usada para calcular o logaritmo natural para números do tipo long double.
 */
long double return_logLD(long double x, const char *dataType)
{
    long double logLD = logl(x);
    printf(" logLD(%LF) = %LF, retornando: %s\n", x, logLD, dataType);
    return logLD;
}

int main(int argc, char **argv)
{
    float resultF = return_logF(6.4f, "tipo float");
    double result = return_logD(5.0, "tipo double");
    long double resultLd = return_logLD(8.1L, "tipo long double");
    return 0;
}
