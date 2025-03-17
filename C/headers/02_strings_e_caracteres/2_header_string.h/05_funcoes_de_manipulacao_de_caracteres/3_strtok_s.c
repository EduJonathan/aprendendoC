#include <stdio.h>
#include <string.h>

/**
 * strtok_s: é uma função segura que requer um ponteiro auxiliar para armazenar o estado
 * da tokenização. E o strtok_s divide a string src em tokens, mas não é necessário
 * re-tokenizar cada token obtido. O código imprime os tokens de src divididos por vírgulas.
 *
 * SINTAXE: char *strtok_s(char *_Str, const char *_Delim, char **_Context);
 *
 * @param _Str Ponteiro para a string
 * @param _Delim Delimitador usado para dividir a string
 * @param _Context O ponteiro auxiliar para armazenar o estado da tokenização
 */

/**
 * @brief Tokeniza uma string usando strtok_s e imprime os tokens.
 *
 * @param src String a ser tokenizada.
 * @param delim Delimitador usado para dividir a string em tokens.
 */
void imprimirTokens(const char *src, const char *delim)
{
    // Buffer para evitar modificar a string original
    char str[25];

    // Copiando determinado quantidade de caracteres
    strncpy(str, src, sizeof(str));

    // Garante que a string está bem terminada
    str[sizeof(str) - 1] = '\0';

    // Ponteiro auxiliar para armazenar o estado da tokenização
    char *context = NULL;

    // Obtém o primeiro token
    char *token = strtok_s(str, delim, &context);

    // Itera sobre os tokens até que não haja mais tokens
    while (token != NULL)
    {
        printf("[%s]\n", token);                 // Imprime o token atual
        token = strtok_s(NULL, delim, &context); // Obtém o próximo token
    }
}

int main(int argc, char **argv)
{
    const char *src = "1, 2, 3, 5, 4, 2"; // String a ser tokenizada
    const char *delim = ",";              // Delimitador para dividir a string

    // Chama a função para imprimir os tokens
    imprimirTokens(src, delim);
    return 0;
}
