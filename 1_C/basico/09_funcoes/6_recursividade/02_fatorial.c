#include <stdio.h>

/**
 * @brief Função recursiva para calcular o fatorial de um número.
 *
 * Calcula o fatorial de um número usando recursão.
 *
 * @param fat O número para o qual o fatorial sera calculado.
 * @return O fatorial de fat.
 *
 * @note A função assume que fat é um número inteiro não negativo.
 */
int fatorial(int fat)
{
  /*
   * Caso a expressão do ou (||) seja true para que fat for igual a zero ou for igual a 1
   * logo o valor retorna 1, pois o fatorial, 0 e o fatorial de 1 é 1, caso não:
   */
  if (fat == 0 || fat == 1)
  {
    return 1; // caso base
  }

  // caso não seja verdade a expressão então entra na recursão que:
  return fat * fatorial(fat - 1); // caso geral

  /*
   * pegando o exemplo de 3! sendo 3 fatorial: fica 3 * 2 * 1 é equivalente a,
   * na recursão fica: fat * (fat - 1) * (fat - 2) * (fat - 3)
   * perceba que o fatorial vai diminuindo até que ele chegue no seu caso base para que termine
   */
}

int main(int argc, char **argv)
{
  // Chamando o fatorial dentro do printf
  printf("%d", fatorial(3));
  return 0;
}
