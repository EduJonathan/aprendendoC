#include <stdio.h>
#include <math.h>

/**
 * round(): Retorna o inteiro mais próximo do número passado.
 *
 * SINTAXE: double round(double _X);
 *
 * @param _X Valor informado para arredondar
 * @return O inteiro mais próximo ao valor fornecido
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo.
 *
 * @param x Valor para arredondar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para o tipo float.
 */
float return_roundF(float x, const char *dataType)
{
    float roundF = roundf(x);
    printf(" round(%f) = %f, retornando : %s\n", x, roundF, dataType);
    return roundF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo.
 *
 * @param x Valor para arredondar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para o tipo double.
 */
double return_roundD(double x, const char *dataType)
{
    double roundD = round(x);
    printf(" roundD(%lf) = %lf, retornando : %s\n", x, roundD, dataType);
    return roundD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo.
 *
 * @param x Valor para arredondar.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para o tipo long double.
 */
long double return_roundLD(long double x, const char *dataType)
{
    long double roundLD = roundl(x);
    printf(" roundLF(%LF) = %LF, retornando : %s\n", x, roundLD, dataType);
    return roundLD;
}

int main(int argc, char **argv)
{
    float fround = return_roundF(3.14F, "tipo float");
    double dround = return_roundD(2.71, "tipo double");
    long double ldround = return_roundLD(1.618L, "tipo long double");
    return 0;
}
