#include <stdio.h>

/**
 * @brief Imprime a representação binária e hexadecimal de um número float.
 *
 * Imprime a representação binária e hexadecimal de um número float.
 *
 * @param num O número float a ser impresso.
 */
void printBinaryAndHex(float num)
{
    // Cria um ponteiro para acessar os bits do número float
    unsigned int *ptr = (unsigned int *)&num;

    // Obtém o valor inteiro (32 bits) correspondente ao número float
    unsigned int bits = *ptr;

    // Imprime a representação binária
    printf("Número: %.22f\n", num);
    printf("Representação binária: ");

    // Percorre cada bit e imprime 0 ou 1
    for (int i = 31; i >= 0; i--)
    {
        // Obtem o bit na posição i
        int bit = (bits >> i) & 1;
        printf("%d", bit);

        // Adiciona espaços para melhor legibilidade
        if (i % 8 == 0)
        {
            printf(" ");
        }
    }

    // Imprime a representação hexadecimal
    printf("\nRepresentação hexadecimal: %#08X\n", bits);
}

int main(int argc, char **argv)
{
    float numero = 301.1489F;
    printBinaryAndHex(numero);
    return 0;
}
