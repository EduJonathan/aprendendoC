#include <stdio.h>
#include <string.h>

/**
 * A função `strcspn()` retorna o comprimento do segmento inicial de `str1` que não contém
 * nenhum dos caracteres encontrados em `str2`. A busca para quando um caractere de `str1`
 * é encontrado em `str2`.
 *
 * @param str1 Ponteiro para a string a ser analisada.
 * @param str2 Ponteiro para a string contendo os caracteres a serem evitados.
 *
 * @return O comprimento do segmento inicial de `str1` que não contém caracteres de `str2`.
 */

/**
 * @brief Calcula e imprime o comprimento do segmento inicial de uma string que não contém
 * nenhum dos caracteres especificados em outra string.
 *
 * O programa utiliza a função `strcspn` para determinar o comprimento do segmento inicial
 * da string `str1` que não contém nenhum dos caracteres encontrados na string `str2`.
 * O comprimento encontrado é então impresso na tela.
 *
 * @param str1 Ponteiro para a string a ser analisada.
 * @param str2 Ponteiro para a string contendo os caracteres a serem evitados.
 */
void imprimirComprimentoSegmentoSemCaracteres(const char *str1, const char *str2)
{
    // Calcula o comprimento do segmento inicial sem caracteres em str2
    size_t comprimento = strcspn(str1, str2);

    // Imprime o comprimento encontrado
    printf("Tamanho inicial sem os caracteres de '%s': %zu\n", str2, comprimento);
}

int main(int argc, char **argv)
{
    const char *str1 = "Hello, World!"; // String para ser analisada
    const char *str2 = "aeiou";         // Conjunto de caracteres a serem evitados (vogais)

    // Chama a função para calcular e imprimir o comprimento do segmento inicial
    imprimirComprimentoSegmentoSemCaracteres(str1, str2);

    /*
     * `str1` é a string na qual queremos encontrar o comprimento do segmento inicial sem
     * caracteres de `str2`, e `str2` é a string contendo os caracteres a serem evitados.
     * A função `strcspn` retorna o comprimento do segmento inicial de `str1` que não contém
     * nenhum dos caracteres em `str2`. Neste caso, deve imprimir "
     * Tamanho inicial sem as vogais: 2", já que "H" e "," são os dois primeiros caracteres
     * antes de encontrar a primeira vogal na string "Hello, World!".
     */
    return 0;
}
