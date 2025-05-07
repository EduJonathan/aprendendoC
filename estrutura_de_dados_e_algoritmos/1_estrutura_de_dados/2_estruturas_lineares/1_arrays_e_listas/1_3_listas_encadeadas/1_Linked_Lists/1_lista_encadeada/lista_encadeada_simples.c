#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

/**
 * @struct Node
 *
 * @brief Estrutura para representar um nó da lista encadeada.
 *
 * LISTA ENCADEADA: Uma lista encadeada é composta por nós (elementos individuais),
 * onde cada nó contém: O dado (por exemplo, um número, caractere, etc.). Um ponteiro
 * para o próximo nó. Os nós não são armazenados em um bloco contíguo de memória.
 * Cada nó pode estar em uma parte diferente da memória, e a relação entre os nós é
 * feita através dos ponteiros. Não há um índice direto, então o acesso aos elementos
 * geralmente exige uma perdição sequencial (percorrendo os nós um por um)
 */
struct Node
{
  int data;          /**< O valor armazenado no nó */
  struct Node *next; /**< Ponteiro para o próximo nó na lista */
};

#endif

/**
 * @brief Itera sobre os nós da lista encadeada e imprime seus valores.
 *
 * @param node Ponteiro para o nó inicial da lista.
 */
void listIterator(struct Node *node)
{
  int i = 0; // Contador

  // Caso a lista esteja vazia
  if (node == NULL)
  {
    printf("Lista vazia.\n");
    return;
  }

  // Itera pela lista e imprime de forma visual
  while (node != NULL)
  {
    // Imprime o valor do nó e indica o ponteiro "next"
    if (node->next != NULL)
    {
      // Mostra o valor do nó seguido do ponteiro
      printf("Dado do nó (%dº): %d -> ", i, node->data);
    }
    else
    {
      // Último nó aponta para NULL
      printf("Dado do nó (%dº): %d -> NULL\n", i, node->data);
    }

    i++; // Incrementa contador

    // Avança para o próximo nó
    node = node->next;
  }
}

int main(int argc, char **argv)
{
  // Declaração da estrutura da lista encadeada
  struct Node *firstNode = NULL;
  struct Node *secondNode = NULL;
  struct Node *thirdNode = NULL;

  // Alocar memória para 3 nós da lista encadeada
  firstNode = (struct Node *)malloc(sizeof(struct Node));
  secondNode = (struct Node *)malloc(sizeof(struct Node));
  thirdNode = (struct Node *)malloc(sizeof(struct Node));

  // Primeiro nó
  firstNode->data = 1;          // Atribui o valor 1 ao primeiro nó
  firstNode->next = secondNode; // Estabelece o link do primeiro nó para o segundo nó

  // Segundo nó
  secondNode->data = 2;         // Atribui o valor 2 ao segundo nó
  secondNode->next = thirdNode; // Estabelece o link do segundo nó para o terceiro nó

  // Terceiro nó
  thirdNode->data = 3;    // Atribui o valor 3 ao terceiro nó
  thirdNode->next = NULL; // Define o próximo do terceiro nó como NULL, indicando o final da lista

  // Iterar pela lista encadeada e imprimir os dados dos nós
  listIterator(firstNode);

  // Libera a memória alocada para os nós da lista encadeada
  free(firstNode);
  free(secondNode);
  free(thirdNode);

  return 0;
}
