#include <stdio.h>
#include <math.h>

/**
 * asinh(): Calcula o arco seno hiperbólico (inverso do seno hiperbólico) de _X.
 * O parâmetro _X pode ser qualquer número real, e o resultado estará no intervalo de
 * [-π/2, +π/2] em radianos.
 *
 * SINTAXE: double asinh(double _X);
 *
 * @param _X O valor para o qual calcular o arco seno hiperbólico.
 * O valor pode ser qualquer número real.
 * @return O arco seno hiperbólico de _X, retornado como um número do tipo `double`.
 * Para valores de _X fora do intervalo [-1, 1], a função retorna NaN (not a number).
 *
 * Parâmetro (_X)    | Valor de retorno
 * -----------------------------------------
 * _X = [-∞, +∞]     | Resultado em radianos no intervalo [-π/2, +π/2]
 * _X < -1 ou _X > 1  | NaN (não é um número real válido para o arco seno hiperbólico)
 *
 * @note O arco seno hiperbólico é a função inversa do seno hiperbólico (sinh).
 * Ele retorna um valor `y` tal que `sinh(y) = _X`. O resultado de `asinh(_X)`
 * estará sempre no intervalo [-π/2, +π/2] para qualquer valor real de _X.
 *
 * @note Para valores de _X fora do intervalo [-1, 1], a função retorna `NaN`,
 * já que o arco seno hiperbólico não está definido para esses valores.
 */

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo float.
 * @note A função `asinhf` é usada para calcular o arcosseno hiperbólico de um número do tipo float.
 */
float return_asinhF(float x, const char *dataType)
{
    float asinhF = asinhf(x);
    printf(" asinhF(%f) = %f, retornando: %s\n", x, asinhF, dataType);
    return asinhF;
}

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo double.
 * @note A função `asinh` é usada para calcular o arcosseno hiperbólico de um número do tipo double.
 */
double return_asinhD(double x, const char *dataType)
{
    double asinhD = asinh(x);
    printf(" asinhD(%lf) = %lf, retornando: %s\n", x, asinhD, dataType);
    return asinhD;
}

/**
 * @brief Calcula o arcosseno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o arcosseno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O arcosseno hiperbólico de x, no tipo long double.
 * @note A função `asinhl` é usada para calcular o arcosseno hiperbólico de um número do tipo
 * long double.
 */
long double return_asinhLD(long double x, const char *dataType)
{
    long double asinhLD = asinhl(x);
    printf(" asinhLD(%LF) = %LF, retornando: %s\n", x, asinhLD, dataType);
    return asinhLD;
}

int main(int argc, char **argv)
{
    float fasinh = return_asinhF(1.5F, "tipo float");
    double dasinh = return_asinhD(2.5, "tipo double");
    long double ldasinh = return_asinhLD(3.5L, "tipo long double");
    return 0;
}
