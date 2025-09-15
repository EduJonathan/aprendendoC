#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRIORIDADE_MINIMA 0
#define PRIORIDADE_MAXIMA 100

typedef struct no
{
    int elemento;
    int prioridade;
    struct no *proximo;
} No;

typedef struct fila_prioridade
{
    No *inicio;
    No *fim;
    size_t tamanho;
} FilaPrioridade;

/**
 * @brief Inicializa uma fila de prioridade como vazia.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade a ser inicializada.
 */
void inicializarFilaPrioridade(FilaPrioridade *fila)
{
    if (fila == NULL)
        return;
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

/**
 * @brief Verifica se a fila de prioridade está vazia.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 * @return true se a fila estiver vazia, false caso contrário.
 */
bool filaPrioridadeVazia(FilaPrioridade *fila)
{
    return fila == NULL || fila->tamanho == 0;
}

/**
 * @brief Adiciona um elemento à fila de prioridade.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 * @param elemento Elemento a ser adicionado.
 * @param prioridade Prioridade do elemento.
 */
void adicionarElemento(FilaPrioridade *fila, int elemento, int prioridade)
{
    if (fila == NULL)
    {
        printf("Erro: Ponteiro para fila é NULL.\n");
        return;
    }
    
    if (prioridade < PRIORIDADE_MINIMA || prioridade > PRIORIDADE_MAXIMA)
    {
        printf("Erro: Prioridade %d fora do intervalo permitido (%d a %d).\n",
               prioridade, PRIORIDADE_MINIMA, PRIORIDADE_MAXIMA);
        return;
    }

    No *novoElemento = malloc(sizeof(No));
    if (novoElemento == NULL)
    {
        printf("Erro ao alocar memória para o elemento da fila de prioridade.\n");
        return;
    }

    novoElemento->elemento = elemento;
    novoElemento->prioridade = prioridade;
    novoElemento->proximo = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    }
    else
    {
        No *atual = fila->inicio, *anterior = NULL;
        while (atual != NULL && atual->prioridade > prioridade)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL)
        {
            novoElemento->proximo = fila->inicio;
            fila->inicio = novoElemento;
        }
        else
        {
            anterior->proximo = novoElemento;
            novoElemento->proximo = atual;
            if (atual == NULL)
            {
                fila->fim = novoElemento;
            }
        }
    }
    fila->tamanho++;
}

/**
 * @brief Remove e retorna o elemento de maior prioridade.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 * @return Ponteiro para o elemento removido ou NULL se a fila estiver vazia.
 */
No *removerElemento(FilaPrioridade *fila)
{
    if (fila == NULL || filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia. Não há elementos para remover.\n");
        return NULL;
    }

    No *elementoRemovido = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    fila->tamanho--;
    return elementoRemovido;
}

/**
 * @brief Verifica se um elemento está presente na fila e exibe sua posição.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 * @param elemento Elemento a ser procurado.
 * @return true se encontrado, false caso contrário.
 */
bool buscarElemento(FilaPrioridade *fila, int elemento)
{
    if (fila == NULL || filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia.\n");
        return false;
    }

    No *atual = fila->inicio;
    int posicao = 1;
    while (atual != NULL)
    {
        if (atual->elemento == elemento)
        {
            printf("Elemento %d encontrado na posição %d da fila.\n", elemento, posicao);
            return true;
        }
        atual = atual->proximo;
        posicao++;
    }
    printf("Elemento %d não encontrado na fila.\n", elemento);
    return false;
}

/**
 * @brief Exibe todos os elementos da fila.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 */
void listarFilaPrioridade(FilaPrioridade *fila)
{
    if (fila == NULL || filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia.\n");
        return;
    }

    No *atual = fila->inicio;
    printf("Fila de Prioridade (maior prioridade primeiro):\n");
    while (atual != NULL)
    {
        printf("Elemento: %d | Prioridade: %d\n", atual->elemento, atual->prioridade);
        atual = atual->proximo;
    }
}

/**
 * @brief Libera a memória alocada para a fila.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 */
void liberarFilaPrioridade(FilaPrioridade *fila)
{
    if (fila == NULL)
        return;

    while (!filaPrioridadeVazia(fila))
    {
        No *elemento = removerElemento(fila);
        free(elemento);
    }
}

/**
 * @brief Retorna o elemento de maior prioridade sem removê-lo.
 * 
 * @param fila Ponteiro para a estrutura FilaPrioridade.
 * @return Ponteiro para o elemento de maior prioridade ou NULL se a fila estiver vazia.
 */
No *peek(FilaPrioridade *fila)
{
    if (fila == NULL || filaPrioridadeVazia(fila))
    {
        printf("A fila de prioridade está vazia.\n");
        return NULL;
    }
    return fila->inicio;
}

void testarFilaPrioridade(void)
{
    FilaPrioridade fila;
    inicializarFilaPrioridade(&fila);

    adicionarElemento(&fila, 4, 10);
    adicionarElemento(&fila, 10, 15);
    adicionarElemento(&fila, 8, 11);

    listarFilaPrioridade(&fila);

    No *elemento = removerElemento(&fila);
    if (elemento != NULL)
    {
        printf("Elemento removido: %d (Prioridade: %d)\n", elemento->elemento, elemento->prioridade);
        free(elemento);
    }

    listarFilaPrioridade(&fila);
    buscarElemento(&fila, 8);

    No *maiorPrioridade = peek(&fila);
    if (maiorPrioridade != NULL)
    {
        printf("Elemento de maior prioridade: %d (Prioridade: %d)\n",
               maiorPrioridade->elemento, maiorPrioridade->prioridade);
    }

    liberarFilaPrioridade(&fila);
}

int main(int argc, char **argv)
{
    testarFilaPrioridade();
    return 0;
}
