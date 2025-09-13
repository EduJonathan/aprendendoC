#include "lista_circular.h"

int main(int argc, char **argv)
{
    listaCircular *head = NULL;
    int opcao = 0;
    int valorParaInserir = 0;
    int posicaoInserir = 0;
    int posicaoRemover = 0;

    do
    {
        printf("\n>>Opções\n");
        printf("1 -> Inserir no início\n");
        printf("2 -> Inserir no final\n");
        printf("3 -> Inserir em posição específica\n");
        printf("4 -> Exibir lista\n");
        printf("5 -> Remover no início\n");
        printf("6 -> Remover no final\n");
        printf("7 -> Remover em posição específica\n");
        printf("8 -> Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valorParaInserir);
            inserirNoInicio(&head, valorParaInserir);
            break;

        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valorParaInserir);
            inserirNoFinal(&head, valorParaInserir);
            break;

        case 3:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valorParaInserir);
            printf("Digite a posição onde deseja inserir: ");
            scanf("%d", &posicaoInserir);
            inserirEmPosicao(&head, valorParaInserir, posicaoInserir);
            break;

        case 4:
            exibirLista(head);
            break;

        case 5:
            removerNoInicio(&head);
            break;

        case 6:
            removerNoFinal(&head);
            break;

        case 7:
            printf("Digite a posição do elemento que deseja remover: ");
            scanf("%d", &posicaoRemover);
            removerEmPosicao(&head, posicaoRemover);
            break;

        case 8:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (opcao != 8); // Enquanto não escolher a opção 8 (Sair)

    liberarMemoria(&head);
    return 0;
}
