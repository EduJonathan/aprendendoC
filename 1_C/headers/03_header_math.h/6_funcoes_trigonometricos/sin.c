#include <stdio.h>
#include <math.h>

/**
 * sin(): Calcula o seno de um ângulo em radianos. O seno de um ângulo é uma função trigonométrica
 * que representa a razão entre o cateto oposto e a hipotenusa em um triângulo retângulo.
 * Esta função é definida para todos os valores reais de _X, com valores retornados no intervalo [-1, 1].
 *
 * SINTAXE: float sin(float _X);
 *
 * @param _X O valor do ângulo em radianos para o qual calcular o seno.
 * @return O seno do ângulo _X, retornado como um número do tipo `float` no intervalo [-1, 1].
 *
 * Parâmetro (_X)    | Valor do retorno (sin(_X))
 * --------------------------------------------
 * _X = [-∞, +∞]     | Valor no intervalo [-1, 1], dependente de _X
 * _X = 0            | 0 (seno de 0 radianos)
 * _X = ±∞           | NaN (não é um número válido)
 *
 * @note O seno de um ângulo é uma função periódica, com período de 2π. Ou seja, sin(x + 2π) = sin(x)
 * para qualquer valor de x. Além disso, a função `sin()` é uma função ímpar, ou seja, sin(-x) = -sin(x).
 *
 * @note O valor retornado pela função está sempre no intervalo [-1, 1], refletindo as propriedades da função seno.
 *
 * @note Para valores infinitos, o retorno é NaN, pois o seno não é definido para infinitos.
 * @note Se o valor de _X não estiver em um múltiplo exato de π/2, o valor retornado será um número entre -1 e 1.
 */

/**
 * @brief Calcula o seno de um número do tipo float.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo float.
 *
 * @note A função `sinf` é usada para calcular o seno de um número do tipo float.
 */
float return_sinF(float x, const char *dataType)
{
    float sinF = sinf(x);
    printf("sinF(%f) = %f, retornando: %s\n", x, sinF, dataType);
    return sinF;
}

/**
 * @brief Calcula o seno de um número do tipo double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo double.
 *
 * @note A função `sin` é usada para calcular o seno de um número do tipo double.
 */
double return_sinD(double x, const char *dataType)
{
    double sinD = sin(x);
    printf("sinD(%lf) = %lf, retornando: %s\n", x, sinD, dataType);
    return sinD;
}

/**
 * @brief Calcula o seno de um número do tipo long double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno do ângulo x, no tipo long double.
 *
 * @note A função `sinl` é usada para calcular o seno de um número do tipo long double.
 */
long double return_sinLD(long double x, const char *dataType)
{
    long double sinLD = sinl(x);
    printf("sinLD(%LF) = %LF, retornando: %s\n", x, sinLD, dataType);
    return sinLD;
}

int main(int argc, char **argv)
{
    float fsin = return_sinF(0.5F, "tipo float");
    double dsin = return_sinD(0.5, "tipo double");
    long double ldsin = return_sinLD(0.5L, "tipo long double");
    return 0;
}
