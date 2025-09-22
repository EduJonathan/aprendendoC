#include <stdio.h>
#include <string.h>

/**
 * A função `memmove()` copia `n` bytes do bloco de memória apontado por `src` para o bloco
 * de memória apontado por `dest`. Ao contrário de `memcpy()`, `memmove()` lida corretamente
 * com casos onde as áreas de memória se  sobrepõem. A cópia é feita de forma segura, garantindo
 * que os dados não sejam corrompidos, mesmo quando `src` e `dest` se sobrepõem.
 *
 * @param dest Ponteiro para o bloco de memória de destino, onde os dados serão copiados.
 * @param src Ponteiro para o bloco de memória de origem, de onde os dados serão copiados.
 * @param n Número de bytes a serem copiados do bloco de memória `src` para o bloco de memória `dest`.
 *
 * @return Um ponteiro para o bloco de memória de destino (`dest`).
 *
 * @note Se as áreas de memória não se sobrepõem, `memmove()` funciona de maneira semelhante
 * a `memcpy()`. No entanto, quando há sobreposição, `memmove()` garante que a cópia seja
 * feita corretamente, evitando problemas de corrupção de dados.
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
