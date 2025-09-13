#include <stdio.h>
#include <math.h>

/**
 * fpclassify: Classifica um valor de ponto flutuante em uma das categorias
 * (normal, subnormal, zero, infinito, NaN).
 *
 * SINTAXE: #define fpclassify(x);
 *
 * @param _X Valor de ponto flutuante a ser classificado.
 */

/**
 * @brief Verifica um valor de ponto flutuante em uma das categorias de classificação de ponto
 * flutuante, usando a função fpclassify. As categorias incluem normal, subnormal, zero,
 * infinito e NaN (Not-a-Number).
 *
 * @param valor Valor de ponto flutuante a ser classificado.
 * @return Um inteiro representando a classificação do valor.
 */
int classificacao(double valor)
{
    int classification = fpclassify(valor);

    switch (classification)
    {
    case FP_NORMAL:
        printf(" O valor é normal\n");
        break;

    case FP_SUBNORMAL:
        printf(" O valor é subnormal\n");
        break;

    case FP_ZERO:
        printf(" O valor é zero\n");
        break;

    case FP_INFINITE:
        printf(" O valor é infinito\n");
        break;

    case FP_NAN:
        printf(" O valor é NaN\n");
        break;
    }
    return classification;
}

int main(int argc, char **argv)
{
    double value = 42.0;
    classificacao(value);

    double valor = sqrt(-1.0); // Calcula a raiz quadrada de um número negativo, resultando em NaN
    classificacao(valor);
    return 0;
}
