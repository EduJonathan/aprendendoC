#include <stdio.h>
#include <math.h>

/**
 * hypot(): Calcula a hipotenusa de um triângulo retângulo dados os comprimentos dos dois catetos.
 *
 * SINTAXE: double hypot(double x, double y);
 *
 * @param x O comprimento do primeiro cateto. Deve ser maior ou igual a 0.
 * @param y O comprimento do segundo cateto. Deve ser maior ou igual a 0.
 * @return A hipotenusa do triângulo retângulo formado pelos catetos x e y.
 *         Se qualquer um dos catetos for zero, o retorno será 0.
 * 
 * @note A função `hypot` é comumente usada para calcular a hipotenusa a partir de dois números do tipo `double`.
 * @note Se ambos os catetos forem zero, a hipotenusa será 0.
 */

/**
 * @brief Calcula a hipotenusa de dois números do tipo float.
 *
 * @param x O comprimento de um cateto.
 * @param y O comprimento do outro cateto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A hipotenusa dos catetos x e y, no tipo float.
 *
 * @note A função `hypotf` é usada para calcular a hipotenusa de dois números do tipo float.
 */
float return_hypotF(float x, float y, const char *dataType)
{
    float hypotF = hypotf(x, y);
    printf("hypotF(%f, %f) = %f, retornando: %s\n", x, y, hypotF, dataType);
    return hypotF;
}

/**
 * @brief Calcula a hipotenusa de dois números do tipo double.
 *
 * @param x O comprimento de um cateto.
 * @param y O comprimento do outro cateto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A hipotenusa dos catetos x e y, no tipo double.
 *
 * @note A função `hypot` é usada para calcular a hipotenusa de dois números do tipo double.
 */
double return_hypotD(double x, double y, const char *dataType)
{
    double hypotD = hypot(x, y);
    printf("hypotD(%lf, %lf) = %lf, retornando: %s\n", x, y, hypotD, dataType);
    return hypotD;
}

/**
 * @brief Calcula a hipotenusa de dois números do tipo long double.
 *
 * @param x O comprimento de um cateto.
 * @param y O comprimento do outro cateto.
 * @param dataType Descrição do tipo de dado utilizado para a exibição.
 * @return A hipotenusa dos catetos x e y, no tipo long double.
 *
 * @note A função `hypotl` é usada para calcular a hipotenusa de dois números do tipo long double.
 */
long double return_hypotLD(long double x, long double y, const char *dataType)
{
    long double hypotLD = hypotl(x, y);
    printf("hypotLD(%LF, %LF) = %LF, retornando: %s\n", x, y, hypotLD, dataType);
    return hypotLD;
}

int main(int argc, char **argv)
{
    float fhypot = return_hypotF(3.0F, 4.0F, "tipo float");
    double dhypot = return_hypotD(5.0, 12.0, "tipo double");
    long double ldhypot = return_hypotLD(8.0L, 15.0L, "tipo long double");
    return 0;
}
