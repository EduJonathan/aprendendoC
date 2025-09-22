#include <stdio.h>
#include <math.h>

/**
 * lrint(): Arredonda um número para o inteiro mais próximo e retorna como tipo `long`.
 *
 * SINTAXE: long lrint(double _X);
 *
 * @param _X O valor de entrada, que pode ser um número real (do tipo `double`).
 * @return O inteiro mais próximo de _X, arredondado conforme a regra padrão de arredondamento.
 *         O valor é retornado como um número do tipo `long`.
 *
 * @note A função `lrint` arredonda o número para o inteiro mais próximo. Se o valor de _X
 * estiver exatamente no meio entre dois inteiros, será arredondado para o inteiro ímpar mais
 * próximo (arredondamento "round half away from zero").
 *
 * @note A função retorna um valor do tipo `long`, que pode representar inteiros maiores que o tipo `int`, dependendo da plataforma.
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo, retornando como tipo long.
 *
 * Esta função utiliza a função `lrintf` para arredondar um número float para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long.
 */
long return_lrintF(float x, const char *dataType)
{
    long lrintF = lrintf(x);
    printf(" lrintF(%f) = %ld, retornando: %s\n", x, lrintF, dataType);
    return lrintF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo, retornando como tipo long.
 *
 * Esta função utiliza a função `lrint` para arredondar um número double para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long.
 */
long return_lrintD(double x, const char *dataType)
{
    long lrintD = lrint(x);
    printf(" lrintD(%lf) = %ld, retornando: %s\n", x, lrintD, dataType);
    return lrintD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo, retornando como tipo long.
 *
 * Esta função utiliza a função `lrintl` para arredondar um número long double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long.
 */
long return_lrintLD(long double x, const char *dataType)
{
    long lrintLD = lrintl(x);
    printf(" lrintLD(%Lf) = %ld, retornando: %s\n", x, lrintLD, dataType);
    return lrintLD;
}

int main(int argc, char **argv)
{
    long flrint = return_lrintF(3.14F, "tipo float");
    long dlrint = return_lrintD(2.71, "tipo double");
    long ldlrint = return_lrintLD(1.618L, "tipo long double");
    return 0;
}
