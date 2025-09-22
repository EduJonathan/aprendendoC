#include <stdio.h>
#include <string.h>

/**
 * A função `strncat()` adiciona até `n` caracteres da string `src` ao final da string `dest`,
 * e adiciona um caractere nulo (`'\0'`) ao final do resultado.
 *
 * @param dest Ponteiro para a string de destino. Deve conter espaço suficiente para o
 *               conteúdo adicional e ser terminada com `'\0'`.
 * @param src Ponteiro para a string de origem, também terminada com `'\0'`.
 * @param count Número máximo de caracteres a serem copiados de `src`.
 *
 * @return Retorna um ponteiro para `dest`.
 *
 * @note A função sempre adiciona `'\0'` no final. O uso incorreto pode causar
 *       *buffer overflow* se `dest` não tiver espaço suficiente.
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
