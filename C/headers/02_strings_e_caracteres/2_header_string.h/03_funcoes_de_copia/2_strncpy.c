#include <stdio.h>
#include <string.h>

/**
 * strncpy(): É usada para copiar os primeiros n caracteres de uma string para outra string.
 *
 * SINTAXE: char *strncpy(char *__restrict__ _Dest, const char *__restrict__ _Source, size_t _Count);
 *
 * @param dest Ponteiro para a string de destino onde os caracteres serão copiados. A string
 * dest deve ter espaço suficiente para armazenar os caracteres copiados e, se necessário, o
 * caractere nulo ('\0'). *
 * @param src Ponteiro para a string de origem que será copiada para a string de destino.
 * Esta string é a fonte dos caracteres a serem copiados. *
 * @param n Número máximo de caracteres a serem copiados da string de origem para a string de
 * destino. Se a string de origem for menor do que n, strncpy preencherá o restante da string
 * de destino com caracteres nulos ('\0'), mas se a string de origem for maior ou igual a n, a
 * string de destino não será automaticamente terminada com um caractere nulo.
 * @return Um ponteiro para a string de destino (dest).
 */

/**
 * @brief Copia os primeiros n caracteres de uma string para outra.
 *
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
    char destination[20];            // Buffer de destino

    // Número de caracteres a serem copiados
    size_t n = 5;

    // Chama a função para copiar os primeiros n caracteres
    copiarNCaracteres(destination, source, n);

    // Exibe o conteúdo das strings para verificação
    printf("Source: %s\n", source);           // Exibe "Hello, World!"
    printf("Destination: %s\n", destination); // Exibe "Hello"
    return 0;
}
