#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @brief Estrutura que representa uma pilha dinâmica.
 *
 * A pilha é uma estrutura de dados LIFO (Last In, First Out) que armazena
 * elementos em um array dinâmico.
 */
typedef struct Stack
{
  int      top;     /**< Índice do topo da pilha. */
  unsigned maxSize; /**< Tamanho máximo da pilha. */
  int      *array;  /**< Array dinâmico que armazena os elementos da pilha. */
} Stack;

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

/**
 * @brief Cria uma pilha com o tamanho especificado.
 *
 * Aloca memória para a pilha e seu array interno. O topo é inicializado como -1.
 *
 * @param maxSize Tamanho máximo da pilha.
 * @return Ponteiro para a pilha criada ou NULL em caso de falha na alocação.
 */
Stack *createStack(unsigned maxSize)
{
  if (maxSize == 0)
  {
    printf("Erro: Tamanho da pilha deve ser maior que zero\n");
    return NULL;
  }

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL)
  {
    printf("Erro ao alocar memória para a pilha\n");
    return NULL;
  }

  stack->maxSize = maxSize;
  stack->top     = -1;
  stack->array   = (int *)malloc(maxSize * sizeof(int));

  if (stack->array == NULL)
  {
    printf("Erro ao alocar memória para o array da pilha\n");
    free(stack);
    return NULL;
  }

  return stack;
}

/**
 * @brief Verifica se a pilha está cheia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver cheia, false caso contrário.
 */
bool isFull(Stack *stack)
{
  if (stack == NULL)
  {
    return false;
  }
  return stack->top == (int)stack->maxSize - 1;
}

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @param stack Ponteiro para a pilha.
 * @return true se a pilha estiver vazia ou NULL, false caso contrário.
 */
bool isEmpty(Stack *stack)
{
  if (stack == NULL)
  {
    return true;
  }
  return stack->top == -1;
}

/**
 * @brief Insere um item no topo da pilha.
 *
 * Se a pilha estiver cheia ou for NULL, a função não insere o item.
 *
 * @param stack Ponteiro para a pilha.
 * @param item Item a ser inserido.
 */
void push(Stack *stack, int item)
{
  if (stack == NULL || isFull(stack))
  {
    if (stack != NULL)
    {
      printf("Pilha cheia, não é possível inserir %d\n", item);
    }
    return;
  }
  stack->array[++stack->top] = item;
  printf("%d empilhado\n", item);
}

/**
 * @brief Remove e retorna o item do topo da pilha.
 *
 * Se a pilha estiver vazia ou for NULL, retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha.
 * @return Item removido do topo ou INT_MIN se a pilha estiver vazia.
 */
int pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Pilha vazia\n");
    return INT_MIN;
  }
  return stack->array[stack->top--];
}

/**
 * @brief Retorna o item do topo da pilha sem removê-lo.
 *
 * Se a pilha estiver vazia ou for NULL, retorna INT_MIN.
 *
 * @param stack Ponteiro para a pilha.
 * @return Item no topo da pilha ou INT_MIN se a pilha estiver vazia.
 */
int peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Pilha vazia\n");
    return INT_MIN;
  }
  return stack->array[stack->top];
}

/**
 * @brief Imprime os elementos da pilha.
 *
 * Exibe os elementos da pilha do topo até a base. Se a pilha estiver vazia,
 * exibe uma mensagem apropriada.
 *
 * @param stack Ponteiro para a pilha.
 */
void printStack(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("A pilha está vazia\n");
    return;
  }

  printf("Elementos da pilha: ");

  for (int i = stack->top; i >= 0; --i)
  {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Libera o array interno e a estrutura da pilha. Se a pilha for NULL, a função retorna.
 *
 * @param stack Ponteiro para a pilha.
 */
void freeStack(Stack *stack)
{
  if (stack == NULL)
  {
    return;
  }
  free(stack->array);
  free(stack);
}

/**
 * @brief Ordena os elementos da pilha em ordem crescente.
 *
 * Reorganiza os elementos no array interno da pilha, mantendo o topo no maior valor.
 *
 * @param stack Ponteiro para a pilha.
 */
void sortStack(Stack *stack)
{
  if (isEmpty(stack) || stack == NULL)
  {
    printf("Pilha vazia ou inválida, não é possível ordenar\n");
    return;
  }

  for (int i = 0; i <= stack->top; i++)
  {
    for (int j = 0; j < stack->top - i; j++)
    {
      if (stack->array[j] > stack->array[j + 1])
      {
        int temp            = stack->array[j];
        stack->array[j]     = stack->array[j + 1];
        stack->array[j + 1] = temp;
      }
    }
  }
  printf("Pilha ordenada em ordem crescente\n");
}

/**
 * @brief Busca um elemento na pilha.
 *
 * Verifica se o valor especificado existe na pilha.
 *
 * @param stack Ponteiro para a pilha.
 * @param value Valor a ser buscado.
 * @return true se o valor for encontrado, false caso contrário ou se a pilha for NULL/vazia.
 */
bool searchStack(Stack *stack, int value)
{
  if (isEmpty(stack) || stack == NULL)
  {
    return false;
  }

  for (int i = stack->top; i >= 0; i--)
  {
    if (stack->array[i] == value)
    {
      return true;
    }
  }
  return false;
}

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

  return 0;
}
