#include <stdio.h>
#include <string.h>

/**
 * VETOR DE CARACTERES VS PONTEIRO PARA CHAR

 * Quando usamos:
 * - char str[] = "hello": declaramos um ARRAY DE CARACTERES de tamanho 6,
 * com a liberdade de alterar cada índice.
 *
 * - char *str = "hello": declaramos um ponteiro para uma string constante literal,
 * permitindo apenas leitura, pois tentativas de modificação podem causar erros de segmentação.

 * char *(Ponteiro para Caractere):
 * - Representa um ponteiro para um caractere ou o endereço do primeiro elemento de uma matriz de caracteres.
 * - Pode apontar para um único caractere ou para o início de uma matriz de caracteres.
 * - O tamanho não é fixo e pode ser usado para apontar para memória alocada dinamicamente.

 * USO:
 * - Ambos char * e char[] são usados para manipular strings em C, mas têm diferenças sutis em termos 
 * de uso e funcionalidade.
 * - char *: é usado quando precisa de um ponteiro para uma string que pode ser
 * modificada ou reatribuída, sendo o conceito mais próximo de uma string.
 *
 * - char[]: é usado quando precisa de um array de caracteres para armazenar uma string fixa,
 * @note Ambos têm seus usos e dependem do contexto e dos requisitos do seu programa.
 */

int main(int argc, char **argv)
{
    printf("\n\tCHAR STR[]:\n");

    char str[] = "Hello";
    printf(" Valor de str antes: %s\n", str);

    str[0] = 'X';
    printf(" Valor de str depois da alteração de str[0]: %s\n", str);

    // str = "yello"; // incorreto, caso deseja alterar o conteúdo, utilizar strcpy
    strcpy(str, "yello");

    printf(" Valor de str depois da alteração de strcpy: %s\n", str);
    printf(" Qual o tamanho de str de acordo com sizeof: %zu\n", sizeof(str));    // 6
    printf(" Qual o comprimento de str de acordo com strlen: %d\n", strlen(str)); // 5

    printf("\n************************************\n");

    printf("\n\tCHAR *STR:");

    const char *str1 = "Hello";
    printf("\n Valor de str1 antes: %s\n", str1);

    // *str1[0] = 'M'; // erro
    // str1[0] = 'X'; // erro

    str1 = "yello"; // válido

    printf(" Valor de str1 depois da alteração de str1: %s\n", str1);

    printf(" Qual o tamanho da string str de acordo com sizeof: %zu\n", sizeof(str1)); // 8
    // Essa linha imprime o tamanho do ponteiro str1 usando sizeof(). Em muitos sistemas,
    // o tamanho do ponteiro é 8 bytes (em sistema de 64 bits). Portanto, o resultado será 8.
    printf(" Qual o comprimento da string str de acordo com strlen: %d\n", strlen(str1)); // 5
    return 0;
}
