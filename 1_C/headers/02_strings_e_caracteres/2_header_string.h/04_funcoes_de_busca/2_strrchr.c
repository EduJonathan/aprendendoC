#include <stdio.h>
#include <string.h>

/**
 * A função `strrchr()` busca o caractere `c` na string `str` e retorna um ponteiro
 * para a **última** ocorrência encontrada. Se o caractere não for encontrado,
 * retorna NULL.
 *
 * @param str Ponteiro para a string onde será feita a busca.
 * @param c   Caractere a ser procurado (passado como int, mas convertido para char).
 *
 * @return Ponteiro para a última ocorrência de `c` em `str`, ou NULL se não encontrado.
 */

/**
 * @brief Procura a última ocorrência de um caractere em uma string.
 *
 * Esta função utiliza `strrchr` para encontrar a última ocorrência do caractere especificado
 * na string fornecida. Se o caractere for encontrado, a posição na string é exibida. Caso
 * contrário, uma mensagem indicando que o caractere não foi encontrado é exibida.
 *
 * @param string Ponteiro para a string onde a procura será realizada.
 * @param caractere Caractere a ser procurado na string.
 */
void procurandoStringComStrrchr(const char *string)
{
    // Caractere a ser encontrado
    char caractere = 'r';

    // Encontrar a última ocorrência do caractere na string
    const char *result = strrchr(string, caractere);

    // Verifica se o caractere foi encontrado
    if (result != NULL)
    {
        int pos = result - string; // Calcula a posição do caractere na string
        printf(" A última ocorrência de '%c' está na posição %d da string.\n", caractere, pos);
    }
    else
    {
        printf(" O caractere '%c' não foi encontrado na string.\n", caractere);
    }
}

int main(int argc, char **argv)
{
    // String de exemplo
    const char *str = "Exemplo usando strrchr";

    // Chama a função para inserir o caractere
    procurandoStringComStrrchr(str);

    /*
     * A string "Exemplo de uso da strrchr", na procura da última ocorrência do caractere 'r'.
     * O resultado será a posição dessa última ocorrência na string.
     */
    return 0;
}
