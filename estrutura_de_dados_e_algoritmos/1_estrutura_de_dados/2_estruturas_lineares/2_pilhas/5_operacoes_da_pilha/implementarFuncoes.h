#ifndef IMPLEMENTARFUNCOES_H
#define IMPLEMENTARFUNCOES_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_PILHA 100 // Tamanho máximo da pilha

// Estrutura que define a pilha
typedef struct pilha
{
    int itens[MAX_PILHA]; // Array para armazenar os elementos
    int topo;             // Índice do topo da pilha
} Pilha;

/**
 * @brief Inicializa a pilha.
 *
 * Esta função inicializa a pilha atribuindo o valor -1 ao seu índice do
 * topo, indicando que a pilha está vazia.
 *
 * @param p Ponteiro para a pilha.
 */
void inicializar(Pilha *p)
{
    // Inicializa o topo da pilha como -1, indicando que está vazia
    p->topo = -1;
}

/**
 * @brief Verifica se a pilha está vazia.
 *
 * Esta função verifica se o índice do topo da pilha é -1, indicando que
 * a pilha está vazia. Retorna 1 se a pilha estiver vazia e 0 caso contrário.
 *
 * @param p Ponteiro para a pilha.
 * @return 1 se a pilha estiver vazia, 0 caso contrário.
 */
int isEmpty(Pilha *p)
{
    // Retorna 1 se a pilha estiver vazia, 0 caso contrário
    return p->topo == -1;
}

/**
 * @brief Verifica se a pilha está cheia.
 *
 * Esta função verifica se a pilha atingiu sua capacidade máxima.
 * Retorna 1 se a pilha estiver cheia e 0 caso contrário.
 *
 * @param p Ponteiro para a pilha.
 * @return 1 se a pilha estiver cheia, 0 caso contrário.
 */
int isFull(Pilha *p)
{
    // Retorna 1 se a pilha estiver cheia, 0 caso contrário
    return p->topo == MAX_PILHA - 1;
}

/**
 * @brief Função para empilhar um elemento na pilha.
 *
 * A função verifica se a pilha está cheia. Se estiver, imprime uma mensagem
 * e não faz nada. Caso contrário, adiciona o elemento ao topo da pilha,
 * incrementando o índice do topo.
 *
 * @param p Ponteiro para a pilha.
 * @param item O elemento a ser empilhado.
 */
void empilhar(Pilha *p, int item)
{
    if (isFull(p))
    {
        printf("Pilha cheia! Não é possível empilhar o elemento %d.\n", item);
    }
    else
    {
        p->itens[++(p->topo)] = item; // Incrementa o topo e adiciona o item
        printf("Elemento %d empilhado.\n", item);
    }
}

/**
 * @brief Remove e retorna o elemento no topo da pilha.
 *
 * A função verifica se a pilha está vazia. Se estiver, imprime uma mensagem
 * e retorna -1. Caso contrário, remove o elemento do topo da pilha,
 * decrementa o índice do topo e retorna o elemento removido.
 *
 * @param p Ponteiro para a pilha.
 * @return O elemento removido do topo da pilha ou -1 se a pilha estiver vazia.
 */
int desempilhar(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia! Não há elementos para desempilhar.\n");
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    else
    {
        // Retorna o topo e decrementa o topo
        return p->itens[(p->topo)--];
    }
}

/**
 * @brief Obtém o elemento no topo da pilha sem removê-lo.
 *
 * A função verifica se a pilha está vazia e, se não estiver, retorna o
 * elemento localizado no topo. Caso a pilha esteja vazia, uma mensagem
 * é exibida e a função retorna -1.
 *
 * @param p Ponteiro para a pilha.
 * @return O elemento no topo da pilha ou -1 se a pilha estiver vazia.
 */
int topo(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia!\n");
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    else
    {
        // Retorna o elemento no topo
        return p->itens[p->topo];
    }
}

/**
 * @brief Função para obter o tamanho da pilha.
 *
 * Retorna o número de elementos armazenados na pilha.
 *
 * @param p Ponteiro para o topo da pilha.
 * @return O tamanho da pilha.
 */
int tamanho(Pilha *p)
{
    // O número de elementos é igual ao índice do topo + 1
    return p->topo + 1;
}

/**
 * @brief Insere um elemento em uma pilha ordenada.
 *
 * A função insere o elemento especificado na posição correta em uma pilha
 * já ordenada de forma não decrescente. Se a pilha estiver vazia ou o elemento
 * for maior ou igual ao elemento no topo, ele é empilhado diretamente.
 * Caso contrário, a função desempilha elementos recursivamente até encontrar
 * a posição correta para inserção, insere o elemento e reempilha os elementos
 * removidos anteriormente.
 *
 * @param p Ponteiro para a pilha onde o elemento será inserido.
 * @param item O elemento a ser inserido na pilha.
 */
void inserirOrdenado(Pilha *p, int item)
{
    // Caso base: a pilha está vazia ou o item é maior que o topo
    if (isEmpty(p) || topo(p) <= item)
    {
        empilhar(p, item);
    }
    else
    {
        // Caso recursivo: desempilhe e insira o item de forma ordenada
        int temp = desempilhar(p);
        inserirOrdenado(p, item);
        empilhar(p, temp); // Reempilhe o elemento retirado
    }
}

/**
 * @brief Função para ordenar a pilha.
 *
 * A função ordena a pilha de forma recursiva, retirando o elemento do topo,
 * ordenando os elementos restantes e inserindo o elemento de volta na pilha
 * de forma ordenada.
 *
 * @param p Ponteiro para o topo da pilha.
 */
void ordenarPilha(Pilha *p)
{
    if (!isEmpty(p))
    {
        int temp = desempilhar(p); // Retire o topo da pilha
        ordenarPilha(p);           // Ordene os elementos restantes
        inserirOrdenado(p, temp);  // Insira o topo de volta na pilha de forma ordenada
    }
}

/**
 * @brief Função para buscar um elemento na pilha.
 *
 * Percorre os elementos da pilha do topo para a base e retorna o
 * índice do elemento encontrado, ou -1 caso o elemento não seja encontrado.
 *
 * @param p Ponteiro para o topo da pilha.
 * @param item O elemento a ser buscado.
 * @return O índice do elemento encontrado, ou -1 se o elemento não for encontrado.
 */
bool buscar(Pilha *p, int item)
{
    // Percorre os elementos da pilha do topo para a base
    for (int i = p->topo; i >= 0; i--)
    {
        if (p->itens[i] == item)
        {
            // Retorna o índice do elemento encontrado
            return i;
        }
    }
    return false; // Retorna false se o elemento não for encontrado
}

/**
 * @brief Imprime os elementos da pilha.
 *
 * Percorre os elementos da pilha do topo para a base e imprime
 * cada um deles, separados por espa o, seguido de uma quebra de linha.
 *
 * @param p Ponteiro para a pilha a ser impressa.
 */
void imprimirPilha(Pilha *p)
{
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

#endif
