#include <stdio.h>
#include <stdlib.h>

/**
 * atof(): Converte string para Ponto Flutuante(double).
 *
 * SINTAXE: double atof(const char *_String);
 *
 * @param _String ponteiro para uma char
 * @return A string convertida para tipo `double`.
 */

/**
 * @brief Converte uma string em um número de ponto flutuante do tipo `double`.
 *
 * Esta função usa `atof` para converter uma string em um número de ponto flutuante
 * de precisão dupla.
 *
 * @param str Ponteiro para a string terminada em nulo a ser convertida.
 * @return O número de ponto flutuante convertido do tipo `double`.
 */
double stringParaDouble(const char *str)
{
    double strToDouble = atof(str);
    return strToDouble;
}

int main(int argc, char **argv)
{
    /* Declarando uma string. */
    const char *str = "123.456";

    /* Variável para armazenar o valor da string convertida.*/
    double valorConvertido = stringParaDouble(str);

    printf(" String convertida para ponto flutuante : %f\n", valorConvertido);
    printf(" Tamanho do tipo float em bytes : %zu\n", sizeof(valorConvertido));
    return 0;
}
