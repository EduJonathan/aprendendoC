#include <stdio.h>

/**
 * @brief Troca os valores de duas variáveis inteiras.
 *
 * Esta função troca os valores de duas variáveis inteiras. A troca é feita usando uma
 * variável temporária para armazenar o valor de uma das variáveis durante o processo.
 *
 * @param n1 Primeiro valor inteiro a ser trocado.
 * @param n2 Segundo valor inteiro a ser trocado.
 */
void troca(int *n1, int *n2)
{
    int temp;   // Variável temporária
    temp = *n1; // Armazena o conteúdo de n1 em uma variável temporária
    *n1 = *n2;  // Atribui o conteúdo de n1 a n2
    *n2 = temp; // Atribui o conteúdo temporário (n1 anterior) a n1 novamente

    printf("\nNa função TROCA: O conteúdo n1: %d\t O conteúdo n2: %d\n", *n1, *n2);
    printf("Na função TROCA: Ender. de n1: %p\t Ender. de n2: %p\n", &n1, &n2);
    printf("Na função TROCA: conteúdo de n1: %p\t conteúdo de n2: %p\n", n1, n2);
}

int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;

    // printf("Entre com o valor de X: ");
    // scanf("%d", &x);
    x = 10;

    // printf("Entre com o valor de Y: ");
    // scanf("%d", &y);
    y = 12;

    printf("\n----------------------------------------------\n");
    printf("Os valores antes da chamada por referencia\n");
    printf("X: %d Y: %d", x, y);

    printf("\n----------------------------------------------\n");
    printf("Os valores depois da chamada por referencia\n");
    troca(&x, &y);

    printf("\nX: %d Y: %d\n", x, y);
    printf("\nNa main: X: %d\t Y: %d\n", x, y);
    printf("Na MAIN: Ender. X: %p\t Ender. Y: %p\n", &x, &y);
    return 0;
}
