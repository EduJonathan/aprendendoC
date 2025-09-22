#include <stdio.h>
#include <math.h>

/**
 * sqrt(): Calcula a raiz quadrada de um número não-negativo.
 *
 * SINTAXE: double sqrt(double _X);
 *
 * @param _X O número do qual se deseja calcular a raiz quadrada. Deve ser maior ou igual a 0.
 *           Para valores negativos, o comportamento não é definido.
 * @return A raiz quadrada de _X, se _X >= 0. Caso _X seja negativo, o comportamento da função
 * é indefinido.
 *
 * @note A função `sqrt` calcula a raiz quadrada de números do tipo `double`.
 *
 * @note Para valores negativos de _X, o comportamento pode resultar em erro ou valor indefinido.
 * Caso seja necessário trabalhar com números negativos, considere usar a função `cbrt` (raiz cúbica),
 * ou trate o erro antes de chamar a função.
 */

/**
 * @brief Calcula a raiz quadrada.
 *
 * @param x Valor para calcular a raiz quadrada (x >= 0).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return A raiz quadrada de x.
 */
float return_sqrtF(float x, const char *dataType)
{
    float sqrtF = sqrtf(x);
    printf(" sqrtF(%f) = %f, retornando: %s\n", x, sqrtF, dataType);
    return sqrtF;
}

/**
 * @brief Calcula a raiz quadrada.
 *
 * @param x Valor para calcular a raiz quadrada (x >= 0).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return A raiz quadrada de x.
 */
double return_sqrtD(double x, const char *dataType)
{
    double sqrtD = sqrt(x);
    printf(" sqrtD(%lf) = %lf, retornando: %s\n", x, sqrtD, dataType);
    return sqrtD;
}

/**
 * @brief Calcula a raiz quadrada.
 *
 * @param x Valor para calcular a raiz quadrada (x >= 0).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return A raiz quadrada de x.
 */
long double return_sqrtLD(long double x, const char *dataType)
{
    long double sqrtLD = sqrtl(x);
    printf(" sqrtLD(%LF) = %LF, retornando: %s\n", x, sqrtLD, dataType);
    return sqrtLD;
}

int main(int argc, char **argv)
{
    printf(" A raiz quadrada de 0 é: %f\n", sqrt(0));   // 0.000000
    printf(" A raiz quadrada de -1 é: %f\n", sqrt(-1)); // -nan (ind)

    float fsqrt = return_sqrtF(9.0F, "tipo float");
    double dsqrt = return_sqrtD(16.0, "tipo double");
    long double ldsqrt = return_sqrtLD(25.0L, "tipo long double");
    return 0;
}
