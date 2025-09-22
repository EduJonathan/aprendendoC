#include <stdio.h>
#include <math.h>

/**
 * remquof(): Calcula o resto da divisão de ponto flutuante de _X por _Y e retorna o menor número inteiro
 * maior ou igual ao valor fornecido. Também armazena o quociente da divisão no ponteiro `quo`.
 *
 * SINTAXE: double remquof(double _X, double _Y, int *quo);
 *
 * @param _X O numerador da divisão.
 * @param _Y O denominador da divisão.
 * @param quo Um ponteiro para um inteiro onde o quociente (arredondado para o inteiro mais próximo) será armazenado.
 * @return O resto da divisão de _X por _Y, ou seja, o valor de _X - (n * _Y), onde n é o quociente arredondado. O valor retornado é do tipo `double`.
 *
 * @note A função `remquof` calcula o resto da divisão de ponto flutuante de _X por _Y,
 * semelhante a `fmod`, mas também armazena o quociente da divisão em `quo`, onde o quociente
 * será arredondado para o inteiro mais próximo.
 *
 * @note Se _Y for igual a zero, o comportamento é indefinido, podendo resultar em uma divisão por zero.
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
