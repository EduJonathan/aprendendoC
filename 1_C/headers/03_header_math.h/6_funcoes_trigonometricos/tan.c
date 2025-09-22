#include <stdio.h>
#include <math.h>

/**
 * tan(): Calcula a tangente de um ângulo em radianos. A tangente de um ângulo é uma função trigonométrica
 * que representa a razão entre o seno e o cosseno do ângulo, ou seja, tan(x) = sin(x) / cos(x).
 * Esta função é definida para todos os valores reais de _X, exceto para \( x = \frac{\pi}{2} + n\pi \)
 * (onde \( n \) é um número inteiro), pois nesses pontos o cosseno é zero, e a tangente não está definida.
 *
 * SINTAXE: double tan(double _X);
 *
 * @param _X O valor do ângulo em radianos para o qual calcular a tangente.
 * @return A tangente do ângulo _X, retornada como um número do tipo `double`.
 *
 * Parâmetro (_X)    | Valor do retorno (tan(_X))
 * --------------------------------------------
 * _X = [-∞, +∞]     | Valor no intervalo [-∞, +∞], exceto para pontos em que cos(x) = 0
 * _X = 0            | 0 (tangente de 0 radianos)
 * _X = ±(π/2 + nπ)  | NaN (não é um número válido, pois cos(x) = 0 nesses pontos)
 * _X = inf          | NaN (não é um número válido)
 *
 * @note A tangente é uma função periódica com período π, ou seja, tan(x + π) = tan(x) para qualquer valor de x.
 * A tangente é indefinida nos pontos onde o cosseno é zero, ou seja, nos múltiplos ímpares de π/2.
 *
 * @note O valor retornado pela função pode ser positivo ou negativo, dependendo do quadrante em que o ângulo se encontra.
 * @note Para valores infinitos, o retorno é NaN, pois a tangente não é definida para esses casos.
 */

/**
 * @brief Calcula a tangente de um ângulo do tipo float.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo float.
 *
 * @note A função `tanf` é usada para calcular a tangente de um número do tipo float.
 */
float return_tanF(float x, const char *dataType)
{
    float tanF = tanf(x);
    printf("tanF(%f) = %f, retornando: %s\n", x, tanF, dataType);
    return tanF;
}

/**
 * @brief Calcula a tangente de um ângulo do tipo double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo double.
 *
 * @note A função `tan` é usada para calcular a tangente de um número do tipo double.
 */
double return_tanD(double x, const char *dataType)
{
    double tanD = tan(x);
    printf("tanD(%lf) = %lf, retornando: %s\n", x, tanD, dataType);
    return tanD;
}

/**
 * @brief Calcula a tangente de um ângulo do tipo long double.
 *
 * @param x O ângulo em radianos.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente do ângulo x, no tipo long double.
 *
 * @note A função `tanl` é usada para calcular a tangente de um número do tipo long double.
 */
long double return_tanLD(long double x, const char *dataType)
{
    long double tanLD = tanl(x);
    printf("tanLD(%LF) = %LF, retornando: %s\n", x, tanLD, dataType);
    return tanLD;
}

int main(int argc, char **argv)
{
    float ftan = return_tanF(0.5F, "tipo float");
    double dtan = return_tanD(0.5, "tipo double");
    long double ldtan = return_tanLD(0.5L, "tipo long double");
    return 0;
}
