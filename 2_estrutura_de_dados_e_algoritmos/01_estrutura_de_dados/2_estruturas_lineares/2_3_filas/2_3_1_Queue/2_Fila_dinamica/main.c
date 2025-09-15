#include <stdio.h>
#include "fila.h"

int main(int argc, char **argv)
{
	Queue *queue = createQueue();
	if (queue == NULL)
	{
		return 1;
	}

	enqueue(queue, 10.0f);
	enqueue(queue, 50.0f);
	enqueue(queue, 30.0f);

	printQueue(queue);

	printf("Removido: %.2f\n", dequeue(queue));
	printQueue(queue);

	freeQueue(queue);

	/**
	 * gcc -std=c11 main.c functions_fila.c -o queue -lm
	 * .\queue.exe
	 */
	return 0;
}
