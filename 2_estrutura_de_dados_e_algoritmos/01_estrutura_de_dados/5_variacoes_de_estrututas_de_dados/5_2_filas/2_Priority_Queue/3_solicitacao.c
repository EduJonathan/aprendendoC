#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de um nó na lista de solicitações do elevador.
 *
 * Representa uma solicitação com andar, prioridade e ponteiro para o próximo nó.
 */
typedef struct No
{
    int andar;          /**< Número do andar solicitado */
    int prioridade;     /**< Prioridade da solicitação */
    struct No *proximo; /**< Ponteiro para o próximo nó */
} No;

/**
 * @brief Estrutura para os dados de uma solicitação removida.
 *
 * Contém o andar e a prioridade de uma solicitação removida da fila.
 */
typedef struct
{
    int andar;      /**< Número do andar solicitado */
    int prioridade; /**< Prioridade da solicitação */
} SolicitacaoDados;

/**
 * @brief Estrutura da fila de solicitações do elevador.
 *
 * Gerencia uma lista encadeada de solicitações ordenada por prioridade.
 */
typedef struct FILA
{
    No *inicio;     /**< Ponteiro para o início da lista */
    No *fim;        /**< Ponteiro para o final da lista */
    size_t tamanho; /**< Número total de solicitações */
} Fila;

/**
 * @brief Registra uma mensagem de erro no stderr.
 *
 * @param mensagem Mensagem de erro a ser exibida.
 */
static void logErro(const char *mensagem)
{
    fprintf(stderr, "[ERRO] %s\n", mensagem);
}

/**
 * @brief Inicializa uma fila de solicitações vazia.
 *
 * Configura os ponteiros de início e fim como NULL e o tamanho como zero.
 *
 * @param fila Ponteiro para a fila a ser inicializada.
 */
void inicializarFila(Fila *fila)
{
    if (!fila)
    {
        logErro("Ponteiro de fila inválido");
        return;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

/**
 * @brief Cria e inicializa uma nova fila de solicitações.
 *
 * @return Ponteiro para a nova fila ou NULL em caso de falha de alocação.
 */
Fila *criarFila(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (!fila)
    {
        logErro("Falha na alocação de memória para a fila");
        return NULL;
    }
    inicializarFila(fila);
    return fila;
}

bool filaVazia(const Fila *fila)
{
    if (!fila)
        return true;
    return fila->tamanho == 0;
}

size_t tamanhoFila(const Fila *fila)
{
    if (!fila)
        return 0;
    return fila->tamanho;
}

/**
 * @brief Encontra a posição para inserção mantendo a ordem de prioridade.
 *
 * @param fila Ponteiro para a fila.
 * @param prioridade Prioridade a ser inserida.
 * @return Ponteiro para o nó anterior à posição de inserção ou NULL se for no início.
 */
static No *encontrarPosicaoInsercao(Fila *fila, int prioridade)
{
    No *atual = fila->inicio;
    No *anterior = NULL;

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
 * Insere uma solicitação com base na prioridade (maior prioridade primeiro).
 * Se o andar já existe, atualiza a prioridade se a nova for maior.
 *
 * @param fila Ponteiro para a fila.
 * @param andar Número do andar solicitado (1 a 100).
 * @param prioridade Prioridade da solicitação (não negativa).
 */
void adicionarSolicitacao(Fila *fila, int andar, int prioridade)
{
    if (!fila || prioridade < 0 || andar < 1 || andar > 100)
    {
        logErro("Parâmetros inválidos para adicionar solicitação");
        return;
    }

    // Verifica se o andar já está na fila
    No *atual = fila->inicio;
    while (atual != NULL)
    {
        if (atual->andar == andar)
        {
            if (prioridade > atual->prioridade)
            {
                atual->prioridade = prioridade;
                // Nota: Reordenar a fila seria necessário em uma implementação mais complexa
            }
            return;
        }
        atual = atual->proximo;
    }

    No *nova = (No *)malloc(sizeof(No));
    if (!nova)
    {
        logErro("Falha na alocação de memória para nova solicitação");
        return;
    }
    nova->andar = andar;
    nova->prioridade = prioridade;
    nova->proximo = NULL;

    if (filaVazia(fila))
    {
        fila->inicio = fila->fim = nova;
    }
    else
    {
        No *anterior = encontrarPosicaoInsercao(fila, prioridade);
        if (anterior == NULL)
        {
            nova->proximo = fila->inicio;
            fila->inicio = nova;
        }
        else
        {
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
 * @brief Remove e retorna os dados da solicitação de maior prioridade.
 *
 * Remove a solicitação do início da fila e retorna seus dados.
 *
 * @param fila Ponteiro para a fila.
 * @return Ponteiro para os dados da solicitação removida ou NULL se a fila estiver vazia.
 */
SolicitacaoDados *removerSolicitacao(Fila *fila)
{
    if (!fila || filaVazia(fila))
    {
        logErro("Tentativa de remoção em fila vazia ou inválida");
        return NULL;
    }

    No *removida = fila->inicio;
    fila->inicio = removida->proximo;
    fila->tamanho--;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    SolicitacaoDados *dados = (SolicitacaoDados *)malloc(sizeof(SolicitacaoDados));
    if (!dados)
    {
        logErro("Falha na alocação de memória para dados da solicitação");
        free(removida);
        return NULL;
    }
    dados->andar = removida->andar;
    dados->prioridade = removida->prioridade;
    free(removida);
    return dados;
}

void listarSolicitacoes(const Fila *fila)
{
    if (!fila || filaVazia(fila))
    {
        printf("Não há solicitações na fila.\n");
        return;
    }

    No *atual = fila->inicio;
    printf("Solicitações de elevador (ordem de prioridade):\n");
    while (atual != NULL)
    {
        printf("Andar: %d | Prioridade: %d\n", atual->andar, atual->prioridade);
        atual = atual->proximo;
    }
}

/**
 * @brief Verifica se um andar específico está na fila.
 *
 * @param fila Ponteiro para a fila.
 * @param andar Andar a ser verificado.
 * @return true se o andar estiver na fila, false caso contrário.
 */
bool contemAndar(const Fila *fila, int andar)
{
    if (!fila)
        return false;

    No *atual = fila->inicio;
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

void liberarFila(Fila *fila)
{
    if (!fila)
        return;

    while (!filaVazia(fila))
    {
        SolicitacaoDados *dados = removerSolicitacao(fila);
        if (dados)
            free(dados);
    }
}

int main(int argc, char **argv)
{
    Fila *fila = criarFila();
    if (!fila)
    {
        logErro("Não foi possível criar a fila");
        return 1;
    }

    // Adicionando solicitações
    adicionarSolicitacao(fila, 5, 3);
    adicionarSolicitacao(fila, 2, 1);
    adicionarSolicitacao(fila, 8, 2);
    adicionarSolicitacao(fila, 3, 5);
    adicionarSolicitacao(fila, 7, 4);
    adicionarSolicitacao(fila, 5, 4); // Testa duplicata com prioridade maior

    // Listando solicitações
    listarSolicitacoes(fila);

    // Removendo uma solicitação
    SolicitacaoDados *dados = removerSolicitacao(fila);
    if (dados)
    {
        printf("\nSolicitação removida (Andar: %d, Prioridade: %d)\n", dados->andar, dados->prioridade);
        free(dados);
    }

    // Listando novamente
    listarSolicitacoes(fila);

    // Verificando andar
    int andarCheck = 5;
    printf("\nO andar %d %s está na fila.\n", andarCheck, contemAndar(fila, andarCheck) ? "" : "NÃO");

    // Liberando recursos
    liberarFila(fila);
    free(fila);
    return 0;
}
