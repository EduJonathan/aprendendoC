#include <stdio.h>
#include <math.h>

/**
 * remainder(): Retorna o resto da divisão de x por y, com base no arredondamento de ponto flutuante.
 *
 * SINTAXE: double remainder(double _X, double _Y);
 *
 * @param _X O numerador da divisão.
 * @param _Y O denominador da divisão.
 * @return O resto da divisão de _X por _Y, de acordo com a fórmula:
 * _X - n * _Y, onde n é o inteiro mais próximo de _X / _Y. O resultado
 * terá o mesmo sinal que o divisor (_Y), e será ajustado para ser o menor
 * valor absoluto possível em relação ao divisor.
 *
 * @note A função `remainder` calcula o resto de ponto flutuante com base em arredondamento
 * de ponto flutuante. O resultado será sempre menor que o valor absoluto de _Y.
 *
 * @note Se _Y for igual a zero, o comportamento é indefinido e pode resultar em um erro de divisão por zero.
 */

/**
 * @brief Calcula o resto da divisão de ponto flutuante para tipo float.
 *
 * @param x Valor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0, com o mesmo sinal de x.
 */
float return_remainderF(float x, const char *dataType)
{
    float remainderF = remainderf(x, 1.0f);
    printf(" remainderF(%f) = %f, retornando : %s\n", x, remainderF, dataType);
    return remainderF;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante para tipo double.
 *
 * @param x Valor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0, com o mesmo sinal de x.
 */
double return_remainderD(double x, const char *dataType)
{
    double remainderD = remainder(x, 1.0);
    printf(" remainderD(%lf) = %lf, retornando : %s\n", x, remainderD, dataType);
    return remainderD;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante para tipo long double.
 *
 * @param x Valor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0, com o mesmo sinal de x.
 */
long double return_remainderLD(long double x, const char *dataType)
{
    long double remainderLD = remainderl(x, 1.0L);
    printf(" remainderLD(%LF) = %LF, retornando : %s\n", x, remainderLD, dataType);
    return remainderLD;
}

int main(int argc, char **argv)
{
    float fremainder = return_remainderF(3.14F, "tipo float");
    double dremainder = return_remainderD(2.71, "tipo double");
    long double ldremainder = return_remainderLD(1.618L, "tipo long double");
    return 0;
}
