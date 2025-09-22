#include <stdio.h>
#include <math.h>

/**
 * sinh(): Calcula o seno hiperbólico de _X, onde _X é um valor em radianos.
 * O seno hiperbólico é uma função que pode ser entendida como uma versão "hiperbólica" do seno,
 * calculada usando a fórmula: sinh(x) = (e^x - e^(-x)) / 2.
 *
 * SINTAXE: double sinh(double _X);
 *
 * @param _X O valor para o qual calcular o seno hiperbólico. Pode ser qualquer número real.
 * @return O seno hiperbólico de _X, retornado como um número do tipo `double`.
 * Para valores de _X < 0, o seno hiperbólico será negativo, e para valores de _X > 0 será positivo.
 *
 * Parâmetro (_X)  | Valor do retorno
 * -----------------------------------------
 * _X = [0, +∞]    | Resultado no intervalo [0, +∞)
 * _X < 0           | Resultado negativo, mas definido em todos os reais
 *
 * @note O seno hiperbólico é uma função definida para todos os números reais.
 * O valor de `sinh(x)` pode ser positivo ou negativo, dependendo do valor de _X,
 * e o crescimento da função é exponencial tanto para valores positivos quanto negativos de _X.
 * Em outras palavras, \( \sinh(-x) = -\sinh(x) \), o que torna a função ímpar.
 *
 * @note A função `sinh` é útil em várias áreas da matemática, física e engenharia,
 * especialmente no estudo de ondas, vibrações e problemas envolvendo crescimento exponencial.
 */

/**
 * @brief Calcula o seno hiperbólico de um número do tipo float.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo float.
 * @note A função `sinhf` é usada para calcular o seno hiperbólico de um número do tipo float.
 */
float return_sinhF(float x, const char *dataType)
{
    float sinhF = sinhf(x);
    printf("sinhF(%f) = %f, retornando: %s\n", x, sinhF, dataType);
    return sinhF;
}

/**
 * @brief Calcula o seno hiperbólico de um número do tipo double.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo double.
 * @note A função `sinh` é usada para calcular o seno hiperbólico de um número do tipo double.
 */
double return_sinhD(double x, const char *dataType)
{
    double sinhD = sinh(x);
    printf("sinhD(%lf) = %lf, retornando: %s\n", x, sinhD, dataType);
    return sinhD;
}

/**
 * @brief Calcula o seno hiperbólico de um número do tipo long double.
 *
 * @param x Valor para o qual o seno hiperbólico será calculado.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O seno hiperbólico de x, no tipo long double.
 * @note A função `sinhl` é usada para calcular o seno hiperbólico de um número do tipo long double.
 */
long double return_sinhLD(long double x, const char *dataType)
{
    long double sinhLD = sinhl(x);
    printf("sinhLD(%LF) = %LF, retornando: %s\n", x, sinhLD, dataType);
    return sinhLD;
}

int main(int argc, char **argv)
{
    float fsinh = return_sinhF(1.5F, "tipo float");
    double dsinh = return_sinhD(2.5, "tipo double");
    long double ldsinh = return_sinhLD(3.5L, "tipo long double");
    return 0;
}
