#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura que representa uma fila circular.
 */
typedef struct fila
{
    int frente;     /**< Índice do primeiro elemento na fila */
    int atras;      /**< Índice do último elemento na fila */
    int *elementos; /**< Ponteiro para o vetor que armazena os elementos da fila */
    int contador;   /**< Número de elementos na fila */
    int capacidade; /**< Capacidade máxima da fila */
} filaCircular;

/**
 * @brief Função para inicializar a fila circular.
 *
 * Aloca memória dinamicamente para a fila com a capacidade especificada.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @param capacidade A capacidade máxima da fila
 */
void inicializarFila(filaCircular *queue, int capacidade)
{
    queue->capacidade = capacidade;
    queue->elementos = (int *)malloc(capacidade * sizeof(int));

    if (queue->elementos == NULL)
    {
        printf("Erro ao alocar memória para a fila!\n");
        exit(1); // Sai caso não consiga alocar a memória
    }

    queue->frente = 0;
    queue->atras = -1;
    queue->contador = 0;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return Retorna true se a fila estiver vazia, caso contrário, retorna false
 */
bool filaVazia(filaCircular *queue)
{
    return (queue->contador == 0);
}

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return Retorna true se a fila estiver cheia, caso contrário, retorna false
 */
bool filaCheia(filaCircular *queue)
{
    return (queue->contador == queue->capacidade);
}

/**
 * @brief Insere um elemento na fila circular.
 *
 * A inserção é feita no final da fila. Quando a fila chega ao fim, ela começa a
 * reutilizar os espaços vagos no início, tornando-se circular.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @param elemento O valor a ser inserido na fila
 */
void inserirElementoNaFila(filaCircular *queue, int elemento)
{
    if (filaCheia(queue))
    {
        printf("Fila cheia! Não é possível inserir %d.\n", elemento);
        return;
    }

    // Atualiza o índice "atras" de forma circular
    queue->atras = (queue->atras + 1) % queue->capacidade;
    queue->elementos[queue->atras] = elemento;
    queue->contador++;
}

/**
 * @brief Remove um elemento da fila circular.
 *
 * O elemento removido será o primeiro da fila, e a fila é atualizada de forma
 * circular. Quando a remoção é feita, o índice "frente" é ajustado.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 * @return O elemento removido da fila, ou -1 se a fila estiver vazia
 */
int removerElementoNaFila(filaCircular *queue)
{
    if (filaVazia(queue))
    {
        printf("Fila vazia! Não é possível remover.\n");
        return -1; // Retorno inválido para indicar erro
    }

    int elementoRemovido = queue->elementos[queue->frente];
    queue->frente = (queue->frente + 1) % queue->capacidade;
    queue->contador--;
    return elementoRemovido;
}

/**
 * @brief Exibe os elementos presentes na fila circular.
 *
 * A função exibe todos os elementos da fila, respeitando a estrutura circular.
 * Caso a fila esteja vazia, uma mensagem informando isso será exibida.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 */
void exibirFila(filaCircular *queue)
{
    if (filaVazia(queue))
    {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");
    int i = queue->frente;
    int count = 0;

    // Exibe os elementos da fila respeitando a circularidade
    while (count < queue->contador)
    {
        printf("%d ", queue->elementos[i]);
        i = (i + 1) % queue->capacidade;
        count++;
    }
    printf("\n");
}

/**
 * @brief Função para liberar a memória alocada para a fila.
 *
 * Desaloca a memória que foi alocada para os elementos da fila.
 *
 * @param queue Ponteiro para a estrutura filaCircular
 */
void liberarFila(filaCircular *queue)
{
    free(queue->elementos); // Libera a memória alocada para os elementos
    queue->elementos = NULL;
}

int main(int argc, char **argv)
{
    // Inicializando a fila com capacidade 5
    filaCircular fila = {0};
    inicializarFila(&fila, 5);

    // Insere elementos na fila
    inserirElementoNaFila(&fila, 10);
    inserirElementoNaFila(&fila, 15);
    inserirElementoNaFila(&fila, 20);
    inserirElementoNaFila(&fila, 25);
    inserirElementoNaFila(&fila, 30);

    // Exibe a fila após inserções
    exibirFila(&fila);

    // Remove um elemento da fila
    int removido = removerElementoNaFila(&fila);
    if (removido != -1)
    {
        printf("Elemento removido: %d\n", removido);
    }

    // Exibe a fila após remoção
    exibirFila(&fila);

    // Insere mais um elemento (testando a circularidade)
    inserirElementoNaFila(&fila, 35);

    // Exibe a fila após nova inserção
    exibirFila(&fila);

    // Libera a memória alocada para a fila
    liberarFila(&fila);

    return 0;
}
