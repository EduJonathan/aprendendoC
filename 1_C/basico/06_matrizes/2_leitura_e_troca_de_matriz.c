#include <stdio.h>

/**
 * @brief Preencha uma matriz 2x2 lendo valores do usuário, e troque os valores
 * entre a primeira e a segunda linha.
 */

int main(int argc, char **argv)
{
    // Declarando uma matriz 2x2, e 2 variáveis auxiliares
    int minhaMatriz[2][2] = {{0, 0}, {0, 0}}, aux1 = 0, aux2 = 0;

    // Lendo valores de matriz por matriz
    printf("Digite um valor para [0][0]: ");
    scanf("%d", &minhaMatriz[0][0]);

    printf("Digite um valor para [0][1]: ");
    scanf("%d", &minhaMatriz[0][1]);

    printf("Digite um valor para [1][0]: ");
    scanf("%d", &minhaMatriz[1][0]);

    printf("Digite um valor para [1][1]: ");
    scanf("%d", &minhaMatriz[1][1]);

    // aux1 recebe o valor da matriz [0][0]
    aux1 = minhaMatriz[0][0];
    printf("aux1: %d\n", aux1);

    // aux1 recebe o valor da matriz [0][1]
    aux2 = minhaMatriz[0][1];
    printf("aux2: %d\n", aux2);

    // Invertendo valores usando auxiliares
    minhaMatriz[0][0] = minhaMatriz[1][0];
    minhaMatriz[0][1] = minhaMatriz[1][1];
    minhaMatriz[1][0] = aux1;
    minhaMatriz[1][1] = aux2;

    printf("\n%d %d\n", minhaMatriz[0][0], minhaMatriz[0][1]);
    printf("%d %d\n", minhaMatriz[1][0], minhaMatriz[1][1]);
    return 0;
}
