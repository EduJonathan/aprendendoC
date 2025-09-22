#include <stdio.h>
#include <math.h>

/**
 * atan(): Calcula o arco tangente de _X, ou seja, o ângulo em radianos cujo tangente é _X.
 * O arco tangente é a função inversa da tangente, e o valor retornado está no intervalo [-π/2, π/2].
 * A função é útil para calcular o ângulo a partir de um valor de tangente dado.
 *
 * SINTAXE: double atan(double _X);
 *
 * @param _X O valor para o qual calcular o arco tangente. Pode ser qualquer número real.
 * @return O arco tangente de _X, retornado como um número do tipo `double` no intervalo [-π/2, π/2].
 *         Para valores de _X positivos e negativos, o resultado será um valor dentro desse intervalo.
 *
 * Parâmetro (_X)    | Valor do retorno
 * -------------------------------------
 * _X = [-∞, +∞]     | Valor retornado no intervalo [-π/2, π/2] em radianos
 * _X = 0            | 0 radianos
 * _X = ±∞           | ±π/2 radianos
 *
 * @note O arco tangente é uma função ímpar, ou seja, \( \text{atan}(-x) = -\text{atan}(x) \).
 * 
 * @note A função `atan` é definida para todos os valores reais de _X, incluindo infinitos.
 * Quando _X tende para \( +\infty \), o retorno é \( \frac{\pi}{2} \), e quando _X tende para \( -\infty \),
 * o retorno é \( -\frac{\pi}{2} \).
 * 
 * @note A função `atan` retorna o valor em radianos. Para converter para graus, multiplique o resultado por 180/π.
 * @note A função `atan` é frequentemente usada em trigonometria, geometria e problemas que envolvem ângulos.
 */

/**
 * @brief Calcula o arco tangente (em radianos) para tipo float.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo float.
 *
 * @note A função `atanf` é usada para calcular o arco tangente de um número do tipo float.
 */
float return_atanF(float x, const char *dataType)
{
    float atanF = atanf(x);
    printf(" atanF(%f) = %f em radianos, retornando: %s\n", x, atanF, dataType);
    return atanF;
}

/**
 * @brief Calcula o arco tangente (em radianos) para tipo double.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo double.
 *
 * @note A função `atan` é usada para calcular o arco tangente de um número do tipo double.
 */
double return_atanD(double x, const char *dataType)
{
    double atanD = atan(x);
    printf(" atanD(%lf) = %lf em radianos, retornando: %s\n", x, atanD, dataType);
    return atanD;
}

/**
 * @brief Calcula o arco tangente (em radianos) para tipo long double.
 *
 * @param x Valor para o qual calcular o arco tangente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O arco tangente de x em radianos, arredondado para o tipo long double.
 *
 * @note A função `atanl` é usada para calcular o arco tangente de um número do tipo long double.
 */
long double return_atanLD(long double x, const char *dataType)
{
    long double atanLD = atanl(x);
    printf(" atanLD(%LF) = %LF em radianos, retornando: %s\n", x, atanLD, dataType);
    return atanLD;
}

int main(int argc, char **argv)
{
    float fatan = return_atanF(0.5F, "tipo float");
    double datan = return_atanD(0.9, "tipo double");
    long double Ldatan = return_atanLD(0.7L, "tipo long double");
    return 0;
}
