#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

/**
 * @brief Estrutura que representa uma fila circular.
 *
 * A fila circular é uma estrutura de dados que armazena elementos de forma
 * sequencial e reutiliza espaços vazios no início após atingir o fim, mantendo
 * a propriedade circular sem mover elementos.
 */
typedef struct fila
{
    int frente;                /**< Índice do primeiro elemento na fila */
    int atras;                 /**< Índice do último elemento na fila */
    int elementos[QUEUE_SIZE]; /**< Vetor estático que armazena os elementos */
    int contador;              /**< Número de elementos na fila */
} filaCircular;

/**
 * @brief Inicializa a fila circular com valores padrão.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 */
void inicializarFila(filaCircular *queue)
{
    queue->frente = 0;
    queue->atras = -1;
    queue->contador = 0;
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        queue->elementos[i] = 0; // Opcional: inicializa elementos com 0
    }
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return true se a fila estiver vazia, false caso contrário
 */
bool filaVazia(const filaCircular *queue)
{
    return queue->contador == 0;
}

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return true se a fila estiver cheia, false caso contrário
 */
bool filaCheia(const filaCircular *queue)
{
    return queue->contador == QUEUE_SIZE;
}

/**
 * @brief Retorna o número de elementos na fila.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return Número de elementos na fila
 */
int tamanhoFila(const filaCircular *queue)
{
    return queue->contador;
}

/**
 * @brief Insere um elemento na fila circular.
 *
 * Insere no final da fila, reutilizando espaços no início quando necessário.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @param elemento O valor a ser inserido
 * @return true se a inserção for bem-sucedida, false se a fila estiver cheia
 */
bool inserirElementoNaFila(filaCircular *queue, int elemento)
{
    if (filaCheia(queue))
    {
        printf("Fila cheia! Não é possível inserir %d.\n", elemento);
        return false;
    }

    if (elemento < 0)
    {
        printf("Erro: Apenas valores não negativos são permitidos.\n");
        return false;
    }

    queue->atras = (queue->atras + 1) % QUEUE_SIZE;
    queue->elementos[queue->atras] = elemento;
    queue->contador++;
    return true;
}

/**
 * @brief Remove um elemento da fila circular.
 *
 * Remove o primeiro elemento da fila e ajusta o índice frente.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return O elemento removido ou -1 se a fila estiver vazia
 */
int removerElementoNaFila(filaCircular *queue)
{
    if (filaVazia(queue))
    {
        printf("Fila vazia! Não é possível remover.\n");
        return -1;
    }

    int elementoRemovido = queue->elementos[queue->frente];
    queue->elementos[queue->frente] = 0; // Opcional: limpa o espaço
    queue->frente = (queue->frente + 1) % QUEUE_SIZE;
    queue->contador--;
    return elementoRemovido;
}

/**
 * @brief Exibe os elementos da fila circular.
 *
 * Exibe os elementos na ordem correta, respeitando a circularidade.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 */
void exibirFila(const filaCircular *queue)
{
    if (filaVazia(queue))
    {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila (%d elementos): ", queue->contador);
    int i = queue->frente;
    for (int count = 0; count < queue->contador; count++)
    {
        printf("%d ", queue->elementos[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    filaCircular fila;
    inicializarFila(&fila);

    // Teste de inserção
    inserirElementoNaFila(&fila, 10);
    inserirElementoNaFila(&fila, 15);
    inserirElementoNaFila(&fila, 20);
    inserirElementoNaFila(&fila, 25);
    inserirElementoNaFila(&fila, 30);
    exibirFila(&fila);

    // Teste de remoção
    int removido = removerElementoNaFila(&fila);
    if (removido != -1)
    {
        printf("Elemento removido: %d\n", removido);
    }
    exibirFila(&fila);

    // Teste de inserção após remoção (circularidade)
    inserirElementoNaFila(&fila, 35);
    exibirFila(&fila);

    // Teste de inserção inválida
    inserirElementoNaFila(&fila, -5);

    // Exibe tamanho da fila
    printf("Tamanho atual da fila: %d\n", tamanhoFila(&fila));

    return 0;
}