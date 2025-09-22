#include <stdio.h>
#include <math.h>

/**
 * log(): Calcula o logaritmo natural (ln) de _X, ou seja, o logaritmo de base e,
 * onde e é a constante de Euler (aproximadamente 2.71828).
 *
 * SINTAXE: double log(double _X);
 *
 * @param _X O número do qual será calculado o logaritmo natural. Deve ser um número positivo (x > 0).
 * @return O logaritmo natural de _X, ou seja, ln(_X), retornado como um número do tipo `double`.
 *
 * @note O logaritmo natural de um número é a potência à qual a constante de Euler (e) deve
 * ser elevada para obter o número _X. Por exemplo, log(2.71828) retorna aproximadamente 1,
 * já que e^1 = e.
 *
 * @note A função retorna um valor indefinido para valores de _X <= 0, resultando em um erro de domínio.
 *
 * @note Para valores muito pequenos de _X (próximos de zero), a função retorna um valor negativo
 * muito grande,indicando que o logaritmo de números pequenos tende a menos infinito.
 */

/**
 * @brief Calcula o logaritmo natural de x para tipo float.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo float.
 *
 * @note A função `logf` é usada para calcular o logaritmo natural para números do tipo float.
 */
float return_logF(float x, const char *dataType)
{
    float logF = logf(x);
    printf(" logF(%f) = %f, retornando: %s\n", x, logF, dataType);
    return logF;
}

/**
 * @brief Calcula o logaritmo natural de x para tipo double.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo double.
 *
 * @note A função `log` é usada para calcular o logaritmo natural para números do tipo double.
 */
double return_logD(double x, const char *dataType)
{
    double logD = log(x);
    printf(" logD(%lf) = %lf, retornando: %s\n", x, logD, dataType);
    return logD;
}

/**
 * @brief Calcula o logaritmo natural de x para tipo long double.
 *
 * @param x Valor para o qual o logaritmo é calculado. Deve ser maior que 0.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return O logaritmo natural de x, arredondado para o tipo long double.
 *
 * @note A função `logl` é usada para calcular o logaritmo natural para números do tipo long double.
 */
long double return_logLD(long double x, const char *dataType)
{
    long double logLD = logl(x);
    printf(" logLD(%LF) = %LF, retornando: %s\n", x, logLD, dataType);
    return logLD;
}

int main(int argc, char **argv)
{
    float resultF = return_logF(6.4f, "tipo float");
    double result = return_logD(5.0, "tipo double");
    long double resultLd = return_logLD(8.1L, "tipo long double");
    return 0;
}
