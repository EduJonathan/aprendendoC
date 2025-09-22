#include <stdio.h>
#include <math.h>

/**
 * acosh(): Calcula o arco cosseno hiperbólico (inverso do cosseno hiperbólico) de _X.
 * O parâmetro deve ser um número real maior ou igual a 1, pois o arco cosseno hiperbólico
 * está definido apenas para valores de _X ≥ 1.
 *
 * SINTAXE: double acosh(double _X);
 *
 * @param _X O valor para o qual calcular o arco cosseno hiperbólico.
 * O valor deve ser maior ou igual a 1.
 * @return O arco cosseno hiperbólico de _X, retornado como um número do tipo `double`.
 * Se _X < 1, a função retorna NaN (not a number).
 *
 * Parâmetro (_X) | Valor de retorno
 * -----------------------------------------
 * _X = [1, +∞]   | Resultado em radianos no intervalo [0, +∞)
 * _X < 1         | NaN (não é um número real válido para o arco cosseno hiperbólico)
 *
 * @note O arco cosseno hiperbólico é a função inversa do cosseno hiperbólico (cosh).
 * Ele retorna um valor `y` tal que `cosh(y) = _X`. Para valores de _X ≥ 1, o resultado
 * de `acosh(_X)` estará no intervalo [0, +∞).
 *
 * @note Para valores menores que 1, a função retorna `NaN`, já que o arco cosseno hiperbólico
 * não está definido para esses valores.
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
