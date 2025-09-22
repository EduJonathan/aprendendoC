#include <stdio.h>
#include <string.h>

/**
 * Copia no máximo n caracteres de `src` para `dest`. Se `src` for menor que `n`,
 * o restante de `dest` será preenchido com '\0'. Caso contrário, `dest` pode não
 * ser terminada com '\0'.
 *
 * @param dest Ponteiro para a string de destino (com espaço suficiente).
 * @param src  Ponteiro para a string de origem.
 * @param n    Número máximo de caracteres a copiar.
 *
 * @return Retorna um ponteiro para `dest`.
 *
 * @note Garanta a terminação com '\0' se `src` tiver tamanho >= n.
 */

/**
 * @brief Copia os primeiros n caracteres de uma string para outra.
 *
 * @param dest Ponteiro para a string de destino onde os caracteres serão copiados.
 * @param src Ponteiro para a string de origem de onde os caracteres serão copiados.
 * @param n Número máximo de caracteres a serem copiados da string de origem.
 *
 * @note Certifique-se de que o tamanho da string de destino seja grande o suficiente
 * para acomodar a cópia e o caractere nulo final.
 */
void copiarNCaracteres(char *dest, const char *src, size_t n)
{
    // Copia até n caracteres da string src para dest
    strncpy(dest, src, n);

    // Garante a terminação nula da string dest
    dest[n] = '\0';
}

int main(int argc, char **argv)
{
    char source[] = "Hello, World!"; // String de origem
    char destination[20] = {0};      // Buffer de destino

    // Número de caracteres a serem copiados
    size_t n = 5;

    // Chama a função para copiar os primeiros n caracteres
    copiarNCaracteres(destination, source, n);

    // Exibe o conteúdo das strings para verificação
    printf("Source: %s\n", source);           // Exibe "Hello, World!"
    printf("Destination: %s\n", destination); // Exibe "Hello"
    return 0;
}
