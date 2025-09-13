#include <stdio.h>

/**
 * #undef: É usado para remover a definição de uma macro previamente definida com #define.
 * Quando terminado de utilizar uma macro definida com #define e deseja liberar o nome
 * para ser utilizado novamente ou para evitar conflitos de definição, você pode
 * utilizar #undef.
 */

// Definimos o nome MAX_TAMANHO para o valor 100
#define MAX_TAMANHO 100

int main(int argc, char **argv)
{
    // Imprime o valor definido pela macro
    printf("Tamanho Máximo: %d\n", MAX_TAMANHO);

// Remove a definição da macro MAX_TAMANHO
#undef MAX_TAMANHO

// Verifica se a macro MAX_TAMANHO está definida ou não
#ifdef MAX_TAMANHO
    printf("Esta linha não será alcançada, pois MAX_TAMANHO foi undefinido.\n");
#else
    printf("MAX_TAMANHO não está mais definido.\n");
#endif

#define MAX_TAMANHO 10
    // Imprime o valor definido pela macro
    printf("Tamanho Máximo redefinido é: %d\n", MAX_TAMANHO);
    return 0;
}
