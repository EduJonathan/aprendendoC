#include <stdio.h>
#include <math.h>

/**
 * floor(): Arredonda para baixo um número float.
 *
 * SINTAXE: double ceil(double _X);
 *
 * @param _X Valor a ser informado.
 * @return O maior número inteiro menor ou igual ao valor fornecido.
 */

/**
 * @brief Arredonda um número float para baixo.
 *
 * @param x Valor para arredondar para baixo.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O maior número inteiro menor ou igual ao valor fornecido.
 */
float return_floorF(float x, const char *dataType)
{
    float floorF = floorf(x);
    printf(" floorF(%f) = %f, retornando : %s\n", x, floorF, dataType);
    return floorF;
}

/**
 * @brief Arredonda um número double para baixo.
 *
 * @param x Valor para arredondar para baixo.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O maior número inteiro menor ou igual ao valor fornecido.
 */
double return_floorD(double x, const char *dataType)
{
    double floorD = floor(x);
    printf(" floorD(%lf) = %lf, retornando : %s\n", x, floorD, dataType);
    return floorD;
}

/**
 * @brief Arredonda um número long double para baixo.
 *
 * @param x Valor para arredondar para baixo.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O maior número inteiro menor ou igual ao valor fornecido.
 */
long double return_floorLD(long double x, const char *dataType)
{
    long double floorLD = floorl(x);
    printf(" floorLD(%LF) = %LF, retornando : %s\n", x, floorLD, dataType);
    return floorLD;
}

int main(int argc, char **argv)
{
    float ffloor = return_floorF(3.14F, "tipo float");
    double dfloor = return_floorD(2.71, "tipo double");
    long double ldfloor = return_floorLD(1.618L, "tipo long double");
    return 0;
}
