#include <stdio.h>
#include <math.h>

/**
 * pow(): Calcula a potenciação.
 *
 * SINTAXE: double pow(double _X, double _Y);
 *
 * @param _X É a base
 * @param _Y Expoente que multiplica a base quantas vezes ele foi declarado
 * @return O resultado da potenciação
 * @note A função `pow` é usada para calcular a potenciação de dois números do tipo double.
 * @note Erros podem ocorrer se x <= 0 e y <= 0.
 */

/**
 * @brief Calcula a potenciação.
 *
 * @param x Base da potenciação.
 * @param y Expoente que multiplica a base quantas vezes for declarado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resultado da potenciação.
 */
float return_powF(float x, float y, const char *dataType)
{
    float powF = powf(x, y);
    printf(" powF(%f, %f) = %f, retornando: %s\n", x, y, powF, dataType);
    return powF;
}

/**
 * @brief Calcula a potenciação.
 *
 * @param x Base da potenciação.
 * @param y Expoente que multiplica a base quantas vezes for declarado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resultado da potenciação.
 */
double return_powD(double x, double y, const char *dataType)
{
    double powD = pow(x, y);
    printf(" powD(%lf, %lf) = %lf, retornando: %s\n", x, y, powD, dataType);
    return powD;
}

/**
 * @brief Calcula a potenciação.
 *
 * @param x Base da potenciação.
 * @param y Expoente que multiplica a base quantas vezes for declarado.
 * @param dataType Informar o tipo de dado utilizado para retornar o resultado.
 * @return O resultado da potenciação.
 */
long double return_powLD(long double x, long double y, const char *dataType)
{
    long double powLD = powl(x, y);
    printf(" powLD(%LF, %LF) = %LF, retornando: %s\n", x, y, powLD, dataType);
    return powLD;
}

int main(int argc, char **argv)
{
    printf("ERROS\n");
    printf("X == 0: %d\n", pow(0, 2));   // 0
    printf("X == 0: %d\n", pow(-1, 2));  // 0
    printf("Y <= 0: %d\n", pow(2, 0));   // 0
    printf("Y <= 0: %d\n", pow(-1, -1)); // 0

    float fpow = return_powF(2.0F, 3.0F, "tipo float");
    double dpow = return_powD(2.5, 2.0, "tipo double");
    long double ldpow = return_powLD(1.5L, 2.0L, "tipo long double");
    return 0;
}
