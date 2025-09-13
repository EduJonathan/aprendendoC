#ifndef ROLETA_DE_ARMAS_H
#define ROLETA_DE_ARMAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_ARMA 20

/**
 * @brief Estrutura que representa um nó da lista circular.
 *
 * Cada nó contém o nome de uma arma e um ponteiro para o próximo nó.
 */
typedef struct Node
{
    char arma[MAX_NOME_ARMA]; /**< Nome da arma */
    struct Node *proximo;     /**< Ponteiro para o próximo nó */
} Node;

/**
 * @brief Estrutura que representa a roleta de armas.
 *
 * A roleta é uma lista circular onde cada nó contém o nome de uma arma e a roleta pode
 * ser manipulada para mover para a esquerda ou direita através dos nós.
 */
typedef struct
{
    Node *atual;    /**< Ponteiro para o nó atual (arma selecionada) */
    Node *anterior; /**< Ponteiro para o nó anterior ao atual */
} RoletaDeArmas;

/**
 * @brief Cria um novo nó contendo o nome de uma arma.
 *
 * Esta função aloca memória dinamicamente para um nó e o inicializa com o nome da arma.
 * O próximo nó é inicializado como NULL.
 *
 * @param arma O nome da arma que será armazenado no nó.
 * @return Um ponteiro para o nó recém-criado.
 */
Node *criar_no(const char *arma)
{
    Node *novo_no = (Node *)malloc(sizeof(Node));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(novo_no->arma, arma);
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * @brief Inicializa a roleta de armas com uma lista circular de armas.
 *
 * Esta função cria uma lista circular com os nomes das armas fornecidas no array.
 * O primeiro nó é criado e os nós subsequentes são adicionados em sequência, formando
 * uma roleta circular.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas a ser inicializada.
 * @param armas Array de strings com os nomes das armas.
 * @param num_armas Número de armas a serem adicionadas na roleta.
 */
void inicializar_roleta(RoletaDeArmas *roleta, const char *armas[], int num_armas)
{
    if (num_armas == 0)
    {
        roleta->atual = NULL;
        roleta->anterior = NULL;
        return;
    }

    // Cria o primeiro nó
    Node *primeiro_no = criar_no(armas[0]);
    roleta->atual = primeiro_no;
    roleta->anterior = primeiro_no;
    Node *ultimo_no = primeiro_no;

    // Adiciona os demais nós e conecta em forma circular
    for (int i = 1; i < num_armas; i++)
    {
        Node *novo_no = criar_no(armas[i]);
        ultimo_no->proximo = novo_no;
        ultimo_no = novo_no;
    }

    // Conecta o último nó ao primeiro para formar a lista circular
    ultimo_no->proximo = primeiro_no;
}

/**
 * @brief Move a roleta para a esquerda (nó anterior).
 *
 * A função encontra o nó anterior ao nó atual na lista circular e atualiza o ponteiro
 * para apontar para ele.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas onde a roleta será movida para a esquerda.
 */
void mover_para_esquerda(RoletaDeArmas *roleta)
{
    if (roleta->atual == NULL)
    {
        return;
    }

    // Atualiza o ponteiro anterior e atual
    roleta->anterior = roleta->atual;
    roleta->atual = roleta->atual->proximo;
}

/**
 * @brief Move a roleta para a direita (próximo nó).
 *
 * A função move o ponteiro atual da roleta para o próximo nó da lista circular.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas onde a roleta será movida para a direita.
 */
void mover_para_direita(RoletaDeArmas *roleta)
{
    if (roleta->atual == NULL)
    {
        return;
    }

    // Move para o próximo nó
    roleta->atual = roleta->atual->proximo;
    roleta->anterior = roleta->atual;
}

/**
 * @brief Exibe o conteúdo da roleta de armas.
 *
 * A função exibe todos os nomes das armas na roleta, destacando a arma atualmente selecionada.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas a ser exibida.
 */
void exibir_roleta(RoletaDeArmas *roleta)
{
    Node *no_atual = roleta->atual;

    if (roleta->atual == NULL)
    {
        printf("A roleta está vazia!\n");
        return;
    }

    do
    {
        if (no_atual == roleta->atual)
        {
            printf("[%s] <-- Selecionada\n", no_atual->arma);
        }
        else
        {
            printf("%s\n", no_atual->arma);
        }
        no_atual = no_atual->proximo;
    } while (no_atual != roleta->atual); // Para quando voltar ao início
}

/**
 * @brief Exibe o menu e processa as escolhas do usuário para controlar a roleta.
 *
 * O menu permite que o usuário mova a roleta para a esquerda ou para a direita, exiba
 * as armas na roleta ou saia do programa. A função processa a entrada do usuário e
 * executa a ação correspondente.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas a ser manipulada.
 */
void exibir_menu(RoletaDeArmas *roleta)
{
    int escolha;

    do
    {
        printf("\n--- ROLETA DE ARMAS ABERTA ---\n");
        printf("1. Mover para a esquerda\n");
        printf("2. Mover para a direita\n");
        printf("3. Exibir roleta\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &escolha) != 1)
        {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            continue;
        }

        switch (escolha)
        {
        case 1:
            mover_para_esquerda(roleta);
            exibir_roleta(roleta);
            break;

        case 2:
            mover_para_direita(roleta);
            exibir_roleta(roleta);
            break;

        case 3:
            exibir_roleta(roleta);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 0);
}

/**
 * @brief Libera a memória alocada para a roleta de armas.
 *
 * A função percorre todos os nós da lista circular e libera a memória de cada um.
 *
 * @param roleta Ponteiro para a estrutura RoletaDeArmas a ser liberada.
 */
void liberar_roleta(RoletaDeArmas *roleta)
{
    if (roleta->atual == NULL)
        return;

    Node *no_atual = roleta->atual;
    Node *no_anterior;

    // Percorre a roleta e libera a memória dos nós
    do
    {
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
        free(no_anterior);
    } while (no_atual != roleta->atual); // Para quando voltar ao início

    roleta->atual = NULL; // Garantir que o ponteiro da roleta seja nulo após a liberação
}

#endif
