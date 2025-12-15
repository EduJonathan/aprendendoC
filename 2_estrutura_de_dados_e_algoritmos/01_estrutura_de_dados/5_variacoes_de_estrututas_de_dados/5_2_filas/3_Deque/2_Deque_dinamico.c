#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int *array;
    int front;
    int rear;
    int max;
} Deque;

/**
 * @brief Inicializa o deque com tamanho fixo.
 *
 * @param max Tamanho máximo do deque.
 * @return Ponteiro para o deque inicializado ou NULL em caso de erro.
 */
Deque *initDeque(int max)
{
    Deque *deque = malloc(sizeof(Deque));
    if (deque == NULL)
        return NULL;

    deque->array = malloc(max * sizeof(int));
    if (deque->array == NULL)
    {
        free(deque);
        return NULL;
    }
    deque->max = max;
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

/**
 * @brief Libera a memória alocada para o deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 */
void freeDeque(Deque *deque)
{
    if (deque != NULL)
    {
        free(deque->array);
        free(deque);
    }
}

/**
 * @brief Verifica se o deque está cheio.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @return 1 se cheio, 0 caso contrário.
 */
int isFull(Deque *deque)
{
    if (deque == NULL)
        return 0;
    return deque->front == (deque->rear + 1) % deque->max;
}

/**
 * @brief Verifica se o deque está vazio.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @return 1 se vazio, 0 caso contrário.
 */
int isEmpty(Deque *deque)
{
    if (deque == NULL)
        return 1;
    return deque->front == -1;
}

/**
 * @brief Insere um elemento na frente do deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @param key Valor a ser inserido.
 */
void insertFront(Deque *deque, int key)
{
    if (deque == NULL || deque->array == NULL)
    {
        printf("Erro: Deque não inicializado.\n");
        return;
    }
    
    if (isFull(deque))
    {
        printf("Estouro: Deque está cheio.\n");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->front == 0)
    {
        deque->front = deque->max - 1;
    }
    else
    {
        deque->front--;
    }

    deque->array[deque->front] = key;
    printf("%d inserido na frente do Deque.\n", key);
}

/**
 * @brief Insere um elemento no final do deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @param key Valor a ser inserido.
 */
void insertRear(Deque *deque, int key)
{
    if (deque == NULL || deque->array == NULL)
    {
        printf("Erro: Deque não inicializado.\n");
        return;
    }

    if (isFull(deque))
    {
        printf("Estouro: Deque está cheio.\n");
        return;
    }

    if (deque->rear == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->rear == deque->max - 1)
    {
        deque->rear = 0;
    }
    else
    {
        deque->rear++;
    }

    deque->array[deque->rear] = key;
    printf("%d inserido atrás no Deque.\n", key);
}

/**
 * @brief Remove um elemento da frente do deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 */
void deleteFront(Deque *deque)
{
    if (deque == NULL || isEmpty(deque))
    {
        printf("Deque está vazio.\n");
        return;
    }

    int removed = deque->array[deque->front];
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->front == deque->max - 1)
    {
        deque->front = 0;
    }
    else
    {
        deque->front++;
    }
    printf("%d removido da frente do Deque.\n", removed);
}

/**
 * @brief Remove um elemento do final do deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 */
void deleteRear(Deque *deque)
{
    if (deque == NULL || isEmpty(deque))
    {
        printf("Deque está vazio.\n");
        return;
    }

    int removed = deque->array[deque->rear];
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
        deque->rear = deque->max - 1;
    }
    else
    {
        deque->rear--;
    }
    printf("%d removido de trás do Deque.\n", removed);
}

/**
 * @brief Consulta o elemento da frente sem removê-lo.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @param value Ponteiro para armazenar o valor da frente.
 * @return 1 se bem-sucedido, 0 se o deque estiver vazio.
 */
int peekFront(Deque *deque, int *value)
{
    if (deque == NULL || isEmpty(deque))
    {
        printf("Deque está vazio.\n");
        return 0;
    }
    *value = deque->array[deque->front];
    return 1;
}

/**
 * @brief Consulta o elemento do final sem removê-lo.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @param value Ponteiro para armazenar o valor do final.
 * @return 1 se bem-sucedido, 0 se o deque estiver vazio.
 */
int peekRear(Deque *deque, int *value)
{
    if (deque == NULL || isEmpty(deque))
    {
        printf("Deque está vazio.\n");
        return 0;
    }
    *value = deque->array[deque->rear];
    return 1;
}

/**
 * @brief Retorna o número de elementos no deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 * @return Número de elementos.
 */
int size(Deque *deque)
{
    if (deque == NULL || isEmpty(deque))
        return 0;

    if (deque->front <= deque->rear)
    {
        return deque->rear - deque->front + 1;
    }
    return (deque->max - deque->front + deque->rear + 1);
}

/**
 * @brief Exibe os elementos do deque.
 *
 * @param deque Ponteiro para a estrutura Deque.
 */
void displayDeque(Deque *deque)
{
    if (deque == NULL || isEmpty(deque))
    {
        printf("Deque está vazio.\n");
        return;
    }

    printf("Elementos no Deque: ");
    int i = deque->front;
    while (1)
    {
        printf("%d ", deque->array[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % deque->max;
    }
    printf("\n");
}

void DequeMenu(Deque *deque)
{
    int opcao = 0, valor = 0;
    while (1)
    {
        printf("\n--- Menu Deque Circular ---\n");
        printf("1. Inserir na frente\n");
        printf("2. Inserir atrás\n");
        printf("3. Remover da frente\n");
        printf("4. Remover atrás\n");
        printf("5. Consultar frente\n");
        printf("6. Consultar trás\n");
        printf("7. Tamanho do deque\n");
        printf("8. Exibir Deque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1)
        {
            printf("Erro: Entrada inválida.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a inserir na frente: ");
            if (scanf("%d", &valor) != 1)
            {
                printf("Erro: Entrada inválida.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');
            insertFront(deque, valor);
            break;

        case 2:
            printf("Digite o valor a inserir atrás: ");
            if (scanf("%d", &valor) != 1)
            {
                printf("Erro: Entrada inválida.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');
            insertRear(deque, valor);
            break;

        case 3:
            deleteFront(deque);
            break;

        case 4:
            deleteRear(deque);
            break;

        case 5:
            if (peekFront(deque, &valor))
            {
                printf("Elemento na frente: %d\n", valor);
            }
            break;

        case 6:
            if (peekRear(deque, &valor))
            {
                printf("Elemento atrás: %d\n", valor);
            }
            break;

        case 7:
            printf("Tamanho do deque: %d\n", size(deque));
            break;

        case 8:
            displayDeque(deque);
            break;

        case 0:
            printf("Encerrando...\n");
            return;

        default:
            printf("Opção inválida.\n");
        }
    }
}

int main(int argc, char **argv)
{
    Deque *deque = initDeque(MAX);
    if (deque == NULL)
    {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    DequeMenu(deque);
    freeDeque(deque);
    return 0;
}
