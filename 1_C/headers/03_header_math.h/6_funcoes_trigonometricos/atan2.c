#include <stdio.h>
#include <math.h>

/**
 * atan2(double, double): calcula o arco tangente com dois parâmetros.
 * tan-1(y / x) in range [-pi, pi].
 * Função atan2 aceita dois argumentos e retorna a arc tangente do quociente y / x.
 *
 * SINTAXE: double atan2(double y, double x);
 *
 * @param y Numerador da divisão.
 * @param x Denominador da divisão.
 * @return O arco tangente do quociente y/x em radianos.
 * @note Se x == 0, o resultado é definido pela implementação.
 */

/**
 * @brief Calcula o arco tangente do quociente y/x, levando em conta o sinal de ambos os argumentos,
 * para tipo float.
 *
 * @param y Numerador da divisão.
 * @param x Denominador da divisão.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente do quociente y/x em radianos, arredondado para o tipo float.
 *
 * @note A função `atan2f` é usada para calcular o arco tangente de dois números do tipo float.
 */
float return_atan2F(float y, float x, const char *dataType)
{
    float atan2F = atan2f(y, x);
    printf(" atan2F(%f, %f) = %f em radianos, retornando: %s\n", y, x, atan2F, dataType);
    return atan2F;
}

/**
 * @brief Calcula o arco tangente do quociente y/x, levando em conta o sinal de ambos os argumentos,
 * para tipo double.
 *
 * @param y Numerador da divisão.
 * @param x Denominador da divisão.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente do quociente y/x em radianos, arredondado para o tipo double.
 *
 * @note A função `atan2` é usada para calcular o arco tangente de dois números do tipo double.
 */
double return_atan2D(double y, double x, const char *dataType)
{
    double atan2D = atan2(y, x);
    printf(" atan2D(%lf, %lf) = %lf em radianos, retornando: %s\n", y, x, atan2D, dataType);
    return atan2D;
}

/**
 * @brief Calcula o arco tangente do quociente y/x, levando em conta o sinal de ambos os argumentos,
 * para tipo long double.
 *
 * @param y Numerador da divisão.
 * @param x Denominador da divisão.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente do quociente y/x em radianos, arredondado para o tipo long double.
 *
 * @note A função `atan2l` é usada para calcular o arco tangente de dois números do tipo long double.
 */
long double return_atan2LD(long double y, long double x, const char *dataType)
{
    long double atan2LD = atan2l(y, x);
    printf(" atan2LD(%LF, %LF) = %LF em radianos, retornando: %s\n", y, x, atan2LD, dataType);
    return atan2LD;
}

int main(int argc, char **argv)
{
    float fatan2 = return_atan2F(1.0F, 2.0F, "tipo float");
    double datan2 = return_atan2D(1.0, 2.0, "tipo double");
    long double Ldatan2 = return_atan2LD(1.0L, 2.0L, "tipo long double");
    return 0;
}
