#ifndef IMPLEMENTACAO_H
#define IMPLEMENTACAO_H

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
 * @brief Função que retorna se a pilha está cheia ou não
 *
 * @param s Ponteiro para a estrutura da pilha
 * @return Retorna 1 se o topo da pilha alcançou o tamanho máximo - 1
 * (índice base 0), caso contrário retorna 0.
 */
unsigned int isFull(struct stack *s)
{
    // Verifica se o topo da pilha alcançou o tamanho máximo - 1
    return (s->top == s->size - 1) ? 1 : 0;
}

/**
 * @brief Função que retorna se a pilha está vazia ou não
 *
 * @param s Ponteiro para a estrutura da pilha
 * @return Retorna 1 se o topo da pilha é -1 (indicando que a pilha está vazia),
 * caso contrário retorna 0.
 */
unsigned int isEmpty(struct stack *s)
{
    // Verifica se o topo da pilha é -1
    return (s->top == -1) ? 1 : 0;
}

/**
 * @brief Insere um elemento na pilha, se a pilha não estiver cheia.
 *
 * @param exp Caractere a ser inserido na pilha
 * @param s Ponteiro para a estrutura da pilha
 */
void push(unsigned char exp, struct stack *s)
{
    if (isFull(s))
    {
        printf("A pilha está cheia!\n");
    }
    else
    {
        s->top++;             // Incrementa o topo da pilha
        s->arr[s->top] = exp; // Insere o caractere exp no topo da pilha
    }
}

/**
 * @brief Remove um elemento da pilha se houver um parêntese correspondente no topo.
 *
 * @param exp Caractere de parêntese de fechamento (')' ou '}')
 * @param s Ponteiro para a estrutura da pilha
 */
void pop(unsigned char exp, struct stack *s)
{
    if (exp == ')' && s->arr[s->top] == '(')
    {
        // Verifica se exp é ')' e o topo da pilha contém '('
        // Remove o '(' da pilha (decrementa o topo)
        s->top--;
    }
    else if (exp == '}' && s->arr[s->top] == '{')
    {
        // Verifica se exp é '}' e o topo da pilha contém '{'
        // Remove o '{' da pilha (decrementa o topo)
        s->top--;
    }
    else if (exp == ']' && s->arr[s->top] == '[')
    {
        // Verifica se exp é ']' e o topo da pilha contém '['
        // Remove o '[' da pilha (decrementa o topo)
        s->top--;
    }
}

/**
 * @brief Verifica o balanceamento de parênteses, colchetes e chaves em uma expressão.
 *
 * @param exp String contendo a expressão a ser verificada
 * @param s Ponteiro para a estrutura da pilha
 * @return Retorna 1 se a expressão estiver balanceada, 0 caso contrário
 */
int paranthesesMaching(unsigned char *exp, struct stack *s)
{
    // Percorre a expressão
    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            // Se for um parêntese de abertura
            // Inserir na pilha
            push(exp[i], s);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // Se for um parêntese de fechamento
            // Verifica se a pilha está vazia
            if (isEmpty(s))
            {
                printf("Parênteses não balanceados: Pilha vazia quando deveria haver um parêntese de abertura.\n");
                return 0; // Retorna 0, indicando desbalanceamento
            }

            // Remove da pilha se encontrar um parêntese de fechamento correspondente
            pop(exp[i], s);
        }
    }

    // Verifica se a pilha está vazia ao final
    if (!isEmpty(s))
    {
        printf("Parênteses não balanceados: Ainda há parênteses de abertura sem correspondência.\n");
        return 0; // Retorna 0, indicando desbalanceamento
    }

    // Retorna 1, indicando que a expressão está balanceada
    return 1;
}

#endif
