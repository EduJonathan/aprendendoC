#include <stdio.h>
#include <math.h>

/**
 * cbrt(): Calcula a raiz cúbica de um número não-negativo.
 *
 * SINTAXE: double cbrt(float _X);
 *
 * @param _X O número para calcular a raiz cúbica. Deve ser maior ou igual a 0.
 *           Para valores negativos, o comportamento não é definido.
 * @return A raiz cúbica de _X, se _X >= 0.
 *         Se _X < 0, o comportamento é indefinido (pode gerar erro ou comportamento inesperado).
 * @note Para valores negativos de _X, recomenda-se tratar o erro antes de chamar esta função.
 */

/**
 * @brief Calcula a raiz cúbica de um número do tipo float.
 *
 * @param x Valor para o qual a raiz cúbica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A raiz cúbica de x, no tipo float.
 *
 * @note A função `cbrtf` é usada para calcular a raiz cúbica de um número do tipo float.
 */
float return_cbrtF(float x, const char *dataType)
{
    float cbrtF = cbrtf(x);
    printf("cbrtF(%f) = %f, retornando : %s\n", x, cbrtF, dataType);
    return cbrtF;
}

/**
 * @brief Calcula a raiz cúbica de um número do tipo double.
 *
 * @param x Valor para o qual a raiz cúbica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A raiz cúbica de x, no tipo double.
 *
 * @note A função `cbrt` é usada para calcular a raiz cúbica de um número do tipo double.
 */
double return_cbrtD(double x, const char *dataType)
{
    double cbrtD = cbrt(x);
    printf("cbrtD(%lf) = %lf, retornando : %s\n", x, cbrtD, dataType);
    return cbrtD;
}

/**
 * @brief Calcula a raiz cúbica de um número do tipo long double.
 *
 * @param x Valor para o qual a raiz cúbica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A raiz cúbica de x, no tipo long double.
 *
 * @note A função `cbrtl` é usada para calcular a raiz cúbica de um número do tipo long double.
 */
long double return_cbrtLD(long double x, const char *dataType)
{
    long double cbrtLD = cbrtl(x);
    printf("cbrtLD(%LF) = %LF, retornando : %s\n", x, cbrtLD, dataType);
    return cbrtLD;
}

int main(int argc, char **argv)
{
    float fcbrt = return_cbrtF(27.0F, "tipo float");
    double dcbrt = return_cbrtD(125.0, "tipo double");
    long double ldcbrt = return_cbrtLD(512.0L, "tipo long double");
    return 0;
}
