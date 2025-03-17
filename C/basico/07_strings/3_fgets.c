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
  char nome[10];
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
   * Digitando meu nome sem espaços "eduardojonathan" ele imprime até "eduardojo" (9 caracteres)
   * mas porque 9 caracteres sendo que eu tenho entrada até 10 caracteres? porque no segundo
   * parâmetro do tamanho da string conta com -1, ou seja, está reservado para o '\0'
   */

  printf("\n-----------------------------------------------------\n");

  // Criando variável e solicitando uma frase ou nome
  char sobreNome[10];
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
