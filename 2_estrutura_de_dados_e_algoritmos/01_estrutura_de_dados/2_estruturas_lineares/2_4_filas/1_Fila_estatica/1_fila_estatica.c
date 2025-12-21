#include <stdio.h>

#define QUEUE_SIZE 10

/**
 * @brief Insere um valor na fila.
 *
 * A função `enQueue` é responsável por inserir um elemento no final da fila.
 * Se a fila estiver vazia, o índice `front` é inicializado.
 * Caso a fila esteja cheia, uma mensagem de erro é exibida.
 *
 * @param queue O vetor que representa a fila.
 * @param front Ponteiro para o índice `front`, que indica o início da fila.
 * @param rear Ponteiro para o índice `rear`, que indica o final da fila.
 * @param valor O valor a ser inserido na fila.
 */
void enQueue(int queue[], int *front, int *rear, int valor)
{
    // Se a fila estiver vazia, inicializamos o front
    if (*front == -1)
    {
        *front = 0;
    }

    // Se a fila não estiver cheia, insere o valor no final
    if (*rear < QUEUE_SIZE - 1)
    {
        (*rear)++;
        queue[*rear] = valor;
        printf("Valor %d inserido na fila\n", valor);
    }
    else
    {
        printf("Fila cheia\n");
    }
}

/**
 * @brief Remove um valor da fila.
 *
 * A função `deQueue` remove o elemento da frente da fila. Se a fila estiver vazia,
 * uma mensagem de erro é exibida. Após a remoção, se a fila ficar vazia, os índices
 * `front` e `rear` são reinicializados.
 *
 * @param queue O vetor que representa a fila.
 * @param front Ponteiro para o índice `front`, que indica o início da fila.
 * @param rear Ponteiro para o índice `rear`, que indica o final da fila.
 */
void deQueue(int queue[], int *front, int *rear)
{
    // Verificando se a fila não está vazia
    if (*front == -1)
    {
        printf("Fila vazia\n");
        return;
    }

    // Removendo o primeiro elemento (da frente)
    printf("Valor %d removido da fila\n", queue[*front]);
    (*front)++;

    // Se a fila ficou vazia após a remoção, reseta os índices
    if (*front > *rear)
    {
        // Após a remoção, se a fila ficar vazia, os índices `front` e `rear` são reinicializados
        *front = *rear = -1;
    }
}

/**
 * @brief Exibe os elementos da fila.
 *
 * @param queue O vetor que representa a fila.
 * @param front O índice `front`, que indica o início da fila.
 * @param rear O índice `rear`, que indica o final da fila.
 */
void display(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Fila vazia\n");
        return;
    }

    printf("Os elementos da fila são: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int queue[QUEUE_SIZE] = {0}; // Fila de tamanho fixo
    int front = -1;              // Inicializando as variáveis `front` e `rear`
    int rear = -1;               // Inicializando as variáveis `front` e `rear`
    int value = 0;               // Variável para armazenar o valor inserido pelo usuário
    int opcao = 0;               // Variável para armazenar a opção escolhida pelo usuário

    do
    {
        printf("\n\nOpções:\n");
        printf("1 -> Inserir um elemento na fila\n");
        printf("2 -> Remover um elemento da fila\n");
        printf("3 -> Mostrar os elementos da fila\n");
        printf("4 -> Sair: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido na fila: ");
            scanf("%d", &value);
            enQueue(queue, &front, &rear, value);
            break;

        case 2:
            deQueue(queue, &front, &rear);
            break;
        case 3:
            display(queue, front, rear);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}
