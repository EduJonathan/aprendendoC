#include <stdio.h>
#include <string.h>

/**
 * strstr(): Função utilizada para dentro de uma string, outras strings.
 *
 * SINTAXE: char *strstr(const char *_Str, const char *_SubStr);
 * @param _Str Ponteiro para a string onde será procurada a substring.
 * @param _SubStr Ponteiro para a substring que será procurada na Str.
 * @return Retorna um ponteiro para a primeira ocorrência da substring na string ou ponteiro
 * NULL se a substring nao for encontrada.
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
        printf("Substring encontrada na posição: %c%c%c%c%c\n", *result, *(result + 1), *(result + 2), *(result + 3), *(result + 4));
        /*
         * printf(" Substring encontrada na posição: %c%c%c%c%c\n", *result, *(result + 1),
         * *(result + 2), *(result + 3), *(result + 4));
         * Se retirar a operador '*' ao imprimir os caracteres da substring encontrada, você estará
         * imprimindo diretamente os valores de cada caractere, em vez de seus conteúdos.
         * Isso ocorre porque a função printf espera que você forneça os valores reais dos
         * caracteres, não os endereços de memória.
         */
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
