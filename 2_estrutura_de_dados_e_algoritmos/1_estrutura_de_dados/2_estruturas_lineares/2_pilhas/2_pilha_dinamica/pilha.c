#include <stdio.h>
#include "funcoes_da_pilha.h"

int main(int argc, char **argv)
{
  // Cria uma pilha com tamanho 5
  struct Stack *stack = createStack(5);

  // Insere elementos na pilha
  push(stack, 3);
  push(stack, 4);
  push(stack, 10);
  push(stack, 30);

  printf("\n---------------------\n");

  // Remove um elemento da pilha
  printf("%d popped da pilha\n", pop(stack));

  printf("\n---------------------\n");

  // Imprime os elementos da pilha
  printStack(stack);

  printf("\n---------------------\n");

  // O topo da pilha é 30
  printf("O topo da pilha é %d\n", peek(stack));

  // Libera a memória da pilha
  freeStack(stack);

  return 0;
}
