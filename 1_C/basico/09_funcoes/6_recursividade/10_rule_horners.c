#include <stdio.h>

/**
 * @brief Calcula uma aproximação de e^x usando a série de Taylor até o n-ésimo termo.
 *
 * Esta função recursiva calcula uma aproximação de e^x usando a série de Taylor:
 * e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
 *
 * @param x O valor para o qual calcular a aproximação de e^x.
 * @param n O número de termos da série de Taylor a serem usados na aproximação.
 * @return Um valor double que é uma aproximação de e^x utilizando a série de Taylor até
 * o n-ésimo termo.
 */
double e(int x, int n)
{
    // Variável estática para armazenar o valor da série
    static double s = 1.0;

    if (n == 0)
    {
        // Caso base: quando n é zero, retorna o valor acumulado da série
        return s;
    }

    // Atualiza o valor da série utilizando a fórmula de Taylor
    s = 1 + x * s / n;

    // Chamada recursiva para calcular o próximo termo da série
    return e(x, n - 1);
}

int main(int argc, char **argv)
{
    int x = 0;
    int n = 0;
    double r = 0.0;

    printf("Entre com o valor de x: ");
    scanf("%d", &x);

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    r = e(x, n);
    printf("e^%d e igual a : %lf", x, r);
    return 0;
}
