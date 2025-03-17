#ifndef FUNCIONS_PILHA_H
#define FUNCIONS_PILHA_H

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10 // Tamanho da pilha

/**
 * @brief Função para adicionar um item no topo da pilha.
 *
 * `push` ou `empilhar` é a função responsável que insere(empilha) um item na pilha.
 * Se a pilha estiver cheia, a função retorna sem inserir o item na pilha.
 *
 * @param items O array que representa os elementos da pilha.
 * @param topo O índice do topo da pilha. Inicialmente é -1.
 * @param item O item a ser inserido na pilha.
 * @return O novo topo da pilha após a inserção.
 */
int push(int items[], int topo, int item)
{
    if (topo == STACK_SIZE - 1)
    {
        printf("Pilha cheia\n");
        return topo; // Retorna o topo sem alterações
    }

    items[++topo] = item; // Insere o item no topo da pilha
    return topo;          // Retorna o novo topo
}

/**
 * @brief Função para verificar se a pilha está vazia.
 *
 * `vazia` ou `isEmpty` é a função responsável que verifica se a pilha está vazia.
 *
 * @param topo O índice do topo da pilha.
 * @return Retorna true se a pilha estiver vazia, senão retorna false.
 */
bool vazia(int topo)
{
    // Se topo é -1, a pilha está vazia
    return topo == -1;
}

/**
 * @brief Função para remover o item do topo da pilha.
 *
 * `pop` ou `desempilhar` é a função responsável de remover(desempilhar) o item do topo da pilha.
 * Se a pilha estiver vazia, a função retorna sem remover o item da pilha.
 *
 * @param items O array que representa os elementos da pilha.
 * @param topo O índice do topo da pilha. Inicialmente é -1.
 * @return O novo topo da pilha após a remoção.
 */
int pop(int items[], int topo)
{
    if (vazia(topo))
    {
        printf("Pilha vazia\n");
        return topo; // Retorna o topo sem alterações
    }

    topo--;      // Decrementa o topo e "remove" o item
    return topo; // Retorna o novo topo
}

/**
 * @brief Função para obter o item no topo da pilha sem removê-lo.
 *
 * `topo` ou `peek` é a função responsável que verifica e retorna o item no
 * topo da pilha sem removê-lo.
 *
 * @param items O array que representa os elementos da pilha.
 * @param topo O índice do topo da pilha.
 * @return O item no topo da pilha ou -1 se a pilha estiver vazia.
 */
int stackTop(int items[], int topo)
{
    if (vazia(topo))
    {
        printf("Pilha vazia\n");
        return -1; // Retorna um valor de erro
    }

    // Retorna o item no topo
    return items[topo];
}

/**
 * @brief Função para exibir todos os itens da pilha.
 *
 * Exibe os itens da pilha do topo até a base.
 *
 * @param items O array que representa os elementos da pilha.
 * @param topo O índice do topo da pilha.
 */
void exibirPilha(int items[], int topo)
{
    if (vazia(topo))
    {
        printf("Pilha vazia\n");
        return;
    }

    // Exibe os itens do topo para a base da pilha
    for (int i = topo; i >= 0; i--)
    {
        printf("%d\n", items[i]);
    }
}

#endif
