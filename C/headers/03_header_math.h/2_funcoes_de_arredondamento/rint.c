#include <stdio.h>
#include <math.h>

/**
 * rint(): Arredonda um número para o inteiro mais próximo, com base no tipo de dado.
 *
 * SINTAXE: double rint(double _X);
 *
 * @param _X Valor a ser arredondado.
 * @return O inteiro mais próximo do valor fornecido, com base na precisão do tipo de dado.
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo.
 *
 * Esta função utiliza a função `rintf` para arredondar um número float para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo float.
 */
float return_rintF(float x, const char *dataType)
{
    float rintF = rintf(x);
    printf(" rintF(%f) = %f, retornando: %s\n", x, rintF, dataType);
    return rintF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo.
 *
 * Esta função utiliza a função `rint` para arredondar um número double para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo double.
 */
double return_rintD(double x, const char *dataType)
{
    double rintD = rint(x);
    printf(" rintD(%lf) = %lf, retornando: %s\n", x, rintD, dataType);
    return rintD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo.
 *
 * Esta função utiliza a função `rintl` para arredondar um número long double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long double.
 */
long double return_rintLD(long double x, const char *dataType)
{
    long double rintLD = rintl(x);
    printf(" rintLD(%Lf) = %Lf, retornando: %s\n", x, rintLD, dataType);
    return rintLD;
}

int main(int argc, char **argv)
{
    float frint = return_rintF(3.14F, "tipo float");
    double drint = return_rintD(2.71, "tipo double");
    long double ldrint = return_rintLD(1.618L, "tipo long double");
    return 0;
}
