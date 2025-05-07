#include "implementacao.h"

int main(int argc, char **argv)
{
    struct Node *head = NULL;

    printf("Digite os dados da lista\n");
    createLista(&head); // Cria a lista
    
    printf("\nExibindo a lista:\n");
    printLista(head); // Exibe a lista antes da reversão
    
    printf("\nRevertendo a lista:\n");
    reverseLista(&head); // Reverte a lista

    printf("\nExibindo a lista inversa:\n");
    printLista(head); // Exibe a lista após a reversão
    
    liberaLista(&head); // Libera a memória alocada para a lista
    
    printf("-----------------------------------\n");
    
    struct Node *no = NULL;

    printf("Digite os dados da lista\n");
    createLista(&no); // Cria a lista
    
    printf("\nExibindo a lista:\n");
    printLista(no); // Exibe a lista antes da reversão
    
    printf("\nRevertendo a lista:\n");
    reverseListaRecursiva(no); // Reverte a lista recursivamente
    
    printf("\nExibindo a lista inversa:\n");
    printLista(no); // Exibe a lista após a reversão

    liberaLista(&no); // Libera a memória alocada para a lista
    return 0;
}
