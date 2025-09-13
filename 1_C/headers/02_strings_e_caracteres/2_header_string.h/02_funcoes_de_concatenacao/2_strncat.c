#include <stdio.h>
#include <string.h>

/**
 * strncat: Função que concatena um número especificado de caracteres de uma cadeia para outra.
 *
 * SINTAXE: char *strncat(char *__restrict__ _Dest, const char *__restrict__ _Source, size_t _Count);
 *
 * @param _Dest: Ponteiro para a string de destino, que deve ter espaço suficiente para acomodar
 * a string concatenada. Esta string deve ser terminada com um caractere nulo ('\0').
 * @param Source: Ponteiro para a string de origem que será concatenada ao final da string
 * de destino. Esta string também deve ser terminada com um caractere nulo.
 * @param _Count: Número máximo de caracteres a serem concatenados da string de origem para
 * a string de destino. O valor de n pode ser menor que o comprimento da string de origem, e a
 * função concatenará apenas `n` caracteres da string de origem.
 * @return Um ponteiro para a string de destino (dest).
 */

/**
 * concatendoStringsComStrncat(): Concatena um número específico de caracteres da string
 * de origem para a string de destino.
 *
 * @param string1 Ponteiro para a string de destino (a qual a string de origem será concatenada).
 * @param string2 Ponteiro para a string de origem (a ser concatenada à string de destino).
 */
void concatendoStringsComStrncat(char *string1, const char *string2)
{
    /* O número de caracteres desejamos concatenar da string2 */
    size_t tamanhoEspecifico = 6;
    strncat(string1, string2, tamanhoEspecifico);
}

int main(int argc, char **argv)
{
    /* Definindo valores para concetar */
    char destination[20] = "Hello, ";
    const char *source = "World!";

    printf(" Antes do strncat: %s\n", destination);

    printf("\n-----------------------------\n");

    // Chamando a função para concatenar as strings
    concatendoStringsComStrncat(destination, source);

    printf(" Depois strncat: %s\n", destination);
    return 0;
}
