#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura para representar um nó da lista encadeada.
 */
struct Node
{
    int data;          /**< O valor armazenado no nó */
    struct Node *next; /**< Ponteiro para o próximo nó na lista */
};

#endif

void createLista(struct Node **);
void reverseLista(struct Node **);
void liberaLista(struct Node **);
void printLista(struct Node *);

#endif
