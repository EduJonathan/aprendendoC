#include <stdio.h>
#include <math.h>

/**
 * tanh(): Calcula a tangente hiperbólica de _X, onde _X é um valor em radianos.
 * A tangente hiperbólica é uma função que pode ser entendida como uma versão "hiperbólica" da tangente,
 * e é definida como: tanh(x) = sinh(x) / cosh(x).
 *
 * SINTAXE: double tanh(double _X);
 *
 * @param _X O valor para o qual calcular a tangente hiperbólica. Pode ser qualquer número real.
 * @return A tangente hiperbólica de _X, retornada como um número do tipo `double`.
 * Para valores de _X, o resultado estará no intervalo [-1, +1].
 *
 * Parâmetro (_X)    | Valor de retorno
 * -------------------------------------
 * _X = [-∞, +∞]     | Resultado no intervalo [-1, +1]
 * _X = 0             | 0
 * _X = ±∞            | 1 (não NaN, pois a função converge para 1 à medida que x tende ao infinito)
 *
 * @note A tangente hiperbólica é uma função definida para todos os números reais.
 * Ela é uma função ímpar, ou seja, \( \tanh(-x) = -\tanh(x) \), e seu valor sempre estará
 * no intervalo [-1, 1].
 * Para \( x \to +\infty \), a tangente hiperbólica tende a 1, e para \( x \to -\infty \), ela tende a -1.
 *
 * @note A função `tanh` é frequentemente usada em áreas como processamento de sinais, física
 * e redes neurais, devido às suas propriedades de saturação, que tornam os valores de saída limitados
 * dentro do intervalo [-1, +1].
 */

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo float.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo float.
 *
 * @note A função `tanhf` é usada para calcular a tangente hiperbólica de um número do tipo float.
 */
float return_tanhF(float x, const char *dataType)
{
    float tanhF = tanhf(x);
    printf("tanhF(%f) = %f, retornando: %s\n", x, tanhF, dataType);
    return tanhF;
}

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo double.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo double.
 *
 * @note A função `tanh` é usada para calcular a tangente hiperbólica de um número do tipo double.
 */
double return_tanhD(double x, const char *dataType)
{
    double tanhD = tanh(x);
    printf("tanhD(%lf) = %lf, retornando: %s\n", x, tanhD, dataType);
    return tanhD;
}

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo long double.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo long double.
 *
 * @note A função `tanhl` é usada para calcular a tangente hiperbólica de um número do tipo
 * long double.
 */
long double return_tanhLD(long double x, const char *dataType)
{
    long double tanhLD = tanhl(x);
    printf("tanhLD(%LF) = %LF, retornando: %s\n", x, tanhLD, dataType);
    return tanhLD;
}

int main(int argc, char **argv)
{
    float ftanh = return_tanhF(0.2F, "tipo float");
    double dtanh = return_tanhD(0.5, "tipo double");
    long double ldtanh = return_tanhLD(0.8L, "tipo long double");
    return 0;
}
