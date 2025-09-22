#include <stdio.h>
#include <string.h>

/**
 * strlen(string length): Calcula e retorna o número de caracteres presentes em uma string,
 * excluindo o caractere nulo de terminação (`'\0'`). Ela percorre a string até encontrar
 * o caractere nulo, que marca o fim da string, e retorna a quantidade de caracteres
 * até esse ponto.
 *
 * @param _Str Ponteiro para a string (cadeia de caracteres) cuja longitudade será calculada.
 *
 * @return O número de caracteres da string, excluindo o caractere nulo de terminação.
 */

/**
 * @brief Calcula e imprime o comprimento de uma string.
 *
 * @param str Ponteiro para a string cuja extensão será calculada.
 */
void imprimirComprimentoDaString(const char *str)
{
    // Calcula o comprimento da string usando strlen
    size_t comprimento = strlen(str);

    // Imprime o comprimento da string
    printf("Comprimento da cadeia de caracteres str (usando strlen): %zu\n", comprimento);
}

/**
 * @brief Calcula e imprime o tamanho em bytes de uma string.
 *
 * @param str Array de caracteres cuja quantidade de bytes será calculada.
 */
void imprimirTamanhoEmBytes(const char *str)
{
    // Calcula o tamanho em bytes usando sizeof
    // O sizeof retorna o tamanho total do array incluindo o caractere de terminação nulo
    printf("Tamanho em bytes da string str (usando sizeof): %zu\n", sizeof(str));
}

int main(int argc, char **argv)
{
    char str[] = "Qual linguagem você começou a programar?";

    // Chama a função para imprimir o comprimento da string
    imprimirComprimentoDaString(str);

    // Chama a função para imprimir o tamanho em bytes da string
    imprimirTamanhoEmBytes(str);

    /**
     * Mais e o operador sizeof (tamanho de) o que ele nos retorna? tanto strlen como sizeof
     * eles irão nos retornar um tamanho de algo que procurarmos, porém a diferença é
     *
     * STRLEN: Função que nos retorna a string verificando do início até atingir o '\0'
     * enquanto o:
     *
     * SIZEOF: Operador únario que vai nos retornar a quantidade em bytes do objeto ou tipo,
     * então ele não é adequado para ver o tamanho da string
     */
    return 0;
}
