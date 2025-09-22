#include <stdio.h>
#include <math.h>

/**
 * fabs(): Calcula o valor absoluto de um número `double`.
 *
 * SINTAXE: double fabs(double _X);
 *
 * @param _X O número de entrada, do tipo `double`, do qual será calculado o valor absoluto.
 * @return O valor absoluto de _X, ou seja, o valor de _X sem o sinal negativo.
 *         O valor retornado é do tipo `double`.
 *
 * @note A função `fabs` retorna o valor absoluto de números reais, removendo o sinal negativo
 * se presente. Por exemplo, `fabs(-3.14)` retorna `3.14`, e `fabs(3.14)` retorna `3.14`.
 *
 * @note A função sempre retorna um valor do tipo `double`, independentemente de o número de entrada ser positivo ou negativo.
 */

/**
 * @brief Calcula o valor absoluto de um número do tipo float.
 *
 * @param x Número do qual será calculado o valor absoluto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O valor absoluto de x, no tipo float.
 *
 * @note A função `fabsf` é usada para calcular o valor absoluto de um número do tipo float.
 */
float return_fabsF(float x, const char *dataType)
{
    float fabsF = fabsf(x);
    printf("fabsF(%f) = %f, retornando : %s\n", x, fabsF, dataType);
    return fabsF;
}

/**
 * @brief Calcula o valor absoluto de um número do tipo double.
 *
 * @param x Número do qual será calculado o valor absoluto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O valor absoluto de x, no tipo double.
 *
 * @note A função `fabs` é usada para calcular o valor absoluto de um número do tipo double.
 */
double return_fabsD(double x, const char *dataType)
{
    double fabsD = fabs(x);
    printf("fabsD(%lf) = %lf, retornando : %s\n", x, fabsD, dataType);
    return fabsD;
}

/**
 * @brief Calcula o valor absoluto de um número do tipo long double.
 *
 * @param x Número do qual será calculado o valor absoluto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O valor absoluto de x, no tipo long double.
 *
 * @note A função `fabsl` é usada para calcular o valor absoluto de um número do tipo long double.
 */
long double return_fabsLD(long double x, const char *dataType)
{
    long double fabsLD = fabsl(x);
    printf("fabsLD(%LF) = %LF, retornando : %s\n", x, fabsLD, dataType);
    return fabsLD;
}

int main(int argc, char **argv)
{
    float ffabs = return_fabsF(-3.14F, "tipo float");
    double dfabs = return_fabsD(-99.9, "tipo double");
    long double ldfabs = return_fabsLD(-123.456L, "tipo long double");
    return 0;
}
