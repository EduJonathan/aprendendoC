#include <stdio.h>
#include <math.h>

/**
 * ldexp(): calcula o valor de x * (2^exp), onde x é a mantissa e exp é o expoente.
 * retorna o resultado da multiplicação da mantissa x por 2 elevado à potência exp.
 *
 * SINTAXE: double ldexp(double x, int exp);
 *
 * @param x Valor base.
 * @param exp Expoente.
 */

/**
 * @brief Calcula o valor de x multiplicado por 2 elevado à potência exp para tipo float.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @return O resultado de x * 2^exp, arredondado para o tipo float.
 *
 * @note A função `ldexpf` é usada para calcular o valor para números do tipo float.
 */
float getLdexpfResult(float x, int exp) { return ldexpf(x, exp); }

/**
 * @brief Calcula o valor de x multiplicado por 2 elevado à potência exp para tipo double.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @return O resultado de x * 2^exp, arredondado para o tipo double.
 *
 * @note A função `ldexp` é usada para calcular o valor para números do tipo double.
 */
double getLdexpResult(double x, int exp) { return ldexp(x, exp); }

/**
 * @brief Calcula o valor de x multiplicado por 2 elevado à potência exp para tipo long double.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @return O resultado de x * 2^exp, arredondado para o tipo long double.
 *
 * @note A função `ldexpl` é usada para calcular o valor para números do tipo long double.
 */
long double getLdexplResult(long double x, int exp) { return ldexpl(x, exp); }

/**
 * @brief Exibe o valor de x multiplicado por 2 elevado à potência exp para tipo double.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printLdexpResult(double x, int exp, const char *dataType)
{
    double result = getLdexpResult(x, exp);
    printf(" %s = %.2lf * 2^%d = %.2lf\n", dataType, x, exp, result);
}

/**
 * @brief Exibe o valor de x multiplicado por 2 elevado à potência exp para tipo float.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printLdexpfResult(float x, int exp, const char *dataType)
{
    float result = getLdexpfResult(x, exp);
    printf(" %s = %.2f * 2^%d = %.2f\n", dataType, x, exp, result);
}

/**
 * @brief Exibe o valor de x multiplicado por 2 elevado à potência exp para tipo long double.
 *
 * @param x Valor base.
 * @param exp Expoente.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printLdexplResult(long double x, int exp, const char *dataType)
{
    long double result = getLdexplResult(x, exp);
    printf(" %s = %.2Lf * 2^%d = %.2Lf\n", dataType, x, exp, result);
}

int main(int argc, char **argv)
{
    float xF = 3.0F;
    double x = 5.0;
    long double xLD = 7.0L;
    int exp = 3;

    printLdexpResult(x, exp, "x (tipo de dadodouble)");
    printLdexpfResult(xF, exp, "xF (tipo de dadofloat)");
    printLdexplResult(xLD, exp, "xLD (tipo de dadolong double)");
    return 0;
}
