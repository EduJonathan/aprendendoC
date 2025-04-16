#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura de um nó da lista duplamente encadeada
 *
 * Lista duplamente encadeada: Cada nó contém um valor (data), um ponteiro para o nó anterior
 * (prev) e um ponteiro para o nó seguinte (next). Essa estrutura é útil em cenários onde é
 * necessário acessar os elementos da lista em direções bidirecional, mais flexível, como em
 * algumas operações de manipulação de dados ou em algoritmos que necessitam de um
 * percorrimento reverso. Consome mais memória devido aos dois ponteiros por nó.
 */
struct node
{
    int data;          /**< O valor armazenado no nó */
    struct node *next; /**< Ponteiro para o nó seguinte na lista */
    struct node *prev; /**< Ponteiro para o nó anterior na lista */
};

#endif

void inserirNoInicio(struct node **, int);
void inserirNoFinal(struct node **, int);
void removerNoInicio(struct node **);
void removerNoFinal(struct node **);
void delecaoEspecifica(struct node **, int);
void imprimir(struct node *);

#endif
