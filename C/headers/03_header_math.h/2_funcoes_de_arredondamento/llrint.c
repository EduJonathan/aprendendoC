#include <stdio.h>
#include <math.h>

/**
 * llrint(): Arredonda um número para o inteiro mais próximo e retorna como tipo long long.
 *
 * SINTAXE: long long llrint(double _X);
 *
 * @param _X Valor a ser arredondado.
 * @return O inteiro mais próximo do valor fornecido como tipo long long.
 */

/**
 * @brief Arredonda um número float para o inteiro mais próximo, retornando como tipo long long.
 *
 * Esta função utiliza a função `llrintf` para arredondar um número float para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long long.
 */
long long return_llrintF(float x, const char *dataType)
{
    long long llrintF = llrintf(x);
    printf(" llrintF(%f) = %lld, retornando: %s\n", x, llrintF, dataType);
    return llrintF;
}

/**
 * @brief Arredonda um número double para o inteiro mais próximo, retornando como tipo long long.
 *
 * Esta função utiliza a função `llrint` para arredondar um número double para o inteiro mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long long.
 */
long long return_llrintD(double x, const char *dataType)
{
    long long llrintD = llrint(x);
    printf(" llrintD(%lf) = %lld, retornando: %s\n", x, llrintD, dataType);
    return llrintD;
}

/**
 * @brief Arredonda um número long double para o inteiro mais próximo, retornando como tipo long long.
 *
 * Esta função utiliza a função `llrintl` para arredondar um número long double para o inteiro
 * mais próximo.
 *
 * @param x Valor a ser arredondado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O inteiro mais próximo ao valor fornecido, como tipo long long.
 */
long long return_llrintLD(long double x, const char *dataType)
{
    long long llrintLD = llrintl(x);
    printf(" llrintLD(%Lf) = %lld, retornando: %s\n", x, llrintLD, dataType);
    return llrintLD;
}

int main(int argc, char **argv)
{
    long long fllrint = return_llrintF(3.14F, "tipo float");
    long long dllrint = return_llrintD(2.71, "tipo double");
    long long ldllrint = return_llrintLD(1.618L, "tipo long double");
    return 0;
}
