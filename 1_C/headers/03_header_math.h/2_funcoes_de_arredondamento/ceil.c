#include <stdio.h>
#include <math.h>

/**
 * ceil(): Retorna o menor número inteiro maior ou igual ao valor fornecido.
 *
 * SINTAXE: double ceil(double _X);
 *
 * @param _X O valor de entrada. Pode ser um número real (positivo ou negativo).
 * @return O menor número inteiro maior ou igual ao valor de _X, arredondado para cima.
 *         Se _X já for um número inteiro, o valor retornado será o próprio _X.
 *
 * @note A função `ceil` arredonda o número para o inteiro mais próximo, sempre para cima.
 * @note A função sempre retorna um número do tipo `double`, representando o valor arredondado.
 */

/**
 * @brief Calcula o menor número inteiro maior ou igual ao valor fornecido.
 *
 * @param x Valor para o qual calcular o ceil (o menor inteiro >= x).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 */
float return_ceilF(float x, const char *dataType)
{
    float ceilF = ceilf(x);
    printf(" ceilF(%f) = %f, retornando : %s\n", x, ceilF, dataType);
    return ceilF;
}

/**
 * @brief Calcula o menor número inteiro maior ou igual ao valor fornecido.
 *
 * @param x Valor para o qual calcular o ceil (o menor inteiro >= x).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 */
double return_ceilD(double x, const char *dataType)
{
    double ceilD = ceil(x);
    printf(" ceilD(%lf) = %lf, retornando : %s\n", x, ceilD, dataType);
    return ceilD;
}

/**
 * @brief Calcula o menor número inteiro maior ou igual ao valor fornecido.
 *
 * @param x Valor para o qual calcular o ceil (o menor inteiro >= x).
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 */
long double return_ceilLD(long double x, const char *dataType)
{
    long double ceilLD = ceill(x);
    printf(" ceilLD(%LF) = %LF, retornando : %s\n", x, ceilLD, dataType);
    return ceilLD;
}

int main(int argc, char **argv)
{
    float fceil = return_ceilF(3.14F, "tipo float");
    double dceil = return_ceilD(2.71, "tipo double");
    long double ldceil = return_ceilLD(1.618L, "tipo long double");
    return 0;
}
