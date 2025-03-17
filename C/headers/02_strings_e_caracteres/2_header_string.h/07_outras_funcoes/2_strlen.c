#include <stdio.h>
#include <string.h>

/**
 * strlen(string length): função que retorna o comprimento da cadeia de caracteres de byte
 * terminada em '\0' que é o NULL(vazio ou fim) de uma string, ou seja, o strlen retorna a
 * quantidade de caracteres que uma string possue.
 *
 * SINTAXE: size_t strlen(const char *_Str);
 *
 * @param _Str Informar um ponteiro para char (string).asm
 * @return Retorna o comprimento da cadeia de caracteres de byte terminada em '\0'.
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
