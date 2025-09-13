#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * strdup(): Usada para duplicar uma string, alocando memória dinamicamente para armazenar
 * uma cópia da string original.
 *
 * SINTAXE: char *strdup(const char *s);
 *
 * @param s: Um ponteiro para a string que você deseja duplicar. *
 * @return Retorna um ponteiro para uma nova string alocada dinamicamente que contém uma cópia
 * da string s. Se a alocação falhar, retorna NULL.
 *
 * @details strdup aloca memória suficiente para a nova string, que inclui o caractere nulo
 * terminador '\0'. O programador é responsável por liberar essa memória com free quando não
 * for mais necessária.
 *
 * @details strdup não é parte do padrão C, em algumas plataformas, você pode precisar
 * implementar sua própria função de duplicação.
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
