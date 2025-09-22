#include <stdio.h>
#include <string.h>

/**
 * A função `strtok_s()` divide a string `str` em tokens, utilizando o delimitador especificado
 * em `delim`. Diferente de `strtok()`, `strtok_s()` é uma versão segura, pois requer um ponteiro
 * auxiliar `context` para armazenar o estado da tokenização entre chamadas consecutivas.
 *
 * @param str     Ponteiro para a string que será tokenizada.
 * @param delim   Ponteiro para a string de delimitadores usados para dividir os tokens.
 * @param context Ponteiro auxiliar que mantém o estado da tokenização entre chamadas consecutivas.
 *
 * @return Ponteiro para o próximo token encontrado, ou NULL se não houver mais tokens.
 */

/**
 * @brief Tokeniza uma string usando strtok_s e imprime os tokens.
 *
 * @param src String a ser tokenizada.
 * @param delim Delimitador usado para dividir a string em tokens.
 */
void imprimirTokens(const char *src, const char *delim)
{
    char str[25] = {0};             // Buffer para evitar modificar a string original
    strncpy(str, src, sizeof(str)); // Copiando determinado quantidade de caracteres
    str[sizeof(str) - 1] = '\0';    // Garante que a string está bem terminada

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
