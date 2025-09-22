#include <stdio.h>
#include <math.h>

/**
 * lround(): Arredonda um número para o inteiro mais próximo e retorna como tipo `long`.
 *
 * SINTAXE: long lround(double _X);
 *
 * @param _X O valor de entrada, que pode ser um número real (do tipo `double`).
 * @return O inteiro mais próximo de _X, arredondado conforme a regra padrão de arredondamento.
 *         O valor é retornado como um número do tipo `long`.
 *
 * @note A função `lround` arredonda o número para o inteiro mais próximo. Se o valor
 * de _X estiver exatamente no meio entre dois inteiros, será arredondado para o inteiro
 * ímpar mais próximo (arredondamento "round half away from zero").
 *
 * @note A função retorna um valor do tipo `long`, que pode ser maior que o tipo `int`, dependendo da plataforma.
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo.
 *
 * Esta função utiliza a função `lroundf` para arredondar um número float para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long.
 */
long return_lroundF(float x, const char *dataType)
{
    long lroundF = lroundf(x);
    printf(" lroundF(%f) = %ld, retornando: %s\n", x, lroundF, dataType);
    return lroundF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo.
 *
 * Esta função utiliza a função `lround` para arredondar um número double para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long.
 */
long return_lroundD(double x, const char *dataType)
{
    long lroundD = lround(x);
    printf(" lroundD(%lf) = %ld, retornando: %s\n", x, lroundD, dataType);
    return lroundD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo.
 *
 * Esta função utiliza a função `lroundl` para arredondar um número long double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long.
 */
long return_lroundLD(long double x, const char *dataType)
{
    long lroundLD = lroundl(x);
    printf(" lroundLD(%Lf) = %ld, retornando: %s\n", x, lroundLD, dataType);
    return lroundLD;
}

int main(int argc, char **argv)
{
    long ffloor = return_lroundF(3.14F, "tipo float");
    long dfloor = return_lroundD(2.71, "tipo double");
    long ldfloor = return_lroundLD(1.618L, "tipo long double");
    return 0;
}
