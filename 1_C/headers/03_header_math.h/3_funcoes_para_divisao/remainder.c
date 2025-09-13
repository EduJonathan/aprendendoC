#include <stdio.h>
#include <math.h>

/**
 * remainder(): Retorna o resto da divisão de x por 1.
 *
 * SINTAXE: double remainder(double _X, double _Y);
 *
 * @param _X Valor do numerador quociente.
 * @param _Y Valor do denominador quociente.
 * @return Retorna restante da divisão dos argumentos.
 * @note Se y == 0, o resultado é definido pela implementação.
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
