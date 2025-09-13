#include <stdio.h>
#include <math.h>

/**
 * double atanh(double): calcula o arco tangente hiperbólico de um ângulo em radianos
 * Parâmetro valor maior igual a 1
 *
 * SINTAXE: double atanh(double _X);
 *
 * @param _X Valor a ser informado para calcular o arco tangente hiperbólico
 * @return O arco tangente hiperbólico de x, no tipo double
 *
 * Parâmetro (x)	| valor do retorno
 * x = [-1, 1]	| [0, +π] em radianos
 * x < -1 or x > 1	| NaN (not a number)
 */

/**
 * @brief Calcula o arcotangente hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o arcotangente hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcotangente hiperbólico de x, no tipo float.
 * @note A função `atanhf` é usada para calcular o arcotangente hiperbólico de um número do tipo
 * float.
 */
float return_atanhF(float x, const char *dataType)
{
    float atanhF = atanhf(x);
    printf(" atanhF(%f) = %f, retornando: %s\n", x, atanhF, dataType);
    return atanhF;
}

/**
 * @brief Calcula o arcotangente hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o arcotangente hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcotangente hiperbólico de x, no tipo double.
 * @note A função `atanh` é usada para calcular o arcotangente hiperbólico de um número do tipo
 * double.
 */
double return_atanhD(double x, const char *dataType)
{
    double atanhD = atanh(x);
    printf(" atanhD(%lf) = %lf, retornando: %s\n", x, atanhD, dataType);
    return atanhD;
}

/**
 * @brief Calcula o arcotangente hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o arcotangente hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcotangente hiperbólico de x, no tipo long double.
 * @note A função `atanhl` é usada para calcular o arcotangente hiperbólico de um número do tipo
 * long double.
 */
long double return_atanhLD(long double x, const char *dataType)
{
    long double atanhLD = atanhl(x);
    printf(" atanhLD(%LF) = %LF, retornando: %s\n", x, atanhLD, dataType);
    return atanhLD;
}

int main(int argc, char **argv)
{
    float fatanh = return_atanhF(0.2F, "tipo float");
    double datanh = return_atanhD(0.5, "tipo double");
    long double ldatanh = return_atanhLD(0.8L, "tipo long double");
    return 0;
}
