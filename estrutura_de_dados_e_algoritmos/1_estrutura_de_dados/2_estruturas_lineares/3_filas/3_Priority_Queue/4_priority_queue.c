#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila_prioridade
{
    int elemento;                    /**< Elemento armazenado na fila (por exemplo, um valor de uma tarefa ou dado) */
    int prioridade;                  /**< Prioridade do elemento (quanto maior o número, maior a prioridade) */
    struct fila_prioridade *proximo; /**< Ponteiro para o próximo elemento da fila */
} FilaPrioridade;

/**
 * @brief Estrutura da fila de prioridade.
 *
 * A fila de prioridade mantém os elementos organizados de acordo com sua prioridade.
 * A inserção de elementos é feita de maneira que os elementos com maior prioridade
 * fiquem na frente da fila, enquanto os elementos com menor prioridade são inseridos
 * na parte de trás da fila. O elemento de maior prioridade é sempre retirado primeiro.
 *
 * @note A estrutura é baseada em uma lista encadeada onde os elementos são inseridos
 *       em ordem de prioridade, com a possibilidade de ter vários elementos com a mesma prioridade.
 */
typedef struct fila_prioridade_struct
{
    FilaPrioridade *inicio; /**< Ponteiro para o início da lista de elementos */
    FilaPrioridade *fim;    /**< Ponteiro para o final da lista de elementos */
    size_t tamanho;         /**< Número total de elementos na fila */
} FilaPrioridadeStruct;

/**
 * @brief Inicializa a fila de prioridade.
 *
 * Esta função inicializa a fila de prioridade como vazia. O ponteiro para o início e o final da lista
 * são definidos como NULL, e o tamanho da fila é setado como zero.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct que será inicializada
 */
void inicializarFilaPrioridade(FilaPrioridadeStruct *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

/**
 * @brief Verifica se a fila de prioridade está vazia.
 *
 * A fila de prioridade é considerada vazia quando o número de elementos é zero ou quando o ponteiro
 * de início é NULL.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct
 * @return true se a fila estiver vazia, caso contrário false
 */
bool filaPrioridadeVazia(FilaPrioridadeStruct *fila) { return fila->tamanho == 0; }

/**
 * @brief Adiciona um novo elemento à fila de prioridade.
 *
 * O elemento é inserido na fila de forma ordenada de acordo com sua prioridade. O elemento com maior prioridade
 * é inserido na frente da fila, e os elementos com prioridades menores são colocados mais para o final.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct
 * @param elemento O elemento a ser adicionado à fila
 * @param prioridade A prioridade do elemento (quanto maior a prioridade, maior a chance de ser retirado primeiro)
 */
void adicionarElemento(FilaPrioridadeStruct *fila, int elemento, int prioridade)
{
    // Criando o novo nó de solicitação
    FilaPrioridade *novoElemento = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    if (novoElemento == NULL)
    {
        printf("Erro ao alocar memória para o elemento da fila de prioridade.\n");
        return;
    }

    novoElemento->elemento = elemento;
    novoElemento->prioridade = prioridade;
    novoElemento->proximo = NULL;

    // Caso a fila esteja vazia, o novo nó se torna o início e o fim
    if (filaPrioridadeVazia(fila))
    {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    }
    else
    {
        // Inserção ordenada de acordo com a prioridade
        FilaPrioridade *atual = fila->inicio;
        FilaPrioridade *anterior = NULL;

        // Procurando a posição correta para o novo elemento
        while (atual != NULL && atual->prioridade >= prioridade)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        // Inserção no início da fila (maior prioridade)
        if (anterior == NULL)
        {
            novoElemento->proximo = fila->inicio;
            fila->inicio = novoElemento;
        }
        else
        {
            // Inserção após o nó anterior
            anterior->proximo = novoElemento;
            novoElemento->proximo = atual;

            // Se o nó inserido for o último, atualizamos o fim
            if (atual == NULL)
            {
                fila->fim = novoElemento;
            }
        }
    }

    fila->tamanho++;
}

/**
 * @brief Remove e retorna o elemento de maior prioridade da fila.
 *
 * O elemento de maior prioridade será removido da fila e retornado. Após a remoção,
 * o próximo elemento se torna o novo início da fila.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct
 * @return FilaPrioridade* Ponteiro para o elemento removido
 */
FilaPrioridade *removerElemento(FilaPrioridadeStruct *fila)
{
    if (filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia. Não há elementos para remover.\n");
        return NULL;
    }

    // O elemento de maior prioridade está no início da fila
    FilaPrioridade *elementoRemovido = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    // Se a fila ficou vazia, o fim também precisa ser NULL
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    fila->tamanho--;
    return elementoRemovido;
}

/**
 * @brief Verifica se um elemento está presente na fila de prioridade e exibe a posição.
 *
 * Esta função percorre a fila de prioridade, comparando o valor do elemento de cada nó com
 * o valor fornecido. Se encontrar um nó com o mesmo valor, retorna `true`, indicando que o
 * elemento está presente na fila e exibe a posição onde o elemento foi encontrado. Caso contrário,
 * retorna `false`, indicando que o elemento não foi encontrado na fila.
 *
 * @param fila Ponteiro para a estrutura `FilaPrioridadeStruct` que representa a fila de prioridade.
 * @param elemento O valor do elemento a ser procurado na fila.
 *
 * @return `true` se o elemento for encontrado na fila, caso contrário, `false`.
 */
bool buscarElemento(FilaPrioridadeStruct *fila, int elemento)
{
    // Ponteiro para percorrer a lista de elementos da fila
    FilaPrioridade *atual = fila->inicio;
    int posicao = 1; // Inicializa a posição na fila

    // Percorre a fila verificando se algum elemento corresponde ao valor procurado
    while (atual != NULL)
    {
        if (atual->elemento == elemento)
        {
            printf("\nElemento %d encontrado na posição %d da fila.\n", elemento, posicao);
            return true; // Elemento encontrado
        }
        atual = atual->proximo; // Avança para o próximo nó
        posicao++;              // Incrementa a posição
    }

    // Elemento não encontrado
    printf("\nElemento %d não encontrado na fila.\n", elemento);
    return false;
}

/**
 * @brief Exibe todos os elementos na fila, ordenados por prioridade.
 *
 * A função percorre a fila e imprime cada elemento junto com a sua prioridade, na ordem de
 * maior para menor prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct
 */
void listarFilaPrioridade(FilaPrioridadeStruct *fila)
{
    if (filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia.\n");
        return;
    }

    FilaPrioridade *atual = fila->inicio;
    printf("Fila de Prioridade (elementos com maior prioridade primeiro):\n");
    while (atual != NULL)
    {
        printf("Elemento: %d | Prioridade: %d\n", atual->elemento, atual->prioridade);
        atual = atual->proximo;
    }
}

/**
 * @brief Libera a memória alocada para a fila de prioridade.
 *
 * A função percorre toda a fila e libera a memória de cada nó da lista de elementos.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridadeStruct
 */
void liberarFilaPrioridade(FilaPrioridadeStruct *fila)
{
    while (!filaPrioridadeVazia(fila))
    {
        FilaPrioridade *elemento = removerElemento(fila);
        free(elemento);
    }
}

int main(int argc, char **argv)
{
    FilaPrioridadeStruct priority_queue;

    inicializarFilaPrioridade(&priority_queue);

    adicionarElemento(&priority_queue, 4, 10);
    adicionarElemento(&priority_queue, 10, 15);
    adicionarElemento(&priority_queue, 8, 11);

    listarFilaPrioridade(&priority_queue);

    removerElemento(&priority_queue);

    listarFilaPrioridade(&priority_queue);

    buscarElemento(&priority_queue, 8);

    liberarFilaPrioridade(&priority_queue);
    return 0;
}
