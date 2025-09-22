#include <stdio.h>
#include <string.h>

/**
 * A função `strpbrk()` procura a primeira ocorrência de qualquer caractere presente
 * na string `control` na string `str`. Retorna um ponteiro para o primeiro caractere
 * encontrado ou NULL se nenhum caractere da string de controle for encontrado na string fornecida.
 *
 * @param str Ponteiro para a string onde será realizada a busca.
 * @param control Ponteiro para a string contendo os caracteres a serem procurados em `str`.
 *
 * @return Ponteiro para a primeira ocorrência de qualquer caractere de `control` em `str`, ou NULL se não encontrado.
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
