#include <stdio.h>
#include <math.h>

/**
 * exp(): Calcula o valor do exponencial de _X, ou seja, e^_X, onde e é a constante de Euler (aproximadamente 2.71828).
 *
 * SINTAXE: double exp(double _X);
 *
 * @param _X O número para o qual será calculado o exponencial.
 * @return O valor de e elevado à potência de _X, ou seja, e^_X, retornado como um número do tipo `double`.
 *
 * @note A função `exp` calcula o exponencial de um número real. O valor de e^_X cresce rapidamente
 * à medida que _X aumenta, e tende a se aproximar de 0 quando _X se aproxima de valores negativos grandes.
 *
 * @note Se o valor de _X for muito grande ou muito pequeno, a função pode retornar valores próximos
 * ao limite superior ou inferior de precisão numérica representável em `double`.
 */

/**
 * @brief Calcula o exponencial de x para tipo float.
 *
 * @param x Valor para o qual calcular o exponencial.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial de x, arredondado para o tipo float.
 *
 * @note A função expf é usada para calcular o exponencial de um número do tipo float.
 */
float return_expF(float x, const char *dataType)
{
    float expF = expf(x);
    printf(" expF(%f) = %f, retornando: %s\n", x, expF, dataType);
    return expF;
}

/**
 * @brief Calcula o exponencial de x para tipo double.
 *
 * @param x Valor para o qual calcular o exponencial.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial de x, arredondado para o tipo double.
 *
 * @note A função exp é usada para calcular o exponencial de um número do tipo double.
 */
double return_expD(double x, const char *dataType)
{
    double expD = exp(x);
    printf(" expD(%lf) = %lf, retornando: %s\n", x, expD, dataType);
    return expD;
}

/**
 * @brief Calcula o exponencial de x para tipo long double.
 *
 * @param x Valor para o qual calcular o exponencial.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O exponencial de x, arredondado para o tipo long double.
 *
 * @note A função expl é usada para calcular o exponencial de um número do tipo long double.
 */
long double return_expLD(long double x, const char *dataType)
{
    long double expLD = expl(x);
    printf(" expLD(%LF) = %LF, retornando: %s\n", x, expLD, dataType);
    return expLD;
}

int main(int argc, char **argv)
{
    float fexp = return_expF(2.0F, "tipo float");
    double dexp = return_expD(3.0, "tipo double");
    long double ldexp = return_expLD(1.5L, "tipo long double");
    return 0;
}
