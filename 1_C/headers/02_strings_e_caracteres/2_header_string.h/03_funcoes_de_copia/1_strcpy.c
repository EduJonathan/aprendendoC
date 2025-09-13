#include <stdio.h>
#include <string.h>

/**
 * strcpy(string copy): É uma função que ele copia um elemento de uma string e através do
 * parâmetro de acordo como inserimos na função, retornando um ponteiro do fim de uma string,
 * seu uso vem de alterar o conteúdo de uma string.
 *
 * SINTAXE: char *strcpy(char * __restrict__ __dst, const char * __restrict__ __src);
 *
 * @param dest é o parâmetro do destino da string.
 * @param src é parâmetro do conteúdo da string de origem que é essa a qual o parâmetro
 * destino (dest) irá recebe-la.
 * @return retorna um ponteiro para o fim da string.
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
