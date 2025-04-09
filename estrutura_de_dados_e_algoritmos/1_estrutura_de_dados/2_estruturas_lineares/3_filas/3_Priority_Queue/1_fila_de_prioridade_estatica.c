#include <stdio.h>

#define MAX_QUEUE 10

/**
 * @brief Estrutura que representa uma fila de prioridade.
 */
typedef struct Fila
{
    int priotyQueue[MAX_QUEUE]; /**< Vetor que armazena os elementos da fila */
    int front;                  /**< Posição do primeiro elemento */
    int rear;                   /**< Posição do último elemento */
} FilaPrioridade;

/**
 * @brief Inicializa a fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 */
void criarFila(FilaPrioridade *fila)
{
    fila->front = -1;
    fila->rear = -1;
}

/**
 * @brief Verifica a posição correta de inserção do dado na fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @param dado Valor a ser inserido na fila
 */
void checarDadoDePrioridadeNaFila(FilaPrioridade *fila, int dado)
{
    for (int i = 0; i <= fila->rear; i++)
    {
        // Se o dado for maior ou igual a um elemento da fila, ele será inserido antes.
        if (dado >= fila->priotyQueue[i])
        {
            for (int j = fila->rear + 1; j > i; j--)
            {
                fila->priotyQueue[j] = fila->priotyQueue[j - 1];
            }
            fila->priotyQueue[i] = dado;
            return;
        }
    }
    fila->priotyQueue[fila->rear + 1] = dado; // Coloca no final se não encontrar prioridade maior
}

/**
 * @brief Insere um dado na fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @param dado Valor a ser inserido na fila
 */
void inserirDadoNaFila(FilaPrioridade *fila, int dado)
{
    if (fila->rear >= MAX_QUEUE - 1)
    {
        printf("Nenhum elemento pode mais ser inserido na fila\n");
        return;
    }

    if ((fila->front == -1) && (fila->rear == -1))
    {
        fila->front++;
        fila->rear++;
        fila->priotyQueue[fila->rear] = dado;
        return;
    }

    checarDadoDePrioridadeNaFila(fila, dado);
    fila->rear++; // Move rear após inserção
}

/**
 * @brief Deleta um dado específico da fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @param dado Valor a ser deletado da fila
 */
void deletarDadoNaFila(FilaPrioridade *fila, int dado)
{
    if ((fila->front == -1) && (fila->rear == -1))
    {
        printf("Fila Vazia\n");
        return;
    }

    for (int i = 0; i <= fila->rear; i++)
    {
        if (dado == fila->priotyQueue[i])
        {
            for (; i < fila->rear; i++)
            {
                fila->priotyQueue[i] = fila->priotyQueue[i + 1];
            }

            fila->priotyQueue[fila->rear] = -99;
            fila->rear--;

            if (fila->rear == -1)
            {
                fila->front = -1;
            }
            return;
        }
    }
    printf("%d Dado não encontrado na fila para deletar\n", dado);
}

/**
 * @brief Exibe todos os elementos da fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 */
void exibirFila(FilaPrioridade *fila)
{
    if ((fila->front == -1) && (fila->rear == -1))
    {
        printf("Fila vazia\n");
        return;
    }
    for (int i = fila->front; i <= fila->rear; i++)
    {
        printf(" %d ", fila->priotyQueue[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    FilaPrioridade fila;
    criarFila(&fila);

    inserirDadoNaFila(&fila, 5);
    inserirDadoNaFila(&fila, 10); /* O maior Elemento da fila será o maior número*/
    inserirDadoNaFila(&fila, 2);

    printf("Fila após inserção: ");
    exibirFila(&fila);

    deletarDadoNaFila(&fila, 10);

    printf("\nFila após deleção: ");
    exibirFila(&fila);

    printf("Fila após nova inserção: ");
    inserirDadoNaFila(&fila, 20); /* O maior Elemento da fila será o maior número*/
    inserirDadoNaFila(&fila, 6);  /* O maior Elemento da fila será o maior número*/
    exibirFila(&fila);

    return 0;
}
