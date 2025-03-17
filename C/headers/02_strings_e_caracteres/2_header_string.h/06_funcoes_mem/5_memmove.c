#include <stdio.h>
#include <string.h>

/**
 * memmove: Copia um bloco de memória de uma localização para outra. A função memmove copia
 * `n` bytes de src para dest, garantindo que a cópia seja feita corretamente mesmo se as áreas
 * de memória se sobrepuserem. copia n caracteres de str2 a str1, mas para blocos de memória
 * sobrepostos, memmove() é uma abordagem mais segura do que memcpy().
 *
 * SINTAXE: void *memmove(void *_Dst, const void *_Src, size_t _Size);
 *
 * @param dest Ponteiro para o bloco de memória de destino.
 * @param src Ponteiro para o bloco de memória de origem.
 * @param n Número de bytes a serem copiados.
 * @return Um ponteiro para o bloco de memória de destino (dest).
 */

/**
 * copyString: Copia o conteúdo de uma string de origem para uma string de destino usando a
 * função memmove. A função memmove é utilizada para garantir que a cópia seja feita
 * corretamente, mesmo quando as áreas de memória de origem e destino se sobrepõem.
 *
 * @param dest Ponteiro para o bloco de memória de destino onde a string será copiada.
 * @param src Ponteiro para o bloco de memória de origem de onde a string será copiada.
 */
void copyString(char *dest, const char *src)
{
    // Usa memmove para copiar de src para dest, garantindo segurança em caso de sobreposição
    memmove(dest, src, strlen(src) + 1); // Inclui o caractere nulo
}

int main(int argc, char **argv)
{
    // Arrays de caracteres que podem ser modificados
    char dest[20] = "oldstring";    // Buffer de destino
    const char src[] = "newstring"; // Buffer de origem

    // Imprime o conteúdo dos buffers antes da cópia
    printf("Antes do memmove:\n");
    printf("dest = %s\n", dest);
    printf("src = %s\n", src);

    // Chama a função para copiar a string
    copyString(dest, src);

    // Imprime o conteúdo dos buffers após a cópia
    printf("Depois do memmove:\n");
    printf("dest = %s\n", dest);
    printf("src = %s\n", src);
    return 0;
}
