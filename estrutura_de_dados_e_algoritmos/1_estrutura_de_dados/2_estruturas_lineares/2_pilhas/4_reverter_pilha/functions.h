#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#ifndef PILHA_H
#define PILHA_H

/**
 * @brief Estrutura que representa um nó da pilha.
 *
 * Esta estrutura contém um valor do tipo inteiro e um ponteiro para o próximo nó da pilha.
 */
struct pilha
{
    int valor;          /**< Valor do elemento armazenado na pilha */
    struct pilha *prox; /**< Ponteiro para o próximo nó na pilha */
};

#endif

/**
 * @brief Função para gerar uma pilha.
 *
 * Esta função solicita ao usuário o tamanho da pilha e os valores dos elementos
 * que serão inseridos. A pilha é construída de forma que o primeiro elemento
 * inserido seja o topo da pilha.
 *
 * @param pilha Ponteiro duplo para o topo da pilha.
 */
void gerarPilha(struct pilha **pilha)
{
    struct pilha *aux = NULL;
    size_t tamanhoDaPilha = 0;

    printf("Digite o tamanho da pilha: ");
    scanf("%zu", &tamanhoDaPilha);

    // Verificar se o tamanho é válido
    if (tamanhoDaPilha == 0)
    {
        printf("O tamanho da pilha deve ser maior que 0.\n");
        return;
    }

    // Criação da pilha
    for (size_t i = 0; i < tamanhoDaPilha; i++)
    {
        aux = (struct pilha *)malloc(sizeof(struct pilha));

        if (aux == NULL)
        {
            printf("Erro ao alocar memória para a pilha.\n");
            return;
        }

        printf("Digite o valor para o elemento %zu: ", i + 1);
        scanf("%d", &aux->valor);

        aux->prox = *pilha; /**< Inserir no topo da pilha */
        *pilha = aux;       /**< Atualiza o topo da pilha */
    }
}

/**
 * @brief Função para imprimir os elementos da pilha.
 *
 * Esta função percorre a pilha e imprime os valores armazenados,
 * com a indicação de que o topo está à esquerda. Caso a pilha esteja vazia,
 * uma mensagem será exibida.
 *
 * @param pilha Ponteiro para o topo da pilha.
 */
void imprimirPilha(struct pilha *pilha)
{
    struct pilha *temp = pilha;

    if (pilha == NULL)
    {
        printf("Pilha vazia.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}

/**
 * @brief Função para reverter a pilha.
 *
 * Esta função reverte a pilha de maneira iterativa, invertendo os
 * ponteiros dos nós para que o último elemento inserido passe a ser o
 * topo da pilha.
 *
 * @param pilha Ponteiro duplo para o topo da pilha.
 */
void reverterPilha(struct pilha **pilha)
{
    struct pilha *prev = NULL;
    struct pilha *current = *pilha;
    struct pilha *next = NULL;

    // Reverter a pilha iterativamente
    while (current != NULL)
    {
        next = current->prox; /**< Salvar o próximo nó */
        current->prox = prev; /**< Inverter o ponteiro */
        prev = current;       /**< Avançar o "prev" */
        current = next;       /**< Avançar o "current" */
    }

    *pilha = prev; /**< Atualiza o topo da pilha */
}

/**
 * @brief Função para limpar a pilha.
 *
 * Esta função desaloca toda a memória utilizada pela pilha,
 * liberando os nós um por um. Após a execução, o ponteiro da pilha será
 * configurado para NULL.
 *
 * @param pilha Ponteiro duplo para o topo da pilha.
 */
void limparPilha(struct pilha **pilha)
{
    struct pilha *aux = NULL;

    while (*pilha != NULL)
    {
        aux = *pilha;            // Armazena o nó atual
        *pilha = (*pilha)->prox; // Avançar o topo da pilha
        free(aux);               // Libera a memória do nó
    }

    *pilha = NULL; /**< Garantir que o ponteiro da pilha seja NULL após limpar */
}

#endif
