#include <stdio.h>
#include <math.h>

/**
 * atanh(): Calcula o arco tangente hiperbólico (inverso da tangente hiperbólica) de _X.
 * O parâmetro _X deve estar no intervalo [-1, 1], já que o arco tangente hiperbólico
 * é definido somente para valores de _X dentro deste intervalo.
 *
 * SINTAXE: double atanh(double _X);
 *
 * @param _X O valor para o qual calcular o arco tangente hiperbólico.
 * O valor deve estar no intervalo [-1, 1] para que o cálculo seja válido.
 *
 * @return O arco tangente hiperbólico de _X, retornado como um número do tipo `double`.
 * Para valores de _X fora do intervalo [-1, 1], a função retorna NaN (not a number).
 *
 * Parâmetro (_X)     | Valor de retorno
 * -----------------------------------------
 * _X = [-1, 1]       | Resultado em radianos no intervalo [-π/4, π/4]
 * _X < -1 ou _X > 1   | NaN (não é um número real válido para o arco tangente hiperbólico)
 *
 * @note O arco tangente hiperbólico é a função inversa da tangente hiperbólica (tanh).
 * Ele retorna um valor `y` tal que `tanh(y) = _X`. O resultado de `atanh(_X)`
 * estará no intervalo de [-π/4, π/4] para valores de _X no intervalo [-1, 1].
 *
 * @note Para valores de _X fora do intervalo [-1, 1], a função retorna `NaN`,
 * já que o arco tangente hiperbólico não está definido para esses valores.
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
