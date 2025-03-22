#include <stdio.h>

/**
 * OBS: Se temos um vetor com um número fixo de elementos e tentamos acessar
 * um índice além do limite do vetor, o compilador não gera um erro (ao contrário de
 * outras linguagens como Java). No entanto, isso pode causar sérios problemas de
 * segurança, como sobrescrever áreas de memória não alocadas, o que é conhecido
 * como "lixo de memória". Em C, isso ocorre sem uma mensagem de erro explícita.
 */

int main(int argc, char **argv)
{
	/* NÃO RETIRE ESSES OS COMENTÁRIOS DESTAS 2 LINHAS POR ENQUANTO */
	// int adicionarEndereco = 0;
	// printf("Valor de \"adicionarEndereco\": %d\t Endereço de \"adicionarEndereco\": %p\n", adicionarEndereco, &adicionarEndereco);

	// array de 3 posições
	int array[3];

	array[0] = 7;
	array[1] = 8;
	array[2] = 9;
	array[3] = 11; // Passamos do limite do vetor

	printf("\n\tINDEX\t Valores\tEnd. de Memoria Alocadas\n");
	printf(" array[0] = %8d\t\t %p\n", array[0], &array[0]);
	printf(" array[1] = %8d\t\t %p\n", array[1], &array[1]);
	printf(" array[2] = %8d\t\t %p\n", array[2], &array[2]);
	printf(" array[3] = %8d\t\t %p\n", array[3], &array[3]);

	/*
	 * Siga as instruções abaixo para entender a situação e o comportamento de
	 * memória ao tentar acessar uma posição fora dos limites do vetor.
	 */

	// ==============================================================================

	/*
	 * => PASSO 1: Compile ou execute o código 2 vezes. Observe a saída do printf
	 * na linha 29 quando executado nas duas vezes. Perceba que o valor de array[3]
	 * em "End. de Memoria Alocadas", já que ultrapassamos os limites do vetor.
	 * O valor impresso pode ser lixo de memória ou qualquer valor residual da memória alocada.
	 *
	 * Nota: Caso o compilador não emita um erro, o comportamento é indefinido e tem
	 * efeitos negativos, com acesso posições fora do vetor pode sobrescrever áreas
	 * de memória não alocadas. Esse comportamento pode variar de uma execução para outra,
	 * dependendo do ambiente de execução.
	 */

	// ==============================================================================

	/*
	 * => PASSO 2: Agora retire os comentários das linhas 14 e 15 e compile ou execute
	 * novamente. Observe que agora o valor atribuído de "End. de Memoria Alocadas" ao
	 * array[3] corresponderá ao endereço de memória da variável 'adicionarEndereco'.
	 * Isso ocorre porque, ao acessar fora do limite do vetor, a memória sobrescreve, e o
	 * endereço da variável 'adicionarEndereco' será atribuído ao índice fora do limite
	 * do vetor, porém fazer o código ter este tipo de comportamento é totalmente perigoso.
	 */

	// ==============================================================================

	/*
	 * EXPLICAÇÃO DO COMPORTAMENTO: Em C, a alocação de memória para variáveis e arrays
	 * funciona de forma direta e eficiente, mas pode ser perigosa se não for bem controlada.
	 * Quando um vetor ultrapassa seu limite, o compilador não emite um erro, mas a memória
	 * usada pelo array pode ser corrompida ou sobrescrita, causando problemas imprevisíveis.
	 *
	 * Em outras linguagens, como Java, um erro de "IndexOutOfBoundsException" é gerado,
	 * tornando o comportamento mais seguro e explícito, mas em lingaguens C/C++ o controle e
	 * gerenciamento depende do programador.
	 */

	// ==============================================================================

	/// @note: **NUNCA ultrapasse os limites de um vetor.** Isso pode
	// causar corrupção de memória e comportamentos inesperados. Sempre verifique os
	// limites dos arrays antes de acessar seus elementos.
	return 0;
}
