#include <stdio.h>
#include "list.h"

int main(int argc, char **argv)
{
    Node *head = NULL; // A cabeça é local na função main

    // Testando a lista duplamente encadeada
    list_insert_front(&head, 10);
    list_insert_front(&head, 20);
    list_insert_back(&head, 30);
    list_insert_back(&head, 40);
    list_insert_back(&head, 50);

    printf("\nLista após inserções: ");
    list_print(head);

    printf("\n------------------------------------\n");
    list_remove_front(&head); // Deleta o nó inicial de valor 20

    printf("\n------------------------------------\n");
    printf("Lista após remoção do início: ");

    list_print(head);
    list_remove_back(&head); // Deleta o nó final de valor 50

    printf("\n------------------------------------\n");
    printf("Lista após remoção do final: ");

    list_print(head);
    list_remove_value(&head, 10); // Deleta o nó com o valor 10

    printf("\n------------------------------------\n");
    printf("Lista após deleção especificada: ");
    list_print(head);

    list_free(&head);

    /**
     * Compile e execute com:
     * gcc -std=c17 -o lista_dupla main_lista_dupla.c functions_list_dupla.c
     * .\lista_dupla.exe
     */
    return 0;
}
