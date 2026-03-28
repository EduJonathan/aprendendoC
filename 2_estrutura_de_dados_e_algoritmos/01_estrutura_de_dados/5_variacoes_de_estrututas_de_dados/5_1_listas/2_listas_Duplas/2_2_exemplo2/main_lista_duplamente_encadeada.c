#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function_lista.h"

int main(int argc, char **argv)
{
    Node *head = NULL;
    int option = 0, value = 0, pos = 0;

    while (true)
    {
        printf("\n=== Menu de Opções ===\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir após uma posição\n");
        printf("4 - Deletar do início\n");
        printf("5 - Deletar do final\n");
        printf("6 - Deletar nó específico\n");
        printf("7 - Exibir lista\n");
        printf("8 - Sair\n");
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

            printf("Digite a posição após a qual inserir: ");
            if (scanf("%d", &pos) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_insert_after(&head, value, pos);
            break;

        case 4:
            list_remove_front(&head);
            break;

        case 5:
            list_remove_back(&head);
            break;

        case 6:
            printf("Digite o valor do nó a ser deletado: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n');
                printf("Entrada inválida!\n");
                continue;
            }

            list_remove_value(&head, value);
            break;

        case 7:
            list_print(head);
            break;

        case 8:
            list_free(&head);
            return 0;

        default:
            printf("Opção inválida!\n");
        }
        while (getchar() != '\n'); // Limpa buffer
    }

    // Caso a opção 8 não for escolhida
    list_free(&head);

    /**
     * Compile e execute com:
     * gcc -std=c17 -o duplamente main_lista_duplamente_encadeada.c lista_duplamente_encadeada.c
     * .\duplamente.exe
     */
    return 0;
}
