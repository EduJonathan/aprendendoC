#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * A função `strdup()` cria uma nova string alocada dinamicamente que contém uma
 * cópia exata da string fornecida, incluindo o caractere nulo de terminação `'\0'`.
 * Se a alocação de memória falhar, a função retorna `NULL`.
 *
 * @param s Ponteiro para a string que será duplicada.
 *
 * @return Retorna um ponteiro para a nova string duplicada alocada dinamicamente.
 *         Se a alocação falhar, retorna `NULL`.
 *
 * @details A função `strdup()` aloca memória suficiente para a nova string, incluindo o caractere nulo
 * de terminação `'\0'`. O programador deve garantir que a memória alocada seja liberada com `free()`
 * quando não for mais necessária.
 *
 * @note `strdup()` não faz parte do padrão C, mas é amplamente disponível em plataformas POSIX.
 * Em plataformas que não oferecem essa função, pode ser necessário implementar uma versão personalizada.
 */

/**
 * @brief Duplica uma string e imprime tanto a original quanto a duplicada. Esta função usa
 * `strdup` para criar uma duplicata da string de entrada, imprime tanto a string original
 * quanto a duplicada e então libera a memória alocada.
 *
 * @param original Ponteiro para a string terminada em nulo a ser duplicada.
 * @return Retorna 0 em caso de sucesso ou 1 se a alocação de memória falhar.
 */
int duplicate_and_print(const char *original)
{
    // Ponteiro para a string duplicada.
    char *copy = NULL;

    // Duplica a string usando strdup
    copy = strdup(original);

    // Verifica se strdup falhou na alocação de memória.
    if (copy == NULL)
    {
        // Imprime uma mensagem de erro se a alocação falhar.
        perror("strdup falhou");

        // Retorna 1 indicando falha.
        return 1;
    }

    // Imprime a string original.
    printf("Original: %s\n", original);

    // Imprime a string duplicada.
    printf("Cópia: %s\n", copy);

    // Libera a memória alocada para a string duplicada.
    free(copy);
    return 0;
}

int main(int argc, char **argv)
{
    const char *original = "Hello, World!";

    // Chama a função para duplicar e imprimir a string
    return duplicate_and_print(original);
}
