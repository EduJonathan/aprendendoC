#include <stdio.h>
#include <string.h>

/**
 * memcpy() Copia um bloco de memória de uma localização para outra. A função memcpy copia
 * `n` bytes do bloco de memória apontado por src para o bloco de memória apontado por dest.
 *
 * SINTAXE: void *memcpy(void *dest, const void *src, size_t n);
 *
 * @param dest - ponteiro para o array de destino onde o conteúdo deve ser copiado,
 * convertido em um ponteiro do tipo void*.
 * @param src - ponteiro para a fonte dos dados a serem copiados, convertido em um ponteiro do
 * tipo void*.
 * @param n - número de bytes a serem copiados. A função retorna um ponteiro para o destino,
 * que é dest.
 */

/**
 * Copia um bloco de memória de uma localização para outra.
 *
 * @param dest Ponteiro para o array de destino onde o conteúdo será copiado.
 * @param src Ponteiro para a fonte dos dados a serem copiados.
 * @param n Número de bytes a serem copiados.
 */
void copiarMemoria(void *dest, const void *src, size_t n) { memcpy(dest, src, n); }

int main(int argc, char **argv)
{
    char src[50] = "Hello, world!"; // String de origem
    char dest[50] = {0};            // Buffer de destino

    // Copia o conteúdo de src para dest, incluindo o caractere nulo
    copiarMemoria(dest, src, strlen(src) + 1);

    // Imprime a string original e a copiada
    printf("String de origem: %s\n", src);
    printf("String de destino: %s\n", dest);
    return 0;
}
