#include <stdio.h>
#include "fila.h"

int main(void)
{
	Queue *queue = createQueue();
	if (queue == NULL)
		return 1;

	// Prompt user for queue size and type
	size_t size;
	printf("Digite o tamanho da fila: ");
	if (scanf("%zu", &size) != 1 || size == 0)
	{
		printf("O tamanho da fila deve ser maior que 0.\n");
		freeQueue(queue);
		return 1;
	}

	int type_choice;
	printf("Escolha o tipo de dado (0: int, 1: char, 2: string, 3: double): ");
	if (scanf("%d", &type_choice) != 1 || type_choice < 0 || type_choice > 3)
	{
		printf("Tipo de dado inválido.\n");
		freeQueue(queue);
		return 1;
	}
	DataType type = (DataType)type_choice;

	// Enqueue elements
	printf("\nEnfileirando valores:\n");
	for (size_t i = 0; i < size; i++)
	{
		void *value;
		printf("Digite o valor para o elemento %zu: ", i);
		if (!readValue(type, &value))
		{
			printf("Erro ao ler valor.\n");
			freeQueue(queue);
			return 1;
		}
		enqueue(queue, value, type);
	}

	// Print the queue
	printf("\nFila gerada:\n");
	printQueue(queue);

	// Dequeue and print elements
	printf("\nDesenfileirando valores:\n");
	DataType dequeued_type;
	void *value = NULL;
	while ((value = dequeue(queue, &dequeued_type)) != NULL)
	{
		printf("Valor desenfileirado: ");
		printValue(value, dequeued_type);
		printf("\n");
		free(value); // Free the dequeued value
	}

	// Print the queue after dequeuing
	printf("\nFila após desenfileirar:\n");
	
	printQueue(queue);
	freeQueue(queue);
	/**
	 * gcc -std=c11 main.c functions_fila.c -o queue
	 * .\queue.exe
	 */
	return 0;
}
