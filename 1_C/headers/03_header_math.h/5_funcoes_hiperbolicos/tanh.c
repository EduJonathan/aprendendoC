#include <stdio.h>
#include <math.h>

/**
 * double tanh(double): calcula a tangente hiperbólica de um ângulo em radianos.
 *
 * SINTAXE: double tanh(double _X);
 *
 * @param _X Valor a ser informado para calcular a tangente hiperbólica
 * @return A tangente hiperbólica de x, no tipo double
 *
 * Parâmetro (x)    | Valor do retorno
 * -------------------------------------
 * x = [-inf, +inf] | [-1, +1]
 * x = 0            | 0
 * x = inf          | NaN (not a number)
 */

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo float.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo float.
 *
 * @note A função `tanhf` é usada para calcular a tangente hiperbólica de um número do tipo float.
 */
float return_tanhF(float x, const char *dataType)
{
    float tanhF = tanhf(x);
    printf("tanhF(%f) = %f, retornando: %s\n", x, tanhF, dataType);
    return tanhF;
}

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo double.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo double.
 *
 * @note A função `tanh` é usada para calcular a tangente hiperbólica de um número do tipo double.
 */
double return_tanhD(double x, const char *dataType)
{
    double tanhD = tanh(x);
    printf("tanhD(%lf) = %lf, retornando: %s\n", x, tanhD, dataType);
    return tanhD;
}

/**
 * @brief Calcula a tangente hiperbólica de um número do tipo long double.
 *
 * @param x Valor para o qual a tangente hiperbólica será calculada.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A tangente hiperbólica de x, no tipo long double.
 *
 * @note A função `tanhl` é usada para calcular a tangente hiperbólica de um número do tipo
 * long double.
 */
long double return_tanhLD(long double x, const char *dataType)
{
    long double tanhLD = tanhl(x);
    printf("tanhLD(%LF) = %LF, retornando: %s\n", x, tanhLD, dataType);
    return tanhLD;
}

int main(int argc, char **argv)
{
    float ftanh = return_tanhF(0.2F, "tipo float");
    double dtanh = return_tanhD(0.5, "tipo double");
    long double ldtanh = return_tanhLD(0.8L, "tipo long double");
    return 0;
}
