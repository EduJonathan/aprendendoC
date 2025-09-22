#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * A função `strxfrm()` transforma uma string `src` para uma forma que pode ser usada em
 * operações de comparação ou ordenação de strings, conforme as regras de localidade
 * (como ordem alfabética, caracteres acentuados, etc). Isso permite que a comparação de
 * strings leve em consideração as particularidades de cada idioma ou cultura.
 *
 * @param dest Ponteiro para o buffer de destino onde a string transformada será armazenada.
 * @param src Ponteiro para a string de origem que será transformada de acordo com a localidade.
 * @param n Tamanho máximo do buffer de destino `dest`, incluindo o espaço para o caractere nulo `'\0'`.
 *
 * @return O comprimento da string transformada, ou seja, o número de caracteres que seriam
 *         copiados para `dest` se `n` fosse suficientemente grande. Se o valor retornado for
 *         maior ou igual a `n`, significa que o buffer `dest` é pequeno e o conteúdo pode
 *         estar truncado. Caso o buffer seja grande o suficiente, a string é completamente transformada.
 *
 * @details A função é útil para preparar strings para operações de ordenação e comparação,
 *          garantindo que elas respeitem as convenções de cada localidade configurada. O
 *          tamanho de `dest` deve ser suficiente para armazenar a string transformada.
 *
 * @note Se o valor retornado for maior ou igual a `n`, o conteúdo de `dest` pode estar truncado.
 *       Para garantir que toda a string seja transformada, o tamanho do buffer `dest` deve ser
 *       maior que o valor retornado.
 */

/**
 * @brief Transforma uma string de acordo com as regras de ordenação do locale atual.
 *
 * @param dest Ponteiro para o buffer onde a string transformada será armazenada.
 * @param src Ponteiro para a string a ser transformada.
 * @param n Tamanho máximo do buffer `dest`, incluindo o espaço para o caractere nulo terminador.
 * @return O comprimento da string transformada se o buffer for suficiente, ou -1 se o buffer
 * for muito pequeno.
 *
 * @note Se o valor retornado for maior ou igual a `n`, o conteúdo de `dest` pode estar truncado.
 */
int transform_string(char *dest, const char *src, size_t n)
{
    /* Armazena a função em um size_t. */
    size_t result = strxfrm(dest, src, n);

    if (result >= n)
    {
        // Retorna -1 para indicar que o buffer é muito pequeno.
        return -1;
    }

    // Retorna 0 para indicar sucesso.
    return 0;
}

int main(int argc, char **argv)
{
    // Define o locale para o idioma específico (por exemplo, "pt_BR.UTF-8" para português do Brasil)
    setlocale(LC_ALL, "pt_BR.UTF-8");

    const char *original = "cadeira";
    char transformed[100]; // Buffer para armazenar a string transformada

    // Chama a função transform_string
    int result = transform_string(transformed, original, sizeof(transformed));

    if (result == -1)
    {
        printf("Buffer insuficiente para a string transformada.\n");
    }
    else
    {
        printf("Original: %s\n", original);
        printf("Transformada: %s\n", transformed);
    }
    return 0;
}
