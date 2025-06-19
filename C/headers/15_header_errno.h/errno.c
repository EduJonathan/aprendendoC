#include <stdio.h>
#include <errno.h>

/**
 * errno: É uma variável global que é usada para indicar o status de erro de uma operação.
 * Ela é definida por muitas funções de biblioteca C quando ocorre um erro.
 */

int main(int argc, char **argv)
{
    FILE *file = fopen("arquivo_inexistente.txt", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        printf("Código de erro: %d\n", errno);
        return 1;
    }

    // Resto do código...

    fclose(file);
    return 0;
}
