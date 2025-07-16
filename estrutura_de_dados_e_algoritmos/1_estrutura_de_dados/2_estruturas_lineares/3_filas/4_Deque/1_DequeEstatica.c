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
        printf("Estouro: Deque está cheio.\n");
        return;
    }

    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else if (*front == 0)
    {
        *front = MAX - 1;
    }
    else
    {
        (*front)--;
    }

    deque[*front] = key;
    printf("%d inserido na frente do Deque.\n", key);
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
        printf("Estouro: Deque está cheio.\n");
        return;
    }

    if (*rear == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else if (*rear == MAX - 1)
    {
        *rear = 0;
    }
    else
    {
        (*rear)++;
    }

    deque[*rear] = key;
    printf("%d inserido atrás no Deque.\n", key);
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
        printf("Deque está vazio.\n");
        return;
    }

    int removed = deque[*front];

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else if (*front == MAX - 1)
    {
        *front = 0;
    }
    else
    {
        (*front)++;
    }

    printf("%d removido da frente do Deque.\n", removed);
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
        printf("Deque está vazio.\n");
        return;
    }

    int removed = deque[*rear];

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else if (*rear == 0)
    {
        *rear = MAX - 1;
    }
    else
    {
        (*rear)--;
    }

    printf("%d removido de trás do Deque.\n", removed);
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
        printf("Deque está vazio.\n");
        return;
    }

    printf("Elementos no Deque: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int front = -1, rear = -1;
    int *deque = (int *)malloc(MAX * sizeof(int));
    if (deque == NULL)
    {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    int opcao = 0, valor = 0;

    do
    {
        printf("\n--- Menu Deque Circular ---\n");
        printf("1. Inserir na frente\n");
        printf("2. Inserir atrás\n");
        printf("3. Remover da frente\n");
        printf("4. Remover atrás\n");
        printf("5. Exibir Deque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a inserir na frente: ");
            scanf("%d", &valor);
            insertFront(deque, &front, &rear, valor);
            break;

        case 2:
            printf("Digite o valor a inserir atrás: ");
            scanf("%d", &valor);
            insertRear(deque, &front, &rear, valor);
            break;

        case 3:
            deleteFront(deque, &front, &rear);
            break;

        case 4:
            deleteRear(deque, &front, &rear);
            break;

        case 5:
            displayDeque(deque, front, rear);
            break;

        case 0:
            printf("Encerrando...\n");

            break;
        default:
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(deque);
    return 0;
}
