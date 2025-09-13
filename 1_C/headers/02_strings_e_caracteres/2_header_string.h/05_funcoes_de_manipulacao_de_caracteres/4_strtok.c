#include <stdio.h>
#include <string.h>

/**
 * strtok: Divide uma string em tokens usando delimitadores especificados.
 *
 * SINTAXE: char *strtok(char *__restrict__ _Str, const char *__restrict__ _Delim);
 *
 * @param _Str Ponteiro para a string a ser dividida em tokens.
 * @param _Delim Ponteiro para a string contendo os delimitadores.
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
    // Aqui, você está declarando um array de caracteres chamado tempStr com o tamanho
    // igual ao tamanho da string `str`.
    char tempStr[strlen(str) + 1]; // Buffer para evitar modificar a string original

    // Copia uma quantidade específica de caracteres de uma string para outra. copia até
    // sizeof(tempStr) caracteres da string str para o array tempStr. e o sizeof(tempStr)
    // garante que você copie no máximo o tamanho do array,
    // tempStr (que é igual ao tamanho de str).
    strncpy(tempStr, str, sizeof(tempStr)); // Copia a string para o buffer

    // divide a string tempStr em tokens usando os delimitadores especificados na string
    // delimiters. A primeira chamada a strtok inicializa a tokenização, retornando o primeiro
    // token encontrado. Em chamadas subsequentes, você deve passar NULL como o primeiro
    // argumento para continuar a tokenização da mesma string.
    char *token = strtok(tempStr, delimiters); // Obtém o primeiro token

    // Itera sobre os tokens até que não haja mais
    while (token != NULL)
    {
        printf("Token: %s\n", token);     // Imprime o token atual
        token = strtok(NULL, delimiters); // Obtém o próximo token
    }
}

int main(int argc, char **argv)
{
    const char str[] = "Olá,Mundo, Exemplo!estou aqui."; // String a ser dividida
    const char delimiters[] = ",!";                      // Delimitadores utilizados para dividir a string

    // Chama a função para dividir e imprimir os tokens
    imprimirTokens(str, delimiters);

    /*
     * A função `strtok` divide a string "str" com base nos delimitadores especificados
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
