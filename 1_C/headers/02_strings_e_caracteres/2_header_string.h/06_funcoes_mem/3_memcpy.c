#include <stdio.h>
#include <string.h>

/**
 * A função `memcpy()` copia exatamente `n` bytes de memória de um local (src) para outro (dest).
 *
 * Ela é comumente usada para transferir dados entre arrays, buffers e estruturas de dados.
 * A função não verifica se os blocos de memória se sobrepõem; para essa situação,
 * deve-se usar a função `memmove()`.
 *
 * @param dest Ponteiro para o bloco de memória de destino onde os dados serão copiados.
 * @param src Ponteiro para o bloco de memória de origem, de onde os dados serão copiados.
 * @param n Número de bytes a serem copiados da área de memória `src` para `dest`.
 *
 * @return Um ponteiro para o bloco de memória de destino (`dest`).
 *
 * @note Se as áreas de memória `src` e `dest` se sobrepuserem, o comportamento é indefinido.
 * Para isso, use a função `memmove()`, que lida com sobreposições corretamente.
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
