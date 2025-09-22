#include <stdio.h>
#include <string.h>

/**
 * A função `strchr()` busca o caractere `c` na string `str` e retorna um ponteiro
 * para a primeira ocorrência encontrada. Se o caractere não for encontrado,
 * retorna NULL.
 *
 * @param str Ponteiro para a string onde será feita a busca.
 * @param c   Caractere a ser procurado (passado como int, mas convertido para char).
 *
 * @return Ponteiro para a primeira ocorrência de `c` em `str`, ou NULL se não encontrado.
 */

/**
 * @brief Procura a primeira ocorrência de um caractere em uma string.
 *
 * Esta função utiliza a função `strchr` para procurar a primeira ocorrência de um caractere
 * específico na string fornecida. Se o caractere for encontrado, a posição na string é
 * impressa. Caso contrário, é exibida uma mensagem indicando que o caractere não foi encontrado.
 *
 * @param string Ponteiro para a string na qual o caractere será procurado.
 */
void procurandoCaractersComStrchr(const char *string)
{
    // Procura o primeiro caractere 'W' na string
    char *result = strchr(string, 'W');

    // Verifica se o caractere foi encontrado
    if (result != NULL)
    {
        // Calcula a posição do caractere encontrado e exibe
        printf("Caractere encontrado na posição: %ld\n", result - string);
    }
    else
    {
        printf("Caractere não encontrado na string.\n");
    }
}

int main(int argc, char **argv)
{
    // Declarando um ponteiro para char
    const char *str = "Hello, World!";

    // Chama a função para procurar o caractere 'W' na string
    procurandoCaractersComStrchr(str);
    return 0;
}
