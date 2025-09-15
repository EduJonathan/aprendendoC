#include <stdio.h>

#define MAX 5 ///< Tamanho máximo do deque

/**
 * @brief Estrutura que representa um deque circular.
 */
typedef struct
{
    int data[MAX]; ///< Array fixo para armazenar os elementos do deque
    int front;     ///< Índice do início do deque
    int rear;      ///< Índice do final do deque
} Deque;

/**
 * @brief Verifica se o deque está cheio.
 *
 * O deque está cheio quando o índice da frente está logo após o de trás,
 * considerando o comportamento circular.
 *
 * @param dq Ponteiro para a estrutura do deque.
 * @return Retorna 1 se cheio, 0 caso contrário.
 */
int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

/**
 * @brief Verifica se o deque está vazio.
 *
 * O deque está vazio quando o índice da frente é -1.
 *
 * @param dq Ponteiro para a estrutura do deque.
 * @return Retorna 1 se vazio, 0 caso contrário.
 */
int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}

/**
 * @brief Insere um elemento no início do deque.
 *
 * @param dq Ponteiro para a estrutura do deque.
 * @param key Valor a ser inserido.
 */
void insertFront(Deque *dq, int key)
{
    if (isFull(dq))
    {
        printf("Erro: Deque está cheio.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }

    dq->data[dq->front] = key;
    printf("%d inserido na frente.\n", key);
}

/**
 * @brief Insere um elemento no final do deque.
 *
 * @param dq Ponteiro para a estrutura do deque.
 * @param key Valor a ser inserido.
 */
void insertRear(Deque *dq, int key)
{
    if (isFull(dq))
    {
        printf("Erro: Deque está cheio.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }

    dq->data[dq->rear] = key;
    printf("%d inserido atrás.\n", key);
}

/**
 * @brief Remove um elemento do início do deque.
 *
 * @param dq Ponteiro para a estrutura do deque.
 */
void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Erro: Deque está vazio.\n");
        return;
    }

    int removed = dq->data[dq->front];

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }

    printf("%d removido da frente.\n", removed);
}

/**
 * @brief Remove um elemento do final do deque.
 *
 * @param dq Ponteiro para a estrutura do deque.
 */
void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Erro: Deque está vazio.\n");
        return;
    }

    int removed = dq->data[dq->rear];

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }

    printf("%d removido de trás.\n", removed);
}

/**
 * @brief Exibe os elementos do deque.
 *
 * Mostra os elementos do início ao fim, considerando o comportamento circular.
 *
 * @param dq Ponteiro para a estrutura do deque.
 */
void displayDeque(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque está vazio.\n");
        return;
    }

    printf("Conteúdo do Deque: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->data[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Deque dq = {.front = -1, .rear = -1};
    int opcao = 0, valor = 0;

    do
    {
        printf("\n--- Menu Deque Circular (Tamanho Fixo) ---\n");
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
            insertFront(&dq, valor);
            break;

        case 2:
            printf("Digite o valor a inserir atrás: ");
            scanf("%d", &valor);
            insertRear(&dq, valor);
            break;

        case 3:
            deleteFront(&dq);
            break;

        case 4:
            deleteRear(&dq);
            break;

        case 5:
            displayDeque(&dq);
            break;

        case 0:
            printf("Encerrando o programa.\n");
            break;

        default:
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
