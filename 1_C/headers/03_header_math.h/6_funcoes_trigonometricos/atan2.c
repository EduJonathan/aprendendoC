#include <stdio.h>
#include <math.h>

/**
 * atan2(): Calcula o arco tangente do quociente y/x, levando em consideração o sinal de ambos
 * os parâmetros, o que permite determinar corretamente o quadrante do ângulo. A função retorna
 * um valor no intervalo [-π, π], ao contrário da função `atan`, que retorna um valor no intervalo
 * [-π/2, π/2].
 *
 * SINTAXE: double atan2(double y, double x);
 *
 * @param y O numerador da divisão, representando a coordenada y no plano cartesiano.
 * @param x O denominador da divisão, representando a coordenada x no plano cartesiano.
 * @return O arco tangente do quociente y/x, retornado como um número do tipo `double` no intervalo [-π, π].
 *         O valor retornado representa o ângulo entre a linha que conecta a origem ao ponto (x, y)
 *         e o eixo x, no plano cartesiano.
 *
 * Parâmetro (y, x)     | Valor do retorno (em radianos)
 * ------------------------------------------------------
 * x > 0, y = 0        | 0 radianos (no eixo positivo x)
 * x > 0, y > 0        | Ângulo entre 0 e π/2 (primeiro quadrante)
 * x > 0, y < 0        | Ângulo entre 0 e -π/2 (quarto quadrante)
 * x < 0, y = 0        | π radianos (no eixo negativo x)
 * x < 0, y > 0        | Ângulo entre π/2 e π (segundo quadrante)
 * x < 0, y < 0        | Ângulo entre -π/2 e -π (terceiro quadrante)
 * x = 0, y > 0        | π/2 radianos (no eixo positivo y)
 * x = 0, y < 0        | -π/2 radianos (no eixo negativo y)
 * x = 0, y = 0        | NaN (não é um número válido)
 *
 * @note A função `atan2` é mais robusta que a função `atan`, pois leva em consideração os sinais
 * de ambos os parâmetros (x e y), o que permite calcular corretamente o ângulo para todos os quadrantes.
 *
 * @note Se x = 0 e y = 0, o comportamento não é definido e o retorno será NaN.
 *
 * @note O intervalo de retorno da função `atan2` é de -π a π, diferente da função `atan` que tem o intervalo de [-π/2, π/2].
 *
 * @note A função `atan2` é frequentemente usada em cálculos de ângulos em coordenadas cartesianas
 * e na conversão de coordenadas polares para cartesianas, pois pode determinar o ângulo com precisão,
 * considerando todos os quadrantes.
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
