#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define o tamanho máximo do deque

/**
 * @brief Estrutura que representa um Deque.
 *
 * fila duplamente terminada (DEQUE, do inglês Double Ended Queue) é um tipo de dado abstrato
 * que generaliza uma fila, para a qual os elementos podem ser adicionados ou removidos da
 * frente (head/front) ou de trás (tail/rear). Também é chamada de lista encadeada cabeça-cauda,
 * apesar de propriamente isto se referir a uma implementação de estrutura de dados específica.
 */
typedef struct Double_Ended_Queue
{
    int *deque; // Ponteiro para o array do deque
    int front;  // Índice da frente do deque
    int rear;   // Índice do final do deque
} Deque;

/**
 * @brief Função para verificar se o deque está cheio.
 *
 * O deque é considerado cheio quando o índice da frente é 0 e o índice de trás
 * é MAX - 1, ou quando o índice da frente é o próximo do índice de trás (formando um ciclo).
 *
 * @param d Ponteiro para a estrutura Deque.
 * @return Retorna 1 se o deque estiver cheio, caso contrário, retorna 0.
 */
int isFull(Deque *d)
{
    return ((d->front == 0 && d->rear == MAX - 1) || (d->front == d->rear + 1));
}

/**
 * @brief Função para verificar se o deque está vazio.
 *
 * O deque é considerado vazio quando o índice da frente é -1.
 *
 * @param d Ponteiro para a estrutura Deque.
 * @return Retorna 1 se o deque estiver vazio, caso contrário, retorna 0.
 */
int isEmpty(Deque *d)
{
    return (d->front == -1);
}

/**
 * @brief Função para inserir um elemento no início do deque.
 *
 * Se o deque não estiver cheio, o elemento é inserido na frente. Caso o deque
 * esteja cheio, uma mensagem de erro será exibida.
 *
 * @param d Ponteiro para a estrutura Deque.
 * @param key O valor a ser inserido no deque.
 * @return A estrutura Deque modificada.
 */
Deque *insertFront(Deque *d, int key)
{
    if (isFull(d))
    {
        printf("Overflow: Não é possível inserir o elemento na frente. O Deque está cheio.\n");
        return d;
    }
    if (d->front == -1)
    {
        // Se o deque estiver vazio
        d->front = 0;
        d->rear = 0;
    }
    else if (d->front == 0)
    {
        d->front = MAX - 1; // Volta para o final, formando a circularidade
    }
    else
    {
        d->front = d->front - 1;
    }

    d->deque[d->front] = key;
    printf("Inserido %d na frente.\n", key);
    return d;
}

/**
 * @brief Função para inserir um elemento no final do deque.
 *
 * Se o deque não estiver cheio, o elemento é inserido no final. Caso o deque
 * esteja cheio, uma mensagem de erro será exibida.
 *
 * @param d Ponteiro para a estrutura Deque.
 * @param key O valor a ser inserido no deque.
 * @return A estrutura Deque modificada.
 */
Deque *insertRear(Deque *d, int key)
{
    if (isFull(d))
    {
        printf("Overflow: Não é possível inserir o elemento no final. O Deque está cheio.\n");
        return d;
    }

    if (d->rear == -1)
    {
        d->front = 0;
        d->rear = 0;
    }
    else if (d->rear == MAX - 1)
    {
        d->rear = 0; // Volta para o início, formando a circularidade
    }
    else
    {
        d->rear = d->rear + 1;
    }

    d->deque[d->rear] = key;
    printf("Inserido %d no final.\n", key);
    return d;
}

/**
 * @brief Função para excluir um elemento do início do deque.
 *
 * Se o deque não estiver vazio, o elemento é removido do início. Caso o deque
 * esteja vazio, uma mensagem de erro será exibida.
 *
 * @param d Ponteiro para a estrutura Deque.
 * @return A estrutura Deque modificada.
 */
Deque *deleteFront(Deque *d)
{
    if (isEmpty(d))
    {
        printf("Underflow: Não é possível excluir o elemento da frente. O Deque está vazio.\n");
        return d;
    }

    int removed = d->deque[d->front];

    if (d->front == d->rear)
    {
        // Se o deque tem apenas um elemento
        d->front = -1;
        d->rear = -1;
    }
    else if (d->front == MAX - 1)
    {
        d->front = 0; // Volta para o início, formando a circularidade
    }
    else
    {
        d->front = d->front + 1;
    }

    printf("Excluído %d da frente.\n", removed);
    return d;
}

/**
 * @brief Função para excluir um elemento do final do deque.
 *
 * Se o deque não estiver vazio, o elemento é removido do final. Caso o deque
 * esteja vazio, uma mensagem de erro será exibida.
 *
 * @param d Ponteiro para a estrutura Deque.
 * @return A estrutura Deque modificada.
 */
Deque *deleteRear(Deque *d)
{
    if (isEmpty(d))
    {
        printf("Underflow: Não é possível excluir o elemento do final. O Deque está vazio.\n");
        return d;
    }

    int removed = d->deque[d->rear];

    if (d->front == d->rear)
    {
        // Se o deque tem apenas um elemento
        d->front = -1;
        d->rear = -1;
    }
    else if (d->rear == 0)
    {
        d->rear = MAX - 1; // Volta para o final, formando a circularidade
    }
    else
    {
        d->rear = d->rear - 1;
    }

    printf("Excluído %d do final.\n", removed);
    return d;
}

/**
 * @brief Função para exibir os elementos do deque.
 *
 * Se o deque estiver vazio, uma mensagem informando que ele está vazio será exibida.
 * Caso contrário, todos os elementos serão mostrados.
 *
 * @param d Ponteiro para a estrutura Deque.
 */
void displayDeque(Deque *d)
{
    if (isEmpty(d))
    {
        printf("O Deque está vazio.\n");
        return;
    }

    printf("Os elementos do Deque são: ");

    int i = d->front;
    while (1)
    {
        printf("%d ", d->deque[i]);
        if (i == d->rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    // Aloca o deque dinamicamente
    Deque *d = (Deque *)malloc(sizeof(Deque));
    if (d == NULL)
    {
        printf("Falha na alocação de memória!\n");
        return 1;
    }

    // Aloca o array para os elementos do deque
    d->deque = (int *)malloc(MAX * sizeof(int));
    if (d->deque == NULL)
    {
        printf("Falha na alocação de memória para o array do Deque!\n");
        free(d);
        return 1;
    }

    // Inicializando os índices do deque
    d->front = -1;
    d->rear = -1;

    // Testando as operações do deque
    d = insertRear(d, 5);
    displayDeque(d);

    d = insertFront(d, 15);
    displayDeque(d);

    d = insertRear(d, 25);
    displayDeque(d);

    d = deleteFront(d);
    displayDeque(d);

    d = deleteRear(d);
    displayDeque(d);

    // Libera a memória do deque
    free(d->deque);
    free(d);

    return 0;
}
