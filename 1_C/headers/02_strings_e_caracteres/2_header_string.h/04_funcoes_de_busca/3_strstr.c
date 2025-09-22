#include <stdio.h>
#include <string.h>

/**
 * A função `strstr()` busca a primeira ocorrência da substring `_SubStr` na string
 * `Str` e retorna um ponteiro para o início dessa ocorrência.
 * Se a substring não for encontrada, retorna NULL.
 *
 * @param Str Ponteiro para a string onde será feita a busca.
 * @param _SubStr   Ponteiro para a substring a ser procurada.
 *
 * @return Ponteiro para a primeira ocorrência da substring em `Str`, ou NULL se não encontrada.
 */

/**
 * @brief Procura a primeira ocorrência de uma substring em uma string.
 *
 * Esta função utiliza `strstr` para encontrar a primeira ocorrência da substring especificada
 * na string fornecida. Se a substring for encontrada, a posição inicial da substring na string
 * é exibida. Caso contrário, uma mensagem indicando que a substring não foi encontrada é exibida.
 *
 * @param string Ponteiro para a string onde a busca será realizada.
 * @param substring Ponteiro para a substring que será procurada na string.
 */
void procurandoSubstringComStrstr(const char *string, const char *substring)
{
    // Usando a função strstr para encontrar a substring na string
    char *result = strstr(string, substring);

    if (result) // Se Equivale a "result != NULL"
    {
        printf("Substring encontrada na posição: %ld\n", result - string);

        // Derreferenciando result um por um
        printf("Substring encontrada na posição: %c%c%c%c%c\n", *result, *(result + 1), *(result + 2), *(result + 3), *(result + 4));
    }
    else
    {
        printf("Substring não encontrada na string.\n");
    }
}

int main(int argc, char **argv)
{
    // String de exemplo e substring a ser procurada
    const char str[] = "Ola, Mundo! Como vai?";
    const char *substring = "Mundo";

    // Chama a função para procurar a substring
    procurandoSubstringComStrstr(str, substring);

    /*
     * A função procurandoSubstringComStrstr é usada para encontrar a primeira ocorrência da
     * substring "Mundo" na string "Ola, Mundo! Como vai?". O resultado é um ponteiro para a
     * posição inicial da substring na string. Se a substring não for encontrada, a função
     * retorna NULL.
     */

    // Iterar posição por posição com o for imprimindo os caracteres
    printf("Caracteres na posição: ");
    for (size_t i = 0; i < strlen(substring); i++)
    {
        printf("%c", substring[i]);
    }

    printf("\n");

    // Percorrendo a substring posição por posição utilizando aritmética de ponteiros
    printf("Substring encontrada: ");
    for (const char *ptr = strstr(str, substring); *ptr != '!' && *ptr != '\0'; ptr++)
    {
        printf("%c", *ptr);
    }

    printf("\n");
    return 0;
}
