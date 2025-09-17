#include <stdio.h>
#include <string.h>
#include "fila.h"

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

int readValue(DataType type, void **value)
{
	switch (type)
	{
	case TYPE_INT:
	{
		int *val = malloc(sizeof(int));
		if (val == NULL)
			return 0;

		printf("Digite um valor inteiro: ");
		if (scanf("%d", val) != 1)
		{
			free(val);
			return 0;
		}
		*value = val;
		return 1;
	}
	case TYPE_CHAR:
	{
		char *val = malloc(sizeof(char));
		if (val == NULL)
			return 0;

		printf("Digite um caractere: ");
		scanf(" %c", val); // Espaço para consumir espaços em branco
		*value = val;
		return 1;
	}
	case TYPE_STRING:
	{
		char buffer[256];
		printf("Digite uma string: ");
		scanf(" %255[^\n]", buffer); // Lê string, limite de 255 chars

		char *val = malloc(strlen(buffer) + 1);
		if (val == NULL)
			return 0;

		strcpy(val, buffer);
		*value = val;
		return 1;
	}
	case TYPE_DOUBLE:
	{
		double *val = malloc(sizeof(double));
		if (val == NULL)
			return 0;
			
		printf("Digite um valor double: ");
		if (scanf("%lf", val) != 1)
		{
			free(val);
			return 0;
		}
		*value = val;
		return 1;
	}
	default:
		return 0;
	}
}

void printValue(void *value, DataType type)
{
	switch (type)
	{
	case TYPE_INT:
		printf("%d", *(int *)value);
		break;

	case TYPE_CHAR:
		printf("%c", *(char *)value);
		break;

	case TYPE_STRING:
		printf("%s", (char *)value);
		break;

	case TYPE_DOUBLE:
		printf("%.2f", *(double *)value);
		break;
	}
}

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

void enqueue(Queue *queue, void *value, DataType type)
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
		free(value); // Free the value since it won't be used
		return;
	}

	newNode->value = value;
	newNode->type = type;
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

void *dequeue(Queue *queue, DataType *type)
{
	if (isEmpty(queue))
	{
		printf("Fila vazia\n");
		*type = TYPE_INT; // Default type for empty queue
		return NULL;
	}
	Node *frontNode = queue->front;
	void *value = frontNode->value;
	*type = frontNode->type;
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
		free(current->value); // Free the stored value
		free(current);		  // Free the node
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
		printValue(current->value, current->type);
		printf(" -> ");
	}
	printf("NULL\n");
}
