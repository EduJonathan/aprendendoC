#include <stdio.h>

/**
 * Esse programa exibe como realizar a formatação de dados e números com a utilização
 * da função printf() para formatar e exibir dados e números. A formatação permite que
 * valores (argumentos ou parâmetros) sejam apresentados de forma legível e controlada na
 * saída. Para isso, utilizamos o printf() com especificadores de formato dentro das aspas,
 * seguidos de uma vírgula e os valores ou variáveis que queremos exibir.
 *
 * SINTAXE: printf("<especificador_de_formato>", arg1, arg2, ...);
 *
 * Especificadores de formato (%d, %f, %s, etc.) define como o valor será exibido,
 * e os argumentos são passados após a vírgula. A função printf() então substitui os
 * especificadores pelos respectivos valores ou conteúdos das variáveis passadas.
 */

int main(int argc, char **argv)
{
	printf("\n\t>> PEQUENA DEMONSTRAÇÃO DE FORMATAÇÃO <<\n");

	// Exibindo um número inteiro com o especificador "%d"
	printf("%d\n", 6); // "%d": Formata um número inteiro.

	// Exibindo um número inteiro com largura mínima de 6 espaços
	printf("%6d\n", 350);
	/*
	 * "%6d": Imprime um número inteiro ocupando pelo menos 6 espaços,
	 * preenchendo com espaços à esquerda se necessário.
	 */

	printf("\n-----------------------------------------------------\n");

	// Demonstração de complementos com zero para números inteiros
	printf("\n\t>> COMPLEMENTOS COM ZERO <<\n");

	printf("%04d\n", 67); // "%04d": Preenche com 0 à esquerda para garantir 4 dígitos
	printf("%06d\n", 67); // "%06d": Preenche com 0 à esquerda para garantir 6 dígitos
	/*
	 * "%04d e %06d": Imprime um número inteiro ocupando pelo menos 4 ou 6 espaços,
	 * preenchendo com zeros à esquerda se necessário.
	 */

	printf("%6.4d\n", 67); // "%6.4d": Imprime com 6 espaços, com no máximo 4 dígitos à direita
	printf("%6.0d\n", 67); // "%6.0d": Imprime com 6 espaços, mas sem dígitos à direita
	/*
	 * "%6.4d e %6.0d": Imprime um número inteiro ocupando pelo menos 6 espaços,
	 * com no máximo 4 e 0 dígitos à direita do ponto decimal.
	 */

	printf("\n-----------------------------------------------------\n");

	printf("\n\t>> DEMONSTRAÇÃO DE FORMATAÇÃO COM CARACTERES <<\n");

	printf("\n SEXO: '%c'\tNOME: \"%s\"\n", 'M', "Eduardo");
	/// OUTPUT: SEXO: 'M'       NOME: "Eduardo"

	printf(" SEXO: '%c'\tNOME: \"%s\"\n", 'F', "Ana");
	/// OUTPUT: SEXO: 'F'       NOME: "Ana"

	/// @note: O especificador "%c" exibe apenas um único caractere
	/// @note: O especificador "%s" exibe uma string (sequência de caracteres)

	printf("\n-----------------------------------------------------\n");

	// Variáveis de tipo inteiro para demonstração de formatação de saída
	int n1 = 10, n2 = 100, n3 = 1000;

	// Variáveis de tipo ponto flutuante (double) para demonstração de formatação
	double value1 = 10.50, value2 = 100.50, value3 = 1000.50;

	// Alinhamento à direita para inteiros e números de ponto flutuante
	printf("\n\t>> ALINHAMENTO PARA A DIREITA <<\n");

	// Alinhamento à direita com 4 espaços para inteiros e 7 espaços para números de
	// ponto flutuante 4 espaços para inteiro, 7 para float com 2 casas decimais
	printf("\n%4d %7.2lf\n", n1, value1);
	printf("%4d %7.2lf\n", n2, value2);
	printf("%4d %7.2lf\n", n3, value3);
	/*
	 * O número após o '%' define a largura mínima do campo para o valor.
	 * O número após o '.' (por exemplo, %.2lf) define o número de casas decimais a exibir.
	 * "%7.2lf" alinha à direita e usa 7 espaços no total, sendo 2 casas decimais para o
	 * valor de ponto flutuante.
	 */

	// Alinhamento à esquerda para inteiros e números de ponto flutuante
	// Alinhamento à esquerda com 4 dígitos para inteiros e 7 espaços para números
	// float com 2 casas decimais
	printf("\n%04d %-7.2lf\n", n1, value1);
	printf("%04d %-7.2lf\n", n2, value2);
	printf("%04d %-7.2lf\n", n3, value3);
	/*
	 * "%-7.2lf": Formata o número de ponto flutuante (double) com 7 espaços no total,
	 * sendo 2 casas decimais, e alinha à esquerda.
	 */

	/// @attention Antes de variáveis, precisamos entender os DATATYPES(tipos de dados), vamos lá!?
	return 0;
}
