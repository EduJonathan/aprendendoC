#include <stdio.h>

/**
 * @brief Imprime a representação binária, hexadecimal e os componentes
 * (sinal, expoente e mantissa) de um número float.
 *
 * @param num O número float a ser analisado.
 */
void printFloatDetails(float num)
{
    unsigned int *ptr = (unsigned int *)&num;
    unsigned int bits = *ptr;

    // Extrai os componentes
    unsigned int sinal = (bits >> 31) & 0x1;
    unsigned int expoente = (bits >> 23) & 0xFF;
    unsigned int mantissa = bits & 0x7FFFFF;

    // Imprime o número original
    printf("Número: %.8f\n", num);

    // Imprime a representação binária completa (com separação de sinal, expoente e mantissa)
    printf("Representação binária: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (bits >> i) & 1);

        // Espaços para separar os campos
        if (i == 31 || i == 23)
        {
            printf(" ");
        }
    }

    // Imprime a representação hexadecimal
    printf("\nRepresentação hexadecimal: %#08X\n", bits);

    // Imprime os componentes
    printf("\nSinal: %u\n", sinal);
    printf("Expoente (binário): ");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (expoente >> i) & 1);
    }
    printf(" (decimal: %u)\n", expoente);

    printf("Mantissa (binário): ");
    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (mantissa >> i) & 1);
    }
    printf("\nMantissa (hexadecimal): 0x%06X\n", mantissa);

    // Calculando expoente real e valor da mantissa normalizada
    int expoenteReal = (int)expoente - 127;
    printf("\nExpoente real (bias 127): %d\n", expoenteReal);

    if (expoente != 0)
    {
        printf("Mantissa normalizada: 1.");
    }
    else
    {
        printf("Mantissa denormalizada: 0.");
    }

    // Exibe a parte fracionária da mantissa em binário
    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (mantissa >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    float numero = 301.1489F;
    printFloatDetails(numero);
    return 0;
}
