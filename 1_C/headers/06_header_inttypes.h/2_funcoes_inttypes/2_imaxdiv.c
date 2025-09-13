#include <stdio.h>
#include <inttypes.h>

/**
 * @brief Realiza a divisão de dois números do tipo intmax_t.
 *
 * Esta função divide o numerador pelo denominador e retorna o quociente e o resto.
 * 
 * imaxdiv(): Função que divide dois números do tipo intmax_t
 *
 * @param numer O numerador (do tipo intmax_t).
 * @param denom O denominador (do tipo intmax_t).
 * @return Uma estrutura imaxdiv_t contendo o quociente e o resto.
 */
imaxdiv_t calcula_imaxdiv(intmax_t number, intmax_t denom) { return imaxdiv(number, denom); }

int main(int argc, char **argv)
{
    intmax_t number = 10;                              // Definindo valores
    intmax_t denom = 3;                                // Definindo valores
    imaxdiv_t result = calcula_imaxdiv(number, denom); // Chamada da função

    printf("Quociente: %" PRIdMAX ", Resto: %" PRIdMAX "\n", result.quot, result.rem);
    return 0;
}
