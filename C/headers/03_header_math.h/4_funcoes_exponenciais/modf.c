#include <stdio.h>
#include <math.h>

/**
 * modf (double,double *): número em partes fracionárias e inteira.
 * Divide x em partes integrais e fracionárias, cada uma com o mesmo sinal de x.
 * Armazena a parte integral em *Y ip e devolve a parte fracionária.
 *
 * SINTAXE: double modf(double x, double *ip);
 *
 * @param x Valor a ser dividido em partes integrais e fracionárias.
 * @param integerPart Ponteiro para armazenar a parte inteira.
 * @return Parte fracionária do valor x.
 */

/**
 * @brief Separa a parte inteira e a parte fracionária de um número do tipo double.
 *
 * @param x Valor a ser separado em parte inteira e parte fracionária.
 * @param integerPart Ponteiro para armazenar a parte inteira.
 * @return Parte fracionária do valor x.
 *
 * @note A função `modf` é usada para separar a parte inteira e a parte fracionária de um número do
 * tipo double.
 */
double getModfResult(double x, double *integerPart) { return modf(x, integerPart); }

/**
 * @brief Separa a parte inteira e a parte fracionária de um número do tipo float.
 *
 * @param x Valor a ser separado em parte inteira e parte fracionária.
 * @param integerPart Ponteiro para armazenar a parte inteira.
 * @return Parte fracionária do valor x.
 *
 * @note A função `modff` é usada para separar a parte inteira e a parte fracionária
 * de um número do tipo float.
 */
float getModffResult(float x, float *integerPart) { return modff(x, integerPart); }

/**
 * @brief Separa a parte inteira e a parte fracionária de um número do tipo long double.
 *
 * @param x Valor a ser separado em parte inteira e parte fracionária.
 * @param integerPart Ponteiro para armazenar a parte inteira.
 * @return Parte fracionária do valor x.
 *
 * @note A função `modfl` é usada para separar a parte inteira e a parte fracionária de
 * um número do tipo long double.
 */
long double getModflResult(long double x, long double *integerPart) { return modfl(x, integerPart); }

/**
 * @brief Exibe a parte inteira e a parte fracionária de um número do tipo double.
 *
 * @param x Valor a ser exibido.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 */
void printModfResult(double x, const char *dataType)
{
    double integerPart = 0.0;
    double fractionalPart = getModfResult(x, &integerPart);
    printf(" %s = %.2lf, Parte Inteira = %.0lf, Parte Fracionária = %.2lf\n", dataType, x, integerPart, fractionalPart);
}

/**
 * @brief Exibe a parte inteira e a parte fracionária de um número do tipo float.
 *
 * @param x Valor a ser exibido.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 */
void printModffResult(float x, const char *dataType)
{
    float integerPart = 0.0f;
    float fractionalPart = getModffResult(x, &integerPart);
    printf(" %s = %.2f, Parte Inteira = %.0f, Parte Fracionária = %.2f\n", dataType, x, integerPart, fractionalPart);
}

/**
 * @brief Exibe a parte inteira e a parte fracionária de um número do tipo long double.
 *
 * @param x Valor a ser exibido.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 */
void printModflResult(long double x, const char *dataType)
{
    long double integerPart = 0.0L;
    long double fractionalPart = getModflResult(x, &integerPart);
    printf(" %s = %.2Lf, Parte Inteira = %.0Lf, Parte Fracionária = %.2Lf\n", dataType, x, integerPart, fractionalPart);
}

int main(int argc, char **argv)
{
    float xF = 5.4F;
    double x = 7.8;
    long double xLD = 9.2L;

    printModfResult(x, "x (tipo de dado double)");
    printModffResult(xF, "xF (tipo de dado float)");
    printModflResult(xLD, "xLD (tipo de dado long double)");
    return 0;
}
