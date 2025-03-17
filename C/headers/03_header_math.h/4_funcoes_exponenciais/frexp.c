#include <stdio.h>
#include <math.h>

/**
 * frexp(): utilizada para decompor um número de ponto flutuante em duas partes:
 * a mantissa (ou significando) é o expoente. retorna a mantissa e define o valor do
 * expoente apontado pelo ponteiro exp. A mantissa retornada está no intervalo [0.5, 1.0]
 * e o valor retornado pela função é m * 2^e, onde m é a mantissa e e é o expoente.
 *
 * SINTAXE: double frexp(double x, int *exp);
 *
 * @param x Número a ser decomposto.
 * @param exponent Ponteiro para armazenar o expoente resultante.
 * @return A fração de x, arredondada para o tipo double.
 */

/**
 * @brief Calcula a fração e o expoente de um número float.
 *
 * @param x Número a ser decomposto.
 * @param exponent Ponteiro para armazenar o expoente resultante.
 * @return A fração de x, arredondada para o tipo float.
 *
 * @note A função `frexpf` é usada para calcular a fração e o expoente para números do tipo float.
 */
float getFrexpfResult(float x, int *exponent) { return frexpf(x, exponent); }

/**
 * @brief Calcula a fração e o expoente de um número double.
 *
 * @param x Número a ser decomposto.
 * @param exponent Ponteiro para armazenar o expoente resultante.
 * @return A fração de x, arredondada para o tipo double.
 *
 * @note A função `frexp` é usada para calcular a fração e o expoente para números do tipo double.
 */
double getFrexpResult(double x, int *exponent) { return frexp(x, exponent); }

/**
 * @brief Calcula a fração e o expoente de um número long double.
 *
 * @param x Número a ser decomposto.
 * @param exponent Ponteiro para armazenar o expoente resultante.
 * @return A fração de x, arredondada para o tipo long double.
 * 
 * @note A função `frexpl` é usada para calcular a fração e o expoente para números do tipo
 * long double.
 */
long double getFrexplResult(long double x, int *exponent) { return frexpl(x, exponent); }

/**
 * @brief Imprime a fração e o expoente de um número double.
 *
 * @param x Número a ser decomposto.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printResult(double x, const char *dataType)
{
    int exponent = 0;
    double result = getFrexpResult(x, &exponent);
    printf(" %s = %.2lf = %.2lf * 2^%d\n", dataType, x, result, exponent);
}

/**
 * @brief Imprime a fração e o expoente de um número float.
 *
 * @param x Número a ser decomposto.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printResultf(float x, const char *dataType)
{
    int exponent = 0;
    float result = getFrexpfResult(x, &exponent);
    printf(" %s = %.2lf = %.2lf * 2^%d\n", dataType, x, result, exponent);
}

/**
 * @brief Imprime a fração e o expoente de um número long double.
 *
 * @param x Número a ser decomposto.
 * @param dataType Informa o tipo de dado utilizado para a exibição.
 */
void printResultLD(long double x, const char *dataType)
{
    int exponent = 0;
    long double result = getFrexplResult(x, &exponent);
    printf(" %s = %.2Lf = %.2Lf * 2^%d\n", dataType, x, result, exponent);
}

int main(int argc, char **argv)
{
    float xF = 1024.0F;
    double x = 1024.0;
    long double xLD = 1024.0L;

    printResult(x, "x (tipo de dado double)");
    printResultf(xF, "xF (tipo de dado float)");
    printResultLD(xLD, "xLD (tipo de dado long double)");
    return 0;
}
