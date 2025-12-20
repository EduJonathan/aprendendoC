#include <stdio.h>

int main(int argc, char **argv)
{
	printf("\n\t>>SCANF-TRADICIONAL E LIMPEZA DE BUFFER EM STRINGS<<\n");

	char primeiro_nome[10] = {0}; // Vetor de 10 posições para armazenar o nome do usuário

	printf(">>Digite seu nome: ");
	// scanf("%s", primeiro_nome);
	fgets(primeiro_nome, sizeof(primeiro_nome), stdin);
	setbuf(stdin, NULL);

	printf("1º nome: %s\n", primeiro_nome);

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; primeiro_nome[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, primeiro_nome[i], &primeiro_nome[i]);
	}

	/*
	 * Digitando meu nome "eduardo jonathan", quando chega no 'o' de "eduardo", veja que
	 * ele ignorou o espaço e não o imprimiu juntamente com o "jonathan", isso é chamado
	 * estouro da variável, pois além de obedecer o limite do vetor, ele só vai ler até o
	 * primeiro espaço e logo após o enter, e a string "nathan", vai para lugares
	 * aleatórios na memória.
	 *
	 * ['e']['d']['u']['a']['r']['d']['o'][' ']['j']['o']['n']['a']['t']['h']['a']['n']['\0']
	 *   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15    16
	 *
	 * poderíamos fazer: "eduardo_jonathan"? sim, mas não é prático, e ninguém escreve o nome
	 * assim! sobre o '\n' não é armazenado com scanf, ele é consumido e descartado, para
	 * capturar '\n', use fgets.
	 */

	printf("\n-----------------------------------------------------\n");

	char segundo_nome[10] = {0}; // Vetor de 10 posições para armazenar o sobrenome do usuário

	printf("\n>>Digite seu segundo nome: ");
	// scanf("%s", segundo_nome);
	fgets(segundo_nome, sizeof(segundo_nome), stdin);
	setbuf(stdin, NULL);

	printf(" 2º nome: %s\n", segundo_nome);

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; segundo_nome[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, segundo_nome[i], &segundo_nome[i]);
	}

	/**
	 * @note Na linguagem C, cuidado com os buffers de memória? O problema de buffer ocorre
	 * quando dados ficam armazenados na memória e precisam ser limpos. Para limpar, usamos
	 * funções como fflush(), setbuf() e fpurge. Isso é importante quando manipulamos várias
	 * strings e dados como nome, e-mail, telefone, etc., para evitar "sujeira" no buffer durante
	 * o cadastro.
	 */

	printf("\n-----------------------------------------------------\n");

	char sexo = '\0'; // Variável para armazenar o sexo do usuário

	printf("\nDigite somente uma letra para (M - DE MASCULINO) OU (F - DE FEMININO): ");
	scanf(" %c", &sexo);
	setbuf(stdin, NULL);

	printf("\nNome: %s %s \nSEXO: %c\n", primeiro_nome, segundo_nome, sexo);

	printf("\n=============================================================================\n");
	printf("\n\t>>SCANF-APRIMORADO PARA STRINGS<<\n");

	/**
	 * O scanf aprimorado se trata de conseguir ler e digitar a string incluindo a
	 * limitação da string, juntamente com os espaços a qual podemos inserir.
	 *
	 * SINTAXE:
	 * - scanf("%<tamanho_da_string>[^\n]"); No Windows,
	 * - para linux scanf("%19s[^\n]", str_input_aprimorado);
	 * - tamanho da string: Quantidade de quantos caracteres o vetor terá
	 * - [^\n]: significa que a string será escrita até chegamos ao enter['\n']
	 */

	char str_input_aprimorado[20] = {0};

	printf("Digite seu primeiro e segundo nome: ");
	scanf("%19s[^\n]", str_input_aprimorado);
	printf("Seu nome completo é: %s\n", str_input_aprimorado);
	setbuf(stdin, NULL);

	/**
	 * @note scanf("%[^\n]", str_input_aprimorado);
	 * Deixando o scanf assim ainda terá o erro de acontecer novamente o estouro da
	 * variável passando mais do que o vetor possue e no final do scanf se ultrapassar o
	 * vetor por mais que imprima, o programa não vai encerrar, e para encerrar "Crtl + c"
	 * no terminal.
	 *
	 * Sendo assim, limitar é recomendado para o quanto ele terá de caracteres,
	 * deixar somente 9 caracteres para que o último seja para o '\0'.
	 *
	 * CUIDADO: Podemos ignorar o tamanho do vetor quantidade de caracteres que quisermos
	 * scanf("%20[^\n]", str_input_aprimorado); que irá compilar sem problemas,
	 * porém lembre-se, NÃO é uma boa prática ultrapassar os limites do vetor.
	 */

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; str_input_aprimorado[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, str_input_aprimorado[i], &str_input_aprimorado[i]);
	}
	return 0;
}
