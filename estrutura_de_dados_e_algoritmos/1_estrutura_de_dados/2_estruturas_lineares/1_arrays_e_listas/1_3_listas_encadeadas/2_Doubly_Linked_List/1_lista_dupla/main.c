#include "functions.h"

int main(int argc, char **argv)
{
    struct node *head = NULL; // A cabeça é local na função main

    // Testando a lista duplamente encadeada
    inserirNoInicio(&head, 10);
    inserirNoInicio(&head, 20);
    inserirNoFinal(&head, 30);
    inserirNoFinal(&head, 40);
    inserirNoFinal(&head, 50);

    printf("\nLista após inserções: ");
    imprimir(head);

    printf("\n------------------------------------\n");
    removerNoInicio(&head); // Deleta o nó inicial de valor 20

    printf("\n------------------------------------\n");
    printf("Lista após remoção do início: ");
    imprimir(head);

    removerNoFinal(&head); // Deleta o nó final de valor 50

    printf("\n------------------------------------\n");
    printf("Lista após remoção do final: ");
    imprimir(head);

    delecaoEspecifica(&head, 10); // Deleta o nó com o valor 10

    printf("\n------------------------------------\n");
    printf("Lista após deleção especificada: ");
    imprimir(head);

    return 0;
}
