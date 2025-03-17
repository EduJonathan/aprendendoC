#include <stdio.h>

#define EPSON 0.0000001
#define EPSON_NEGATIVO -0.0000001

// Exiba uma a soma de dois números floats: 0.1 e 0.2 contendo 17 casas decimais

int main(int argc, char **argv)
{
    // Definindo valores
    float n1 = 0.1, n2 = 0.2;

    // Soma dos valores
    float soma = n1 + n2;

    printf("%f\n", soma);
    printf("%.17f\n", soma);

    if (soma == 0.3)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    // Use uma tolerância para comparação
    if (soma - 0.3 < EPSON && soma - 0.3 > EPSON_NEGATIVO)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    return 0;
}
