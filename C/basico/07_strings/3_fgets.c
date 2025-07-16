#include <stdio.h>

/**
 * fgets(): Função para a leitura de strings
 *
 * SINTAXE: char *fgets(char *str, int tamanho, File *fp)
 *
 * @param str é a string que devemos passar para ser lida
 * @param tamanho limite até onde os caracteres devem ser lidos
 * @param FILE variável associada ao arquivo onde a string será lida
 * @return A função retorna a string lida ou NULL em caso de erro ou fim de arquivo
 */

int main(int argc, char **argv)
{
  // Criando variável e solicitando uma frase ou nome
  char nome[10] = {0}; // Vetor de 10 posições para armazenar o nome do usuário
  printf("Digite seu primeiro nome: ");
  fgets(nome, 10, stdin);

  // Imprimindo
  printf("Primeiro nome: %s\n", nome);

  /*
   * caso o tamanho do fgets seja maior que o do vetor ou programa não irá encerrar,
   * ou a exibição irá até onde tamanho que foi declarado:
   *
   * char nome[10];
   * printf("Digite uma frase ou seu nome: ");
   * fgets(nome, 20, stdin);
   *
   * E a informação de fgets em File *fp, já que nossa string não está vindo de um arquivo
   * e sim de um componente de entrada o stdin (stander input) o teclado
   */

  printf("\n-----------------------------------------------------\n");

  /* Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória). */
  for (int i = 0; nome[i] != '\0'; i++)
  {
    printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, nome[i], &nome[i]);
  }

  /*
   * O fgets() lê a entrada até encontrar um '\n' ou atingir o tamanho máximo do buffer,
   * garantindo espaço para o '\0'. Como o buffer tem um tamanho fixo, parte da entrada
   * pode ser truncada. Além disso, se outro fgets() for chamado em seguida, caracteres
   * remanescentes do buffer de entrada podem ser lidos automaticamente, causando efeitos
   * colaterais na próxima leitura.
   *
   * No caso "eduardojonathan\n" é preenchido os 8 índices do primeiro fgets() com "eduardo"
   * enquanto o "nathan\n" preenche os outros índices do próximo fgets().
   *
   * Mas porque 8 caracteres no primeiro fgets() sendo que eu tenho entrada até 10 caracteres?
   * Como explicado a função garante o '\0' contabilizando -1, ainda mais se ultrapassar o limite.
   */

  printf("\n-----------------------------------------------------\n");

  // Criando variável e solicitando uma frase ou nome
  char sobreNome[10] = {0}; // Vetor de 10 posições para armazenar o sobrenome do usuário
  printf("Digite seu segundo nome: ");
  fgets(sobreNome, sizeof(sobreNome), stdin);

  // Imprimindo
  printf("\nSobrenome: %s\n", sobreNome);

  printf("\n-----------------------------------------------------\n");

  /* Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória). */
  for (int i = 0; sobreNome[i] != '\0'; i++)
  {
    printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, sobreNome[i], &sobreNome[i]);
  }
  return 0;
}
