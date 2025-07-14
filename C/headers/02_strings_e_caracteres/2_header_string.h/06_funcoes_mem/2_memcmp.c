#include <stdio.h>
#include <string.h>

/**
 * memcmp(): Compara os primeiros n bytes das áreas de memória str1 e str2. A função memcmp
 * compara os primeiros n bytes das duas áreas de memória fornecidas. compara os primeiros n bytes
 * da área de memória str1 e da área de memória str2.
 *
 * SINTAXE: memcmp(const void *str1, const void *str2, size_t n);
 *
 * @param str1 Ponteiro para o primeiro bloco de memória.
 * @param str2 Ponteiro para o segundo bloco de memória.
 * @param n Número de bytes a serem comparados.
 * @return Menor que 0 se str1 é menor que str2; maior que 0 se str1 é maior que str2;
 * 0 se são iguais.
 *
 *              COMPARAÇÕES:
 * | menor que 0 | str1 é menor que str1      |
 * | maior que 0 | str2 é menor que str1      |
 * |    ZERO     | as duas strings são iguais |
 */

/**
 * Compara os primeiros n bytes de dois blocos de memória e imprime o resultado da comparação.
 *
 * @param str1 Ponteiro para o primeiro bloco de memória.
 * @param str2 Ponteiro para o segundo bloco de memória.
 * @param n Número de bytes a serem comparados.
 */
void compararMemoria(const void *str1, const void *str2, size_t n)
{
    int resultado = memcmp(str1, str2, n);

    if (resultado > 0)
    {
        printf("O primeiro bloco de memória é maior que o segundo bloco de memória.\n");
    }
    else if (resultado < 0)
    {
        printf("O primeiro bloco de memória é menor que o segundo bloco de memória.\n");
    }
    else
    {
        printf("Os dois blocos de memória são iguais.\n");
    }
}

int main(int argc, char **argv)
{
    char str1[15] = {0}; /**< Buffer para armazenar a primeira string */
    char str2[15] = {0}; /**< Buffer para armazenar a segunda string */

    // Copia as strings para os buffers
    memcpy(str1, "abcdef", 6); // Inclui o caractere nulo '\0'
    memcpy(str2, "ABCDEF", 6); // Inclui o caractere nulo '\0'

    // Compara os primeiros 5 bytes dos dois blocos de memória
    compararMemoria(str1, str2, 5);

    return 0;
}
