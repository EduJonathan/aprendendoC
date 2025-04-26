#include <stdio.h>
#include <stdint.h>

#define EPSON 0.0000001
#define EPSON_NEGATIVO -0.0000001

/**
 * @brief Imprime a representação binária e hexadecimal de um número float
 * e reconstrói o float a partir dos bits para verificação.
 *
 * @param f Número float original.
 */
void print_and_verify_float_bits(float f)
{
    uint32_t *p = (uint32_t *)&f;

    printf("Valor original: %.20f\n", f);
    printf("Hexadecimal: 0x%08X\n", *p);
    printf("Binário: ");

    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (*p >> i) & 1);
        if (i % 4 == 0 && i != 0)
            printf(" ");
    }
    printf("\n");

    // Agora reconstrói o float a partir dos bits
    uint32_t bits = *p;
    float *reconstructed = (float *)&bits;

    printf("Valor reconstruído: %.20f\n", *reconstructed);
}

int main(int argc, char **argv)
{
    // Definindo valores
    float n1 = 0.1, n2 = 0.2;

    // Soma dos valores
    float soma = n1 + n2;

    printf("%f\n", soma);
    printf("%.17f\n", soma);

    printf("------------------------------------------------\n");

    // Evite Comparações Diretas:
    if (soma == 0.3f)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    printf("------------------------------------------------\n");

    // Use uma tolerância para comparação
    if (soma - 0.3 < EPSON && soma - 0.3 > EPSON_NEGATIVO)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    printf("------------------------------------------------\n");

    float numero = 0.1f; // (≈ 0.10000000149011612)
    print_and_verify_float_bits(numero);
    return 0;
}
