#include <stdio.h>
#include <math.h>

/**
 * log10(): Calcula o logaritmo na base 10 de _X, ou seja, o valor de y tal que 10^y = _X.
 *
 * SINTAXE: double log10(double _X);
 *
 * @param _X O número do qual será calculado o logaritmo na base 10. Deve ser um número positivo (x > 0).
 * @return O logaritmo na base 10 de _X, ou seja, log10(_X), retornado como um número do tipo `double`.
 *
 * @note A função retorna o valor y tal que 10^y = _X. Por exemplo, log10(1000) retorna 3, pois 10^3 = 1000.
 *
 * @note O logaritmo de base 10 é amplamente utilizado em várias disciplinas, incluindo ciência, engenharia, e finanças.
 *
 * @note A função retorna um erro ou valor indefinido se _X <= 0.
 * @note Para valores de _X muito pequenos (próximos de zero), o logaritmo se aproxima de menos infinito.
 */

/**
 * @brief Calcula o logaritmo na base 10 de x para tipo float.
 *
 * @param x Valor para o qual o logaritmo na base 10 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 10 de x, arredondado para o tipo float.
 *
 * @note A função `log10f` é usada para calcular o logaritmo na base 10 para números do tipo float.
 */
float return_log10F(float x, const char *dataType)
{
    float log10F = log10f(x);
    printf(" log10F(%f) = %f, retornando: %s\n", x, log10F, dataType);
    return log10F;
}

/**
 * @brief Calcula o logaritmo na base 10 de x para tipo double.
 *
 * @param x Valor para o qual o logaritmo na base 10 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 10 de x, arredondado para o tipo double.
 *
 * @note A função `log10` é usada para calcular o logaritmo na base 10 para números do tipo double.
 */
double return_log10D(double x, const char *dataType)
{
    double log10D = log10(x);
    printf(" log10D(%lf) = %lf, retornando: %s\n", x, log10D, dataType);
    return log10D;
}

/**
 * @brief Calcula o logaritmo na base 10 de x para tipo long double.
 *
 * @param x Valor para o qual o logaritmo na base 10 é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo na base 10 de x, arredondado para o tipo long double.
 *
 * @note A função `log10l` é usada para calcular o logaritmo na base 10 para números
 * do tipo long double.
 */
long double return_log10LD(long double x, const char *dataType)
{
    long double log10LD = log10l(x);
    printf(" log10LD(%LF) = %LF, retornando: %s\n", x, log10LD, dataType);
    return log10LD;
}

int main(int argc, char **argv)
{
    float resultF = return_log10F(6.0F, "tipo float");
    double result = return_log10D(4.0, "tipo double");
    long double resultLD = return_log10LD(7.0L, "tipo double");
    return 0;
}
