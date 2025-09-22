#include <stdio.h>
#include <string.h>

/**
 * A função `strcpy()` copia todos os caracteres da string `src` (incluindo o
 * caractere nulo `'\0'`) para a string `dest`.
 *
 * @param dest Ponteiro para o destino, onde a string será copiada.
 *             Deve ter espaço suficiente para armazenar `src`.
 * @param src  Ponteiro para a string de origem.
 *
 * @return Retorna um ponteiro para `dest`.
 *
 * @note A função não verifica o tamanho de `dest`. Use com cuidado para evitar
 *       *buffer overflows*. Prefira `strncpy()` quando for necessário limitar a cópia.
 */

/**
 * @brief Função que copia o conteúdo de uma string para outra.
 *
 * @param dest Ponteiro para a string de destino onde o conteúdo será copiado.
 * @param src Ponteiro para a string de origem que será copiada para a string de destino.
 */
void copiandoStringParaOutra(char *dest, const char *src) { strcpy(dest, src); }

int main(int argc, char **argv)
{
    /* Declarando vetor de strings para utilizar a função `strcpy`. */
    char palavra1[10] = "bola";
    char palavra2[10] = "abacate";

    // Exibe o conteúdo das strings antes da cópia
    printf("\nAntes de copiar\n");

    printf("palavra 1: %s\n", palavra1); // Exibe "bola"
    printf("palavra 2: %s\n", palavra2); // Exibe "abacate"

    // Copia o conteúdo de palavra1 para palavra2
    copiandoStringParaOutra(palavra2, palavra1);

    printf("\n---------------------------------\n");

    // Exibe o conteúdo das strings depois da cópia
    printf("\nDepois de copiar\n");

    printf("palavra 1: %s\n", palavra1); // Ainda exibe "bola"
    printf("palavra 2: %s\n", palavra2); // Agora exibe "bola", o que foi copiado de palavra1

    printf("\n---------------------------------\n");

    /* Declarando vetor de strings para utilizar a função `strcpy`. */
    char palavra[11] = "Chinês";
    char nova_palavra[9] = "Japones";

    // Copia o conteúdo de palavra para nova_palavra
    copiandoStringParaOutra(nova_palavra, palavra);

    // Exibe as strings após a cópia
    printf("Primeira Nacionalidade? %s\n", palavra);     // Exibe "Chinês"
    printf("Segunda Nacionalidade? %s\n", nova_palavra); // Exibe "Chinês", o que foi copiado de palavra

    printf("\n---------------------------------\n");

    // Modifica o conteúdo da string palavra
    copiandoStringParaOutra(palavra, "Americano");
    printf("\nNacionalidade atual do palavra: %s\n", palavra); // Agora exibe "Americano"

    printf("\n---------------------------------\n");

    // Modifica o conteúdo da string nova_palavra
    copiandoStringParaOutra(nova_palavra, "Coerano");
    printf("Nacionalidade atual do nova_palavra: %s\n", nova_palavra); // Agora exibe "Coerano"
    return 0;
}
