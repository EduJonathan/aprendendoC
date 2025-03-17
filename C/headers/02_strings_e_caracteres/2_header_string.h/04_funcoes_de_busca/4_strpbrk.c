#include <stdio.h>
#include <string.h>

/**
 * strpbrk(): Encontra a primeira ocorrência de qualquer caractere da string de busca na
 * string fornecida.
 *
 * SINTAXE: char *strpbrk(const char *_Str, const char *_Control);
 *
 * @param _Str: Ponteiro para a string onde será realizada a busca.
 * @param _Control: Ponteiro para a string contendo os caracteres a serem procurados na str1.
 * @return Retorna um ponteiro para a primeira ocorrência de um caractere da string de busca
 * na string fornecida ou NULL se nenhuma ocorrência for encontrada.
 */

/**
 * @brief Procura o primeiro caractere de uma string de busca em outra string.
 *
 * @param str Ponteiro para a string onde a busca será realizada.
 * @param search Ponteiro para a string de caracteres a serem procurados.
 */
void procurandoCaracteresComStrpbrk(const char *str, const char *search)
{
    // Encontrar o primeiro caractere de 'search' na string 'str'
    const char *result = strpbrk(str, search);

    if (result != NULL)
    {
        printf("Primeira ocorrência de um caractere em 'search': %c\n", *result);
    }
    else
    {
        printf("Nenhum caractere em 'search' encontrado na string.\n");
    }
}

int main(int argc, char **argv)
{
    // String de exemplo e caracteres de busca
    const char str[] = "Exemplo de uso da funcao strpbrk";
    const char search[] = "aeiou"; // Caracteres a serem procurados

    printf("String original: %s\n", str);

    // Chama a função para procurar caracteres
    procurandoCaracteresComStrpbrk(str, search);
    return 0;
}
