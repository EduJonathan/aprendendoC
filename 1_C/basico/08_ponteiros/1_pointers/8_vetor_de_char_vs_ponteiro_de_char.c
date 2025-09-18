#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * VETOR DE CARACTERES VS PONTEIRO PARA CHAR
 *
 * Quando usamos:
 * - char str[] = "hello": declaramos um ARRAY DE CARACTERES de tamanho 6,
 *   com a liberdade de alterar cada índice. A string é copiada para o array.
 * - const char *str = "hello": declaramos um ponteiro para uma string literal
 *   constante, permitindo apenas leitura, pois modificações causam erro de segmentação.
 *
 * char * (Ponteiro para Caractere):
 * - Representa o endereço do primeiro caractere de uma string ou um único caractere.
 * - Pode apontar para memória alocada dinamicamente (ex: com malloc).
 * - O tamanho não é fixo, e o ponteiro pode ser reatribuído.
 *
 * USO:
 * - char[]: Ideal para strings fixas ou mutáveis com tamanho conhecido.
 * - char *: Usado para strings constantes ou dinâmicas, com reatribuição de endereço.
 * @note A escolha depende do contexto e dos requisitos do programa.
 */

int main(int argc, char **argv)
{
    printf("\n=== DEMONSTRAÇÃO DE CHAR STR[] ===\n");

    // Array de caracteres: mutável, tamanho fixo (6 bytes, incluindo '\0')
    char str[] = "Hello";
    printf("Valor de str antes: %s\n", str);

    // Modificação direta de um caractere
    str[0] = 'X';
    printf("Valor de str após alterar str[0]: %s\n", str);

    // Modificação da string usando strncpy para segurança
    strncpy(str, "yello", sizeof(str));
    str[sizeof(str) - 1] = '\0'; // Garante terminador nulo
    printf("Valor de str após strncpy: %s\n", str);

    // sizeof(str) retorna o tamanho total do array (6 bytes)
    printf("Tamanho total do array str (sizeof): %zu bytes\n", sizeof(str));
    // strlen(str) retorna o comprimento da string (sem o '\0')
    printf("Comprimento da string str (strlen): %zu\n", strlen(str));

    printf("\n=== DEMONSTRAÇÃO DE CONST CHAR *STR ===\n");

    // Ponteiro para string literal: somente leitura, mas reatribuível
    const char *str1 = "Hello";
    printf("Valor de str1 antes: %s\n", str1);

    // str1[0] = 'X'; // ERRO: string literal é somente leitura
    // Reatribuir o ponteiro é válido
    str1 = "yello";
    printf("Valor de str1 após reatribuição: %s\n", str1);

    // sizeof(str1) retorna o tamanho do ponteiro (ex: 8 bytes em 64 bits)
    printf("Tamanho do ponteiro str1 (sizeof): %zu bytes\n", sizeof(str1));
    // strlen(str1) retorna o comprimento da string (sem o '\0')
    printf("Comprimento da string str1 (strlen): %zu\n", strlen(str1));

    printf("\n=== DEMONSTRAÇÃO DE CHAR * COM MALLOC ===\n");

    // Exemplo com memória dinâmica
    char *str2 = malloc(6 * sizeof(char)); // Aloca espaço para "Hello" + '\0'
    if (str2 == NULL)
    {
        fprintf(stderr, "Erro de alocação de memória\n");
        return 1;
    }
    strcpy(str2, "Hello");
    printf("Valor de str2 (memória dinâmica): %s\n", str2);

    // Modificação da string alocada dinamicamente
    str2[0] = 'M';
    printf("Valor de str2 após alterar str2[0]: %s\n", str2);

    // sizeof(str2) retorna o tamanho do ponteiro
    printf("Tamanho do ponteiro str2 (sizeof): %zu bytes\n", sizeof(str2));
    printf("Comprimento da string str2 (strlen): %zu\n", strlen(str2));

    // Libera memória alocada
    free(str2);
    return 0;
}
