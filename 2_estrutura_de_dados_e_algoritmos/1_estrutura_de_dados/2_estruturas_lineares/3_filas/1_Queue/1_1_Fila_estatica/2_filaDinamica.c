#include <stdio.h>
#include <stdlib.h>

#ifndef FILA_H
#define FILA_H

/**
 * @brief Estrutura de um nó da fila.
 * Cada nó contém um valor `data` e um ponteiro `next` que aponta para o próximo nó da fila.
 *
 * Fila é uma estrutura de dados linear que segue a ordem FIFO (First In First Out).
 * Os elementos são inseridos no final da fila e removidos do início.
 * Muitas vezes utilizada em algoritmos de processamento de tarefas, impressão, etc.
 * A fila é uma estrutura dinâmica, onde os elementos podem ser adicionados ou removidos
 * sem a necessidade de um tamanho fixo.
 *
 * Suas operações principais incluem:
 * - `enQueue`: Adiciona um elemento ao final da fila.
 *
 * - `deQueue`: Remove o elemento do início da fila.
 *
 * - `display`: Exibe todos os elementos da fila.
 *
 * - `checkEmpty`: Verifica se a fila está vazia.
 *
 * - `checkFull`: Verifica se a fila está cheia (apenas para filas estáticas).
 */
struct node
{
    float data;        ///< Valor armazenado na fila
    struct node *next; ///< Ponteiro para o próximo elemento da fila
};

#endif

/**
 * @brief Insere um valor na fila.
 *
 * Função que insere um valor no final da fila. Se a fila estiver vazia,
 * inicializa tanto o ponteiro `front` quanto o ponteiro `rear` para o novo nó.
 *
 * @param front Ponteiro para o ponteiro do início da fila.
 * @param rear Ponteiro para o ponteiro do final da fila.
 * @param valor O valor a ser inserido na fila.
 */
void enQueue(struct node **front, struct node **rear, float valor)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); ///< Criação de um novo nó
    newNode->data = valor;                                             ///< Atribui o valor ao nó
    newNode->next = NULL;                                              ///< O próximo nó é NULL, já que ele será o último

    // Verifica se a fila está vazia
    if (*front == NULL)
    {
        *front = newNode; ///< Inicializa o ponteiro `front` para o novo nó
        *rear = newNode;  ///< Inicializa o ponteiro `rear` para o novo nó
    }
    else
    {
        (*rear)->next = newNode; ///< Conecta o nó anterior ao novo
        *rear = newNode;         ///< Atualiza o ponteiro `rear` para o novo nó
    }
    printf("Valor %f inserido na fila\n", valor);
}

/**
 * @brief Remove um valor da fila.
 *
 * Função que remove o elemento da frente da fila. Se a fila estiver vazia,
 * uma mensagem de erro será exibida. Após a remoção, a memória do nó removido é liberada.
 *
 * @param front Ponteiro para o ponteiro do início da fila.
 * @param rear Ponteiro para o ponteiro do final da fila.
 */
void deQueue(struct node **front, struct node **rear)
{
    // Verifica se a fila está vazia
    if (*front == NULL)
    {
        printf("Fila vazia\n");
    }
    else
    {
        struct node *temp = *front; ///< Armazena o nó removido temporariamente
        *front = (*front)->next;    ///< Atualiza o ponteiro `front` para o próximo nó

        printf("Valor %.2f removido da fila\n", temp->data);
        free(temp); ///< Libera a memória do nó removido

        // Se a fila ficou vazia, reinicializa o ponteiro `rear`
        if (*front == NULL)
        {
            // Após a remoção, se a fila ficar vazia, os índices `front` e `rear` são reinicializados
            *rear = NULL;
        }
    }
}

/**
 * @brief Exibe os elementos da fila.
 *
 * Função que exibe todos os elementos presentes na fila. Se a fila estiver vazia,
 * uma mensagem de erro será exibida.
 *
 * @param front Ponteiro para o ponteiro do início da fila.
 */
void display(struct node *front)
{
    // Verifica se a fila está vazia
    if (front == NULL)
    {
        printf("Fila vazia\n");
    }
    else
    {
        // Ponteiro para percorrer a fila
        struct node *temp = front;

        // Enquanto houver elementos na fila
        while (temp != NULL)
        {
            printf("%f--> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/**
 * @brief Libera toda a memória alocada para a fila.
 *
 * Função que percorre todos os nós da fila e libera a memória alocada para cada um deles.
 * Após a execução, os ponteiros `front` e `rear` são atualizados para NULL.
 *
 * @param front Ponteiro para o ponteiro do início da fila.
 * @param rear Ponteiro para o ponteiro do final da fila.
 */
void freeQueue(struct node **front, struct node **rear)
{
    // Ponteiro para percorrer a fila
    struct node *temp = NULL;

    // Enquanto houver elementos na fila
    while (*front != NULL)
    {
        temp = *front;           ///< Armazena o nó atual
        *front = (*front)->next; ///< Avança para o próximo nó
        free(temp);              ///< Libera a memória do nó removido
    }

    *rear = NULL; // Após liberar todos os nós, atualiza os ponteiros `rear` para NULL
    printf("Memória da fila liberada\n");
}

int main(int argc, char **argv)
{
    struct node *front = NULL; ///< Ponteiro para o início da fila
    struct node *rear = NULL;  ///< Ponteiro para o final da fila
    float value = 0.0f;        ///< Variável para armazenar o valor inserido pelo usuário
    int opcao = 0;             ///< Variável para armazenar a opção escolhida pelo usuário

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
            scanf("%f", &value);
            enQueue(&front, &rear, value);
            break;

        case 2:
            deQueue(&front, &rear);
            break;

        case 3:
            display(front);
            break;

        case 4:
            printf("ATÉ A PRÓXIMA\n");
            exit(0);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 4);

    freeQueue(&front, &rear); ///< Libera a memória
    return 0;
}
