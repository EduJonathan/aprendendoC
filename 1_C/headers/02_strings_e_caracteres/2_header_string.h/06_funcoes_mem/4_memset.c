#include <stdio.h>
#include <string.h>

/**
 * A função `memset()` preenche os primeiros `num` bytes do bloco de memória apontado por `ptr`
 * com o valor especificado em `value`, que é convertido para um caractere não assinado (`unsigned char`).
 * É comumente usada para inicializar ou limpar áreas de memória com um valor padrão.
 *
 * @param ptr Ponteiro para o bloco de memória que será preenchido.
 * @param value Valor a ser definido para os bytes do bloco de memória. O valor é convertido para `unsigned char`.
 * @param num Número de bytes a serem preenchidos com o valor especificado.
 *
 * @return Um ponteiro para o bloco de memória preenchido (`ptr`).
 */

/**
 * Preenche um bloco de memória com um valor específico.
 *
 * @param ptr Ponteiro para o bloco de memória a ser preenchido.
 * @param value Valor a ser definido para os bytes (convertido para unsigned char).
 * @param num Número de bytes a serem preenchidos com o valor.
 * @return Um ponteiro para o bloco de memória preenchido.
 */
void *preencherMemoria(void *ptr, int value, size_t num) { return memset(ptr, value, num); }

int main(int argc, char **argv)
{
    // Array de caracteres que pode ser modificado
    char str[50] = "almost every programmer should know memset!";

    // Preenche os primeiros 6 bytes com o caractere '-'
    preencherMemoria(str, '-', 6);

    // Imprime a string modificada
    printf("String modificada: %s\n", str);
    return 0;
}
