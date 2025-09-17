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

  push(stack, 3);
  push(stack, 1);
  push(stack, 4);
  push(stack, 1);
  push(stack, 5);
  printStack(stack); // Outputs: 5 1 4 1 3

  sortStack(stack);
  printStack(stack); // Outputs: 5 4 3 1 1 (sorted, largest at top)

  printf("Search 4: %s\n", searchStack(stack, 4) ? "Encontrado" : "Nao Encontrado"); // Outputs: Encontrado
  printf("Search 2: %s\n", searchStack(stack, 2) ? "Encontrado" : "Nao Encontrado"); // Outputs: Nao Encontrado

  freeStack(stack);

  /**
   * gcc -std=c11 main_pilha_dinamica.c funcoes_da_pilha.c -o pilha_dinamica
   * .\pilha_dinamica.exe
   */
  return 0;
}
