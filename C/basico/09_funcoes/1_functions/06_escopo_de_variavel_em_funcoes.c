#include <stdio.h>

// Variável global `a` inicializada com 0
int a = 0;

/**
 * @brief Função que imprime variáveis locais, estáticas e parâmetros.
 *
 * Esta função demonstra o uso de variáveis locais, variáveis estáticas e parâmetros.
 * A variável local é reinicializada a cada chamada da função, a variável estática mantém
 * seu valor entre as chamadas, e o parâmetro é passado durante a chamada da função.
 *
 * @param d Valor inteiro passado como parâmetro para a função.
 */
void variaveis(int d)
{
	// Variável local `b` inicializada com 1
	int b = 1;

	// Variável estática `c` inicializada com 5
	static int c = 5;

	// Incrementa a variável estática `c`
	c++;

	// Imprime as variáveis a, b, c, e d
	printf("%d %d %d %d\n", a, b, c, d);
}

int main(int argc, char **argv)
{
	// Variáveis locais `b`, `c`, e `d` inicializadas com valores específicos
	int b = 10, c = 20, d = 3;

	// Imprime as variáveis a, b, c, e d antes de chamar a função f
	printf("%d %d %d %d\n", a, b, c, d);
	/// OUTPUT: 0 10 20 3

	// Chama a função f com argumento 9
	variaveis(9);
	/// OUTPUT: 0 1 6 9

	// Imprime as variáveis a, b, c, e d após chamar a função f
	printf("%d %d %d %d\n", a, b, c, d);
	/// OUTPUT: 0 10 20 3

	// Atribui o valor 2 à variável global a e o valor 30 à variável local b
	a = 2;
	b = 30;

	// Chama a função f com o valor da variável b como argumento
	variaveis(b);
	/// OUTPUT: 2 1 7 30

	// Imprime as variáveis a, b, c, e d após chamar a função f novamente
	printf("%d %d %d %d\n", a, b, c, d);
	/// OUTPUT: 2 30 20 3
	return 0;
}
