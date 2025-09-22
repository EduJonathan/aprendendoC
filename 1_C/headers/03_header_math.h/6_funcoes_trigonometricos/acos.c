#include <stdio.h>
#include <math.h>

/**
 * acos(): Calcula o arco cosseno de _X, ou seja, o ângulo em radianos cujo cosseno é _X.
 * O arco cosseno é a função inversa do cosseno, e é definido no intervalo [0, π].
 * A função retorna um valor em radianos, e o valor de _X deve estar no intervalo [-1, 1].
 *
 * SINTAXE: double acos(double _X);
 *
 * @param _X O valor para o qual calcular o arco cosseno. O valor de _X deve estar no intervalo [-1, 1].
 * @return O arco cosseno de _X, retornado como um número do tipo `double` no intervalo [0, π].
 * Se _X estiver fora do intervalo válido, a função retornará `NaN`.
 *
 * Parâmetro (_X)   | Valor do retorno
 * -------------------------------------
 * _X = [ -1, 1 ]   | Valor retornado em [ 0, π ] em radianos
 * _X = 1            | 0 radianos
 * _X = 0            | π / 2 radianos
 * _X = -1           | π radianos
 * _X < -1 ou _X > 1 | NaN (não é um número válido)
 *
 * @note O arco cosseno é definido apenas para valores de _X no intervalo [-1, 1]. Para valores fora
 * desse intervalo, a função retorna `NaN`, pois não existe um valor de ângulo cujo cosseno seja menor
 * que -1 ou maior que 1.
 *
 * @note A função `acos` retorna o valor em radianos. Para converter para graus, multiplique o resultado por 180/π.
 * @note A função `acos` é útil em cálculos trigonométricos, geometria e em problemas que envolvem ângulos entre vetores.
 */

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo float.
 *
 * @note A função `acosf` é usada para calcular o arco cosseno de um número do tipo float.
 */
float return_acosf(float x, const char *dataType)
{
    float acosF = acosf(x);
    printf(" acosf(%f) = %f em radianos, retornando : %s\n", x, acosF, dataType);
    return acosF;
}

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo double.
 *
 * @note A função `acos` é usada para calcular o arco cosseno de um número do tipo double.
 */
double return_acosD(double x, const char *dataType)
{
    double acosD = acos(x);
    printf(" acosD(%lf) = %lf em radianos, retornando : %s\n", x, acosD, dataType);
    return acosD;
}

/**
 * @brief Calcula o arco cosseno (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco cosseno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco cosseno de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `acosl` é usada para calcular o arco cosseno de um número do tipo long double.
 */
long double return_acosLD(long double x, const char *dataType)
{
    long double acosLD = acosl(x);
    printf(" acosLD(%LF) = %LF em radianos, retornando : %s\n", x, acosLD, dataType);
    return acosLD;
}

int main(int argc, char **argv)
{
    float facosx = return_acosf(0.5F, "tipo float");
    double dAcosX = return_acosD(0.3, "tipo double");
    long double Ldacosx = return_acosLD(0.7L, "tipo long double");
    return 0;
}
