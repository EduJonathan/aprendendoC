#include <stdio.h>
#include <math.h>

/**
 * asin(): Calcula o arco seno de _X, ou seja, o ângulo em radianos cujo seno é _X.
 * O arco seno é a função inversa do seno, e é definido no intervalo [-π/2, π/2].
 * A função retorna um valor em radianos, e o valor de _X deve estar no intervalo [-1, 1].
 *
 * SINTAXE: double asin(double _X);
 *
 * @param _X O valor para o qual calcular o arco seno. O valor de _X deve estar no intervalo [-1, 1].
 * @return O arco seno de _X, retornado como um número do tipo `double` no intervalo [-π/2, π/2].
 * Se _X estiver fora do intervalo válido, a função retornará `NaN`.
 *
 * Parâmetro (_X)    | Valor do retorno
 * -------------------------------------
 * _X = [-1, 1]      | Valor retornado no intervalo [-π/2, π/2] em radianos
 * _X = 1            | π/2 radianos
 * _X = 0            | 0 radianos
 * _X = -1           | -π/2 radianos
 * _X < -1 ou _X > 1 | NaN (não é um número válido)
 *
 * @note O arco seno é definido apenas para valores de _X no intervalo [-1, 1]. Para valores fora
 * desse intervalo, a função retorna `NaN`, pois não existe um valor de ângulo cujo seno seja menor
 * que -1 ou maior que 1.
 *
 * @note A função `asin` retorna o valor em radianos. Para converter para graus, multiplique o resultado por 180/π.
 *
 * @note A função `asin` é útil em cálculos trigonométricos, geometria e em problemas que envolvem ângulos entre vetores.
 */

/**
 * @brief Calcula o arco seno (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo float.
 *
 * @note A função `asinf` é usada para calcular o arco seno de um número do tipo float.
 */
float return_asinF(float x, const char *dataType)
{
    float asinF = asinf(x);
    printf(" asinF(%f) = %f em radianos, retornando : %s\n", x, asinF, dataType);
    return asinF;
}

/**
 * @brief Calcula o arco seno (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo double.
 *
 * @note A função `asin` é usada para calcular o arco seno de um número do tipo double.
 */
double return_asinD(double x, const char *dataType)
{
    double asinD = asin(x);
    printf(" asinD(%lf) = %lf em radianos, retornando : %s\n", x, asinD, dataType);
    return asinD;
}

/**
 * @brief Calcula o arco seno (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco seno. Deve estar no intervalo [-1, 1].
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco seno de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `asinl` é usada para calcular o arco seno de um número do tipo long double.
 */
long double return_asinLD(long double x, const char *dataType)
{
    long double asinLD = asinl(x);
    printf(" asinLD(%LF) = %LF em radianos, retornando : %s\n", x, asinLD, dataType);
    return asinLD;
}

int main(int argc, char **argv)
{
    float facosx = return_asinF(0.5F, "tipo float");
    double dAcosX = return_asinD(0.9, "tipo double");
    long double Ldacosx = return_asinLD(0.7L, "tipo long double");
    return 0;
}
