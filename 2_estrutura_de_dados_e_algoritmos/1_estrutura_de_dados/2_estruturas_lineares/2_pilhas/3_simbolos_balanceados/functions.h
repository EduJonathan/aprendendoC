#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief Estrutura de pilha para armazenar elementos de caracteres
 *
 * Definição da estrutura de pilha
 */
struct stack
{
    unsigned int size;  /**< Tamanho máximo da pilha */
    unsigned int top;   /**< Índice do topo da pilha */
    unsigned char *arr; /**< Array que armazena os elementos da pilha */
};

unsigned int isFull(struct stack *);
unsigned int isEmpty(struct stack *);
void push(unsigned char, struct stack *);
void pop(unsigned char, struct stack *);
void paranthesesMaching(unsigned char *, struct stack *);

#endif
