#include <stdio.h>
#include <math.h>

/**
 * round(): Retorna o inteiro mais próximo ao número fornecido, arredondando de acordo com a regra de arredondamento padrão.
 *
 * SINTAXE: double round(double _X);
 *
 * @param _X O valor de entrada, que pode ser um número real (do tipo `double`).
 * @return O inteiro mais próximo de _X, arredondado para o inteiro mais próximo.
 *         O valor retornado é do tipo `double`.
 *
 * @note A função `round` arredonda o número para o inteiro mais próximo. Se o valor de _X
 * estiver exatamente no meio entre dois inteiros, ele será arredondado para o inteiro ímpar
 * mais próximo (arredondamento "round half away from zero").
 *
 * @note A função retorna um valor do tipo `double`, mesmo quando o número arredondado é um inteiro exato.
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
