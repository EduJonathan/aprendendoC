#include <stdio.h>
#include <math.h>

/**
 * cos(): Calcula o cosseno de um ângulo em radianos. O cosseno de um ângulo é uma função trigonométrica
 * que representa a razão entre o cateto adjacente e a hipotenusa em um triângulo retângulo.
 * Esta função é definida para todos os valores reais de _X, com valores retornados no intervalo [-1, 1].
 *
 * SINTAXE: double cos(double _X);
 *
 * @param _X O valor do ângulo em radianos para o qual calcular o cosseno.
 * @return O cosseno do ângulo _X, retornado como um número do tipo `double` no intervalo [-1, 1].
 *
 * Parâmetro (_X)    | Valor do retorno (cos(_X))
 * --------------------------------------------
 * _X = [-∞, +∞]     | Valor no intervalo [-1, 1], dependente de _X
 * _X = 0            | 1 (cosseno de 0 radianos)
 * _X = ±∞           | NaN (não é um número válido)
 *
 * @note O cosseno de um ângulo é uma função periódica, com período de 2π. Ou seja, cos(x + 2π) = cos(x)
 * para qualquer valor de x. Além disso, a função `cos()` é uma função par, ou seja, cos(-x) = cos(x).
 *
 * @note O valor retornado pela função está sempre no intervalo [-1, 1], refletindo as propriedades da função cosseno.
 *
 * @note Para valores infinitos, o retorno é NaN, pois o cosseno não é definido para infinitos.
 * @note Se o valor de _X não estiver em um múltiplo exato de π/2, o valor retornado será um número entre -1 e 1.
 */

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo float.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo float.
 *
 * @note A função `cosf` é usada para calcular o cosseno de um ângulo em radianos do tipo float.
 */
float return_cosF(float x, const char *dataType)
{
    float cosF = cosf(x);
    printf("cosF(%f) = %f, retornando: %s\n", x, cosF, dataType);
    return cosF;
}

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo double.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo double.
 *
 * @note A função `cos` é usada para calcular o cosseno de um ângulo em radianos do tipo double.
 */
double return_cosD(double x, const char *dataType)
{
    double cosD = cos(x);
    printf("cosD(%lf) = %lf, retornando: %s\n", x, cosD, dataType);
    return cosD;
}

/**
 * @brief Calcula o cosseno de um ângulo em radianos do tipo long double.
 *
 * @param x Ângulo em radianos para o qual o cosseno será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O cosseno de x, no tipo long double.
 *
 * @note A função `cosl` é usada para calcular o cosseno de um ângulo em radianos do tipo long double.
 */
long double return_cosLD(long double x, const char *dataType)
{
    long double cosLD = cosl(x);
    printf("cosLD(%LF) = %LF, retornando: %s\n", x, cosLD, dataType);
    return cosLD;
}

int main(int argc, char **argv)
{
    float fcos = return_cosF(0.5F, "tipo float");
    double dcos = return_cosD(0.5, "tipo double");
    long double ldcos = return_cosLD(0.5L, "tipo long double");
    return 0;
}
