#include <stdio.h>
#include <math.h>

/**
 * hypot(): calcula a hipotenusa de um triângulo retângulo com os dois catetos fornecidos.
 *
 * SINTAXE: double hypot(double x, double y);
 *
 * @param x O comprimento de um cateto.
 * @param y O comprimento do outro cateto.
 * @return A hipotenusa dos catetos x e y.
 * @note Erros podem ocorrer se x <= 0 e y <= 0.
 * @note A função `hypot` é usada para calcular a hipotenusa de dois números do tipo double.
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
