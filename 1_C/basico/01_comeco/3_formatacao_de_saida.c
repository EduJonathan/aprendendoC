#include <stdio.h>

/**
 * Este programa demonstra como realizar a formatação de dados e números utilizando
 * a função printf() em C. A formatação de dados permite controlar a maneira como
 * os valores são exibidos na tela, tornando a saída mais legível e organizada.
 * Utilizamos especificadores de formato (como %d, %f, %s, etc.) para definir o tipo
 * de dado a ser exibido e como ele deve ser apresentado.
 *
 * SINTAXE: printf("<especificador_de_formato>", arg1, arg2, ...);
 *
 * Especificadores de formato determinam como o valor será exibido (por exemplo, %d
 * para números inteiros, %f para números de ponto flutuante, %s para strings, etc.),
 * e os valores a serem exibidos são passados como argumentos após a vírgula.
 * O printf() substitui cada especificador de formato pelo respectivo valor.
 */

int main(int argc, char **argv)
{
	printf("\n\t>> PEQUENA DEMONSTRAÇÃO DE FORMATAÇÃO <<\n");

	// Exibe um número inteiro utilizando o especificador "%d"
	printf("%d\n", 6); // "%d": Formata e exibe um número inteiro.

	// Exibe um número inteiro com largura mínima de 6 espaços
	printf("%6d\n", 350);
	/*
	 * "%6d": Formata e exibe o número inteiro com um mínimo de 6 espaços.
	 * Se o número for menor que 6 dígitos, espaços em branco são adicionados à esquerda.
	 */

	printf("\n-----------------------------------------------------\n");

	// Demonstração de como preencher com zeros à esquerda
	printf("\n\t>> COMPLEMENTOS COM ZERO <<\n");

	printf("%04d\n", 67); // "%04d": Preenche com zeros à esquerda, totalizando 4 dígitos
	printf("%06d\n", 67); // "%06d": Preenche com zeros à esquerda, totalizando 6 dígitos
	/*
	 * "%04d" e "%06d": Formata o número inteiro com um total de 4 ou 6 dígitos, respectivamente.
	 * Se o número for menor que a largura definida, zeros são adicionados à esquerda.
	 */

	printf("%6.4d\n", 67); // "%6.4d": Formata para ocupar 6 espaços, com no máximo 4 dígitos à direita
	printf("%6.0d\n", 67); // "%6.0d": Formata para ocupar 6 espaços, sem mostrar dígitos à direita
	/*
	 * "%6.4d" e "%6.0d": Formata um número inteiro para ocupar pelo menos 6 espaços.
	 * O número após o ponto define a quantidade de dígitos a exibir, e a parte anterior
	 * da largura mínima totaliza os espaços ocupados.
	 */

	printf("\n-----------------------------------------------------\n");

	// Exibe caracteres e strings utilizando "%c" e "%s"
	printf("\n\t>> DEMONSTRAÇÃO DE FORMATAÇÃO COM CARACTERES <<\n");

	printf("\n SEXO: '%c'\tNOME: \"%s\"\n", 'M', "Eduardo");
	// OUTPUT: SEXO: 'M'       NOME: "Eduardo"

	// printf(" SEXO: '%c'\tNOME: \"%s\"\n", 'FA', "Ana");
	// OUTPUT: SEXO: 'A'       NOME: "Ana"

	/*
	 * "%c" exibe um único caractere.
	 * "%s" exibe uma sequência de caracteres (string).
	 */

	printf("\n-----------------------------------------------------\n");

	// Alinhamento à direita para inteiros e números de ponto flutuante
	printf("\n\t>> ALINHAMENTO PARA A DIREITA <<\n");

	// Variáveis de tipo inteiro para demonstração de formatação de saída
	int n1 = 10, n2 = 100, n3 = 1000;

	// Variáveis de tipo ponto flutuante (double) para demonstração de formatação
	double value1 = 10.50, value2 = 100.50, value3 = 1000.50;

	// Exibe inteiros com 4 espaços e números de ponto flutuante com 7 espaços e 2 casas decimais
	printf("\n%4d %7.2lf\n", n1, value1);
	printf("%4d %7.2lf\n", n2, value2);
	printf("%4d %7.2lf\n", n3, value3);
	/*
	 * "%4d": Alinha o número inteiro à direita, utilizando 4 espaços.
	 * "%7.2lf": Alinha o número de ponto flutuante à direita, utilizando 7 espaços no total, com 2 casas decimais.
	 * O número após o '.' indica a quantidade de casas decimais.
	 */

	// Alinhamento à esquerda para inteiros e números de ponto flutuante
	printf("\n%04d %-7.2lf\n", n1, value1);
	printf("%04d %-7.2lf\n", n2, value2);
	printf("%04d %-7.2lf\n", n3, value3);
	/*
	 * "%-7.2lf": Formata o número de ponto flutuante para ocupar 7 espaços, alinhado à esquerda.
	 * "%04d": Preenche com zeros à esquerda, se necessário, para garantir pelo menos 4 dígitos.
	 */

	printf("\n-----------------------------------------------------\n");
	printf("\n\t>> Formatação Especial <<\n");

	// Neste exemplo é criado um efeito prático: o "%*s" irá imprimir espaços em branco
	// até completar a largura criando um recuo proporcional à profundidade.
	int indetacao = 3; // Quanto maior é, maior será o espaçamento
	const char *texto = "Exemplo";

	printf("%*s> %s (indentação: %d)\n",
		   indetacao * 2, // largura: número de espaços, ira multiplicar indentação x 2
		   "",			  // string vazia — usada como "preenchimento"
		   texto,		  // texto após o marcador
		   indetacao);	  // valor da indentação

	/// @attention Antes de começar a trabalhar com as variáveis, é importante entender os TIPOS DE DADOS.
	/// Vamos explorar mais sobre como escolher o tipo correto para diferentes valores e qual o impacto disso na formatação.

	return 0;
}
