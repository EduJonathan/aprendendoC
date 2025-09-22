#include <stdio.h>
#include <math.h>

/**
 * fpclassify(): Classifica um valor de ponto flutuante em uma das categorias
 * predefinidas, com base no valor e no estado do número representado.
 * As categorias possíveis incluem:
 * - Normal: Um número de ponto flutuante que é representado normalmente.
 * - Subnormal: Um número de ponto flutuante que é muito pequeno para ser representado como um número normal.
 * - Zero: Representa o número zero, tanto positivo quanto negativo.
 * - Infinito: Representa os valores infinitos, que ocorrem em casos de divisão por zero, entre outros.
 * - NaN: Not-a-Number, usado para representar resultados indefinidos ou inválidos.
 *
 * SINTAXE: #define fpclassify(x);
 *
 * @param _X O valor de ponto flutuante a ser classificado. Esse valor pode ser um número real qualquer,
 * incluindo números normais, subnormais, zero, infinito ou NaN.
 *
 * @return A categoria do valor de ponto flutuante, representada por um inteiro que indica uma das categorias:
 * - `FP_NORMAL`: Número normal.
 * - `FP_SUBNORMAL`: Número subnormal.
 * - `FP_ZERO`: Zero.
 * - `FP_INFINITE`: Infinito.
 * - `FP_NAN`: Not-a-Number (NaN).
 *
 * @note A função `fpclassify()` é útil para verificar a natureza do valor de ponto flutuante, especialmente em cálculos numéricos que podem resultar em números especiais, como NaN ou infinito.
 * A classificação é baseada no formato interno de representação do número em ponto flutuante.
 *
 * @note Para obter os valores específicos dessas categorias, você pode usar constantes como:
 * - `FP_NORMAL`: Para números normais.
 * - `FP_SUBNORMAL`: Para números subnormais.
 * - `FP_ZERO`: Para zero.
 * - `FP_INFINITE`: Para infinito.
 * - `FP_NAN`: Para NaN.
 *
 * @note A macro `fpclassify()` não realiza operações matemáticas com o valor, apenas classifica
 * a representação interna. O valor retornado é um inteiro, e você pode usá-lo em estruturas
 * de controle, como `switch` ou `if`, para determinar a categoria de um número de ponto flutuante.
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
