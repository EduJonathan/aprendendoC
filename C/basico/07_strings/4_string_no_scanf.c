#include <stdio.h>

int main(int argc, char **argv)
{
	printf("\n\t>>SCANF-TRADICIONAL E LIMPEZA DE BUFFER EM STRINGS<<\n");

	char string_input_name[10];

	printf(">>Digite seu nome: ");
	scanf("%s", string_input_name);
	setbuf(stdin, NULL);

	printf("1º nome: %s\n", string_input_name);

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; string_input_name[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, string_input_name[i], &string_input_name[i]);
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
	
	char string_segundo_nome[10];

	printf("\n>>Digite seu segundo nome: ");
	scanf("%s", string_segundo_nome);
	setbuf(stdin, NULL);

	printf(" 2º nome: %s\n", string_segundo_nome);

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; string_segundo_nome[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, string_segundo_nome[i], &string_segundo_nome[i]);
	}

	/**
	 * @note Na linguagem C, cuidado com os buffers de memória? O problema de buffer ocorre
	 * quando dados ficam armazenados na memória e precisam ser limpos. Para limpar, usamos
	 * funções como fflush(), setbuf() e fpurge. Isso é importante quando manipulamos várias
	 * strings e dados como nome, e-mail, telefone, etc., para evitar "sujeira" no buffer durante
	 * o cadastro.
	 */

	printf("\n-----------------------------------------------------\n");

	char sexo;

	printf("\nDigite somente uma letra para (M - DE MASCULINO) OU (F - DE FEMININO): ");
	scanf("%c", &sexo);
	setbuf(stdin, NULL);

	printf("\nNome: %s %s \nSEXO: %c\n", string_input_name, string_segundo_nome, sexo);

	printf("\n=============================================================================\n");
	printf("\n\t>>SCANF-APRIMORADO PARA STRINGS<<\n");

	/**
	 * O scanf aprimorado se trata de conseguir ler e digitar a string incluindo a
	 * limitação da string, juntamente com os espaços a qual podemos inserir.
	 *
	 * SINTAXE: scanf("%<tamanho_da_string>[^\n]");
	 * - tamanho da string: Quantidade de quantos caracteres o vetor terá
	 * - [^\n]: significa que a string será escrita até chegamos ao enter['\n']
	 */

	char input_string_aprimorado[10];

	printf("Digite seu primeiro e segundo nome: ");
	scanf("%9[^\n]", input_string_aprimorado);

	printf("Seu nome completo é: %s\n", input_string_aprimorado);
	setbuf(stdin, NULL);

	/**
	 * @note scanf("%[^\n]", input_string_aprimorado);
	 * Deixando o scanf assim ainda terá o erro de acontecer novamente o estouro da
	 * variável passando mais do que o vetor possue e no final do scanf se ultrapassar o
	 * vetor por mais que imprima, o programa não vai encerrar, e para encerrar "Crtl + c"
	 * no terminal.
	 *
	 * Sendo assim, limitar é recomendado para o quanto ele terá de caracteres,
	 * deixar somente 9 caracteres para que o último seja para o '\0'.
	 *
	 * CUIDADO: Podemos ignorar o tamanho do vetor quantidade de caracteres que quisermos
	 * scanf("%20[^\n]", input_string_aprimorado); que irá compilar sem problemas,
	 * porém lembre-se, NÃO é uma boa prática ultrapassar os limites do vetor.
	 */

	printf("\n-----------------------------------------------------\n");

	// Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória).
	for (int i = 0; input_string_aprimorado[i] != '\0'; i++)
	{
		printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, input_string_aprimorado[i], &input_string_aprimorado[i]);
	}
	return 0;
}
