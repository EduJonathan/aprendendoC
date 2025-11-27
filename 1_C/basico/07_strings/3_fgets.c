#include <stdio.h>

/**
 * ### fgets()
 * Lê uma linha de texto de um fluxo (arquivo ou entrada padrão).
 *
 * **Protótipo**:
 *     char *fgets(char *str, int tamanho, FILE *fp);
 *
 * **Parâmetros**
 * - `str`     : buffer onde a string será armazenada.
 * - `tamanho` : tamanho máximo do buffer (inclui o byte de '\0').
 * - `fp`      : fluxo de entrada (ex.: `stdin` para teclado ou ponteiro para arquivo).
 *
 * **Retorno**
 * - Ponteiro para `str` em caso de sucesso.
 * - `NULL` se ocorrer erro ou se o fim de arquivo for atingido sem caracteres lidos.
 *
 * **Importante**: `fgets` **lê o '\n'** se houver espaço. É comum remover
 * esse caractere depois, caso não seja desejado.
 */

int main(int argc, char **argv)
{
  // --- Primeiro nome --------------------------------------------------------
  char nome[10] = {0}; // Vetor com espaço para até 9 caracteres + '\0'
  printf("Digite seu primeiro nome: ");
  fgets(nome, sizeof(nome), stdin);

  // Exibe o conteúdo lido (pode incluir '\n')
  printf("Primeiro nome: %s\n", nome);

  /*
   * Detalhes sobre `fgets`:
   * - Lê até `tamanho-1` caracteres ou até encontrar '\n', o que ocorrer primeiro.
   * - Sempre grava o terminador '\0'.
   * - Se o usuário digitar mais que 9 caracteres, o restante permanece no buffer
   *   de entrada. Uma chamada subsequente de `fgets()` continuará lendo o que sobrou.
   *
   * Exemplo: vetor de 10 bytes, entrada "eduardojonathan\n"
   *  1ª chamada: "eduardojo" (9 caracteres) + '\0'
   *  2ª chamada: "nathan\n" (restante do buffer)
   *
   * Observação: o '\n' só é incluído se couber no espaço restante.
   */

  printf("\n-----------------------------------------------------\n");

  // Mostra índice, caractere e endereço de memória de cada posição preenchida
  for (int i = 0; nome[i] != '\0'; i++)
  {
    printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, nome[i], (void *)&nome[i]);
  }

  printf("\n-----------------------------------------------------\n");

  // --- Sobrenome ------------------------------------------------------------
  char sobreNome[10] = {0};
  printf("Digite seu segundo nome: ");
  fgets(sobreNome, sizeof(sobreNome), stdin);

  printf("\nSobrenome: %s\n", sobreNome);

  printf("\n-----------------------------------------------------\n");

  for (int i = 0; sobreNome[i] != '\0'; i++)
  {
    printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, sobreNome[i], (void *)&sobreNome[i]);
  }

  return 0;
}
