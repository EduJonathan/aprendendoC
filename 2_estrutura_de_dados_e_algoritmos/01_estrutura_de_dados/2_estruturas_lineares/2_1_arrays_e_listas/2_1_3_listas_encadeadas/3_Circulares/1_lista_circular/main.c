
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_circular.h"

int main(void)
{
    Node *head = NULL;
    int option = 0, value = 0, position = 0;

    while (true)
    {
        printf("\n=== Menu de Opções ===\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir em posição específica\n");
        printf("4 - Exibir lista\n");
        printf("5 - Remover no início\n");
        printf("6 - Remover no final\n");
        printf("7 - Remover em posição específica\n");
        printf("8 - Buscar elemento\n");
        printf("9 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &option) != 1)
        {
            while (getchar() != '\n'); // Limpa buffer
            printf("Entrada inválida!\n");
            continue;
        }

        switch (option)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_front(&head, value);
            break;

        case 2:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_back(&head, value);
            break;

        case 3:
            printf("Digite o valor a ser inserido: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            printf("Digite a posição onde deseja inserir: ");
            if (scanf("%d", &position) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_at(&head, value, position);
            break;

        case 4:
            list_print(head);
            break;

        case 5:
            list_remove_front(&head);
            break;

        case 6:
            list_remove_back(&head);
            break;

        case 7:
            printf("Digite a posição do elemento que deseja remover: ");
            if (scanf("%d", &position) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }
            
            list_remove_at(&head, position);
            break;

        case 8:
            printf("Digite o valor a ser buscado: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            if (list_search(head, value))
            {
                printf("O elemento %d foi encontrado na lista.\n", value);
            }
            else
            {
                printf("O elemento %d não foi encontrado na lista.\n", value);
            }
            break;

        case 9:
            list_free(&head);
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        while (getchar() != '\n'); // Limpa buffer
    }

    /**
     * Compile e execute com:
     * gcc -std=c17 -o lista_circular main.c lista_circular.c
     * .\lista_circular.exe
     */
    return 0;
}
