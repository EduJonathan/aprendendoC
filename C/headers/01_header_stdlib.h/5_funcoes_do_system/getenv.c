#include <stdio.h>
#include <stdlib.h>

/**
 * getenv(): Retorna um ponteiro para a string contendo o valor da variável de ambiente ou
 * NULL se não estiver definida. A função variavelDeAmbiente agora retorna o valor correto.
 *
 * SINTAXE: char *getenv(const char *name);
 * 
 * @param _VarName Nome da variável de ambiente.
 * @return Ponteiro para a string contendo o valor da variável de ambiente ou NULL
 * @note Essa função pode ser usada para obter o valor de variáveis de ambiente em programas C.
 */

/**
 * @brief Obtém o valor de uma variável de ambiente.
 *
 * @param string Nome da variável de ambiente.
 * @return Valor da variável de ambiente ou NULL se não estiver definida.
 */
char *variavelDeAmbiente(const char *string) { return getenv(string); }

int main(int argc, char **argv)
{
    // Obtém o valor da variável de ambiente "PATH"
    char *path_directory = variavelDeAmbiente("PATH");

    if (path_directory != NULL)
    {
        printf("O valor da variável de ambiente PATH é: %s\n", path_directory);
    }
    else
    {
        printf("A variável de ambiente PATH não está definida.\n");
    }
    return 0;
}
