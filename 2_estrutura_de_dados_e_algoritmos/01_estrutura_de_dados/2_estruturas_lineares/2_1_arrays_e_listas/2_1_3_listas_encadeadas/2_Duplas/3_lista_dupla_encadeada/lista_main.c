#include <stdio.h>
#include <stdlib.h>
#include "lista_functions.h"

int main(int argc, char **argv)
{
    List *list = list_create();
    if (!list)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < 15; i++)
    {
        list_append(list, (i + 1) * 10);
    }

    printf("Lista em ordem normal:\n");
    list_print_forward(list);

    printf("\nLista em ordem reversa:\n");
    list_print_reverse(list);

    list_free(&list);

    /**
     * Compile e execute com:
     * gcc -std=c17 -o lista_dupla lista_main.c lista_dupla_encadeada.c
     * .\lista_dupla.exe
     */
    return 0;
}
