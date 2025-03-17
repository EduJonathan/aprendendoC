#include <stdio.h>
#include <math.h>

/**
 * log2(double _X): calcula o logaritmo na base 2 de um número.
 *
 * SINTAXE: double log2(double _X);
 *
 * @param _X Número do qual é calculado o logaritmo na base 2.
 * @return O logaritmo na base 2 de _X.
 */

/**
 * @brief Calcula o logaritmo na base 2 de x para tipo float.
 *
 * @param x Valor para o qual o logaritmo na base 2 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 2 de x, arredondado para o tipo float.
 * 
 * @note A função `log2f` é usada para calcular o logaritmo na base 2 para números do tipo float.
 */
float return_log2F(float x, const char *dataType)
{
    float log2F = log2f(x);
    printf(" log2F(%f) = %f, retornando : %s\n", x, log2F, dataType);
    return log2F;
}

/**
 * @brief Calcula o logaritmo na base 2 de x para tipo double.
 *
 * @param x Valor para o qual o logaritmo na base 2 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 2 de x, arredondado para o tipo double.
 * 
 * @note A função `log2` é usada para calcular o logaritmo na base 2 para números do tipo double.
 */
double return_log2D(double x, const char *dataType)
{
    double log2D = log2(x);
    printf(" log2D(%lf) = %lf, retornando : %s\n", x, log2D, dataType);
    return log2D;
}

/**
 * @brief Calcula o logaritmo na base 2 de x para tipo long double.
 *
 * @param x Valor para o qual o logaritmo na base 2 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 2 de x, arredondado para o tipo long double.
 * 
 * @note A função `log2l` é usada para calcular o logaritmo na base 2 para números do tipo long double.
 */
long double return_log2LD(long double x, const char *dataType)
{
    long double log2LD = log2l(x);
    printf(" log2LD(%LF) = %LF, retornando : %s\n", x, log2LD, dataType);
    return log2LD;
}

int main(int argc, char **argv)
{
    float flog2 = return_log2F(8.0F, "tipo float");
    double dlog2 = return_log2D(64.0, "tipo double");
    long double ldlog2 = return_log2LD(14.0L, "tipo long double");
    return 0;
}
