#include <stdio.h>
#include "stack.h"

/**
 * @brief Programa principal para demonstrar o uso da pilha.
 *
 * Demonstra as operações básicas de uma pilha dinâmica (LIFO) com alocação de memória.
 *
 * @param argc Número de argumentos da linha de comando.
 * @param argv Array de strings com os argumentos da linha de comando.
 * @return 0 em caso de sucesso, 1 em caso de erro.
 */
int main(int argc, char **argv)
{
  Stack *stack = createStack(5);
  if (stack == NULL)
  {
    return 1;
  }

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  printStack(stack);

  printf("Desempilhado: %d\n", pop(stack));
  printStack(stack);

  printf("Topo: %d\n", peek(stack));
  freeStack(stack);

  /**
   * gcc -std=c11 main_pilha_dinamica.c pilha.c -o pilha_dinamica
   * .\pilha_dinamica.exe
   */
  return 0;
}
