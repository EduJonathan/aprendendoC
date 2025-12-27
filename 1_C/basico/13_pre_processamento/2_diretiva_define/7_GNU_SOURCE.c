/**
 * Se você está trabalhando em um ambiente GNU/Linux, ativar _GNU_SOURCE
 * pode ser uma boa forma de acessar essas funções adicionais, mas sempre
 * leve em consideração a portabilidade do seu código para outros sistemas.
 */

// Utilizaremos para ativar funções da header string.h, para as funções `strcasestr` e `strdup`
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // Agora você pode usar `strdup` sem problemas
    char *str = strdup("Exemplo de string");
    printf("%s\n", str);
    free(str); // Utilizar free pois strdup, retorna com alocando memória

    // Comparação de strings ignorando maiúsculas e minúsculas
    char *comparar = strcasestr("alegria", "Alegria");

    // Verifique se foi encontrado
    if (comparar != NULL)
    {
        printf("Substring encontrada: %s\n", comparar);
    }
    else
    {
        printf("Substring não encontrada.\n");
    }

    return 0;
}
