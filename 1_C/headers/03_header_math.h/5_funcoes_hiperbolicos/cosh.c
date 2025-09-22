#include <stdio.h>
#include <math.h>

/**
 * cosh(): Calcula o cosseno hiperbólico de _X, onde _X é um valor em radianos.
 * O cosseno hiperbólico é uma função que pode ser entendida como uma versão "hiperbólica" do cosseno,
 * calculada usando a fórmula: cosh(x) = (e^x + e^(-x)) / 2.
 *
 * SINTAXE: double cosh(double _X);
 *
 * @param _X O valor para o qual calcular o cosseno hiperbólico. Pode ser qualquer número real.
 * @return O cosseno hiperbólico de _X, retornado como um número do tipo `double`.
 * Para valores de _X < 0, o cosseno hiperbólico será sempre maior ou igual a 1.
 *
 * Parâmetro (_X) | Valor do retorno
 * -------------------------------------
 * _X = [0, +∞]   | Resultado no intervalo [1, +∞)
 * _X < 0          | Resultado sempre maior ou igual a 1
 *
 * @note O cosseno hiperbólico é uma função de valor sempre não negativa e crescente para valores de x
 * positivos. Para valores de _X negativos, a função retorna o mesmo valor que para o valor absoluto
 * de _X. A função é definida para todos os valores reais, ou seja, a função `cosh` é válida para
 * todo número real e não apresenta valores indefinidos ou `NaN`.
 *
 * @note A função `cosh` pode ser útil em cálculos envolvendo física, engenharia e matemática,
 * onde as funções hiperbólicas frequentemente aparecem, como no cálculo de ondas, ressonâncias,
 * e crescimento exponencial.
 */

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo float.
 *
 * @note A função `coshf` é usada para calcular o cosseno hiperbólico de um número do tipo float.
 */
float return_coshF(float x, const char *dataType)
{
    float coshF = coshf(x);
    printf(" coshF(%f) = %f, retornando: %s\n", x, coshF, dataType);
    return coshF;
}

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo double.
 *
 * @note A função `cosh` é usada para calcular o cosseno hiperbólico de um número do tipo double.
 */
double return_coshD(double x, const char *dataType)
{
    double coshD = cosh(x);
    printf(" coshD(%lf) = %lf, retornando: %s\n", x, coshD, dataType);
    return coshD;
}

/**
 * @brief Calcula o cosseno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o cosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno hiperbólico de x, no tipo long double.
 *
 * @note A função `coshl` é usada para calcular o cosseno hiperbólico de um número do tipo
 * long double.
 */
long double return_coshLD(long double x, const char *dataType)
{
    long double coshLD = coshl(x);
    printf(" coshLD(%LF) = %LF, retornando: %s\n", x, coshLD, dataType);
    return coshLD;
}

int main(int argc, char **argv)
{
    float fcosh = return_coshF(2.0F, "tipo float");
    double dcosh = return_coshD(3.0, "tipo double");
    long double ldcosh = return_coshLD(4.0L, "tipo long double");
    return 0;
}
