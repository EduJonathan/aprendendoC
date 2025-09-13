#include <stdio.h>
#include <string.h>

/**
 * strspn: Calcula o comprimento do segmento inicial de uma string que contém apenas
 * caracteres presentes em um conjunto especificado.
 *
 * SINTAXE: size_t strspn(const char *str, const char *charset);
 *
 * @param str Ponteiro para a string a ser analisada.
 * @param charset Ponteiro para o conjunto de caracteres permitidos.
 */

/**
 * @brief Calcula e imprime o comprimento do segmento inicial de uma string que contém apenas
 * caracteres presentes em um conjunto especificado.
 *
 * O programa utiliza a função `strspn` para determinar o comprimento do segmento inicial
 * da string `str` que contém apenas caracteres encontrados no conjunto `charset`.
 * O comprimento encontrado é então impresso na tela.
 *
 * @param str Ponteiro para a string a ser analisada.
 * @param charset Ponteiro para o conjunto de caracteres permitidos.
 */
void imprimirComprimentoSegmentoInicial(const char *str, const char *charset)
{
    // Calcula o comprimento do segmento inicial que contém apenas caracteres do conjunto
    size_t comprimento = strspn(str, charset);

    // Imprime o comprimento encontrado
    if (comprimento > 0)
    {
        printf("Comprimento do segmento inicial contendo apenas caracteres do conjunto: %zu\n", comprimento);
    }
    else
    {
        printf("Nenhum caractere do conjunto encontrado no início da string.\n");
    }
}

int main(int argc, char **argv)
{
    const char *str = "123abc456def";   // String para ser analisada
    const char *charset = "1234567890"; // Conjunto de caracteres permitidos

    // Chama a função para calcular e imprimir o comprimento do segmento inicial
    imprimirComprimentoSegmentoInicial(str, charset);

    /*
     * A string `str` contém números e letras, e o conjunto de caracteres `charset` contém
     * apenas dígitos. A função `strspn` é utilizada para encontrar o comprimento do segmento
     * inicial de `str` que contém apenas caracteres presentes em `charset`. O comprimento
     * encontrado é impresso na tela.
     */
    return 0;
}
