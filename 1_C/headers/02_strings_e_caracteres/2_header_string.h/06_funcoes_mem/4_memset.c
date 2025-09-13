#include <stdio.h>
#include <string.h>

/**
 * memset: Preenche bloco de memória: Define os primeiros bytes de num do bloco de memória
 * apontado por ptr para o valor especificado (interpretado como um caractere não assinado).
 * A função memset define todos os bytes do bloco de memória apontado por ptr para o valor
 * especificado.
 *
 * SINTAXE: void *memset(void *ptr, int value, size_t num );
 *
 * @param ptr Ponteiro para o bloco de memória a ser preenchido.
 * @param value Valor a ser definido para os bytes. Convertido para unsigned char.
 * @param num Número de bytes a serem preenchidos com o valor.
 * @return Um ponteiro para o bloco de memória preenchido (ptr).
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
