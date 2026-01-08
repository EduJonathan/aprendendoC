#include <stdio.h>
#include <inttypes.h>

/**
 * @brief Calcula o valor absoluto de um número intmax_t.
 *
 * Esta função recebe um número do tipo intmax_t e retorna seu valor absoluto.
 *
 * imaxabs(): retorna o valor absoluto de um número intmax_t.
 *
 * @param num O número do tipo intmax_t.
 * @return O valor absoluto do número.
 */
intmax_t calcula_imaxabs(intmax_t num) { return imaxabs(num); }

int main(int argc, char **argv)
{
    intmax_t num = -12345;                  // Exemplo com número negativo
    intmax_t absNum = calcula_imaxabs(num); // Calcula o valor absoluto

    printf("Valor absoluto de %" PRIdMAX " é: %" PRIdMAX "\n", num, absNum);
    return 0;
}
