#include <stdio.h>
#include "functions_fila.h"

int main(int argc, char **argv)
{
	// Criando a fila
	Fila *fila = criar_fila();

	// Inserindo os valores
	inserir(fila, 10);
	inserir(fila, 50);
	inserir(fila, 30);

	// Imprima os valores
	imprimir(fila);

	// Remova um valor da fila
	remover(fila);
	printf("\n");

	// Imprima novamente
	imprimir(fila);

	// Libere a fila
	liberar(fila);
	return 0;
}
