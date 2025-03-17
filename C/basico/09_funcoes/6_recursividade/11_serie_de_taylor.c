#include <stdio.h>

/**
 * @brief Calcula uma aproximação de e^x usando a série de Taylor até o n-ésimo termo.
 *
 * Esta função recursiva calcula uma aproximação de e^x usando a série de Taylor:
 * e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
 *
 * @param x O valor para o qual calcular a aproximação de e^x.
 * @param n O número de termos da série de Taylor a serem usados na aproximação.
 * @return Um valor double que é uma aproximação de e^x utilizando a série de Taylor
 * até o n-ésimo termo.
 */
double e(int x, int n)
{
    // Variáveis estáticas para armazenar p e f da série de Taylor
    double p = 1.0;
    double f = 1.0;
    double res = 0.0;

    if (n == 0)
    {
        // Caso base: quando n é zero, retorna 0
        return 0;
    }
    else
    {
        res = e(x, n - 1);  // Chamada recursiva para calcular o próximo termo da série
        p = p * x;          // Atualiza p multiplicando por x
        f = f * n;          // Atualiza f multiplicando por n
        return res + p / f; // Retorna a soma acumulada da série de Taylor
    }
}

int main(int argc, char **argv)
{
    int x = 0;
    int n = 0;
    double r = 0.0;

    printf("Entre com o valor de s: ");
    scanf("%d", &x);

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    r = e(x, n);
    printf("e^%d e igual a : %lf", x, r);
    return 0;
}
