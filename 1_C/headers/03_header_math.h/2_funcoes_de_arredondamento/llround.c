#include <stdio.h>
#include <math.h>

/**
 * llround(): Arredonda um número para o inteiro mais próximo e retorna como tipo `long long`.
 *
 * SINTAXE: long long llround(double _X);
 *
 * @param _X O valor de entrada, que pode ser um número real (do tipo `double`).
 * @return O inteiro mais próximo de _X, arredondado conforme a regra padrão de arredondamento.
 *         O valor é retornado como um número do tipo `long long`.
 *
 * @note A função `llround` arredonda o número para o inteiro mais próximo. Se o valor de _X
 * estiver exatamente no meio entre dois inteiros, será arredondado para o inteiro ímpar mais
 * próximo (arredondamento "round half away from zero").
 *
 * @note A função retorna um valor do tipo `long long`, que pode representar inteiros maiores do que o tipo `int`.
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo como tipo long long.
 *
 * Esta função utiliza a função `llroundf` para arredondar um número float para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long long.
 */
long long return_llroundF(float x, const char *dataType)
{
    long long llroundF = llroundf(x);
    printf(" llroundF(%f) = %lld, retornando: %s\n", x, llroundF, dataType);
    return llroundF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo como tipo long long.
 *
 * Esta função utiliza a função `llround` para arredondar um número double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long long.
 */
long long return_llroundD(double x, const char *dataType)
{
    long long llroundD = llround(x);
    printf(" llroundD(%lf) = %lld, retornando: %s\n", x, llroundD, dataType);
    return llroundD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo como tipo long long.
 *
 * Esta função utiliza a função `llroundl` para arredondar um número long double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, arredondado para tipo long long.
 */
long long return_llroundLD(long double x, const char *dataType)
{
    long long llroundLD = llroundl(x);
    printf(" llroundLD(%Lf) = %lld, retornando: %s\n", x, llroundLD, dataType);
    return llroundLD;
}

int main(int argc, char **argv)
{
    long long fllround = return_llroundF(3.14F, "tipo float");
    long long dllround = return_llroundD(2.71, "tipo double");
    long long ldllround = return_llroundLD(1.618L, "tipo long double");
    return 0;
}
