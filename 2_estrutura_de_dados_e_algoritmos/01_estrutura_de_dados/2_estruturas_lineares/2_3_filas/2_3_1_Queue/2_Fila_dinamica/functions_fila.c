#include "fila.h"
#include <stdio.h>
#include <math.h>

_Static_assert(sizeof(float) >= 4, "float deve ser 32 bits");

Queue *createQueue(void)
{
	Queue *queue = malloc(sizeof(Queue));
	if (queue == NULL)
	{
		printf("Erro ao alocar memória para a fila\n");
		return NULL;
	}
	queue->front = queue->rear = NULL;
	return queue;
}

bool isEmpty(Queue *queue)
{
	if (queue == NULL)
	{
		return true;
	}
	return queue->front == NULL;
}

void enqueue(Queue *queue, float value)
{
	if (queue == NULL)
	{
		printf("Erro: Fila inválida\n");
		return;
	}

	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Erro ao alocar memória para o nó\n");
		return;
	}

	newNode->value = value;
	newNode->next = NULL;

	if (queue->rear != NULL)
	{
		queue->rear->next = newNode;
	}
	else
	{
		queue->front = newNode;
	}
	queue->rear = newNode;
}

float dequeue(Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("Fila vazia\n");
		return NAN;
	}

	Node *frontNode = queue->front;
	float value = frontNode->value;
	queue->front = frontNode->next;

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(frontNode);
	return value;
}

void freeQueue(Queue *queue)
{
	if (queue == NULL)
	{
		return;
	}

	Node *current = queue->front;
	while (current != NULL)
	{
		Node *next = current->next;
		free(current);
		current = next;
	}
	free(queue);
}

void printQueue(Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("Fila vazia\n");
		return;
	}

	printf("Fila: ");
	for (Node *current = queue->front; current != NULL; current = current->next)
	{
		printf("%.2f -> ", current->value);
	}
	printf("NULL\n");
}
