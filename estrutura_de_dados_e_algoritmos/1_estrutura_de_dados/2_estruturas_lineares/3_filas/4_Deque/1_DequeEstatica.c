#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the deque

/**
 * @brief Função para verificar se o deque está cheio.
 *
 * O deque é considerado cheio quando o índice da frente é 0 e o índice de trás
 * é MAX - 1, ou quando o índice da frente é o próximo do índice de trás (formando um ciclo).
 *
 * @param front Índice da frente do deque.
 * @param rear Índice de trás do deque.
 * @return Retorna 1 se o deque estiver cheio, caso contrário, retorna 0.
 */
int isFull(int front, int rear)
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

/**
 * @brief Função para verificar se o deque está vazio.
 *
 * O deque é considerado vazio quando o índice da frente é -1.
 *
 * @param front Índice da frente do deque.
 * @return Retorna 1 se o deque estiver vazio, caso contrário, retorna 0.
 */
int isEmpty(int front)
{
    return (front == -1);
}

/**
 * @brief Função para inserir um elemento no início do deque.
 *
 * Se o deque não estiver cheio, o elemento é inserido na frente. Caso o deque
 * esteja cheio, uma mensagem de erro será exibida.
 *
 * @param deque Ponteiro para o deque.
 * @param front Ponteiro para o índice da frente.
 * @param rear Ponteiro para o índice de trás.
 * @param key O valor a ser inserido no deque.
 */
void insertFront(int *deque, int *front, int *rear, int key)
{
    if (isFull(*front, *rear))
    {
        printf("Estouro: Não é possível inserir o elemento na parte traseira. Deque está cheio.\n");
        return;
    }

    if (*front == -1)
    { 
        // Se o deque estiver vazio
        *front = 0;
        *rear = 0;
    }
    else if (*front == 0)
    {
        *front = MAX - 1; // Volta para o final, formando a circularidade
    }
    else
    {
        *front = *front - 1;
    }

    deque[*front] = key;
    printf("%d inserida na atrás no Deque.\n", key);
}

/**
 * @brief Função para inserir um elemento no final do deque.
 *
 * Se o deque não estiver cheio, o elemento é inserido no final. Caso o deque
 * esteja cheio, uma mensagem de erro será exibida.
 *
 * @param deque Ponteiro para o deque.
 * @param front Ponteiro para o índice da frente.
 * @param rear Ponteiro para o índice de trás.
 * @param key O valor a ser inserido no deque.
 */
void insertRear(int *deque, int *front, int *rear, int key)
{
    if (isFull(*front, *rear))
    {
        printf("Overflow: Unable to insert element at the rear. Deque is full.\n");
        return;
    }

    if (*rear == -1)
    {
        // Se o deque estiver vazio
        *front = 0;
        *rear = 0;
    }
    else if (*rear == MAX - 1)
    {
        *rear = 0; // Volta para o início, formando a circularidade
    }
    else
    {
        *rear = *rear + 1;
    }

    deque[*rear] = key;
    printf("Inserted %d at the rear.\n", key);
}

/**
 * @brief Função para excluir um elemento do início do deque.
 *
 * Se o deque não estiver vazio, o elemento é removido do início. Caso o deque
 * esteja vazio, uma mensagem de erro será exibida.
 *
 * @param deque Ponteiro para o deque.
 * @param front Ponteiro para o índice da frente.
 * @param rear Ponteiro para o índice de trás.
 */
void deleteFront(int *deque, int *front, int *rear)
{
    if (isEmpty(*front))
    {
        printf("Estouro: Não é possível excluir o elemento da frente. Deque está vazio.\n");
        return;
    }

    int removed = deque[*front];

    if (*front == *rear)
    {
        // Se o deque tem apenas um elemento
        *front = -1;
        *rear = -1;
    }
    else if (*front == MAX - 1)
    {
        *front = 0; // Volta para o início, formando a circularidade
    }
    else
    {
        *front = *front + 1;
    }

    printf("%d excluída da frente no Deque.\n", removed);
}

/**
 * @brief Função para excluir um elemento do final do deque.
 *
 * Se o deque não estiver vazio, o elemento é removido do final. Caso o deque
 * esteja vazio, uma mensagem de erro será exibida.
 *
 * @param deque Ponteiro para o deque.
 * @param front Ponteiro para o índice da frente.
 * @param rear Ponteiro para o índice de trás.
 */
void deleteRear(int *deque, int *front, int *rear)
{
    if (isEmpty(*front))
    {
        printf("Estouro: Não é possível excluir o elemento atrás. Deque está vazio.\n");
        return;
    }

    int removed = deque[*rear];

    if (*front == *rear)
    { // Se o deque tem apenas um elemento
        *front = -1;
        *rear = -1;
    }
    else if (*rear == 0)
    {
        *rear = MAX - 1; // Volta para o final, formando a circularidade
    }
    else
    {
        *rear = *rear - 1;
    }

    printf("%d excluída atrás no Deque.\n", removed);
}

/**
 * @brief Função para exibir os elementos do deque.
 *
 * Se o deque estiver vazio, uma mensagem informando que ele está vazio será exibida.
 * Caso contrário, todos os elementos serão mostrados.
 *
 * @param deque Ponteiro para o deque.
 * @param front Índice da frente do deque.
 * @param rear Índice de trás do deque.
 */
void displayDeque(int *deque, int front, int rear)
{
    if (isEmpty(front))
    {
        printf("Deque está vazia.\n");
        return;
    }

    printf("Os elementos da Deque são: ");

    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
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
    int *deque = (int *)malloc(MAX * sizeof(int));
    if (deque == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inicializando os índices do deque
    int front = -1;
    int rear = -1;

    insertRear(deque, &front, &rear, 5);
    displayDeque(deque, front, rear);

    insertFront(deque, &front, &rear, 15);
    displayDeque(deque, front, rear);

    insertRear(deque, &front, &rear, 25);
    displayDeque(deque, front, rear);

    deleteFront(deque, &front, &rear);
    displayDeque(deque, front, rear);

    deleteRear(deque, &front, &rear);
    displayDeque(deque, front, rear);

    // Libera a memória do deque
    free(deque);

    return 0;
}
