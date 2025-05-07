#include <stdio.h>
#include "lista_encadeada.h"

int main(int argc, char **argv)
{
    struct node *head = NULL; // Ponteiro para o primeiro nó da lista
    int opcao = 0;
    int valor = 0;
    int pos = 0;

    do
    {
        printf("\nEscolha uma Opções\n");
        printf("1 -> Inserir no início\n");
        printf("2 -> Inserir no final\n");
        printf("3 -> Inserir após uma posição\n");
        printf("4 -> Deletar do início\n");
        printf("5 -> Deletar do final\n");
        printf("6 -> Deletar nó específico\n");
        printf("7 -> Exibir lista: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);

            inserirNoInicio(&head, valor);
            break;

        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);

            inserirNoFinal(&head, valor);
            break;

        case 3:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);

            printf("Digite a posição após a qual inserir: ");
            scanf("%d", &pos);

            insertAfter(&head, valor, pos);
            break;

        case 4:
            deletarNoInicio(&head);
            break;

        case 5:
            deletarNoFinal(&head);
            break;

        case 6:
            printf("Digite o valor do nó a ser deletado: ");
            scanf("%d", &valor);

            delecaoEspecifica(&head, valor);
            break;

        case 7:
            exibirLista(head);
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    liberarMemoria(head);
    return 0;
}
