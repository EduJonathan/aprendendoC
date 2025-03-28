#include <stdio.h>

/**
 * @brief Calcula a potência de um número n elevado a um expoente b.
 *
 * @param n A base da potência.
 * @param b O expoente da potência.
 * @return O resultado recursivamente da potência n^b.
 * @note A função utiliza recursão para calcular a potência de `n` elevado a `b`.
 */
double potenciacao(double n, double b)
{
    if (b == 0)
    {
        // Caso base: n^0 = 1 para qualquer n (exceto 0^0, que é ambíguo)
        return 1;
    }
    else if ((int)b % 2 == 0)
    {
        // Se o expoente b é par, reduz pela metade
        return potenciacao(n * n, b / 2);
    }

    // Se o expoente b é ímpar, reduz o expoente em 1 antes de dividir pela metade
    return n * potenciacao(n * n, (b - 1) / 2);
}

int main(int argc, char **argv)
{
    double base = 0.0;
    double exp = 0.0;
    double res = 0.0;

    // Pede a inserção da base
    printf("Digite a base: ");
    scanf("%lf", &base);

    // Pede a inserção do expoente
    printf("Digite o expoente: ");
    scanf("%lf", &exp);

    // Armazena na variável "res" o valor retornado da função recursiva potenciacao
    res = potenciacao(base, exp);

    printf("%.2lf ^ %.2lf = %.2lf\n", base, exp, res);
    return 0;
}
