#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * SNPRINTF: Função que formata e armazena uma string em um buffer, garantindo que o número de caracteres
 * não ultrapasse o limite do buffer, evitando o risco de buffer overflow.
 *
 * SINTAXE: int snprintf(char *__restrict__ __stream, size_t __n, const char *__restrict__ __format, ...);
 *
 * PARÂMETROS:
 * @param __stream Buffer onde a string formatada será armazenada.
 * @param __n Tamanho máximo do buffer (incluindo o caractere nulo \0).
 * @param __format String de formato com especificadores de dados (ex: %d, %s).
 * @param ... Argumentos a serem formatados conforme o formato especificado.
 *
 * RETORNO:
 * - Retorna o número de caracteres que seriam escritos no buffer (sem contar o \0).
 * - Se o buffer for pequeno, a string será truncada.
 */

void imprimindoComSnprintf(void)
{
    const char fmt[] = "sqrt(2) = %f";
    int sz = snprintf(NULL, 0, fmt, sqrt(2)); // Calcula o tamanho necessário
    char buf[sz + 1];                         // Buffer para armazenar o resultado formatado
    snprintf(buf, sizeof(buf), fmt, sqrt(2)); // Formata e armazena no buffer

    printf("Resultado formatado: %s\n", buf);
}

int main(int argc, char **argv)
{
    imprimindoComSnprintf();

    printf("\n------------------------------------\n");

    char buffer[1024];
    int i = 35;
    int j = 0;
    double fp = 1.7320;
    char *string = "Eduardo";
    char caractere = 'l';

    /* Formatando com snprintf() uma variedade de dados */
    j = snprintf(buffer, sizeof(buffer), "%s\n", string);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%c\n", caractere);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%d\n", i);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%f\n", fp);

    // Exibe a string formatada
    printf("String formatada:\n\"%s\"\nCaractere contador = %d\n", buffer, j);

    return 0;
}
