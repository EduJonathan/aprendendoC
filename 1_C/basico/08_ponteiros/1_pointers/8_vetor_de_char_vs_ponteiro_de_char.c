#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * VETOR DE CARACTERES VS. PONTEIRO PARA CHAR
 *
 * Quando usamos:
 *
 * - char str[] = "hello":
 *     Declaramos um ARRAY DE CARACTERES com tamanho 6 (incluindo '\0').
 *     A string literal é COPIADA para dentro do array, permitindo que cada
 *     posição seja modificada livremente.
 *
 * - const char *str = "hello":
 *     Declaramos um PONTEIRO para uma **string literal constante**.
 *     Esse ponteiro pode mudar para apontar para outra string, mas o conteúdo
 *     da string literal não pode ser modificado — tentativas de alteração
 *     causam comportamento indefinido (geralmente erro de segmentação).
 *
 * char * (Ponteiro para caractere):
 * - Representa o endereço de um caractere ou do primeiro caractere de uma string.
 * - Pode apontar para memória alocada dinamicamente (ex.: malloc).
 * - O ponteiro pode ser reatribuído a outro endereço.
 * - A mutabilidade depende da memória para a qual aponta.
 *
 * USO RECOMENDADO:
 * - char[] : Ideal para strings mutáveis com tamanho conhecido ou quando desejamos
 *            armazenar a cópia local da string.
 *
 * - char * : Usado para strings literais (com const) ou memória dinâmica quando
 *            precisamos alterar o tamanho ou reatribuir o ponteiro.
 *
 * @note A escolha depende do contexto: mutabilidade, tempo de vida e necessidade
 *       de realocação ou reatribuição.
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
