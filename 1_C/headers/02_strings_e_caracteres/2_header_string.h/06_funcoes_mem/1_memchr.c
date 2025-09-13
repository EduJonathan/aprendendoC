#include <stdio.h>
#include <string.h>

/**
 * memchr(): A função memchr procura a primeira ocorrência de um valor específico em um bloco
 * de memória. A função memchr retorna um ponteiro para a primeira ocorrência do valor
 * especificado ou NULL se o valor não for encontrado. Nos retorna um ponteiro para a primeira
 * ocorrência de ch em buffer ou ponteiro NULL se ch não for encontrado.
 *
 * SINTAXE: void memchr(const void *buffer, int Val, size_t Maxcount);
 *
 * @param buffer Ponteiro para o bloco de memória onde a pesquisa é realizada.
 * @param c Valor a ser procurado, passado como um int mas comparado byte a byte.
 * @param n Número de bytes a serem analisados.
 * @return Ponteiro para a primeira ocorrência de c ou NULL se não encontrado
 */

/**
 * Procura a primeira ocorrência de um valor específico em um bloco de memória e imprime o
 * resultado.
 *
 * @param buffer Ponteiro para o bloco de memória onde a pesquisa é realizada.
 * @param valor Valor a ser procurado, passado como um int mas comparado byte a byte.
 * @param tamanho Número de bytes a serem analisados.
 */
void buscarEImprimir(const void *buffer, int valor, size_t tamanho)
{
    const char *resultado = memchr(buffer, valor, tamanho);

    if (resultado != NULL)
    {
        printf("Primeira ocorrência de '%c' na string: %s\n", valor, resultado);
    }
    else
    {
        printf("Caractere '%c' não encontrado na string.\n", valor);
    }
}

int main(int argc, char **argv)
{
    const char str1[] = "Isto é um Teste";
    const char str2[] = "Language.Linguagem C";

    // Procura o primeiro espaço na string str1
    buscarEImprimir(str1, ' ', sizeof(str1) - 1);

    // Procura o primeiro '.' na string str2
    buscarEImprimir(str2, '.', strlen(str2));
    return 0;
}
