#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Estrutura de um nó na lista de solicitações do elevador.
 *
 * Cada nó representa uma solicitação de andar com o número do andar e um ponteiro
 * para o próximo nó na lista de prioridades.
 * A lista é gerenciada como uma fila de prioridade, onde as solicitações mais urgentes
 * (por exemplo, chamadas para andar mais próximo) são atendidas primeiro.
 */
typedef struct solicitacao
{
    int andar;                   /**< Número do andar solicitado */
    int prioridade;              /**< Prioridade da solicitação (quanto maior o valor, maior a prioridade) */
    struct solicitacao *proximo; /**< Ponteiro para o próximo nó na lista de solicitações */
} Solicitacao;

/**
 * @brief Estrutura de dados que representa a fila de solicitações do elevador.
 *
 * A fila de solicitações é organizada como uma lista encadeada de nós (do tipo
 * Solicitacao) e pode ser ordenada de acordo com a prioridade das solicitações.
 */
typedef struct filaSolicitacoes
{
    Solicitacao *inicio; /**< Ponteiro para o início da lista de solicitações */
    Solicitacao *fim;    /**< Ponteiro para o final da lista de solicitações */
    size_t tamanho;      /**< Número total de solicitações na fila */
} FilaSolicitacoes;

/**
 * @brief Inicializa a fila de solicitações do elevador.
 *
 * Essa função cria uma fila de solicitações vazia, com o ponteiro para o início
 * e o fim da lista configurados como NULL e o tamanho igual a zero.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes que será inicializada
 */
void inicializarFilaSolicitacoes(FilaSolicitacoes *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

/**
 * @brief Verifica se a fila de solicitações está vazia.
 *
 * A fila é considerada vazia quando o número de solicitações é igual a zero ou quando
 * o ponteiro de início é NULL.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes
 * @return true se a fila estiver vazia, caso contrário false
 */
bool filaSolicitacoesVazia(FilaSolicitacoes *fila) { return fila->tamanho == 0; }

/**
 * @brief Retorna o tamanho atual da fila
 *
 * @param fila Ponteiro para a fila
 * @return Número de solicitações na fila
 */
size_t tamanhoFila(const FilaSolicitacoes *fila) { return fila->tamanho; }

/**
 * @brief Encontra a posição correta para inserção mantendo a ordem de prioridade
 *
 * @param fila Ponteiro para a fila
 * @param prioridade Prioridade a ser inserida
 * @return Ponteiro para o nó anterior à posição de inserção
 */
static Solicitacao *encontrarPosicaoInsercao(FilaSolicitacoes *fila, int prioridade)
{
    Solicitacao *atual = fila->inicio;
    Solicitacao *anterior = NULL;

    while (atual != NULL && atual->prioridade >= prioridade)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    return anterior;
}

/**
 * @brief Adiciona uma nova solicitação à fila, mantendo a ordem de prioridade.
 *
 * A solicitação é inserida na fila com base na prioridade. As solicitações com maior
 * prioridade (valor maior) serão inseridas mais próximas da frente da fila.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes
 * @param andar Número do andar solicitado
 * @param prioridade Prioridade da solicitação (quanto maior o número, maior a prioridade)
 */
void adicionarSolicitacao(FilaSolicitacoes *fila, int andar, int prioridade)
{
    if (prioridade < 0)
    {
        fprintf(stderr, "Erro: Prioridade negativa não permitida\n");
        return;
    }

    Solicitacao *nova = (Solicitacao *)malloc(sizeof(Solicitacao));
    if (!nova)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        return;
    }

    nova->andar = andar;
    nova->prioridade = prioridade;
    nova->proximo = NULL;

    if (filaSolicitacoesVazia(fila))
    {
        fila->inicio = fila->fim = nova;
    }
    else
    {
        Solicitacao *anterior = encontrarPosicaoInsercao(fila, prioridade);

        if (anterior == NULL)
        {
            // Inserção no início
            nova->proximo = fila->inicio;
            fila->inicio = nova;
        }
        else
        {
            // Inserção no meio ou fim
            nova->proximo = anterior->proximo;
            anterior->proximo = nova;

            if (nova->proximo == NULL)
            {
                fila->fim = nova;
            }
        }
    }

    fila->tamanho++;
}

/**
 * @brief Remove e retorna a solicitação de maior prioridade da fila.
 *
 * A solicitação com a maior prioridade será removida e retornada. Após a remoção,
 * o próximo nó se torna o novo início da fila.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes
 * @return Solicitacao* Ponteiro para a solicitação removida
 */
Solicitacao *removerSolicitacao(FilaSolicitacoes *fila)
{
    if (filaSolicitacoesVazia(fila))
    {
        fprintf(stderr, "Aviso: Tentativa de remoção em fila vazia\n");
        return NULL;
    }

    Solicitacao *removida = fila->inicio;
    fila->inicio = removida->proximo;
    fila->tamanho--;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    removida->proximo = NULL;
    return removida;
}

/**
 * @brief Exibe todas as solicitações na fila, ordenadas por prioridade.
 *
 * A função percorre a fila e imprime cada solicitação, juntamente com seu andar e
 * prioridade, na ordem de chegada de maior prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes
 */
void listarSolicitacoes(FilaSolicitacoes *fila)
{
    if (filaSolicitacoesVazia(fila))
    {
        printf("Não há solicitações na fila.\n");
        return;
    }

    Solicitacao *atual = fila->inicio;
    printf("Solicitações de elevador (ordem de prioridade):\n");
    while (atual != NULL)
    {
        printf("Andar: %d | Prioridade: %d\n", atual->andar, atual->prioridade);
        atual = atual->proximo;
    }
}

/**
 * @brief Verifica se um andar específico está na fila
 *
 * @param fila Ponteiro para a fila
 * @param andar Andar a ser verificado
 * @return true se o andar estiver na fila, false caso contrário
 */
bool contemAndar(const FilaSolicitacoes *fila, int andar)
{
    Solicitacao *atual = fila->inicio;
    while (atual != NULL)
    {
        if (atual->andar == andar)
        {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

/**
 * @brief Libera a memória alocada para a fila de solicitações.
 *
 * A função percorre toda a fila e libera a memória de cada nó da lista de solicitações.
 *
 * @param fila Ponteiro para a estrutura FilaSolicitacoes
 */
void liberarFilaSolicitacoes(FilaSolicitacoes *fila)
{
    while (!filaSolicitacoesVazia(fila))
    {
        Solicitacao *solicitacao = removerSolicitacao(fila);
        free(solicitacao);
    }
}

int main(int argc, char **argv)
{
    FilaSolicitacoes fila = {0}; // Inicializa a fila de solicitações do elevador
    inicializarFilaSolicitacoes(&fila);

    // Adicionando solicitações
    adicionarSolicitacao(&fila, 5, 3);
    adicionarSolicitacao(&fila, 2, 1);
    adicionarSolicitacao(&fila, 8, 2);
    adicionarSolicitacao(&fila, 3, 5);
    adicionarSolicitacao(&fila, 7, 4);

    // Listando as solicitações (em ordem de prioridade)
    listarSolicitacoes(&fila);

    // Removendo uma solicitação e mostrando a nova lista
    Solicitacao *removida = removerSolicitacao(&fila);
    if (removida)
    {
        printf("\nSolicitação removida (Andar: %d, Prioridade: %d)\n", removida->andar, removida->prioridade);
        free(removida);
    }

    // Listando novamente as solicitações
    listarSolicitacoes(&fila);

    // Verificando se um andar está na fila
    int andarCheck = 5;
    if (contemAndar(&fila, andarCheck))
    {
        printf("\nO andar %d está na fila.\n", andarCheck);
    }
    else
    {
        printf("\nO andar %d NÃO está na fila.\n", andarCheck);
    }

    // Liberando a memória da fila
    liberarFilaSolicitacoes(&fila);

    return 0;
}
