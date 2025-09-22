#include <stdio.h>
#include <string.h>

/**
 * A função `memcmp()` compara byte a byte os primeiros `n` bytes das áreas de memória
 * `str1` e `str2`. Ela retorna um valor negativo, zero ou positivo, dependendo do
 * resultado da comparação:
 *
 * - Menor que 0: se a primeira área de memória `str1` for lexicograficamente menor que `str2`.
 * - Maior que 0: se a primeira área de memória `str1` for lexicograficamente maior que `str2`.
 * - Zero: se as duas áreas de memória forem iguais nos primeiros `n` bytes.
 *
 * @param str1 Ponteiro para o primeiro bloco de memória a ser comparado.
 * @param str2 Ponteiro para o segundo bloco de memória a ser comparado.
 * @param n Número de bytes a serem comparados entre as duas áreas de memória.
 *
 * @return Valor negativo se `str1` é menor que `str2`, valor positivo se `str1` é maior que `str2`,
 * ou 0 se ambos os blocos de memória são iguais nos primeiros `n` bytes.
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
