#include <stdio.h>
#include <string.h>

/**
 * strrchr(): É usada para encontrar a última ocorrência de um caractere específico em uma string.
 *
 * SINTAXE: char *strrchr(const char *_Str, int _Ch);
 * @param _Str Insere um ponteiro para char
 * @param _Ch Insere um valor caractere para realizar a busca
 * @return Retorna um ponteiro para a primeira ocorrência de ch em str ou ponteiro NULL se ch
 * não for encontrado
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
