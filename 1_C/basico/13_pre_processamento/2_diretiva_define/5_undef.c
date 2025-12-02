#include <stdio.h>

/**
 * O diretivo `#undef` é utilizado para remover a definição de uma macro previamente
 * declarada com `#define`. Isso é útil quando se deseja:
 *
 *   - liberar o nome da macro para reutilização posterior,
 *   - evitar conflitos com outras definições,
 *   - redefinir uma macro com um novo valor,
 *   - garantir que trechos condicionais (#ifdef / #ifndef) reflitam o estado desejado.
 *
 * Após um `#undef`, o nome deixa de ser reconhecido como macro pelo pré-processador,
 * permitindo que seja testado com `#ifdef` ou redefinido com `#define` novamente.
 *
 * No exemplo abaixo:
 *   1. `MAX_TAMANHO` é definido como 100;
 *   2. É utilizado normalmente em um `printf`;
 *   3. Em seguida, é removido com `#undef MAX_TAMANHO`;
 *   4. O bloco condicional `#ifdef` detecta que a macro não existe mais;
 *   5. Por fim, `MAX_TAMANHO` é redefinida com um novo valor (10).
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
