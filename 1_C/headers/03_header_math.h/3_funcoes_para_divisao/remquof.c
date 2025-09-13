#include <stdio.h>
#include <math.h>

/**
 * remquof(): Retorna o menor número inteiro maior ou igual ao valor fornecido.
 *
 * SINTAXE: double remquof(double _X, double _Y, int *quo);
 *
 * @param _X Numerador.
 * @param _Y Denominador.
 * @param quoc Um ponteiro para um inteiro para armazenar um valor que tem o sinal
 * e magnitude aproximada do quociente.
 */

/**
 * @brief Calcula o resto da divisão de ponto flutuante e o quociente para tipo float.
 *
 * @param x Valor para calcular o resto e o quociente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0.
 *
 * @note O quociente é armazenado no parâmetro fornecido (ponteiro para int).
 */
float return_ceilF(float x, const char *dataType)
{
    int quo = 0;
    float rem = remquof(x, 1.0f, &quo);
    printf(" remquoF(%f) = Quociente: %d, Resto: %f, retornando: %s\n", x, quo, rem, dataType);
    return rem;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante e o quociente para tipo double.
 *
 * @param x Valor para calcular o resto e o quociente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0.
 *
 * @note O quociente é armazenado no parâmetro fornecido (ponteiro para int).
 */
double return_ceilD(double x, const char *dataType)
{
    int quo = 0;
    double rem = remquo(x, 1.0, &quo);
    printf(" remquoD(%lf) = Quociente: %d, Resto: %lf, retornando: %s\n", x, quo, rem, dataType);
    return rem;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante e o quociente para tipo long double.
 *
 * @param x Valor para calcular o resto e o quociente.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por 1.0.
 *
 * @note O quociente é armazenado no parâmetro fornecido (ponteiro para int).
 */
long double return_ceilLD(long double x, const char *dataType)
{
    int quo = 0;
    long double rem = remquol(x, 1.0L, &quo);
    printf(" remquoLD(%LF) = Quociente: %d, Resto: %LF, retornando: %s\n", x, quo, rem, dataType);
    return rem;
}

int main(int argc, char **argv)
{
    float fremquo = return_ceilF(3.14F, "tipo float");
    double dremquo = return_ceilD(2.71, "tipo double");
    long double ldremquo = return_ceilLD(1.618L, "tipo long double");
    return 0;
}
