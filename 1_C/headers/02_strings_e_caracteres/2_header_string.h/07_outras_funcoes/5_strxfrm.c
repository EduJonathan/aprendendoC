#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * strxfrm() em C é usada para transformar uma string de acordo com a ordem de
 * classificação definida pela configuração local (locale). Ela é útil para preparar
 * strings para ordenação, especialmente em contextos onde a ordem dos caracteres pode
 * variar dependendo do idioma ou das regras de ordenação.
 *
 * SINTAXE: size_t strxfrm(char *dest, const char *src, size_t n);
 *
 * @param dest Ponteiro para o buffer onde a string transformada será armazenada.
 * @param src Ponteiro para a string a ser transformada.
 * @param n O tamanho máximo do buffer dest (em bytes), incluindo o espaço para o
 * caractere nulo '\0'.
 * @return O comprimento da string transformada se o buffer for suficiente, ou -1 se o
 * buffer for muito pequeno.
 *
 * @details Retorna o comprimento da string transformada, que é o número de caracteres que
 * seriam escritos em dest se n fosse suficientemente grande. Se o valor retornado for maior
 * ou igual a n, então a string não foi completamente transformada e o conteúdo de dest pode
 * estar truncado.
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
