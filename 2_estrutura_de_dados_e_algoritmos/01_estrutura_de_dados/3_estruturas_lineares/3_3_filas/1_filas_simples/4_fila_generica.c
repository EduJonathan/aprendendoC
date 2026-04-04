#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Enum para representar os tipos de dados suportados.
 */
typedef enum
{
	TYPE_INT,	 /**< Inteiro */
	TYPE_CHAR,	 /**< Caractere */
	TYPE_STRING, /**< Cadeia de caracteres (string) */
	TYPE_DOUBLE	 /**< Número de ponto flutuante (double) */
} DataType;

/**
 * @brief Estrutura que representa um nó da fila encadeada.
 *
 * Contém um ponteiro genérico para o valor, um identificador do tipo
 * e um ponteiro para o próximo nó.
 */
typedef struct Node
{
	void        *value; /**< Ponteiro para o valor armazenado. */
	DataType    type;   /**< Tipo do valor armazenado. */
	struct Node *next;  /**< Ponteiro para o próximo nó. */
} Node;

/**
 * @brief Estrutura que representa uma fila encadeada.
 *
 * Armazena ponteiros para o início e o fim da fila (FIFO).
 */
typedef struct Queue
{
	Node *front; /**< Ponteiro para o início da fila. */
	Node *rear;	 /**< Ponteiro para o fim da fila. */
} Queue;

_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 32 bits");

/**
 * @brief Função auxiliar para ler um valor de acordo com o tipo de dado.
 *
 * Aloca memória para o valor e o lê do usuário.
 *
 * @param type Tipo de dado do valor.
 * @param value Ponteiro para armazenar o valor alocado.
 * @return 1 em caso de sucesso, 0 em caso de falha.
 */
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

/**
 * @brief Imprime um valor de acordo com seu tipo.
 *
 * @param value Ponteiro para o valor.
 * @param type Tipo de dado do valor.
 */
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

/**
 * @brief Cria uma nova fila vazia.
 *
 * Aloca memória para a estrutura da fila e inicializa os ponteiros como NULL.
 *
 * @return Ponteiro para a nova fila criada ou NULL em caso de falha.
 */
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

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a fila.
 * @return true se a fila estiver vazia ou NULL, false caso contrário.
 */
bool isEmpty(Queue *queue)
{
	if (queue == NULL)
	{
		return true;
	}
	return queue->front == NULL;
}

/**
 * @brief Insere um elemento no fim da fila.
 *
 * @param queue Ponteiro para a fila.
 * @param value Ponteiro para o valor a ser inserido.
 * @param type Tipo do valor a ser inserido.
 */
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
	newNode->type  = type;
	newNode->next  = NULL;

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

/**
 * @brief Remove e retorna o elemento do início da fila.
 *
 * Se a fila estiver vazia, retorna NULL e exibe uma mensagem.
 *
 * @param queue Ponteiro para a fila.
 * @param type Ponteiro para armazenar o tipo do valor removido.
 * @return Ponteiro para o valor removido ou NULL se a fila estiver vazia.
 */
void *dequeue(Queue *queue, DataType *type)
{
	if (isEmpty(queue))
	{
		printf("Fila vazia\n");
		*type = TYPE_INT; // Default type for empty queue
		return NULL;
	}

	Node *frontNode = queue->front;
	void *value     = frontNode->value;
	*type           = frontNode->type;
	queue->front    = frontNode->next;

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(frontNode);
	return value;
}

/**
 * @brief Libera toda a memória alocada para a fila.
 *
 * Desaloca todos os nós e a estrutura da fila, incluindo os valores armazenados.
 *
 * @param queue Ponteiro para a fila.
 */
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

/**
 * @brief Imprime os elementos da fila.
 *
 * Exibe os valores do início ao fim da fila. Se a fila estiver vazia, exibe uma mensagem.
 *
 * @param queue Ponteiro para a fila.
 */
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

int main(int argc, char **argv)
{
	Queue *queue = createQueue();
	if (queue == NULL)
		return 1;

	size_t size = 0ull;
	printf("Digite o tamanho da fila: ");
	if (scanf("%zu", &size) != 1 || size == 0)
	{
		printf("O tamanho da fila deve ser maior que 0.\n");
		freeQueue(queue);
		return 1;
	}

	int type_choice = 0;
	printf("Escolha o tipo de dado (0: int, 1: char, 2: string, 3: double): ");
	if (scanf("%d", &type_choice) != 1 || type_choice < 0 || type_choice > 3)
	{
		printf("Tipo de dado inválido.\n");
		freeQueue(queue);
		return 1;
	}
	DataType type = (DataType)type_choice;

	printf("\nEnfileirando valores:\n");
	for (size_t i = 0; i < size; i++)
	{
		void *value = NULL;
		printf("Digite o valor para o elemento %zu: ", i);
		if (!readValue(type, &value))
		{
			printf("Erro ao ler valor.\n");
			freeQueue(queue);
			return 1;
		}
		enqueue(queue, value, type);
	}

	printf("\nFila gerada:\n");
	printQueue(queue);

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

	printf("\nFila após desenfileirar:\n");
	
	printQueue(queue);
	freeQueue(queue);

	return 0;
}
