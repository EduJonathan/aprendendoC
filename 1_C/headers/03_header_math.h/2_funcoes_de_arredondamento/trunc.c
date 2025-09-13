#include <stdio.h>
#include <math.h>

/**
 * trunc(): Remove a parte decimal de um número, arredondando para zero.
 *
 * SINTAXE: double trunc(double _X);
 *
 * @param _X Valor a ser informado.
 * @return O número sem a parte decimal, arredondado para zero.
 */

/**
 * @brief Remove a parte decimal de um número float, arredondando para zero.
 *
 * Esta função utiliza a função `truncf` para remover a parte decimal do número float.
 *
 * @param x Valor para truncar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O número sem a parte decimal, arredondado para zero.
 */
float return_truncF(float x, const char *dataType)
{
    float truncF = truncf(x);
    printf(" truncF(%f) = %f, retornando: %s\n", x, truncF, dataType);
    return truncF;
}

/**
 * @brief Remove a parte decimal de um número double, arredondando para zero.
 *
 * Esta função utiliza a função `trunc` para remover a parte decimal do número double.
 *
 * @param x Valor para truncar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O número sem a parte decimal, arredondado para zero.
 */
double return_truncD(double x, const char *dataType)
{
    double truncD = trunc(x);
    printf(" truncD(%lf) = %lf, retornando: %s\n", x, truncD, dataType);
    return truncD;
}

/**
 * @brief Remove a parte decimal de um número long double, arredondando para zero.
 *
 * Esta função utiliza a função `truncl` para remover a parte decimal do número long double.
 *
 * @param x Valor para truncar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O número sem a parte decimal, arredondado para zero.
 */
long double return_truncLD(long double x, const char *dataType)
{
    long double truncLD = truncl(x);
    printf(" truncLD(%LF) = %LF, retornando: %s\n", x, truncLD, dataType);
    return truncLD;
}

int main(int argc, char **argv)
{
    float ffloor = return_truncF(3.14F, "tipo float");
    double dfloor = return_truncD(2.71, "tipo double");
    long double ldfloor = return_truncLD(1.618L, "tipo long double");
    return 0;
}
