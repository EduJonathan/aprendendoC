#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A função `strtok()` divide a string `str` em tokens, onde cada token é uma sequência
 * de caracteres delimitada por um ou mais caracteres encontrados em `delim`.
 *
 * A função substitui o delimitador por um caractere nulo (`\0`) e retorna um ponteiro
 * para o token encontrado. Chamadas subsequentes de `strtok` devem passar `NULL` como
 * o primeiro parâmetro, para continuar a tokenização da mesma string.
 *
 * @param str Ponteiro para a string a ser dividida em tokens.
 * @param delim Ponteiro para a string contendo os caracteres delimitadores.
 *
 * @return Ponteiro para o próximo token encontrado, ou NULL se não houver mais tokens.
 *
 * @note A função `strtok()` modifica a string original, substituindo os delimitadores por
 * caracteres nulos (`'\0'`). Se for necessário preservar a string original, use uma cópia dela.
 */

/**
 * @brief Divide uma string em tokens usando delimitadores especificados e imprime cada token.
 *
 * O programa utiliza a função `strtok` para dividir a string `str` em tokens com base
 * em um conjunto de delimitadores fornecidos na string `delimiters`. A função `strtok`
 * retorna cada token encontrado na string, substituindo os delimitadores por caracteres
 * nulos e retornando ponteiros para cada token. O código imprime cada token na tela.
 *
 * @param str A string a ser dividida em tokens.
 * @param delimiters A string contendo os caracteres delimitadores.
 */
void imprimirTokens(const char *str, const char *delimiters)
{
    // Aloca memória dinamicamente para o buffer temporário
    char *tempStr = (char *)malloc(strlen(str) + 1); // +1 para o caractere nulo '\0'
    if (tempStr == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return; // Retorna se a alocação falhar
    }

    // Copia a string para o buffer temporário para que a original não seja alterada
    strncpy(tempStr, str, strlen(str) + 1); // Garante que a string seja copiada corretamente

    // A primeira chamada ao strtok inicializa a tokenização
    char *token = strtok(tempStr, delimiters); // Obtém o primeiro token

    // Itera sobre os tokens até que não haja mais
    while (token != NULL)
    {
        printf("Token: %s\n", token);     // Imprime o token atual
        token = strtok(NULL, delimiters); // Obtém o próximo token
    }

    // Libera a memória alocada
    free(tempStr);
}

int main(int argc, char **argv)
{
    const char str[] = "Olá,Mundo, Exemplo!estou aqui."; // String a ser dividida
    const char delimiters[] = ",!";                      // Delimitadores utilizados para dividir a string

    // Chama a função para dividir e imprimir os tokens
    imprimirTokens(str, delimiters);

    /*
     * A função `strtok` divide a string `str` com base nos delimitadores especificados
     * (vírgula e ponto de exclamação). Ela retorna um token por vez, substituindo o
     * delimitador encontrado por um caractere nulo (`\0`).
     *
     * - A primeira chamada usa a string original como primeiro argumento.
     * - Chamadas subsequentes devem passar `NULL` no lugar da string original,
     * continuando a divisão.
     *
     * Atenção: `strtok` modifica a string original, então se precisar preservá-la, use uma cópia.
     */
    return 0;
}
