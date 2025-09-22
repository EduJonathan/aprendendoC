#include <stdio.h>
#include <math.h>

/**
 * fmod(): Calcula o resto da divisão de ponto flutuante de x por y, mantendo o sinal de x.
 *
 * SINTAXE: double fmod(double _X, double _Y);
 *
 * @param _X O valor do qual será calculado o resto.
 * @param _Y O divisor usado para calcular o resto.
 * @return O resto da divisão de ponto flutuante de _X por _Y, com o mesmo sinal de _X.
 *         O valor retornado é do tipo `double`.
 *
 * @note A função `fmod` retorna o resto da divisão de ponto flutuante, ou seja, o valor de
 * _X - (n * _Y), onde n é o maior inteiro que torna a expressão válida.
 * O sinal do resultado é o mesmo que o de _X.
 *
 * @note Se _Y for igual a zero, o comportamento é indefinido e pode gerar um erro ou
 * resultado específico dependendo da implementação da biblioteca matemática utilizada.
 * Em geral, isso pode causar uma divisão por zero.
 */

/**
 * @brief Calcula o resto da divisão de ponto flutuante.
 *
 * @param x Valor do qual calcular o resto.
 * @param y Divisor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por y, com o mesmo sinal de x.
 */
float return_fmodF(float x, float y, const char *dataType)
{
    float fmodF = fmodf(x, y);
    printf(" fmodF(%f, %f) = %f, retornando : %s\n", x, y, fmodF, dataType);
    return fmodF;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante.
 *
 * @param x Valor do qual calcular o resto.
 * @param y Divisor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por y, com o mesmo sinal de x.
 */
double return_fmodD(double x, double y, const char *dataType)
{
    double fmodD = fmod(x, y);
    printf(" fmodD(%lf, %lf) = %lf, retornando : %s\n", x, y, fmodD, dataType);
    return fmodD;
}

/**
 * @brief Calcula o resto da divisão de ponto flutuante.
 *
 * @param x Valor do qual calcular o resto.
 * @param y Divisor para calcular o resto.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resto da divisão de ponto flutuante de x por y, com o mesmo sinal de x.
 */
long double return_fmodLD(long double x, long double y, const char *dataType)
{
    long double fmodLD = fmodl(x, y);
    printf(" fmodLD(%LF, %LF) = %LF, retornando : %s\n", x, y, fmodLD, dataType);
    return fmodLD;
}

int main(int argc, char **argv)
{
    float ffmod = return_fmodF(3.14F, 2.0F, "tipo float");
    double dfmod = return_fmodD(2.71, 1.5, "tipo double");
    long double ldfmod = return_fmodLD(1.618L, 1.2L, "tipo long double");
    return 0;
}
